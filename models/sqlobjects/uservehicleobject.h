#ifndef USERVEHICLEOBJECT_H
#define USERVEHICLEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserVehicleObject : public TSqlObject, public QSharedData
{
public:
    int id;
    int user_id;
    int vehicle_id;
    QDateTime created_at;
    QDateTime updated_at;
    int lock_revision;

    enum PropertyIndex {
        Id = 0,
        UserId,
        VehicleId,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("user_vehicle"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(int vehicle_id READ getvehicle_id WRITE setvehicle_id)
    T_DEFINE_PROPERTY(int, vehicle_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // USERVEHICLEOBJECT_H
