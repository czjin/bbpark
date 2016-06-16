#ifndef VEHICLE_H
#define VEHICLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VehicleObject;
class QJsonArray;


class T_MODEL_EXPORT Vehicle : public TAbstractModel
{
public:
    Vehicle();
    Vehicle(const Vehicle &other);
    Vehicle(const VehicleObject &object);
    ~Vehicle();

    int id() const;
    QString plate() const;
    void setPlate(const QString &plate);
    QString engineNo() const;
    void setEngineNo(const QString &engineNo);
    QString frameNo() const;
    void setFrameNo(const QString &frameNo);
    QDateTime registerTime() const;
    void setRegisterTime(const QDateTime &registerTime);
    int vehicleType() const;
    void setVehicleType(int vehicleType);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int lockRevision() const;
    Vehicle &operator=(const Vehicle &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Vehicle create(const QString &plate, const QString &engineNo, const QString &frameNo, const QDateTime &registerTime, int vehicleType);
    static Vehicle create(const QVariantMap &values);
    static Vehicle get(int id);
    static Vehicle get(int id, int lockRevision);
    static int count();
    static QList<Vehicle> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<VehicleObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Vehicle)
Q_DECLARE_METATYPE(QList<Vehicle>)

#endif // VEHICLE_H
