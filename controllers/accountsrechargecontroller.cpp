#include "accountsrechargecontroller.h"
#include "accountsrecharge.h"


AccountsRechargeController::AccountsRechargeController(const AccountsRechargeController &)
    : ApplicationController()
{ }

void AccountsRechargeController::index()
{
    QList<AccountsRecharge> accountsRechargeList = AccountsRecharge::getAll();
    texport(accountsRechargeList);
    render();
}

void AccountsRechargeController::show(const QString &pk)
{
    auto accountsRecharge = AccountsRecharge::get(pk.toInt());
    texport(accountsRecharge);
    render();
}

void AccountsRechargeController::entry()
{
    renderEntry();
}

void AccountsRechargeController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("accountsRecharge");
    auto accountsRecharge = AccountsRecharge::create(form);
    if (!accountsRecharge.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", accountsRecharge.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void AccountsRechargeController::renderEntry(const QVariantMap &accountsRecharge)
{
    texport(accountsRecharge);
    render("entry");
}

void AccountsRechargeController::edit(const QString &pk)
{
    auto accountsRecharge = AccountsRecharge::get(pk.toInt());
    if (!accountsRecharge.isNull()) {
        renderEdit(accountsRecharge.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void AccountsRechargeController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    auto accountsRecharge = AccountsRecharge::get(pk.toInt());
    if (accountsRecharge.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("accountsRecharge");
    accountsRecharge.setProperties(form);
    if (accountsRecharge.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void AccountsRechargeController::renderEdit(const QVariantMap &accountsRecharge)
{
    texport(accountsRecharge);
    render("edit");
}

void AccountsRechargeController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto accountsRecharge = AccountsRecharge::get(pk.toInt());
    accountsRecharge.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(accountsrechargecontroller)
