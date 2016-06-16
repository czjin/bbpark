#ifndef PARKSCONTROLLER_H
#define PARKSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ParksController : public ApplicationController
{
    Q_OBJECT
public:
    ParksController() { }
    ParksController(const ParksController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &parks = QVariantMap());
    void renderEdit(const QVariantMap &parks = QVariantMap());
};

T_DECLARE_CONTROLLER(ParksController, parkscontroller)

#endif // PARKSCONTROLLER_H
