#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FeedbackObject;
class QJsonArray;


class T_MODEL_EXPORT Feedback : public TAbstractModel
{
public:
    Feedback();
    Feedback(const Feedback &other);
    Feedback(const FeedbackObject &object);
    ~Feedback();

    int id() const;
    void setId(int id);
    int userId() const;
    void setUserId(int userId);
    QString content() const;
    void setContent(const QString &content);
    QByteArray voice() const;
    void setVoice(const QByteArray &voice);
    QDateTime createdAt() const;
    Feedback &operator=(const Feedback &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Feedback create(int id, int userId, const QString &content, const QByteArray &voice);
    static Feedback create(const QVariantMap &values);
    static Feedback get(int id);
    static int count();
    static QList<Feedback> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<FeedbackObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Feedback)
Q_DECLARE_METATYPE(QList<Feedback>)

#endif // FEEDBACK_H
