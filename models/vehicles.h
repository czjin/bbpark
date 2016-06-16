#ifndef VEHICLES_H
#define VEHICLES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VehiclesObject;
class QJsonArray;


class T_MODEL_EXPORT Vehicles : public TAbstractModel
{
public:
    Vehicles();
    Vehicles(const Vehicles &other);
    Vehicles(const VehiclesObject &object);
    ~Vehicles();

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
    Vehicles &operator=(const Vehicles &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Vehicles create(const QString &plate, const QString &engineNo, const QString &frameNo, const QDateTime &registerTime, int vehicleType);
    static Vehicles create(const QVariantMap &values);
    static Vehicles get(int id);
    static Vehicles get(int id, int lockRevision);
    static int count();
    static QList<Vehicles> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<VehiclesObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Vehicles)
Q_DECLARE_METATYPE(QList<Vehicles>)

#endif // VEHICLES_H
