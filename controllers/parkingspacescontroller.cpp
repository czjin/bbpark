#include "parkingspacescontroller.h"
#include "parkingspaces.h"


ParkingSpacesController::ParkingSpacesController(const ParkingSpacesController &)
    : ApplicationController()
{ }

void ParkingSpacesController::index()
{
    QList<ParkingSpaces> parkingSpacesList = ParkingSpaces::getAll();
    texport(parkingSpacesList);
    render();
}

void ParkingSpacesController::show(const QString &pk)
{
    auto parkingSpaces = ParkingSpaces::get(pk.toInt());
    texport(parkingSpaces);
    render();
}

void ParkingSpacesController::entry()
{
    renderEntry();
}

void ParkingSpacesController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("parkingSpaces");
    auto parkingSpaces = ParkingSpaces::create(form);
    if (!parkingSpaces.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", parkingSpaces.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void ParkingSpacesController::renderEntry(const QVariantMap &parkingSpaces)
{
    texport(parkingSpaces);
    render("entry");
}

void ParkingSpacesController::edit(const QString &pk)
{
    auto parkingSpaces = ParkingSpaces::get(pk.toInt());
    if (!parkingSpaces.isNull()) {
        session().insert("parkingSpaces_lockRevision", parkingSpaces.lockRevision());
        renderEdit(parkingSpaces.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void ParkingSpacesController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("parkingSpaces_lockRevision").toInt();
    auto parkingSpaces = ParkingSpaces::get(pk.toInt(), rev);
    if (parkingSpaces.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("parkingSpaces");
    parkingSpaces.setProperties(form);
    if (parkingSpaces.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void ParkingSpacesController::renderEdit(const QVariantMap &parkingSpaces)
{
    texport(parkingSpaces);
    render("edit");
}

void ParkingSpacesController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto parkingSpaces = ParkingSpaces::get(pk.toInt());
    parkingSpaces.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(parkingspacescontroller)
