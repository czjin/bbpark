#ifndef PARKPREPAYCONTROLLER_H
#define PARKPREPAYCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ParkPrepayController : public ApplicationController
{
    Q_OBJECT
public:
    ParkPrepayController() { }
    ParkPrepayController(const ParkPrepayController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &parkPrepay = QVariantMap());
    void renderEdit(const QVariantMap &parkPrepay = QVariantMap());
};

T_DECLARE_CONTROLLER(ParkPrepayController, parkprepaycontroller)

#endif // PARKPREPAYCONTROLLER_H
