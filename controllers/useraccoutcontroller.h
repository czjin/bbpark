#ifndef USERACCOUTCONTROLLER_H
#define USERACCOUTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT UserAccoutController : public ApplicationController
{
    Q_OBJECT
public:
    UserAccoutController() { }
    UserAccoutController(const UserAccoutController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &userAccout = QVariantMap());
    void renderEdit(const QVariantMap &userAccout = QVariantMap());
};

T_DECLARE_CONTROLLER(UserAccoutController, useraccoutcontroller)

#endif // USERACCOUTCONTROLLER_H
