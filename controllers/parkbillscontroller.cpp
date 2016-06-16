#include "parkbillscontroller.h"
#include "parkbills.h"


ParkBillsController::ParkBillsController(const ParkBillsController &)
    : ApplicationController()
{ }

void ParkBillsController::index()
{
    QList<ParkBills> parkBillsList = ParkBills::getAll();
    texport(parkBillsList);
    render();
}

void ParkBillsController::show(const QString &pk)
{
    auto parkBills = ParkBills::get(pk.toInt());
    texport(parkBills);
    render();
}

void ParkBillsController::entry()
{
    renderEntry();
}

void ParkBillsController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("parkBills");
    auto parkBills = ParkBills::create(form);
    if (!parkBills.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", parkBills.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void ParkBillsController::renderEntry(const QVariantMap &parkBills)
{
    texport(parkBills);
    render("entry");
}

void ParkBillsController::edit(const QString &pk)
{
    auto parkBills = ParkBills::get(pk.toInt());
    if (!parkBills.isNull()) {
        renderEdit(parkBills.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void ParkBillsController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    auto parkBills = ParkBills::get(pk.toInt());
    if (parkBills.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("parkBills");
    parkBills.setProperties(form);
    if (parkBills.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void ParkBillsController::renderEdit(const QVariantMap &parkBills)
{
    texport(parkBills);
    render("edit");
}

void ParkBillsController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto parkBills = ParkBills::get(pk.toInt());
    parkBills.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(parkbillscontroller)
