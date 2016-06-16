#include <TreeFrogModel>
#include "parkprepay.h"
#include "parkprepayobject.h"

ParkPrepay::ParkPrepay()
    : TAbstractModel(), d(new ParkPrepayObject)
{
    d->id = 0;
    d->user_id = 0;
    d->prepaid = 0;
}

ParkPrepay::ParkPrepay(const ParkPrepay &other)
    : TAbstractModel(), d(new ParkPrepayObject(*other.d))
{ }

ParkPrepay::ParkPrepay(const ParkPrepayObject &object)
    : TAbstractModel(), d(new ParkPrepayObject(object))
{ }

ParkPrepay::~ParkPrepay()
{
    // If the reference count becomes 0,
    // the shared data object 'ParkPrepayObject' is deleted.
}

int ParkPrepay::id() const
{
    return d->id;
}

int ParkPrepay::userId() const
{
    return d->user_id;
}

void ParkPrepay::setUserId(int userId)
{
    d->user_id = userId;
}

QString ParkPrepay::sessionId() const
{
    return d->session_id;
}

void ParkPrepay::setSessionId(const QString &sessionId)
{
    d->session_id = sessionId;
}

double ParkPrepay::prepaid() const
{
    return d->prepaid;
}

void ParkPrepay::setPrepaid(double prepaid)
{
    d->prepaid = prepaid;
}

QDateTime ParkPrepay::createdAt() const
{
    return d->created_at;
}

ParkPrepay &ParkPrepay::operator=(const ParkPrepay &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ParkPrepay ParkPrepay::create(int userId, const QString &sessionId, double prepaid)
{
    ParkPrepayObject obj;
    obj.user_id = userId;
    obj.session_id = sessionId;
    obj.prepaid = prepaid;
    if (!obj.create()) {
        return ParkPrepay();
    }
    return ParkPrepay(obj);
}

ParkPrepay ParkPrepay::create(const QVariantMap &values)
{
    ParkPrepay model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ParkPrepay ParkPrepay::get(int id)
{
    TSqlORMapper<ParkPrepayObject> mapper;
    return ParkPrepay(mapper.findByPrimaryKey(id));
}

int ParkPrepay::count()
{
    TSqlORMapper<ParkPrepayObject> mapper;
    return mapper.findCount();
}

QList<ParkPrepay> ParkPrepay::getAll()
{
    return tfGetModelListByCriteria<ParkPrepay, ParkPrepayObject>(TCriteria());
}

QJsonArray ParkPrepay::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ParkPrepayObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ParkPrepayObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(ParkPrepay(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *ParkPrepay::modelData()
{
    return d.data();
}

const TModelObject *ParkPrepay::modelData() const
{
    return d.data();
}
