#ifndef ACCOUNTSRECHARGECONTROLLER_H
#define ACCOUNTSRECHARGECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AccountsRechargeController : public ApplicationController
{
    Q_OBJECT
public:
    AccountsRechargeController() { }
    AccountsRechargeController(const AccountsRechargeController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &accountsRecharge = QVariantMap());
    void renderEdit(const QVariantMap &accountsRecharge = QVariantMap());
};

T_DECLARE_CONTROLLER(AccountsRechargeController, accountsrechargecontroller)

#endif // ACCOUNTSRECHARGECONTROLLER_H
