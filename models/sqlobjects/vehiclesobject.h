#ifndef VEHICLESOBJECT_H
#define VEHICLESOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VehiclesObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString plate;
    QString engine_no;
    QString frame_no;
    QDateTime register_time;
    int vehicle_type;
    QDateTime created_at;
    QDateTime updated_at;
    int lock_revision;

    enum PropertyIndex {
        Id = 0,
        Plate,
        EngineNo,
        FrameNo,
        RegisterTime,
        VehicleType,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("vehicles"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString plate READ getplate WRITE setplate)
    T_DEFINE_PROPERTY(QString, plate)
    Q_PROPERTY(QString engine_no READ getengine_no WRITE setengine_no)
    T_DEFINE_PROPERTY(QString, engine_no)
    Q_PROPERTY(QString frame_no READ getframe_no WRITE setframe_no)
    T_DEFINE_PROPERTY(QString, frame_no)
    Q_PROPERTY(QDateTime register_time READ getregister_time WRITE setregister_time)
    T_DEFINE_PROPERTY(QDateTime, register_time)
    Q_PROPERTY(int vehicle_type READ getvehicle_type WRITE setvehicle_type)
    T_DEFINE_PROPERTY(int, vehicle_type)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // VEHICLESOBJECT_H
