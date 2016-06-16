#include <TreeFrogModel>
#include "parkings.h"
#include "parkingsobject.h"

Parkings::Parkings()
    : TAbstractModel(), d(new ParkingsObject)
{
    d->id = 0;
    d->longitude = 0;
    d->latitude = 0;
    d->type = 0;
    d->space_total = 0;
    d->space_free = 0;
    d->qrcode_id = 0;
    d->lock_revision = 0;
}

Parkings::Parkings(const Parkings &other)
    : TAbstractModel(), d(new ParkingsObject(*other.d))
{ }

Parkings::Parkings(const ParkingsObject &object)
    : TAbstractModel(), d(new ParkingsObject(object))
{ }

Parkings::~Parkings()
{
    // If the reference count becomes 0,
    // the shared data object 'ParkingsObject' is deleted.
}

int Parkings::id() const
{
    return d->id;
}

QString Parkings::name() const
{
    return d->name;
}

void Parkings::setName(const QString &name)
{
    d->name = name;
}

QString Parkings::description() const
{
    return d->description;
}

void Parkings::setDescription(const QString &description)
{
    d->description = description;
}

QString Parkings::addr() const
{
    return d->addr;
}

void Parkings::setAddr(const QString &addr)
{
    d->addr = addr;
}

QString Parkings::chargeStandard() const
{
    return d->charge_standard;
}

void Parkings::setChargeStandard(const QString &chargeStandard)
{
    d->charge_standard = chargeStandard;
}

double Parkings::longitude() const
{
    return d->longitude;
}

void Parkings::setLongitude(double longitude)
{
    d->longitude = longitude;
}

double Parkings::latitude() const
{
    return d->latitude;
}

void Parkings::setLatitude(double latitude)
{
    d->latitude = latitude;
}

int Parkings::type() const
{
    return d->type;
}

void Parkings::setType(int type)
{
    d->type = type;
}

QString Parkings::planPath() const
{
    return d->plan_path;
}

void Parkings::setPlanPath(const QString &planPath)
{
    d->plan_path = planPath;
}

QString Parkings::spaceStart() const
{
    return d->space_start;
}

void Parkings::setSpaceStart(const QString &spaceStart)
{
    d->space_start = spaceStart;
}

int Parkings::spaceTotal() const
{
    return d->space_total;
}

void Parkings::setSpaceTotal(int spaceTotal)
{
    d->space_total = spaceTotal;
}

int Parkings::spaceFree() const
{
    return d->space_free;
}

void Parkings::setSpaceFree(int spaceFree)
{
    d->space_free = spaceFree;
}

int Parkings::qrcodeId() const
{
    return d->qrcode_id;
}

void Parkings::setQrcodeId(int qrcodeId)
{
    d->qrcode_id = qrcodeId;
}

QString Parkings::memo() const
{
    return d->memo;
}

void Parkings::setMemo(const QString &memo)
{
    d->memo = memo;
}

QDateTime Parkings::createdAt() const
{
    return d->created_at;
}

QDateTime Parkings::updatedAt() const
{
    return d->updated_at;
}

int Parkings::lockRevision() const
{
    return d->lock_revision;
}

Parkings &Parkings::operator=(const Parkings &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Parkings Parkings::create(const QString &name, const QString &description, const QString &addr, const QString &chargeStandard, double longitude, double latitude, int type, const QString &planPath, const QString &spaceStart, int spaceTotal, int spaceFree, int qrcodeId, const QString &memo)
{
    ParkingsObject obj;
    obj.name = name;
    obj.description = description;
    obj.addr = addr;
    obj.charge_standard = chargeStandard;
    obj.longitude = longitude;
    obj.latitude = latitude;
    obj.type = type;
    obj.plan_path = planPath;
    obj.space_start = spaceStart;
    obj.space_total = spaceTotal;
    obj.space_free = spaceFree;
    obj.qrcode_id = qrcodeId;
    obj.memo = memo;
    if (!obj.create()) {
        return Parkings();
    }
    return Parkings(obj);
}

Parkings Parkings::create(const QVariantMap &values)
{
    Parkings model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Parkings Parkings::get(int id)
{
    TSqlORMapper<ParkingsObject> mapper;
    return Parkings(mapper.findByPrimaryKey(id));
}

Parkings Parkings::get(int id, int lockRevision)
{
    TSqlORMapper<ParkingsObject> mapper;
    TCriteria cri;
    cri.add(ParkingsObject::Id, id);
    cri.add(ParkingsObject::LockRevision, lockRevision);
    return Parkings(mapper.findFirst(cri));
}

int Parkings::count()
{
    TSqlORMapper<ParkingsObject> mapper;
    return mapper.findCount();
}

QList<Parkings> Parkings::getAll()
{
    return tfGetModelListByCriteria<Parkings, ParkingsObject>(TCriteria());
}

QJsonArray Parkings::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ParkingsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ParkingsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Parkings(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Parkings::modelData()
{
    return d.data();
}

const TModelObject *Parkings::modelData() const
{
    return d.data();
}
