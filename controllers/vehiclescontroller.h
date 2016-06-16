#ifndef VEHICLESCONTROLLER_H
#define VEHICLESCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT VehiclesController : public ApplicationController
{
    Q_OBJECT
public:
    VehiclesController() { }
    VehiclesController(const VehiclesController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &vehicles = QVariantMap());
    void renderEdit(const QVariantMap &vehicles = QVariantMap());
};

T_DECLARE_CONTROLLER(VehiclesController, vehiclescontroller)

#endif // VEHICLESCONTROLLER_H
