#include "accountscontroller.h"
#include "accounts.h"


AccountsController::AccountsController(const AccountsController &)
    : ApplicationController()
{ }

void AccountsController::index()
{
    QList<Accounts> accountsList = Accounts::getAll();
    texport(accountsList);
    render();
}

void AccountsController::show(const QString &pk)
{
    auto accounts = Accounts::get(pk.toInt());
    texport(accounts);
    render();
}

void AccountsController::entry()
{
    renderEntry();
}

void AccountsController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("accounts");
    auto accounts = Accounts::create(form);
    if (!accounts.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", accounts.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void AccountsController::renderEntry(const QVariantMap &accounts)
{
    texport(accounts);
    render("entry");
}

void AccountsController::edit(const QString &pk)
{
    auto accounts = Accounts::get(pk.toInt());
    if (!accounts.isNull()) {
        renderEdit(accounts.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void AccountsController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    auto accounts = Accounts::get(pk.toInt());
    if (accounts.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("accounts");
    accounts.setProperties(form);
    if (accounts.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void AccountsController::renderEdit(const QVariantMap &accounts)
{
    texport(accounts);
    render("edit");
}

void AccountsController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto accounts = Accounts::get(pk.toInt());
    accounts.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(accountscontroller)
