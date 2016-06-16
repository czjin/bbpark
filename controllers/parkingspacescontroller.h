#ifndef PARKINGSPACESCONTROLLER_H
#define PARKINGSPACESCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ParkingSpacesController : public ApplicationController
{
    Q_OBJECT
public:
    ParkingSpacesController() { }
    ParkingSpacesController(const ParkingSpacesController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &parkingSpaces = QVariantMap());
    void renderEdit(const QVariantMap &parkingSpaces = QVariantMap());
};

T_DECLARE_CONTROLLER(ParkingSpacesController, parkingspacescontroller)

#endif // PARKINGSPACESCONTROLLER_H
