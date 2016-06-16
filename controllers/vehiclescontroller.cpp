#include "vehiclescontroller.h"
#include "vehicles.h"


VehiclesController::VehiclesController(const VehiclesController &)
    : ApplicationController()
{ }

void VehiclesController::index()
{
    QList<Vehicles> vehiclesList = Vehicles::getAll();
    texport(vehiclesList);
    render();
}

void VehiclesController::show(const QString &pk)
{
    auto vehicles = Vehicles::get(pk.toInt());
    texport(vehicles);
    render();
}

void VehiclesController::entry()
{
    renderEntry();
}

void VehiclesController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("vehicles");
    auto vehicles = Vehicles::create(form);
    if (!vehicles.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", vehicles.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void VehiclesController::renderEntry(const QVariantMap &vehicles)
{
    texport(vehicles);
    render("entry");
}

void VehiclesController::edit(const QString &pk)
{
    auto vehicles = Vehicles::get(pk.toInt());
    if (!vehicles.isNull()) {
        session().insert("vehicles_lockRevision", vehicles.lockRevision());
        renderEdit(vehicles.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void VehiclesController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("vehicles_lockRevision").toInt();
    auto vehicles = Vehicles::get(pk.toInt(), rev);
    if (vehicles.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("vehicles");
    vehicles.setProperties(form);
    if (vehicles.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void VehiclesController::renderEdit(const QVariantMap &vehicles)
{
    texport(vehicles);
    render("edit");
}

void VehiclesController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto vehicles = Vehicles::get(pk.toInt());
    vehicles.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(vehiclescontroller)
