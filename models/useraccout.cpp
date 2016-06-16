#include <TreeFrogModel>
#include "useraccout.h"
#include "useraccoutobject.h"

UserAccout::UserAccout()
    : TAbstractModel(), d(new UserAccoutObject)
{
    d->id = 0;
    d->user_id = 0;
    d->account_id = 0;
    d->lock_revision = 0;
}

UserAccout::UserAccout(const UserAccout &other)
    : TAbstractModel(), d(new UserAccoutObject(*other.d))
{ }

UserAccout::UserAccout(const UserAccoutObject &object)
    : TAbstractModel(), d(new UserAccoutObject(object))
{ }

UserAccout::~UserAccout()
{
    // If the reference count becomes 0,
    // the shared data object 'UserAccoutObject' is deleted.
}

int UserAccout::id() const
{
    return d->id;
}

int UserAccout::userId() const
{
    return d->user_id;
}

void UserAccout::setUserId(int userId)
{
    d->user_id = userId;
}

int UserAccout::accountId() const
{
    return d->account_id;
}

void UserAccout::setAccountId(int accountId)
{
    d->account_id = accountId;
}

QDateTime UserAccout::createdAt() const
{
    return d->created_at;
}

QDateTime UserAccout::updatedAt() const
{
    return d->updated_at;
}

int UserAccout::lockRevision() const
{
    return d->lock_revision;
}

UserAccout &UserAccout::operator=(const UserAccout &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

UserAccout UserAccout::create(int userId, int accountId)
{
    UserAccoutObject obj;
    obj.user_id = userId;
    obj.account_id = accountId;
    if (!obj.create()) {
        return UserAccout();
    }
    return UserAccout(obj);
}

UserAccout UserAccout::create(const QVariantMap &values)
{
    UserAccout model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

UserAccout UserAccout::get(int id)
{
    TSqlORMapper<UserAccoutObject> mapper;
    return UserAccout(mapper.findByPrimaryKey(id));
}

UserAccout UserAccout::get(int id, int lockRevision)
{
    TSqlORMapper<UserAccoutObject> mapper;
    TCriteria cri;
    cri.add(UserAccoutObject::Id, id);
    cri.add(UserAccoutObject::LockRevision, lockRevision);
    return UserAccout(mapper.findFirst(cri));
}

int UserAccout::count()
{
    TSqlORMapper<UserAccoutObject> mapper;
    return mapper.findCount();
}

QList<UserAccout> UserAccout::getAll()
{
    return tfGetModelListByCriteria<UserAccout, UserAccoutObject>(TCriteria());
}

QJsonArray UserAccout::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<UserAccoutObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<UserAccoutObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(UserAccout(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *UserAccout::modelData()
{
    return d.data();
}

const TModelObject *UserAccout::modelData() const
{
    return d.data();
}
