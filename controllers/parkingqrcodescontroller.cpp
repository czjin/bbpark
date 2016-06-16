#include "parkingqrcodescontroller.h"
#include "parkingqrcodes.h"


ParkingQrcodesController::ParkingQrcodesController(const ParkingQrcodesController &)
    : ApplicationController()
{ }

void ParkingQrcodesController::index()
{
    QList<ParkingQrcodes> parkingQrcodesList = ParkingQrcodes::getAll();
    texport(parkingQrcodesList);
    render();
}

void ParkingQrcodesController::show(const QString &pk)
{
    auto parkingQrcodes = ParkingQrcodes::get(pk.toInt());
    texport(parkingQrcodes);
    render();
}

void ParkingQrcodesController::entry()
{
    renderEntry();
}

void ParkingQrcodesController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("parkingQrcodes");
    auto parkingQrcodes = ParkingQrcodes::create(form);
    if (!parkingQrcodes.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", parkingQrcodes.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void ParkingQrcodesController::renderEntry(const QVariantMap &parkingQrcodes)
{
    texport(parkingQrcodes);
    render("entry");
}

void ParkingQrcodesController::edit(const QString &pk)
{
    auto parkingQrcodes = ParkingQrcodes::get(pk.toInt());
    if (!parkingQrcodes.isNull()) {
        session().insert("parkingQrcodes_lockRevision", parkingQrcodes.lockRevision());
        renderEdit(parkingQrcodes.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void ParkingQrcodesController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("parkingQrcodes_lockRevision").toInt();
    auto parkingQrcodes = ParkingQrcodes::get(pk.toInt(), rev);
    if (parkingQrcodes.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("parkingQrcodes");
    parkingQrcodes.setProperties(form);
    if (parkingQrcodes.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void ParkingQrcodesController::renderEdit(const QVariantMap &parkingQrcodes)
{
    texport(parkingQrcodes);
    render("edit");
}

void ParkingQrcodesController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto parkingQrcodes = ParkingQrcodes::get(pk.toInt());
    parkingQrcodes.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(parkingqrcodescontroller)
