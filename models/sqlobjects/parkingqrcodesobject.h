#ifndef PARKINGQRCODESOBJECT_H
#define PARKINGQRCODESOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ParkingQrcodesObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString description;
    QString path;
    QDateTime created_at;
    QDateTime updated_at;
    int lock_revision;

    enum PropertyIndex {
        Id = 0,
        Description,
        Path,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("parking_qrcodes"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString description READ getdescription WRITE setdescription)
    T_DEFINE_PROPERTY(QString, description)
    Q_PROPERTY(QString path READ getpath WRITE setpath)
    T_DEFINE_PROPERTY(QString, path)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // PARKINGQRCODESOBJECT_H
