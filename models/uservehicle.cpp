#include <TreeFrogModel>
#include "uservehicle.h"
#include "uservehicleobject.h"

UserVehicle::UserVehicle()
    : TAbstractModel(), d(new UserVehicleObject)
{
    d->id = 0;
    d->user_id = 0;
    d->vehicle_id = 0;
    d->lock_revision = 0;
}

UserVehicle::UserVehicle(const UserVehicle &other)
    : TAbstractModel(), d(new UserVehicleObject(*other.d))
{ }

UserVehicle::UserVehicle(const UserVehicleObject &object)
    : TAbstractModel(), d(new UserVehicleObject(object))
{ }

UserVehicle::~UserVehicle()
{
    // If the reference count becomes 0,
    // the shared data object 'UserVehicleObject' is deleted.
}

int UserVehicle::id() const
{
    return d->id;
}

int UserVehicle::userId() const
{
    return d->user_id;
}

void UserVehicle::setUserId(int userId)
{
    d->user_id = userId;
}

int UserVehicle::vehicleId() const
{
    return d->vehicle_id;
}

void UserVehicle::setVehicleId(int vehicleId)
{
    d->vehicle_id = vehicleId;
}

QDateTime UserVehicle::createdAt() const
{
    return d->created_at;
}

QDateTime UserVehicle::updatedAt() const
{
    return d->updated_at;
}

int UserVehicle::lockRevision() const
{
    return d->lock_revision;
}

UserVehicle &UserVehicle::operator=(const UserVehicle &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

UserVehicle UserVehicle::create(int userId, int vehicleId)
{
    UserVehicleObject obj;
    obj.user_id = userId;
    obj.vehicle_id = vehicleId;
    if (!obj.create()) {
        return UserVehicle();
    }
    return UserVehicle(obj);
}

UserVehicle UserVehicle::create(const QVariantMap &values)
{
    UserVehicle model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

UserVehicle UserVehicle::get(int id)
{
    TSqlORMapper<UserVehicleObject> mapper;
    return UserVehicle(mapper.findByPrimaryKey(id));
}

UserVehicle UserVehicle::get(int id, int lockRevision)
{
    TSqlORMapper<UserVehicleObject> mapper;
    TCriteria cri;
    cri.add(UserVehicleObject::Id, id);
    cri.add(UserVehicleObject::LockRevision, lockRevision);
    return UserVehicle(mapper.findFirst(cri));
}

int UserVehicle::count()
{
    TSqlORMapper<UserVehicleObject> mapper;
    return mapper.findCount();
}

QList<UserVehicle> UserVehicle::getAll()
{
    return tfGetModelListByCriteria<UserVehicle, UserVehicleObject>(TCriteria());
}

QJsonArray UserVehicle::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<UserVehicleObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<UserVehicleObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(UserVehicle(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *UserVehicle::modelData()
{
    return d.data();
}

const TModelObject *UserVehicle::modelData() const
{
    return d.data();
}
