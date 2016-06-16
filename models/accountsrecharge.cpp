#include <TreeFrogModel>
#include "accountsrecharge.h"
#include "accountsrechargeobject.h"

AccountsRecharge::AccountsRecharge()
    : TAbstractModel(), d(new AccountsRechargeObject)
{
    d->id = 0;
    d->user_id = 0;
    d->amount = 0;
    d->source = 0;
}

AccountsRecharge::AccountsRecharge(const AccountsRecharge &other)
    : TAbstractModel(), d(new AccountsRechargeObject(*other.d))
{ }

AccountsRecharge::AccountsRecharge(const AccountsRechargeObject &object)
    : TAbstractModel(), d(new AccountsRechargeObject(object))
{ }

AccountsRecharge::~AccountsRecharge()
{
    // If the reference count becomes 0,
    // the shared data object 'AccountsRechargeObject' is deleted.
}

int AccountsRecharge::id() const
{
    return d->id;
}

int AccountsRecharge::userId() const
{
    return d->user_id;
}

void AccountsRecharge::setUserId(int userId)
{
    d->user_id = userId;
}

double AccountsRecharge::amount() const
{
    return d->amount;
}

void AccountsRecharge::setAmount(double amount)
{
    d->amount = amount;
}

int AccountsRecharge::source() const
{
    return d->source;
}

void AccountsRecharge::setSource(int source)
{
    d->source = source;
}

QDateTime AccountsRecharge::createdAt() const
{
    return d->created_at;
}

QString AccountsRecharge::memo() const
{
    return d->memo;
}

void AccountsRecharge::setMemo(const QString &memo)
{
    d->memo = memo;
}

AccountsRecharge &AccountsRecharge::operator=(const AccountsRecharge &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AccountsRecharge AccountsRecharge::create(int userId, double amount, int source, const QString &memo)
{
    AccountsRechargeObject obj;
    obj.user_id = userId;
    obj.amount = amount;
    obj.source = source;
    obj.memo = memo;
    if (!obj.create()) {
        return AccountsRecharge();
    }
    return AccountsRecharge(obj);
}

AccountsRecharge AccountsRecharge::create(const QVariantMap &values)
{
    AccountsRecharge model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AccountsRecharge AccountsRecharge::get(int id)
{
    TSqlORMapper<AccountsRechargeObject> mapper;
    return AccountsRecharge(mapper.findByPrimaryKey(id));
}

int AccountsRecharge::count()
{
    TSqlORMapper<AccountsRechargeObject> mapper;
    return mapper.findCount();
}

QList<AccountsRecharge> AccountsRecharge::getAll()
{
    return tfGetModelListByCriteria<AccountsRecharge, AccountsRechargeObject>(TCriteria());
}

QJsonArray AccountsRecharge::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<AccountsRechargeObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<AccountsRechargeObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(AccountsRecharge(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *AccountsRecharge::modelData()
{
    return d.data();
}

const TModelObject *AccountsRecharge::modelData() const
{
    return d.data();
}
