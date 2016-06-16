#include "attendantparkingcontroller.h"
#include "attendantparking.h"


AttendantParkingController::AttendantParkingController(const AttendantParkingController &)
    : ApplicationController()
{ }

void AttendantParkingController::index()
{
    QList<AttendantParking> attendantParkingList = AttendantParking::getAll();
    texport(attendantParkingList);
    render();
}

void AttendantParkingController::show(const QString &pk)
{
    auto attendantParking = AttendantParking::get(pk.toInt());
    texport(attendantParking);
    render();
}

void AttendantParkingController::entry()
{
    renderEntry();
}

void AttendantParkingController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("attendantParking");
    auto attendantParking = AttendantParking::create(form);
    if (!attendantParking.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", attendantParking.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void AttendantParkingController::renderEntry(const QVariantMap &attendantParking)
{
    texport(attendantParking);
    render("entry");
}

void AttendantParkingController::edit(const QString &pk)
{
    auto attendantParking = AttendantParking::get(pk.toInt());
    if (!attendantParking.isNull()) {
        renderEdit(attendantParking.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void AttendantParkingController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    auto attendantParking = AttendantParking::get(pk.toInt());
    if (attendantParking.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("attendantParking");
    attendantParking.setProperties(form);
    if (attendantParking.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void AttendantParkingController::renderEdit(const QVariantMap &attendantParking)
{
    texport(attendantParking);
    render("edit");
}

void AttendantParkingController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto attendantParking = AttendantParking::get(pk.toInt());
    attendantParking.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(attendantparkingcontroller)
