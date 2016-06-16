#include <TreeFrogModel>
#include "vehicles.h"
#include "vehiclesobject.h"

Vehicles::Vehicles()
    : TAbstractModel(), d(new VehiclesObject)
{
    d->id = 0;
    d->vehicle_type = 0;
    d->lock_revision = 0;
}

Vehicles::Vehicles(const Vehicles &other)
    : TAbstractModel(), d(new VehiclesObject(*other.d))
{ }

Vehicles::Vehicles(const VehiclesObject &object)
    : TAbstractModel(), d(new VehiclesObject(object))
{ }

Vehicles::~Vehicles()
{
    // If the reference count becomes 0,
    // the shared data object 'VehiclesObject' is deleted.
}

int Vehicles::id() const
{
    return d->id;
}

QString Vehicles::plate() const
{
    return d->plate;
}

void Vehicles::setPlate(const QString &plate)
{
    d->plate = plate;
}

QString Vehicles::engineNo() const
{
    return d->engine_no;
}

void Vehicles::setEngineNo(const QString &engineNo)
{
    d->engine_no = engineNo;
}

QString Vehicles::frameNo() const
{
    return d->frame_no;
}

void Vehicles::setFrameNo(const QString &frameNo)
{
    d->frame_no = frameNo;
}

QDateTime Vehicles::registerTime() const
{
    return d->register_time;
}

void Vehicles::setRegisterTime(const QDateTime &registerTime)
{
    d->register_time = registerTime;
}

int Vehicles::vehicleType() const
{
    return d->vehicle_type;
}

void Vehicles::setVehicleType(int vehicleType)
{
    d->vehicle_type = vehicleType;
}

QDateTime Vehicles::createdAt() const
{
    return d->created_at;
}

QDateTime Vehicles::updatedAt() const
{
    return d->updated_at;
}

int Vehicles::lockRevision() const
{
    return d->lock_revision;
}

Vehicles &Vehicles::operator=(const Vehicles &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Vehicles Vehicles::create(const QString &plate, const QString &engineNo, const QString &frameNo, const QDateTime &registerTime, int vehicleType)
{
    VehiclesObject obj;
    obj.plate = plate;
    obj.engine_no = engineNo;
    obj.frame_no = frameNo;
    obj.register_time = registerTime;
    obj.vehicle_type = vehicleType;
    if (!obj.create()) {
        return Vehicles();
    }
    return Vehicles(obj);
}

Vehicles Vehicles::create(const QVariantMap &values)
{
    Vehicles model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Vehicles Vehicles::get(int id)
{
    TSqlORMapper<VehiclesObject> mapper;
    return Vehicles(mapper.findByPrimaryKey(id));
}

Vehicles Vehicles::get(int id, int lockRevision)
{
    TSqlORMapper<VehiclesObject> mapper;
    TCriteria cri;
    cri.add(VehiclesObject::Id, id);
    cri.add(VehiclesObject::LockRevision, lockRevision);
    return Vehicles(mapper.findFirst(cri));
}

int Vehicles::count()
{
    TSqlORMapper<VehiclesObject> mapper;
    return mapper.findCount();
}

QList<Vehicles> Vehicles::getAll()
{
    return tfGetModelListByCriteria<Vehicles, VehiclesObject>(TCriteria());
}

QJsonArray Vehicles::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<VehiclesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<VehiclesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Vehicles(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Vehicles::modelData()
{
    return d.data();
}

const TModelObject *Vehicles::modelData() const
{
    return d.data();
}
