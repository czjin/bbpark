#ifndef ACCOUNTSCONTROLLER_H
#define ACCOUNTSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AccountsController : public ApplicationController
{
    Q_OBJECT
public:
    AccountsController() { }
    AccountsController(const AccountsController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &accounts = QVariantMap());
    void renderEdit(const QVariantMap &accounts = QVariantMap());
};

T_DECLARE_CONTROLLER(AccountsController, accountscontroller)

#endif // ACCOUNTSCONTROLLER_H
