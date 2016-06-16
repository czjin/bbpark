#ifndef OPERATORPARKINGCONTROLLER_H
#define OPERATORPARKINGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OperatorParkingController : public ApplicationController
{
    Q_OBJECT
public:
    OperatorParkingController() { }
    OperatorParkingController(const OperatorParkingController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &operatorParking = QVariantMap());
    void renderEdit(const QVariantMap &operatorParking = QVariantMap());
};

T_DECLARE_CONTROLLER(OperatorParkingController, operatorparkingcontroller)

#endif // OPERATORPARKINGCONTROLLER_H
