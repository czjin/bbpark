#include <TreeFrogModel>
#include "vehicle.h"
#include "vehicleobject.h"

Vehicle::Vehicle()
    : TAbstractModel(), d(new VehicleObject)
{
    d->id = 0;
    d->vehicle_type = 0;
    d->lock_revision = 0;
}

Vehicle::Vehicle(const Vehicle &other)
    : TAbstractModel(), d(new VehicleObject(*other.d))
{ }

Vehicle::Vehicle(const VehicleObject &object)
    : TAbstractModel(), d(new VehicleObject(object))
{ }

Vehicle::~Vehicle()
{
    // If the reference count becomes 0,
    // the shared data object 'VehicleObject' is deleted.
}

int Vehicle::id() const
{
    return d->id;
}

QString Vehicle::plate() const
{
    return d->plate;
}

void Vehicle::setPlate(const QString &plate)
{
    d->plate = plate;
}

QString Vehicle::engineNo() const
{
    return d->engine_no;
}

void Vehicle::setEngineNo(const QString &engineNo)
{
    d->engine_no = engineNo;
}

QString Vehicle::frameNo() const
{
    return d->frame_no;
}

void Vehicle::setFrameNo(const QString &frameNo)
{
    d->frame_no = frameNo;
}

QDateTime Vehicle::registerTime() const
{
    return d->register_time;
}

void Vehicle::setRegisterTime(const QDateTime &registerTime)
{
    d->register_time = registerTime;
}

int Vehicle::vehicleType() const
{
    return d->vehicle_type;
}

void Vehicle::setVehicleType(int vehicleType)
{
    d->vehicle_type = vehicleType;
}

QDateTime Vehicle::createdAt() const
{
    return d->created_at;
}

QDateTime Vehicle::updatedAt() const
{
    return d->updated_at;
}

int Vehicle::lockRevision() const
{
    return d->lock_revision;
}

Vehicle &Vehicle::operator=(const Vehicle &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Vehicle Vehicle::create(const QString &plate, const QString &engineNo, const QString &frameNo, const QDateTime &registerTime, int vehicleType)
{
    VehicleObject obj;
    obj.plate = plate;
    obj.engine_no = engineNo;
    obj.frame_no = frameNo;
    obj.register_time = registerTime;
    obj.vehicle_type = vehicleType;
    if (!obj.create()) {
        return Vehicle();
    }
    return Vehicle(obj);
}

Vehicle Vehicle::create(const QVariantMap &values)
{
    Vehicle model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Vehicle Vehicle::get(int id)
{
    TSqlORMapper<VehicleObject> mapper;
    return Vehicle(mapper.findByPrimaryKey(id));
}

Vehicle Vehicle::get(int id, int lockRevision)
{
    TSqlORMapper<VehicleObject> mapper;
    TCriteria cri;
    cri.add(VehicleObject::Id, id);
    cri.add(VehicleObject::LockRevision, lockRevision);
    return Vehicle(mapper.findFirst(cri));
}

int Vehicle::count()
{
    TSqlORMapper<VehicleObject> mapper;
    return mapper.findCount();
}

QList<Vehicle> Vehicle::getAll()
{
    return tfGetModelListByCriteria<Vehicle, VehicleObject>(TCriteria());
}

QJsonArray Vehicle::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<VehicleObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<VehicleObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Vehicle(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Vehicle::modelData()
{
    return d.data();
}

const TModelObject *Vehicle::modelData() const
{
    return d.data();
}
