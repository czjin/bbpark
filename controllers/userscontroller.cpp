#include "userscontroller.h"
#include "users.h"


UsersController::UsersController(const UsersController &)
    : ApplicationController()
{ }

void UsersController::index()
{
    QList<Users> usersList = Users::getAll();
    texport(usersList);
    render();
}

void UsersController::show(const QString &pk)
{
    auto users = Users::get(pk.toInt());
    texport(users);
    render();
}

void UsersController::entry()
{
    renderEntry();
}

void UsersController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("users");
    auto users = Users::create(form);
    if (!users.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", users.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void UsersController::renderEntry(const QVariantMap &users)
{
    texport(users);
    render("entry");
}

void UsersController::edit(const QString &pk)
{
    auto users = Users::get(pk.toInt());
    if (!users.isNull()) {
        session().insert("users_lockRevision", users.lockRevision());
        renderEdit(users.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void UsersController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("users_lockRevision").toInt();
    auto users = Users::get(pk.toInt(), rev);
    if (users.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("users");
    users.setProperties(form);
    if (users.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void UsersController::renderEdit(const QVariantMap &users)
{
    texport(users);
    render("edit");
}

void UsersController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto users = Users::get(pk.toInt());
    users.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(userscontroller)
