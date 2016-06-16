#include "parkingscontroller.h"
#include "parkings.h"


ParkingsController::ParkingsController(const ParkingsController &)
    : ApplicationController()
{ }

void ParkingsController::index()
{
    QList<Parkings> parkingsList = Parkings::getAll();
    texport(parkingsList);
    render();
}

void ParkingsController::show(const QString &pk)
{
    auto parkings = Parkings::get(pk.toInt());
    texport(parkings);
    render();
}

void ParkingsController::entry()
{
    renderEntry();
}

void ParkingsController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("parkings");
    auto parkings = Parkings::create(form);
    if (!parkings.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", parkings.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void ParkingsController::renderEntry(const QVariantMap &parkings)
{
    texport(parkings);
    render("entry");
}

void ParkingsController::edit(const QString &pk)
{
    auto parkings = Parkings::get(pk.toInt());
    if (!parkings.isNull()) {
        session().insert("parkings_lockRevision", parkings.lockRevision());
        renderEdit(parkings.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void ParkingsController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("parkings_lockRevision").toInt();
    auto parkings = Parkings::get(pk.toInt(), rev);
    if (parkings.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("parkings");
    parkings.setProperties(form);
    if (parkings.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void ParkingsController::renderEdit(const QVariantMap &parkings)
{
    texport(parkings);
    render("edit");
}

void ParkingsController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto parkings = Parkings::get(pk.toInt());
    parkings.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(parkingscontroller)
