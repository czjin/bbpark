#include "operatorparkingcontroller.h"
#include "operatorparking.h"


OperatorParkingController::OperatorParkingController(const OperatorParkingController &)
    : ApplicationController()
{ }

void OperatorParkingController::index()
{
    QList<OperatorParking> operatorParkingList = OperatorParking::getAll();
    texport(operatorParkingList);
    render();
}

void OperatorParkingController::show(const QString &pk)
{
    auto operatorParking = OperatorParking::get(pk.toInt());
    texport(operatorParking);
    render();
}

void OperatorParkingController::entry()
{
    renderEntry();
}

void OperatorParkingController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("operatorParking");
    auto operatorParking = OperatorParking::create(form);
    if (!operatorParking.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", operatorParking.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void OperatorParkingController::renderEntry(const QVariantMap &operatorParking)
{
    texport(operatorParking);
    render("entry");
}

void OperatorParkingController::edit(const QString &pk)
{
    auto operatorParking = OperatorParking::get(pk.toInt());
    if (!operatorParking.isNull()) {
        renderEdit(operatorParking.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void OperatorParkingController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    auto operatorParking = OperatorParking::get(pk.toInt());
    if (operatorParking.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("operatorParking");
    operatorParking.setProperties(form);
    if (operatorParking.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void OperatorParkingController::renderEdit(const QVariantMap &operatorParking)
{
    texport(operatorParking);
    render("edit");
}

void OperatorParkingController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto operatorParking = OperatorParking::get(pk.toInt());
    operatorParking.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(operatorparkingcontroller)
