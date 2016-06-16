#include <TreeFrogModel>
#include "version.h"
#include "versionobject.h"

Version::Version()
    : TAbstractModel(), d(new VersionObject)
{
    d->id = 0;
    d->major_version = 0;
    d->minor_version = 0;
    d->revision = 0;
}

Version::Version(const Version &other)
    : TAbstractModel(), d(new VersionObject(*other.d))
{ }

Version::Version(const VersionObject &object)
    : TAbstractModel(), d(new VersionObject(object))
{ }

Version::~Version()
{
    // If the reference count becomes 0,
    // the shared data object 'VersionObject' is deleted.
}

int Version::id() const
{
    return d->id;
}

QString Version::appid() const
{
    return d->appid;
}

void Version::setAppid(const QString &appid)
{
    d->appid = appid;
}

int Version::majorVersion() const
{
    return d->major_version;
}

void Version::setMajorVersion(int majorVersion)
{
    d->major_version = majorVersion;
}

int Version::minorVersion() const
{
    return d->minor_version;
}

void Version::setMinorVersion(int minorVersion)
{
    d->minor_version = minorVersion;
}

int Version::revision() const
{
    return d->revision;
}

void Version::setRevision(int revision)
{
    d->revision = revision;
}

QString Version::content() const
{
    return d->content;
}

void Version::setContent(const QString &content)
{
    d->content = content;
}

QString Version::help() const
{
    return d->help;
}

void Version::setHelp(const QString &help)
{
    d->help = help;
}

QString Version::downloadUrl() const
{
    return d->download_url;
}

void Version::setDownloadUrl(const QString &downloadUrl)
{
    d->download_url = downloadUrl;
}

QDateTime Version::createdAt() const
{
    return d->created_at;
}

Version &Version::operator=(const Version &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Version Version::create(const QString &appid, int majorVersion, int minorVersion, int revision, const QString &content, const QString &help, const QString &downloadUrl)
{
    VersionObject obj;
    obj.appid = appid;
    obj.major_version = majorVersion;
    obj.minor_version = minorVersion;
    obj.revision = revision;
    obj.content = content;
    obj.help = help;
    obj.download_url = downloadUrl;
    if (!obj.create()) {
        return Version();
    }
    return Version(obj);
}

Version Version::create(const QVariantMap &values)
{
    Version model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Version Version::get(int id)
{
    TSqlORMapper<VersionObject> mapper;
    return Version(mapper.findByPrimaryKey(id));
}

int Version::count()
{
    TSqlORMapper<VersionObject> mapper;
    return mapper.findCount();
}

QList<Version> Version::getAll()
{
    return tfGetModelListByCriteria<Version, VersionObject>(TCriteria());
}

QJsonArray Version::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<VersionObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<VersionObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Version(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Version::modelData()
{
    return d.data();
}

const TModelObject *Version::modelData() const
{
    return d.data();
}
