#ifndef PARKINGQRCODESCONTROLLER_H
#define PARKINGQRCODESCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ParkingQrcodesController : public ApplicationController
{
    Q_OBJECT
public:
    ParkingQrcodesController() { }
    ParkingQrcodesController(const ParkingQrcodesController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &parkingQrcodes = QVariantMap());
    void renderEdit(const QVariantMap &parkingQrcodes = QVariantMap());
};

T_DECLARE_CONTROLLER(ParkingQrcodesController, parkingqrcodescontroller)

#endif // PARKINGQRCODESCONTROLLER_H
