#ifndef OPERATORPARKING_H
#define OPERATORPARKING_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class OperatorParkingObject;
class QJsonArray;


class T_MODEL_EXPORT OperatorParking : public TAbstractModel
{
public:
    OperatorParking();
    OperatorParking(const OperatorParking &other);
    OperatorParking(const OperatorParkingObject &object);
    ~OperatorParking();

    int id() const;
    int operatorId() const;
    void setOperatorId(int operatorId);
    int parkingId() const;
    void setParkingId(int parkingId);
    int status() const;
    void setStatus(int status);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    OperatorParking &operator=(const OperatorParking &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static OperatorParking create(int operatorId, int parkingId, int status);
    static OperatorParking create(const QVariantMap &values);
    static OperatorParking get(int id);
    static int count();
    static QList<OperatorParking> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<OperatorParkingObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(OperatorParking)
Q_DECLARE_METATYPE(QList<OperatorParking>)

#endif // OPERATORPARKING_H
