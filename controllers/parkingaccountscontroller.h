#ifndef PARKINGACCOUNTSCONTROLLER_H
#define PARKINGACCOUNTSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ParkingAccountsController : public ApplicationController
{
    Q_OBJECT
public:
    ParkingAccountsController() { }
    ParkingAccountsController(const ParkingAccountsController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &parkingAccounts = QVariantMap());
    void renderEdit(const QVariantMap &parkingAccounts = QVariantMap());
};

T_DECLARE_CONTROLLER(ParkingAccountsController, parkingaccountscontroller)

#endif // PARKINGACCOUNTSCONTROLLER_H
