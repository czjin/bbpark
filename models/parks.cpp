#include <TreeFrogModel>
#include "parks.h"
#include "parksobject.h"

Parks::Parks()
    : TAbstractModel(), d(new ParksObject)
{
    d->id = 0;
    d->user_id = 0;
    d->vehicle_id = 0;
    d->parking_id = 0;
    d->park_fee = 0;
    d->prepaid = 0;
    d->order_duration = 0;
    d->status = 0;
    d->pay_mode = 0;
    d->pay_source = 0;
}

Parks::Parks(const Parks &other)
    : TAbstractModel(), d(new ParksObject(*other.d))
{ }

Parks::Parks(const ParksObject &object)
    : TAbstractModel(), d(new ParksObject(object))
{ }

Parks::~Parks()
{
    // If the reference count becomes 0,
    // the shared data object 'ParksObject' is deleted.
}

int Parks::id() const
{
    return d->id;
}

QString Parks::sessionId() const
{
    return d->session_id;
}

void Parks::setSessionId(const QString &sessionId)
{
    d->session_id = sessionId;
}

int Parks::userId() const
{
    return d->user_id;
}

void Parks::setUserId(int userId)
{
    d->user_id = userId;
}

int Parks::vehicleId() const
{
    return d->vehicle_id;
}

void Parks::setVehicleId(int vehicleId)
{
    d->vehicle_id = vehicleId;
}

int Parks::parkingId() const
{
    return d->parking_id;
}

void Parks::setParkingId(int parkingId)
{
    d->parking_id = parkingId;
}

QString Parks::parkingSpaceNo() const
{
    return d->parking_space_no;
}

void Parks::setParkingSpaceNo(const QString &parkingSpaceNo)
{
    d->parking_space_no = parkingSpaceNo;
}

QDateTime Parks::startTime() const
{
    return d->start_time;
}

void Parks::setStartTime(const QDateTime &startTime)
{
    d->start_time = startTime;
}

QDateTime Parks::endTime() const
{
    return d->end_time;
}

void Parks::setEndTime(const QDateTime &endTime)
{
    d->end_time = endTime;
}

double Parks::parkFee() const
{
    return d->park_fee;
}

void Parks::setParkFee(double parkFee)
{
    d->park_fee = parkFee;
}

double Parks::prepaid() const
{
    return d->prepaid;
}

void Parks::setPrepaid(double prepaid)
{
    d->prepaid = prepaid;
}

int Parks::orderDuration() const
{
    return d->order_duration;
}

void Parks::setOrderDuration(int orderDuration)
{
    d->order_duration = orderDuration;
}

int Parks::status() const
{
    return d->status;
}

void Parks::setStatus(int status)
{
    d->status = status;
}

int Parks::payMode() const
{
    return d->pay_mode;
}

void Parks::setPayMode(int payMode)
{
    d->pay_mode = payMode;
}

int Parks::paySource() const
{
    return d->pay_source;
}

void Parks::setPaySource(int paySource)
{
    d->pay_source = paySource;
}

QString Parks::qrcodePath() const
{
    return d->qrcode_path;
}

void Parks::setQrcodePath(const QString &qrcodePath)
{
    d->qrcode_path = qrcodePath;
}

QString Parks::memo() const
{
    return d->memo;
}

void Parks::setMemo(const QString &memo)
{
    d->memo = memo;
}

Parks &Parks::operator=(const Parks &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Parks Parks::create(const QString &sessionId, int userId, int vehicleId, int parkingId, const QString &parkingSpaceNo, const QDateTime &startTime, const QDateTime &endTime, double parkFee, double prepaid, int orderDuration, int status, int payMode, int paySource, const QString &qrcodePath, const QString &memo)
{
    ParksObject obj;
    obj.session_id = sessionId;
    obj.user_id = userId;
    obj.vehicle_id = vehicleId;
    obj.parking_id = parkingId;
    obj.parking_space_no = parkingSpaceNo;
    obj.start_time = startTime;
    obj.end_time = endTime;
    obj.park_fee = parkFee;
    obj.prepaid = prepaid;
    obj.order_duration = orderDuration;
    obj.status = status;
    obj.pay_mode = payMode;
    obj.pay_source = paySource;
    obj.qrcode_path = qrcodePath;
    obj.memo = memo;
    if (!obj.create()) {
        return Parks();
    }
    return Parks(obj);
}

Parks Parks::create(const QVariantMap &values)
{
    Parks model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Parks Parks::get(int id)
{
    TSqlORMapper<ParksObject> mapper;
    return Parks(mapper.findByPrimaryKey(id));
}

int Parks::count()
{
    TSqlORMapper<ParksObject> mapper;
    return mapper.findCount();
}

QList<Parks> Parks::getAll()
{
    return tfGetModelListByCriteria<Parks, ParksObject>(TCriteria());
}

QJsonArray Parks::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ParksObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ParksObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Parks(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Parks::modelData()
{
    return d.data();
}

const TModelObject *Parks::modelData() const
{
    return d.data();
}
