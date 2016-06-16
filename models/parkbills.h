#ifndef PARKBILLS_H
#define PARKBILLS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ParkBillsObject;
class QJsonArray;


class T_MODEL_EXPORT ParkBills : public TAbstractModel
{
public:
    ParkBills();
    ParkBills(const ParkBills &other);
    ParkBills(const ParkBillsObject &object);
    ~ParkBills();

    int id() const;
    QString sessionId() const;
    void setSessionId(const QString &sessionId);
    int source() const;
    void setSource(int source);
    double amount() const;
    void setAmount(double amount);
    int status() const;
    void setStatus(int status);
    QDateTime createdAt() const;
    ParkBills &operator=(const ParkBills &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static ParkBills create(const QString &sessionId, int source, double amount, int status);
    static ParkBills create(const QVariantMap &values);
    static ParkBills get(int id);
    static int count();
    static QList<ParkBills> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ParkBillsObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(ParkBills)
Q_DECLARE_METATYPE(QList<ParkBills>)

#endif // PARKBILLS_H
