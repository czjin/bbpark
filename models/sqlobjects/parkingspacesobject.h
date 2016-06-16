#ifndef PARKINGSPACESOBJECT_H
#define PARKINGSPACESOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ParkingSpacesObject : public TSqlObject, public QSharedData
{
public:
    int id;
    int parking_id;
    QString number;
    int status;
    QString qrcode_path;
    QDateTime created_at;
    QDateTime updated_at;
    int lock_revision;

    enum PropertyIndex {
        Id = 0,
        ParkingId,
        Number,
        Status,
        QrcodePath,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("parking_spaces"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int parking_id READ getparking_id WRITE setparking_id)
    T_DEFINE_PROPERTY(int, parking_id)
    Q_PROPERTY(QString number READ getnumber WRITE setnumber)
    T_DEFINE_PROPERTY(QString, number)
    Q_PROPERTY(int status READ getstatus WRITE setstatus)
    T_DEFINE_PROPERTY(int, status)
    Q_PROPERTY(QString qrcode_path READ getqrcode_path WRITE setqrcode_path)
    T_DEFINE_PROPERTY(QString, qrcode_path)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // PARKINGSPACESOBJECT_H
