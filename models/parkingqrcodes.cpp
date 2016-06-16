#include <TreeFrogModel>
#include "parkingqrcodes.h"
#include "parkingqrcodesobject.h"

ParkingQrcodes::ParkingQrcodes()
    : TAbstractModel(), d(new ParkingQrcodesObject)
{
    d->id = 0;
    d->lock_revision = 0;
}

ParkingQrcodes::ParkingQrcodes(const ParkingQrcodes &other)
    : TAbstractModel(), d(new ParkingQrcodesObject(*other.d))
{ }

ParkingQrcodes::ParkingQrcodes(const ParkingQrcodesObject &object)
    : TAbstractModel(), d(new ParkingQrcodesObject(object))
{ }

ParkingQrcodes::~ParkingQrcodes()
{
    // If the reference count becomes 0,
    // the shared data object 'ParkingQrcodesObject' is deleted.
}

int ParkingQrcodes::id() const
{
    return d->id;
}

QString ParkingQrcodes::description() const
{
    return d->description;
}

void ParkingQrcodes::setDescription(const QString &description)
{
    d->description = description;
}

QString ParkingQrcodes::path() const
{
    return d->path;
}

void ParkingQrcodes::setPath(const QString &path)
{
    d->path = path;
}

QDateTime ParkingQrcodes::createdAt() const
{
    return d->created_at;
}

QDateTime ParkingQrcodes::updatedAt() const
{
    return d->updated_at;
}

int ParkingQrcodes::lockRevision() const
{
    return d->lock_revision;
}

ParkingQrcodes &ParkingQrcodes::operator=(const ParkingQrcodes &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ParkingQrcodes ParkingQrcodes::create(const QString &description, const QString &path)
{
    ParkingQrcodesObject obj;
    obj.description = description;
    obj.path = path;
    if (!obj.create()) {
        return ParkingQrcodes();
    }
    return ParkingQrcodes(obj);
}

ParkingQrcodes ParkingQrcodes::create(const QVariantMap &values)
{
    ParkingQrcodes model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ParkingQrcodes ParkingQrcodes::get(int id)
{
    TSqlORMapper<ParkingQrcodesObject> mapper;
    return ParkingQrcodes(mapper.findByPrimaryKey(id));
}

ParkingQrcodes ParkingQrcodes::get(int id, int lockRevision)
{
    TSqlORMapper<ParkingQrcodesObject> mapper;
    TCriteria cri;
    cri.add(ParkingQrcodesObject::Id, id);
    cri.add(ParkingQrcodesObject::LockRevision, lockRevision);
    return ParkingQrcodes(mapper.findFirst(cri));
}

int ParkingQrcodes::count()
{
    TSqlORMapper<ParkingQrcodesObject> mapper;
    return mapper.findCount();
}

QList<ParkingQrcodes> ParkingQrcodes::getAll()
{
    return tfGetModelListByCriteria<ParkingQrcodes, ParkingQrcodesObject>(TCriteria());
}

QJsonArray ParkingQrcodes::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ParkingQrcodesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ParkingQrcodesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(ParkingQrcodes(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *ParkingQrcodes::modelData()
{
    return d.data();
}

const TModelObject *ParkingQrcodes::modelData() const
{
    return d.data();
}
