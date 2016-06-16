#include <TreeFrogModel>
#include "operatorparking.h"
#include "operatorparkingobject.h"

OperatorParking::OperatorParking()
    : TAbstractModel(), d(new OperatorParkingObject)
{
    d->id = 0;
    d->operator_id = 0;
    d->parking_id = 0;
    d->status = 0;
}

OperatorParking::OperatorParking(const OperatorParking &other)
    : TAbstractModel(), d(new OperatorParkingObject(*other.d))
{ }

OperatorParking::OperatorParking(const OperatorParkingObject &object)
    : TAbstractModel(), d(new OperatorParkingObject(object))
{ }

OperatorParking::~OperatorParking()
{
    // If the reference count becomes 0,
    // the shared data object 'OperatorParkingObject' is deleted.
}

int OperatorParking::id() const
{
    return d->id;
}

int OperatorParking::operatorId() const
{
    return d->operator_id;
}

void OperatorParking::setOperatorId(int operatorId)
{
    d->operator_id = operatorId;
}

int OperatorParking::parkingId() const
{
    return d->parking_id;
}

void OperatorParking::setParkingId(int parkingId)
{
    d->parking_id = parkingId;
}

int OperatorParking::status() const
{
    return d->status;
}

void OperatorParking::setStatus(int status)
{
    d->status = status;
}

QDateTime OperatorParking::createdAt() const
{
    return d->created_at;
}

QDateTime OperatorParking::updatedAt() const
{
    return d->updated_at;
}

OperatorParking &OperatorParking::operator=(const OperatorParking &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

OperatorParking OperatorParking::create(int operatorId, int parkingId, int status)
{
    OperatorParkingObject obj;
    obj.operator_id = operatorId;
    obj.parking_id = parkingId;
    obj.status = status;
    if (!obj.create()) {
        return OperatorParking();
    }
    return OperatorParking(obj);
}

OperatorParking OperatorParking::create(const QVariantMap &values)
{
    OperatorParking model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

OperatorParking OperatorParking::get(int id)
{
    TSqlORMapper<OperatorParkingObject> mapper;
    return OperatorParking(mapper.findByPrimaryKey(id));
}

int OperatorParking::count()
{
    TSqlORMapper<OperatorParkingObject> mapper;
    return mapper.findCount();
}

QList<OperatorParking> OperatorParking::getAll()
{
    return tfGetModelListByCriteria<OperatorParking, OperatorParkingObject>(TCriteria());
}

QJsonArray OperatorParking::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<OperatorParkingObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<OperatorParkingObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(OperatorParking(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *OperatorParking::modelData()
{
    return d.data();
}

const TModelObject *OperatorParking::modelData() const
{
    return d.data();
}
