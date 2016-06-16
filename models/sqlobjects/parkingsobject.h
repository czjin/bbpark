#ifndef PARKINGSOBJECT_H
#define PARKINGSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ParkingsObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString name;
    QString description;
    QString addr;
    QString charge_standard;
    double longitude;
    double latitude;
    int type;
    QString plan_path;
    QString space_start;
    int space_total;
    int space_free;
    int qrcode_id;
    QString memo;
    QDateTime created_at;
    QDateTime updated_at;
    int lock_revision;

    enum PropertyIndex {
        Id = 0,
        Name,
        Description,
        Addr,
        ChargeStandard,
        Longitude,
        Latitude,
        Type,
        PlanPath,
        SpaceStart,
        SpaceTotal,
        SpaceFree,
        QrcodeId,
        Memo,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("parkings"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString name READ getname WRITE setname)
    T_DEFINE_PROPERTY(QString, name)
    Q_PROPERTY(QString description READ getdescription WRITE setdescription)
    T_DEFINE_PROPERTY(QString, description)
    Q_PROPERTY(QString addr READ getaddr WRITE setaddr)
    T_DEFINE_PROPERTY(QString, addr)
    Q_PROPERTY(QString charge_standard READ getcharge_standard WRITE setcharge_standard)
    T_DEFINE_PROPERTY(QString, charge_standard)
    Q_PROPERTY(double longitude READ getlongitude WRITE setlongitude)
    T_DEFINE_PROPERTY(double, longitude)
    Q_PROPERTY(double latitude READ getlatitude WRITE setlatitude)
    T_DEFINE_PROPERTY(double, latitude)
    Q_PROPERTY(int type READ gettype WRITE settype)
    T_DEFINE_PROPERTY(int, type)
    Q_PROPERTY(QString plan_path READ getplan_path WRITE setplan_path)
    T_DEFINE_PROPERTY(QString, plan_path)
    Q_PROPERTY(QString space_start READ getspace_start WRITE setspace_start)
    T_DEFINE_PROPERTY(QString, space_start)
    Q_PROPERTY(int space_total READ getspace_total WRITE setspace_total)
    T_DEFINE_PROPERTY(int, space_total)
    Q_PROPERTY(int space_free READ getspace_free WRITE setspace_free)
    T_DEFINE_PROPERTY(int, space_free)
    Q_PROPERTY(int qrcode_id READ getqrcode_id WRITE setqrcode_id)
    T_DEFINE_PROPERTY(int, qrcode_id)
    Q_PROPERTY(QString memo READ getmemo WRITE setmemo)
    T_DEFINE_PROPERTY(QString, memo)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // PARKINGSOBJECT_H
