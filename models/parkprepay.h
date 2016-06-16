#ifndef PARKPREPAY_H
#define PARKPREPAY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ParkPrepayObject;
class QJsonArray;


class T_MODEL_EXPORT ParkPrepay : public TAbstractModel
{
public:
    ParkPrepay();
    ParkPrepay(const ParkPrepay &other);
    ParkPrepay(const ParkPrepayObject &object);
    ~ParkPrepay();

    int id() const;
    int userId() const;
    void setUserId(int userId);
    QString sessionId() const;
    void setSessionId(const QString &sessionId);
    double prepaid() const;
    void setPrepaid(double prepaid);
    QDateTime createdAt() const;
    ParkPrepay &operator=(const ParkPrepay &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static ParkPrepay create(int userId, const QString &sessionId, double prepaid);
    static ParkPrepay create(const QVariantMap &values);
    static ParkPrepay get(int id);
    static int count();
    static QList<ParkPrepay> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ParkPrepayObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(ParkPrepay)
Q_DECLARE_METATYPE(QList<ParkPrepay>)

#endif // PARKPREPAY_H
