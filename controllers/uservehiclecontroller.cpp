#include "uservehiclecontroller.h"
#include "uservehicle.h"


UserVehicleController::UserVehicleController(const UserVehicleController &)
    : ApplicationController()
{ }

void UserVehicleController::index()
{
    QList<UserVehicle> userVehicleList = UserVehicle::getAll();
    texport(userVehicleList);
    render();
}

void UserVehicleController::show(const QString &pk)
{
    auto userVehicle = UserVehicle::get(pk.toInt());
    texport(userVehicle);
    render();
}

void UserVehicleController::entry()
{
    renderEntry();
}

void UserVehicleController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("userVehicle");
    auto userVehicle = UserVehicle::create(form);
    if (!userVehicle.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", userVehicle.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void UserVehicleController::renderEntry(const QVariantMap &userVehicle)
{
    texport(userVehicle);
    render("entry");
}

void UserVehicleController::edit(const QString &pk)
{
    auto userVehicle = UserVehicle::get(pk.toInt());
    if (!userVehicle.isNull()) {
        session().insert("userVehicle_lockRevision", userVehicle.lockRevision());
        renderEdit(userVehicle.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void UserVehicleController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("userVehicle_lockRevision").toInt();
    auto userVehicle = UserVehicle::get(pk.toInt(), rev);
    if (userVehicle.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("userVehicle");
    userVehicle.setProperties(form);
    if (userVehicle.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void UserVehicleController::renderEdit(const QVariantMap &userVehicle)
{
    texport(userVehicle);
    render("edit");
}

void UserVehicleController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto userVehicle = UserVehicle::get(pk.toInt());
    userVehicle.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(uservehiclecontroller)
