#ifndef USERVEHICLECONTROLLER_H
#define USERVEHICLECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT UserVehicleController : public ApplicationController
{
    Q_OBJECT
public:
    UserVehicleController() { }
    UserVehicleController(const UserVehicleController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &userVehicle = QVariantMap());
    void renderEdit(const QVariantMap &userVehicle = QVariantMap());
};

T_DECLARE_CONTROLLER(UserVehicleController, uservehiclecontroller)

#endif // USERVEHICLECONTROLLER_H
