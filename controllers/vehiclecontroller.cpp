#include "vehiclecontroller.h"
#include "vehicle.h"


VehicleController::VehicleController(const VehicleController &)
    : ApplicationController()
{ }

void VehicleController::index()
{
    QList<Vehicle> vehicleList = Vehicle::getAll();
    texport(vehicleList);
    render();
}

void VehicleController::show(const QString &pk)
{
    auto vehicle = Vehicle::get(pk.toInt());
    texport(vehicle);
    render();
}

void VehicleController::entry()
{
    renderEntry();
}

void VehicleController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("vehicle");
    auto vehicle = Vehicle::create(form);
    if (!vehicle.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", vehicle.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void VehicleController::renderEntry(const QVariantMap &vehicle)
{
    texport(vehicle);
    render("entry");
}

void VehicleController::edit(const QString &pk)
{
    auto vehicle = Vehicle::get(pk.toInt());
    if (!vehicle.isNull()) {
        session().insert("vehicle_lockRevision", vehicle.lockRevision());
        renderEdit(vehicle.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void VehicleController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("vehicle_lockRevision").toInt();
    auto vehicle = Vehicle::get(pk.toInt(), rev);
    if (vehicle.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("vehicle");
    vehicle.setProperties(form);
    if (vehicle.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void VehicleController::renderEdit(const QVariantMap &vehicle)
{
    texport(vehicle);
    render("edit");
}

void VehicleController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto vehicle = Vehicle::get(pk.toInt());
    vehicle.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(vehiclecontroller)
