#include <TreeFrogModel>
#include "sysinfo.h"
#include "sysinfoobject.h"

Sysinfo::Sysinfo()
    : TAbstractModel(), d(new SysinfoObject)
{
    d->id = 0;
}

Sysinfo::Sysinfo(const Sysinfo &other)
    : TAbstractModel(), d(new SysinfoObject(*other.d))
{ }

Sysinfo::Sysinfo(const SysinfoObject &object)
    : TAbstractModel(), d(new SysinfoObject(object))
{ }

Sysinfo::~Sysinfo()
{
    // If the reference count becomes 0,
    // the shared data object 'SysinfoObject' is deleted.
}

int Sysinfo::id() const
{
    return d->id;
}

void Sysinfo::setId(int id)
{
    d->id = id;
}

QString Sysinfo::company() const
{
    return d->company;
}

void Sysinfo::setCompany(const QString &company)
{
    d->company = company;
}

QString Sysinfo::slogan() const
{
    return d->slogan;
}

void Sysinfo::setSlogan(const QString &slogan)
{
    d->slogan = slogan;
}

QString Sysinfo::website() const
{
    return d->website;
}

void Sysinfo::setWebsite(const QString &website)
{
    d->website = website;
}

QString Sysinfo::contactHotline() const
{
    return d->contact_hotline;
}

void Sysinfo::setContactHotline(const QString &contactHotline)
{
    d->contact_hotline = contactHotline;
}

QString Sysinfo::servVer() const
{
    return d->serv_ver;
}

void Sysinfo::setServVer(const QString &servVer)
{
    d->serv_ver = servVer;
}

QString Sysinfo::appVer() const
{
    return d->app_ver;
}

void Sysinfo::setAppVer(const QString &appVer)
{
    d->app_ver = appVer;
}

QString Sysinfo::handsetVer() const
{
    return d->handset_ver;
}

void Sysinfo::setHandsetVer(const QString &handsetVer)
{
    d->handset_ver = handsetVer;
}

QDateTime Sysinfo::createdAt() const
{
    return d->created_at;
}

Sysinfo &Sysinfo::operator=(const Sysinfo &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Sysinfo Sysinfo::create(int id, const QString &company, const QString &slogan, const QString &website, const QString &contactHotline, const QString &servVer, const QString &appVer, const QString &handsetVer)
{
    SysinfoObject obj;
    obj.id = id;
    obj.company = company;
    obj.slogan = slogan;
    obj.website = website;
    obj.contact_hotline = contactHotline;
    obj.serv_ver = servVer;
    obj.app_ver = appVer;
    obj.handset_ver = handsetVer;
    if (!obj.create()) {
        return Sysinfo();
    }
    return Sysinfo(obj);
}

Sysinfo Sysinfo::create(const QVariantMap &values)
{
    Sysinfo model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Sysinfo Sysinfo::get(int id)
{
    TSqlORMapper<SysinfoObject> mapper;
    return Sysinfo(mapper.findByPrimaryKey(id));
}

int Sysinfo::count()
{
    TSqlORMapper<SysinfoObject> mapper;
    return mapper.findCount();
}

QList<Sysinfo> Sysinfo::getAll()
{
    return tfGetModelListByCriteria<Sysinfo, SysinfoObject>(TCriteria());
}

QJsonArray Sysinfo::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<SysinfoObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<SysinfoObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Sysinfo(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Sysinfo::modelData()
{
    return d.data();
}

const TModelObject *Sysinfo::modelData() const
{
    return d.data();
}
