#ifndef VERSIONCONTROLLER_H
#define VERSIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT VersionController : public ApplicationController
{
    Q_OBJECT
public:
    VersionController() { }
    VersionController(const VersionController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &version = QVariantMap());
    void renderEdit(const QVariantMap &version = QVariantMap());
};

T_DECLARE_CONTROLLER(VersionController, versioncontroller)

#endif // VERSIONCONTROLLER_H
