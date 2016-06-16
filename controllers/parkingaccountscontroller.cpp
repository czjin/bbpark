#include "parkingaccountscontroller.h"
#include "parkingaccounts.h"


ParkingAccountsController::ParkingAccountsController(const ParkingAccountsController &)
    : ApplicationController()
{ }

void ParkingAccountsController::index()
{
    QList<ParkingAccounts> parkingAccountsList = ParkingAccounts::getAll();
    texport(parkingAccountsList);
    render();
}

void ParkingAccountsController::show(const QString &pk)
{
    auto parkingAccounts = ParkingAccounts::get(pk.toInt());
    texport(parkingAccounts);
    render();
}

void ParkingAccountsController::entry()
{
    renderEntry();
}

void ParkingAccountsController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("parkingAccounts");
    auto parkingAccounts = ParkingAccounts::create(form);
    if (!parkingAccounts.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", parkingAccounts.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void ParkingAccountsController::renderEntry(const QVariantMap &parkingAccounts)
{
    texport(parkingAccounts);
    render("entry");
}

void ParkingAccountsController::edit(const QString &pk)
{
    auto parkingAccounts = ParkingAccounts::get(pk.toInt());
    if (!parkingAccounts.isNull()) {
        renderEdit(parkingAccounts.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void ParkingAccountsController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    auto parkingAccounts = ParkingAccounts::get(pk.toInt());
    if (parkingAccounts.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("parkingAccounts");
    parkingAccounts.setProperties(form);
    if (parkingAccounts.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void ParkingAccountsController::renderEdit(const QVariantMap &parkingAccounts)
{
    texport(parkingAccounts);
    render("edit");
}

void ParkingAccountsController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto parkingAccounts = ParkingAccounts::get(pk.toInt());
    parkingAccounts.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(parkingaccountscontroller)
