#include "parkcouponcontroller.h"
#include "parkcoupon.h"


ParkCouponController::ParkCouponController(const ParkCouponController &)
    : ApplicationController()
{ }

void ParkCouponController::index()
{
    QList<ParkCoupon> parkCouponList = ParkCoupon::getAll();
    texport(parkCouponList);
    render();
}

void ParkCouponController::show(const QString &pk)
{
    auto parkCoupon = ParkCoupon::get(pk.toInt());
    texport(parkCoupon);
    render();
}

void ParkCouponController::entry()
{
    renderEntry();
}

void ParkCouponController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("parkCoupon");
    auto parkCoupon = ParkCoupon::create(form);
    if (!parkCoupon.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", parkCoupon.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void ParkCouponController::renderEntry(const QVariantMap &parkCoupon)
{
    texport(parkCoupon);
    render("entry");
}

void ParkCouponController::edit(const QString &pk)
{
    auto parkCoupon = ParkCoupon::get(pk.toInt());
    if (!parkCoupon.isNull()) {
        renderEdit(parkCoupon.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void ParkCouponController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    auto parkCoupon = ParkCoupon::get(pk.toInt());
    if (parkCoupon.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("parkCoupon");
    parkCoupon.setProperties(form);
    if (parkCoupon.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void ParkCouponController::renderEdit(const QVariantMap &parkCoupon)
{
    texport(parkCoupon);
    render("edit");
}

void ParkCouponController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto parkCoupon = ParkCoupon::get(pk.toInt());
    parkCoupon.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(parkcouponcontroller)
