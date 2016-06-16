#ifndef PARKATTENDANTSCONTROLLER_H
#define PARKATTENDANTSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ParkAttendantsController : public ApplicationController
{
    Q_OBJECT
public:
    ParkAttendantsController() { }
    ParkAttendantsController(const ParkAttendantsController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &parkAttendants = QVariantMap());
    void renderEdit(const QVariantMap &parkAttendants = QVariantMap());
};

T_DECLARE_CONTROLLER(ParkAttendantsController, parkattendantscontroller)

#endif // PARKATTENDANTSCONTROLLER_H
