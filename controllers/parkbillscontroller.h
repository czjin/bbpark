#ifndef PARKBILLSCONTROLLER_H
#define PARKBILLSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ParkBillsController : public ApplicationController
{
    Q_OBJECT
public:
    ParkBillsController() { }
    ParkBillsController(const ParkBillsController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &parkBills = QVariantMap());
    void renderEdit(const QVariantMap &parkBills = QVariantMap());
};

T_DECLARE_CONTROLLER(ParkBillsController, parkbillscontroller)

#endif // PARKBILLSCONTROLLER_H
