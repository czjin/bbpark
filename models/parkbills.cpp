#include <TreeFrogModel>
#include "parkbills.h"
#include "parkbillsobject.h"

ParkBills::ParkBills()
    : TAbstractModel(), d(new ParkBillsObject)
{
    d->id = 0;
    d->source = 0;
    d->amount = 0;
    d->status = 0;
}

ParkBills::ParkBills(const ParkBills &other)
    : TAbstractModel(), d(new ParkBillsObject(*other.d))
{ }

ParkBills::ParkBills(const ParkBillsObject &object)
    : TAbstractModel(), d(new ParkBillsObject(object))
{ }

ParkBills::~ParkBills()
{
    // If the reference count becomes 0,
    // the shared data object 'ParkBillsObject' is deleted.
}

int ParkBills::id() const
{
    return d->id;
}

QString ParkBills::sessionId() const
{
    return d->session_id;
}

void ParkBills::setSessionId(const QString &sessionId)
{
    d->session_id = sessionId;
}

int ParkBills::source() const
{
    return d->source;
}

void ParkBills::setSource(int source)
{
    d->source = source;
}

double ParkBills::amount() const
{
    return d->amount;
}

void ParkBills::setAmount(double amount)
{
    d->amount = amount;
}

int ParkBills::status() const
{
    return d->status;
}

void ParkBills::setStatus(int status)
{
    d->status = status;
}

QDateTime ParkBills::createdAt() const
{
    return d->created_at;
}

ParkBills &ParkBills::operator=(const ParkBills &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ParkBills ParkBills::create(const QString &sessionId, int source, double amount, int status)
{
    ParkBillsObject obj;
    obj.session_id = sessionId;
    obj.source = source;
    obj.amount = amount;
    obj.status = status;
    if (!obj.create()) {
        return ParkBills();
    }
    return ParkBills(obj);
}

ParkBills ParkBills::create(const QVariantMap &values)
{
    ParkBills model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ParkBills ParkBills::get(int id)
{
    TSqlORMapper<ParkBillsObject> mapper;
    return ParkBills(mapper.findByPrimaryKey(id));
}

int ParkBills::count()
{
    TSqlORMapper<ParkBillsObject> mapper;
    return mapper.findCount();
}

QList<ParkBills> ParkBills::getAll()
{
    return tfGetModelListByCriteria<ParkBills, ParkBillsObject>(TCriteria());
}

QJsonArray ParkBills::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ParkBillsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ParkBillsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(ParkBills(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *ParkBills::modelData()
{
    return d.data();
}

const TModelObject *ParkBills::modelData() const
{
    return d.data();
}
