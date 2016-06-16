#include "useraccoutcontroller.h"
#include "useraccout.h"


UserAccoutController::UserAccoutController(const UserAccoutController &)
    : ApplicationController()
{ }

void UserAccoutController::index()
{
    QList<UserAccout> userAccoutList = UserAccout::getAll();
    texport(userAccoutList);
    render();
}

void UserAccoutController::show(const QString &pk)
{
    auto userAccout = UserAccout::get(pk.toInt());
    texport(userAccout);
    render();
}

void UserAccoutController::entry()
{
    renderEntry();
}

void UserAccoutController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("userAccout");
    auto userAccout = UserAccout::create(form);
    if (!userAccout.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", userAccout.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void UserAccoutController::renderEntry(const QVariantMap &userAccout)
{
    texport(userAccout);
    render("entry");
}

void UserAccoutController::edit(const QString &pk)
{
    auto userAccout = UserAccout::get(pk.toInt());
    if (!userAccout.isNull()) {
        session().insert("userAccout_lockRevision", userAccout.lockRevision());
        renderEdit(userAccout.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void UserAccoutController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("userAccout_lockRevision").toInt();
    auto userAccout = UserAccout::get(pk.toInt(), rev);
    if (userAccout.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("userAccout");
    userAccout.setProperties(form);
    if (userAccout.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void UserAccoutController::renderEdit(const QVariantMap &userAccout)
{
    texport(userAccout);
    render("edit");
}

void UserAccoutController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto userAccout = UserAccout::get(pk.toInt());
    userAccout.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(useraccoutcontroller)
