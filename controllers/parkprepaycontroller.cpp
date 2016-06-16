#include "parkprepaycontroller.h"
#include "parkprepay.h"


ParkPrepayController::ParkPrepayController(const ParkPrepayController &)
    : ApplicationController()
{ }

void ParkPrepayController::index()
{
    QList<ParkPrepay> parkPrepayList = ParkPrepay::getAll();
    texport(parkPrepayList);
    render();
}

void ParkPrepayController::show(const QString &pk)
{
    auto parkPrepay = ParkPrepay::get(pk.toInt());
    texport(parkPrepay);
    render();
}

void ParkPrepayController::entry()
{
    renderEntry();
}

void ParkPrepayController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("parkPrepay");
    auto parkPrepay = ParkPrepay::create(form);
    if (!parkPrepay.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", parkPrepay.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void ParkPrepayController::renderEntry(const QVariantMap &parkPrepay)
{
    texport(parkPrepay);
    render("entry");
}

void ParkPrepayController::edit(const QString &pk)
{
    auto parkPrepay = ParkPrepay::get(pk.toInt());
    if (!parkPrepay.isNull()) {
        renderEdit(parkPrepay.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void ParkPrepayController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    auto parkPrepay = ParkPrepay::get(pk.toInt());
    if (parkPrepay.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("parkPrepay");
    parkPrepay.setProperties(form);
    if (parkPrepay.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void ParkPrepayController::renderEdit(const QVariantMap &parkPrepay)
{
    texport(parkPrepay);
    render("edit");
}

void ParkPrepayController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto parkPrepay = ParkPrepay::get(pk.toInt());
    parkPrepay.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(parkprepaycontroller)
