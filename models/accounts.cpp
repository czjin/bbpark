#include <TreeFrogModel>
#include "accounts.h"
#include "accountsobject.h"

Accounts::Accounts()
    : TAbstractModel(), d(new AccountsObject)
{
    d->id = 0;
    d->user_id = 0;
    d->balance = 0;
    d->credit = 0;
    d->credit_available = 0;
    d->status = 0;
    d->type = 0;
}

Accounts::Accounts(const Accounts &other)
    : TAbstractModel(), d(new AccountsObject(*other.d))
{ }

Accounts::Accounts(const AccountsObject &object)
    : TAbstractModel(), d(new AccountsObject(object))
{ }

Accounts::~Accounts()
{
    // If the reference count becomes 0,
    // the shared data object 'AccountsObject' is deleted.
}

int Accounts::id() const
{
    return d->id;
}

QString Accounts::accNo() const
{
    return d->acc_no;
}

void Accounts::setAccNo(const QString &accNo)
{
    d->acc_no = accNo;
}

int Accounts::userId() const
{
    return d->user_id;
}

void Accounts::setUserId(int userId)
{
    d->user_id = userId;
}

QString Accounts::payCode() const
{
    return d->pay_code;
}

void Accounts::setPayCode(const QString &payCode)
{
    d->pay_code = payCode;
}

double Accounts::balance() const
{
    return d->balance;
}

void Accounts::setBalance(double balance)
{
    d->balance = balance;
}

double Accounts::credit() const
{
    return d->credit;
}

void Accounts::setCredit(double credit)
{
    d->credit = credit;
}

double Accounts::creditAvailable() const
{
    return d->credit_available;
}

void Accounts::setCreditAvailable(double creditAvailable)
{
    d->credit_available = creditAvailable;
}

int Accounts::status() const
{
    return d->status;
}

void Accounts::setStatus(int status)
{
    d->status = status;
}

int Accounts::type() const
{
    return d->type;
}

void Accounts::setType(int type)
{
    d->type = type;
}

QString Accounts::issuer() const
{
    return d->issuer;
}

void Accounts::setIssuer(const QString &issuer)
{
    d->issuer = issuer;
}

QDateTime Accounts::createdAt() const
{
    return d->created_at;
}

QDateTime Accounts::updatedAt() const
{
    return d->updated_at;
}

QString Accounts::memo() const
{
    return d->memo;
}

void Accounts::setMemo(const QString &memo)
{
    d->memo = memo;
}

Accounts &Accounts::operator=(const Accounts &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Accounts Accounts::create(const QString &accNo, int userId, const QString &payCode, double balance, double credit, double creditAvailable, int status, int type, const QString &issuer, const QString &memo)
{
    AccountsObject obj;
    obj.acc_no = accNo;
    obj.user_id = userId;
    obj.pay_code = payCode;
    obj.balance = balance;
    obj.credit = credit;
    obj.credit_available = creditAvailable;
    obj.status = status;
    obj.type = type;
    obj.issuer = issuer;
    obj.memo = memo;
    if (!obj.create()) {
        return Accounts();
    }
    return Accounts(obj);
}

Accounts Accounts::create(const QVariantMap &values)
{
    Accounts model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Accounts Accounts::get(int id)
{
    TSqlORMapper<AccountsObject> mapper;
    return Accounts(mapper.findByPrimaryKey(id));
}

int Accounts::count()
{
    TSqlORMapper<AccountsObject> mapper;
    return mapper.findCount();
}

QList<Accounts> Accounts::getAll()
{
    return tfGetModelListByCriteria<Accounts, AccountsObject>(TCriteria());
}

QJsonArray Accounts::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<AccountsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<AccountsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Accounts(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Accounts::modelData()
{
    return d.data();
}

const TModelObject *Accounts::modelData() const
{
    return d.data();
}
