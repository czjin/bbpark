#ifndef VERSION_H
#define VERSION_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VersionObject;
class QJsonArray;


class T_MODEL_EXPORT Version : public TAbstractModel
{
public:
    Version();
    Version(const Version &other);
    Version(const VersionObject &object);
    ~Version();

    int id() const;
    QString appid() const;
    void setAppid(const QString &appid);
    int majorVersion() const;
    void setMajorVersion(int majorVersion);
    int minorVersion() const;
    void setMinorVersion(int minorVersion);
    int revision() const;
    void setRevision(int revision);
    QString content() const;
    void setContent(const QString &content);
    QString help() const;
    void setHelp(const QString &help);
    QString downloadUrl() const;
    void setDownloadUrl(const QString &downloadUrl);
    QDateTime createdAt() const;
    Version &operator=(const Version &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Version create(const QString &appid, int majorVersion, int minorVersion, int revision, const QString &content, const QString &help, const QString &downloadUrl);
    static Version create(const QVariantMap &values);
    static Version get(int id);
    static int count();
    static QList<Version> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<VersionObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Version)
Q_DECLARE_METATYPE(QList<Version>)

#endif // VERSION_H
