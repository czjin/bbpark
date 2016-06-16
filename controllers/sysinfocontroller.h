#ifndef SYSINFOCONTROLLER_H
#define SYSINFOCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SysinfoController : public ApplicationController
{
    Q_OBJECT
public:
    SysinfoController() { }
    SysinfoController(const SysinfoController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &sysinfo = QVariantMap());
    void renderEdit(const QVariantMap &sysinfo = QVariantMap());
};

T_DECLARE_CONTROLLER(SysinfoController, sysinfocontroller)

#endif // SYSINFOCONTROLLER_H
