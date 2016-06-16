#include "parkscontroller.h"
#include "parks.h"


ParksController::ParksController(const ParksController &)
    : ApplicationController()
{ }

void ParksController::index()
{
    QList<Parks> parksList = Parks::getAll();
    texport(parksList);
    render();
}

void ParksController::show(const QString &pk)
{
    auto parks = Parks::get(pk.toInt());
    texport(parks);
    render();
}

void ParksController::entry()
{
    renderEntry();
}

void ParksController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("parks");
    auto parks = Parks::create(form);
    if (!parks.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", parks.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void ParksController::renderEntry(const QVariantMap &parks)
{
    texport(parks);
    render("entry");
}

void ParksController::edit(const QString &pk)
{
    auto parks = Parks::get(pk.toInt());
    if (!parks.isNull()) {
        renderEdit(parks.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void ParksController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    auto parks = Parks::get(pk.toInt());
    if (parks.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("parks");
    parks.setProperties(form);
    if (parks.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void ParksController::renderEdit(const QVariantMap &parks)
{
    texport(parks);
    render("edit");
}

void ParksController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto parks = Parks::get(pk.toInt());
    parks.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(parkscontroller)
