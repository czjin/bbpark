#include "feedbackcontroller.h"
#include "feedback.h"


FeedbackController::FeedbackController(const FeedbackController &)
    : ApplicationController()
{ }

void FeedbackController::index()
{
    QList<Feedback> feedbackList = Feedback::getAll();
    texport(feedbackList);
    render();
}

void FeedbackController::show(const QString &pk)
{
    auto feedback = Feedback::get(pk.toInt());
    texport(feedback);
    render();
}

void FeedbackController::entry()
{
    renderEntry();
}

void FeedbackController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("feedback");
    auto feedback = Feedback::create(form);
    if (!feedback.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", feedback.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void FeedbackController::renderEntry(const QVariantMap &feedback)
{
    texport(feedback);
    render("entry");
}

void FeedbackController::edit(const QString &pk)
{
    auto feedback = Feedback::get(pk.toInt());
    if (!feedback.isNull()) {
        renderEdit(feedback.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void FeedbackController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    auto feedback = Feedback::get(pk.toInt());
    if (feedback.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("feedback");
    feedback.setProperties(form);
    if (feedback.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void FeedbackController::renderEdit(const QVariantMap &feedback)
{
    texport(feedback);
    render("edit");
}

void FeedbackController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto feedback = Feedback::get(pk.toInt());
    feedback.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(feedbackcontroller)
