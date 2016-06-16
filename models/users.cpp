#include <TreeFrogModel>
#include "users.h"
#include "usersobject.h"

Users::Users()
    : TAbstractModel(), d(new UsersObject)
{
    d->id = 0;
    d->sex = 0;
    d->lock_revision = 0;
}

Users::Users(const Users &other)
    : TAbstractModel(), d(new UsersObject(*other.d))
{ }

Users::Users(const UsersObject &object)
    : TAbstractModel(), d(new UsersObject(object))
{ }

Users::~Users()
{
    // If the reference count becomes 0,
    // the shared data object 'UsersObject' is deleted.
}

int Users::id() const
{
    return d->id;
}

QString Users::name() const
{
    return d->name;
}

void Users::setName(const QString &name)
{
    d->name = name;
}

QString Users::code() const
{
    return d->code;
}

void Users::setCode(const QString &code)
{
    d->code = code;
}

QString Users::realName() const
{
    return d->real_name;
}

void Users::setRealName(const QString &realName)
{
    d->real_name = realName;
}

int Users::sex() const
{
    return d->sex;
}

void Users::setSex(int sex)
{
    d->sex = sex;
}

QString Users::avatar() const
{
    return d->avatar;
}

void Users::setAvatar(const QString &avatar)
{
    d->avatar = avatar;
}

QDateTime Users::createdAt() const
{
    return d->created_at;
}

QDateTime Users::updatedAt() const
{
    return d->updated_at;
}

int Users::lockRevision() const
{
    return d->lock_revision;
}

Users &Users::operator=(const Users &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Users Users::create(const QString &name, const QString &code, const QString &realName, int sex, const QString &avatar)
{
    UsersObject obj;
    obj.name = name;
    obj.code = code;
    obj.real_name = realName;
    obj.sex = sex;
    obj.avatar = avatar;
    if (!obj.create()) {
        return Users();
    }
    return Users(obj);
}

Users Users::create(const QVariantMap &values)
{
    Users model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Users Users::get(int id)
{
    TSqlORMapper<UsersObject> mapper;
    return Users(mapper.findByPrimaryKey(id));
}

Users Users::get(int id, int lockRevision)
{
    TSqlORMapper<UsersObject> mapper;
    TCriteria cri;
    cri.add(UsersObject::Id, id);
    cri.add(UsersObject::LockRevision, lockRevision);
    return Users(mapper.findFirst(cri));
}

int Users::count()
{
    TSqlORMapper<UsersObject> mapper;
    return mapper.findCount();
}

QList<Users> Users::getAll()
{
    return tfGetModelListByCriteria<Users, UsersObject>(TCriteria());
}

QJsonArray Users::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<UsersObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<UsersObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Users(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Users::modelData()
{
    return d.data();
}

const TModelObject *Users::modelData() const
{
    return d.data();
}
