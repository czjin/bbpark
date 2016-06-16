#ifndef ATTENDANTPARKINGCONTROLLER_H
#define ATTENDANTPARKINGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AttendantParkingController : public ApplicationController
{
    Q_OBJECT
public:
    AttendantParkingController() { }
    AttendantParkingController(const AttendantParkingController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &attendantParking = QVariantMap());
    void renderEdit(const QVariantMap &attendantParking = QVariantMap());
};

T_DECLARE_CONTROLLER(AttendantParkingController, attendantparkingcontroller)

#endif // ATTENDANTPARKINGCONTROLLER_H
