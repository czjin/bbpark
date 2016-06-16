#ifndef VEHICLECONTROLLER_H
#define VEHICLECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT VehicleController : public ApplicationController
{
    Q_OBJECT
public:
    VehicleController() { }
    VehicleController(const VehicleController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &vehicle = QVariantMap());
    void renderEdit(const QVariantMap &vehicle = QVariantMap());
};

T_DECLARE_CONTROLLER(VehicleController, vehiclecontroller)

#endif // VEHICLECONTROLLER_H
