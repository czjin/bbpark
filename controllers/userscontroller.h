#ifndef USERSCONTROLLER_H
#define USERSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT UsersController : public ApplicationController
{
    Q_OBJECT
public:
    UsersController() { }
    UsersController(const UsersController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &users = QVariantMap());
    void renderEdit(const QVariantMap &users = QVariantMap());
};

T_DECLARE_CONTROLLER(UsersController, userscontroller)

#endif // USERSCONTROLLER_H
