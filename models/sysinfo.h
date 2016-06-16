#ifndef SYSINFO_H
#define SYSINFO_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SysinfoObject;
class QJsonArray;


class T_MODEL_EXPORT Sysinfo : public TAbstractModel
{
public:
    Sysinfo();
    Sysinfo(const Sysinfo &other);
    Sysinfo(const SysinfoObject &object);
    ~Sysinfo();

    int id() const;
    void setId(int id);
    QString company() const;
    void setCompany(const QString &company);
    QString slogan() const;
    void setSlogan(const QString &slogan);
    QString website() const;
    void setWebsite(const QString &website);
    QString contactHotline() const;
    void setContactHotline(const QString &contactHotline);
    QString servVer() const;
    void setServVer(const QString &servVer);
    QString appVer() const;
    void setAppVer(const QString &appVer);
    QString handsetVer() const;
    void setHandsetVer(const QString &handsetVer);
    QDateTime createdAt() const;
    Sysinfo &operator=(const Sysinfo &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Sysinfo create(int id, const QString &company, const QString &slogan, const QString &website, const QString &contactHotline, const QString &servVer, const QString &appVer, const QString &handsetVer);
    static Sysinfo create(const QVariantMap &values);
    static Sysinfo get(int id);
    static int count();
    static QList<Sysinfo> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<SysinfoObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Sysinfo)
Q_DECLARE_METATYPE(QList<Sysinfo>)

#endif // SYSINFO_H
