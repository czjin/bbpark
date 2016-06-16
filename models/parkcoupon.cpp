#include <TreeFrogModel>
#include "parkcoupon.h"
#include "parkcouponobject.h"

ParkCoupon::ParkCoupon()
    : TAbstractModel(), d(new ParkCouponObject)
{
    d->id = 0;
    d->amount = 0;
    d->status = 0;
}

ParkCoupon::ParkCoupon(const ParkCoupon &other)
    : TAbstractModel(), d(new ParkCouponObject(*other.d))
{ }

ParkCoupon::ParkCoupon(const ParkCouponObject &object)
    : TAbstractModel(), d(new ParkCouponObject(object))
{ }

ParkCoupon::~ParkCoupon()
{
    // If the reference count becomes 0,
    // the shared data object 'ParkCouponObject' is deleted.
}

int ParkCoupon::id() const
{
    return d->id;
}

QString ParkCoupon::couponNo() const
{
    return d->coupon_no;
}

void ParkCoupon::setCouponNo(const QString &couponNo)
{
    d->coupon_no = couponNo;
}

QString ParkCoupon::checkCode() const
{
    return d->check_code;
}

void ParkCoupon::setCheckCode(const QString &checkCode)
{
    d->check_code = checkCode;
}

double ParkCoupon::amount() const
{
    return d->amount;
}

void ParkCoupon::setAmount(double amount)
{
    d->amount = amount;
}

int ParkCoupon::status() const
{
    return d->status;
}

void ParkCoupon::setStatus(int status)
{
    d->status = status;
}

QDateTime ParkCoupon::createdAt() const
{
    return d->created_at;
}

QDateTime ParkCoupon::useTime() const
{
    return d->use_time;
}

void ParkCoupon::setUseTime(const QDateTime &useTime)
{
    d->use_time = useTime;
}

QDateTime ParkCoupon::validTill() const
{
    return d->valid_till;
}

void ParkCoupon::setValidTill(const QDateTime &validTill)
{
    d->valid_till = validTill;
}

ParkCoupon &ParkCoupon::operator=(const ParkCoupon &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ParkCoupon ParkCoupon::create(const QString &couponNo, const QString &checkCode, double amount, int status, const QDateTime &useTime, const QDateTime &validTill)
{
    ParkCouponObject obj;
    obj.coupon_no = couponNo;
    obj.check_code = checkCode;
    obj.amount = amount;
    obj.status = status;
    obj.use_time = useTime;
    obj.valid_till = validTill;
    if (!obj.create()) {
        return ParkCoupon();
    }
    return ParkCoupon(obj);
}

ParkCoupon ParkCoupon::create(const QVariantMap &values)
{
    ParkCoupon model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ParkCoupon ParkCoupon::get(int id)
{
    TSqlORMapper<ParkCouponObject> mapper;
    return ParkCoupon(mapper.findByPrimaryKey(id));
}

int ParkCoupon::count()
{
    TSqlORMapper<ParkCouponObject> mapper;
    return mapper.findCount();
}

QList<ParkCoupon> ParkCoupon::getAll()
{
    return tfGetModelListByCriteria<ParkCoupon, ParkCouponObject>(TCriteria());
}

QJsonArray ParkCoupon::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ParkCouponObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ParkCouponObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(ParkCoupon(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *ParkCoupon::modelData()
{
    return d.data();
}

const TModelObject *ParkCoupon::modelData() const
{
    return d.data();
}
