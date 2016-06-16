#ifndef SYSINFOOBJECT_H
#define SYSINFOOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SysinfoObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString company;
    QString slogan;
    QString website;
    QString contact_hotline;
    QString serv_ver;
    QString app_ver;
    QString handset_ver;
    QDateTime created_at;

    enum PropertyIndex {
        Id = 0,
        Company,
        Slogan,
        Website,
        ContactHotline,
        ServVer,
        AppVer,
        HandsetVer,
        CreatedAt,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return -1; }
    QString tableName() const { return QLatin1String("sysinfo"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString company READ getcompany WRITE setcompany)
    T_DEFINE_PROPERTY(QString, company)
    Q_PROPERTY(QString slogan READ getslogan WRITE setslogan)
    T_DEFINE_PROPERTY(QString, slogan)
    Q_PROPERTY(QString website READ getwebsite WRITE setwebsite)
    T_DEFINE_PROPERTY(QString, website)
    Q_PROPERTY(QString contact_hotline READ getcontact_hotline WRITE setcontact_hotline)
    T_DEFINE_PROPERTY(QString, contact_hotline)
    Q_PROPERTY(QString serv_ver READ getserv_ver WRITE setserv_ver)
    T_DEFINE_PROPERTY(QString, serv_ver)
    Q_PROPERTY(QString app_ver READ getapp_ver WRITE setapp_ver)
    T_DEFINE_PROPERTY(QString, app_ver)
    Q_PROPERTY(QString handset_ver READ gethandset_ver WRITE sethandset_ver)
    T_DEFINE_PROPERTY(QString, handset_ver)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
};

#endif // SYSINFOOBJECT_H
