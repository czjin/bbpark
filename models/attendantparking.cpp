#include <TreeFrogModel>
#include "attendantparking.h"
#include "attendantparkingobject.h"

AttendantParking::AttendantParking()
    : TAbstractModel(), d(new AttendantParkingObject)
{
    d->id = 0;
    d->attendant_id = 0;
    d->parking_id = 0;
    d->status = 0;
}

AttendantParking::AttendantParking(const AttendantParking &other)
    : TAbstractModel(), d(new AttendantParkingObject(*other.d))
{ }

AttendantParking::AttendantParking(const AttendantParkingObject &object)
    : TAbstractModel(), d(new AttendantParkingObject(object))
{ }

AttendantParking::~AttendantParking()
{
    // If the reference count becomes 0,
    // the shared data object 'AttendantParkingObject' is deleted.
}

int AttendantParking::id() const
{
    return d->id;
}

int AttendantParking::attendantId() const
{
    return d->attendant_id;
}

void AttendantParking::setAttendantId(int attendantId)
{
    d->attendant_id = attendantId;
}

int AttendantParking::parkingId() const
{
    return d->parking_id;
}

void AttendantParking::setParkingId(int parkingId)
{
    d->parking_id = parkingId;
}

int AttendantParking::status() const
{
    return d->status;
}

void AttendantParking::setStatus(int status)
{
    d->status = status;
}

QDateTime AttendantParking::createdAt() const
{
    return d->created_at;
}

QDateTime AttendantParking::updatedAt() const
{
    return d->updated_at;
}

AttendantParking &AttendantParking::operator=(const AttendantParking &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AttendantParking AttendantParking::create(int attendantId, int parkingId, int status)
{
    AttendantParkingObject obj;
    obj.attendant_id = attendantId;
    obj.parking_id = parkingId;
    obj.status = status;
    if (!obj.create()) {
        return AttendantParking();
    }
    return AttendantParking(obj);
}

AttendantParking AttendantParking::create(const QVariantMap &values)
{
    AttendantParking model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AttendantParking AttendantParking::get(int id)
{
    TSqlORMapper<AttendantParkingObject> mapper;
    return AttendantParking(mapper.findByPrimaryKey(id));
}

int AttendantParking::count()
{
    TSqlORMapper<AttendantParkingObject> mapper;
    return mapper.findCount();
}

QList<AttendantParking> AttendantParking::getAll()
{
    return tfGetModelListByCriteria<AttendantParking, AttendantParkingObject>(TCriteria());
}

QJsonArray AttendantParking::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<AttendantParkingObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<AttendantParkingObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(AttendantParking(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *AttendantParking::modelData()
{
    return d.data();
}

const TModelObject *AttendantParking::modelData() const
{
    return d.data();
}
