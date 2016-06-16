#ifndef PARKCOUPONCONTROLLER_H
#define PARKCOUPONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ParkCouponController : public ApplicationController
{
    Q_OBJECT
public:
    ParkCouponController() { }
    ParkCouponController(const ParkCouponController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &parkCoupon = QVariantMap());
    void renderEdit(const QVariantMap &parkCoupon = QVariantMap());
};

T_DECLARE_CONTROLLER(ParkCouponController, parkcouponcontroller)

#endif // PARKCOUPONCONTROLLER_H
