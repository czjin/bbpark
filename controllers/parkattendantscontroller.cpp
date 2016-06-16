#include "parkattendantscontroller.h"
#include "parkattendants.h"


ParkAttendantsController::ParkAttendantsController(const ParkAttendantsController &)
    : ApplicationController()
{ }

void ParkAttendantsController::index()
{
    QList<ParkAttendants> parkAttendantsList = ParkAttendants::getAll();
    texport(parkAttendantsList);
    render();
}

void ParkAttendantsController::show(const QString &pk)
{
    auto parkAttendants = ParkAttendants::get(pk.toInt());
    texport(parkAttendants);
    render();
}

void ParkAttendantsController::entry()
{
    renderEntry();
}

void ParkAttendantsController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("parkAttendants");
    auto parkAttendants = ParkAttendants::create(form);
    if (!parkAttendants.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", parkAttendants.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void ParkAttendantsController::renderEntry(const QVariantMap &parkAttendants)
{
    texport(parkAttendants);
    render("entry");
}

void ParkAttendantsController::edit(const QString &pk)
{
    auto parkAttendants = ParkAttendants::get(pk.toInt());
    if (!parkAttendants.isNull()) {
        session().insert("parkAttendants_lockRevision", parkAttendants.lockRevision());
        renderEdit(parkAttendants.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void ParkAttendantsController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("parkAttendants_lockRevision").toInt();
    auto parkAttendants = ParkAttendants::get(pk.toInt(), rev);
    if (parkAttendants.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("parkAttendants");
    parkAttendants.setProperties(form);
    if (parkAttendants.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void ParkAttendantsController::renderEdit(const QVariantMap &parkAttendants)
{
    texport(parkAttendants);
    render("edit");
}

void ParkAttendantsController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto parkAttendants = ParkAttendants::get(pk.toInt());
    parkAttendants.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(parkattendantscontroller)
