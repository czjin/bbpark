#include <TreeFrogModel>
#include "parkingspaces.h"
#include "parkingspacesobject.h"

ParkingSpaces::ParkingSpaces()
    : TAbstractModel(), d(new ParkingSpacesObject)
{
    d->id = 0;
    d->parking_id = 0;
    d->status = 0;
    d->lock_revision = 0;
}

ParkingSpaces::ParkingSpaces(const ParkingSpaces &other)
    : TAbstractModel(), d(new ParkingSpacesObject(*other.d))
{ }

ParkingSpaces::ParkingSpaces(const ParkingSpacesObject &object)
    : TAbstractModel(), d(new ParkingSpacesObject(object))
{ }

ParkingSpaces::~ParkingSpaces()
{
    // If the reference count becomes 0,
    // the shared data object 'ParkingSpacesObject' is deleted.
}

int ParkingSpaces::id() const
{
    return d->id;
}

int ParkingSpaces::parkingId() const
{
    return d->parking_id;
}

void ParkingSpaces::setParkingId(int parkingId)
{
    d->parking_id = parkingId;
}

QString ParkingSpaces::number() const
{
    return d->number;
}

void ParkingSpaces::setNumber(const QString &number)
{
    d->number = number;
}

int ParkingSpaces::status() const
{
    return d->status;
}

void ParkingSpaces::setStatus(int status)
{
    d->status = status;
}

QString ParkingSpaces::qrcodePath() const
{
    return d->qrcode_path;
}

void ParkingSpaces::setQrcodePath(const QString &qrcodePath)
{
    d->qrcode_path = qrcodePath;
}

QDateTime ParkingSpaces::createdAt() const
{
    return d->created_at;
}

QDateTime ParkingSpaces::updatedAt() const
{
    return d->updated_at;
}

int ParkingSpaces::lockRevision() const
{
    return d->lock_revision;
}

ParkingSpaces &ParkingSpaces::operator=(const ParkingSpaces &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ParkingSpaces ParkingSpaces::create(int parkingId, const QString &number, int status, const QString &qrcodePath)
{
    ParkingSpacesObject obj;
    obj.parking_id = parkingId;
    obj.number = number;
    obj.status = status;
    obj.qrcode_path = qrcodePath;
    if (!obj.create()) {
        return ParkingSpaces();
    }
    return ParkingSpaces(obj);
}

ParkingSpaces ParkingSpaces::create(const QVariantMap &values)
{
    ParkingSpaces model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ParkingSpaces ParkingSpaces::get(int id)
{
    TSqlORMapper<ParkingSpacesObject> mapper;
    return ParkingSpaces(mapper.findByPrimaryKey(id));
}

ParkingSpaces ParkingSpaces::get(int id, int lockRevision)
{
    TSqlORMapper<ParkingSpacesObject> mapper;
    TCriteria cri;
    cri.add(ParkingSpacesObject::Id, id);
    cri.add(ParkingSpacesObject::LockRevision, lockRevision);
    return ParkingSpaces(mapper.findFirst(cri));
}

int ParkingSpaces::count()
{
    TSqlORMapper<ParkingSpacesObject> mapper;
    return mapper.findCount();
}

QList<ParkingSpaces> ParkingSpaces::getAll()
{
    return tfGetModelListByCriteria<ParkingSpaces, ParkingSpacesObject>(TCriteria());
}

QJsonArray ParkingSpaces::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ParkingSpacesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ParkingSpacesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(ParkingSpaces(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *ParkingSpaces::modelData()
{
    return d.data();
}

const TModelObject *ParkingSpaces::modelData() const
{
    return d.data();
}
