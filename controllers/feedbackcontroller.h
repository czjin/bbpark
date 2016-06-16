#ifndef FEEDBACKCONTROLLER_H
#define FEEDBACKCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT FeedbackController : public ApplicationController
{
    Q_OBJECT
public:
    FeedbackController() { }
    FeedbackController(const FeedbackController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &feedback = QVariantMap());
    void renderEdit(const QVariantMap &feedback = QVariantMap());
};

T_DECLARE_CONTROLLER(FeedbackController, feedbackcontroller)

#endif // FEEDBACKCONTROLLER_H
