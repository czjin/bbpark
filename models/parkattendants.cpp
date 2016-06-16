#include <TreeFrogModel>
#include "parkattendants.h"
#include "parkattendantsobject.h"

ParkAttendants::ParkAttendants()
    : TAbstractModel(), d(new ParkAttendantsObject)
{
    d->id = 0;
    d->sex = 0;
    d->lock_revision = 0;
}

ParkAttendants::ParkAttendants(const ParkAttendants &other)
    : TAbstractModel(), d(new ParkAttendantsObject(*other.d))
{ }

ParkAttendants::ParkAttendants(const ParkAttendantsObject &object)
    : TAbstractModel(), d(new ParkAttendantsObject(object))
{ }

ParkAttendants::~ParkAttendants()
{
    // If the reference count becomes 0,
    // the shared data object 'ParkAttendantsObject' is deleted.
}

int ParkAttendants::id() const
{
    return d->id;
}

QString ParkAttendants::name() const
{
    return d->name;
}

void ParkAttendants::setName(const QString &name)
{
    d->name = name;
}

QString ParkAttendants::code() const
{
    return d->code;
}

void ParkAttendants::setCode(const QString &code)
{
    d->code = code;
}

QString ParkAttendants::realName() const
{
    return d->real_name;
}

void ParkAttendants::setRealName(const QString &realName)
{
    d->real_name = realName;
}

int ParkAttendants::sex() const
{
    return d->sex;
}

void ParkAttendants::setSex(int sex)
{
    d->sex = sex;
}

QString ParkAttendants::avatar() const
{
    return d->avatar;
}

void ParkAttendants::setAvatar(const QString &avatar)
{
    d->avatar = avatar;
}

QDateTime ParkAttendants::createdAt() const
{
    return d->created_at;
}

QDateTime ParkAttendants::updatedAt() const
{
    return d->updated_at;
}

int ParkAttendants::lockRevision() const
{
    return d->lock_revision;
}

ParkAttendants &ParkAttendants::operator=(const ParkAttendants &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ParkAttendants ParkAttendants::create(const QString &name, const QString &code, const QString &realName, int sex, const QString &avatar)
{
    ParkAttendantsObject obj;
    obj.name = name;
    obj.code = code;
    obj.real_name = realName;
    obj.sex = sex;
    obj.avatar = avatar;
    if (!obj.create()) {
        return ParkAttendants();
    }
    return ParkAttendants(obj);
}

ParkAttendants ParkAttendants::create(const QVariantMap &values)
{
    ParkAttendants model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ParkAttendants ParkAttendants::get(int id)
{
    TSqlORMapper<ParkAttendantsObject> mapper;
    return ParkAttendants(mapper.findByPrimaryKey(id));
}

ParkAttendants ParkAttendants::get(int id, int lockRevision)
{
    TSqlORMapper<ParkAttendantsObject> mapper;
    TCriteria cri;
    cri.add(ParkAttendantsObject::Id, id);
    cri.add(ParkAttendantsObject::LockRevision, lockRevision);
    return ParkAttendants(mapper.findFirst(cri));
}

int ParkAttendants::count()
{
    TSqlORMapper<ParkAttendantsObject> mapper;
    return mapper.findCount();
}

QList<ParkAttendants> ParkAttendants::getAll()
{
    return tfGetModelListByCriteria<ParkAttendants, ParkAttendantsObject>(TCriteria());
}

QJsonArray ParkAttendants::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ParkAttendantsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ParkAttendantsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(ParkAttendants(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *ParkAttendants::modelData()
{
    return d.data();
}

const TModelObject *ParkAttendants::modelData() const
{
    return d.data();
}
