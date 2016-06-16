#include <TreeFrogModel>
#include "parkingaccounts.h"
#include "parkingaccountsobject.h"

ParkingAccounts::ParkingAccounts()
    : TAbstractModel(), d(new ParkingAccountsObject)
{
    d->id = 0;
    d->balance = 0;
    d->parking_id = 0;
    d->status = 0;
    d->type = 0;
}

ParkingAccounts::ParkingAccounts(const ParkingAccounts &other)
    : TAbstractModel(), d(new ParkingAccountsObject(*other.d))
{ }

ParkingAccounts::ParkingAccounts(const ParkingAccountsObject &object)
    : TAbstractModel(), d(new ParkingAccountsObject(object))
{ }

ParkingAccounts::~ParkingAccounts()
{
    // If the reference count becomes 0,
    // the shared data object 'ParkingAccountsObject' is deleted.
}

int ParkingAccounts::id() const
{
    return d->id;
}

QString ParkingAccounts::accNo() const
{
    return d->acc_no;
}

void ParkingAccounts::setAccNo(const QString &accNo)
{
    d->acc_no = accNo;
}

double ParkingAccounts::balance() const
{
    return d->balance;
}

void ParkingAccounts::setBalance(double balance)
{
    d->balance = balance;
}

int ParkingAccounts::parkingId() const
{
    return d->parking_id;
}

void ParkingAccounts::setParkingId(int parkingId)
{
    d->parking_id = parkingId;
}

int ParkingAccounts::status() const
{
    return d->status;
}

void ParkingAccounts::setStatus(int status)
{
    d->status = status;
}

int ParkingAccounts::type() const
{
    return d->type;
}

void ParkingAccounts::setType(int type)
{
    d->type = type;
}

QString ParkingAccounts::issuer() const
{
    return d->issuer;
}

void ParkingAccounts::setIssuer(const QString &issuer)
{
    d->issuer = issuer;
}

QDateTime ParkingAccounts::createdAt() const
{
    return d->created_at;
}

QDateTime ParkingAccounts::updatedAt() const
{
    return d->updated_at;
}

QString ParkingAccounts::memo() const
{
    return d->memo;
}

void ParkingAccounts::setMemo(const QString &memo)
{
    d->memo = memo;
}

ParkingAccounts &ParkingAccounts::operator=(const ParkingAccounts &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ParkingAccounts ParkingAccounts::create(const QString &accNo, double balance, int parkingId, int status, int type, const QString &issuer, const QString &memo)
{
    ParkingAccountsObject obj;
    obj.acc_no = accNo;
    obj.balance = balance;
    obj.parking_id = parkingId;
    obj.status = status;
    obj.type = type;
    obj.issuer = issuer;
    obj.memo = memo;
    if (!obj.create()) {
        return ParkingAccounts();
    }
    return ParkingAccounts(obj);
}

ParkingAccounts ParkingAccounts::create(const QVariantMap &values)
{
    ParkingAccounts model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ParkingAccounts ParkingAccounts::get(int id)
{
    TSqlORMapper<ParkingAccountsObject> mapper;
    return ParkingAccounts(mapper.findByPrimaryKey(id));
}

int ParkingAccounts::count()
{
    TSqlORMapper<ParkingAccountsObject> mapper;
    return mapper.findCount();
}

QList<ParkingAccounts> ParkingAccounts::getAll()
{
    return tfGetModelListByCriteria<ParkingAccounts, ParkingAccountsObject>(TCriteria());
}

QJsonArray ParkingAccounts::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ParkingAccountsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ParkingAccountsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(ParkingAccounts(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *ParkingAccounts::modelData()
{
    return d.data();
}

const TModelObject *ParkingAccounts::modelData() const
{
    return d.data();
}
