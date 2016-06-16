#ifndef PARKINGSCONTROLLER_H
#define PARKINGSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ParkingsController : public ApplicationController
{
    Q_OBJECT
public:
    ParkingsController() { }
    ParkingsController(const ParkingsController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &parkings = QVariantMap());
    void renderEdit(const QVariantMap &parkings = QVariantMap());
};

T_DECLARE_CONTROLLER(ParkingsController, parkingscontroller)

#endif // PARKINGSCONTROLLER_H
