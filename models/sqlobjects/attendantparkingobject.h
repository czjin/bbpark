#ifndef ATTENDANTPARKINGOBJECT_H
#define ATTENDANTPARKINGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AttendantParkingObject : public TSqlObject, public QSharedData
{
public:
    int id;
    int attendant_id;
    int parking_id;
    int status;
    QDateTime created_at;
    QDateTime updated_at;

    enum PropertyIndex {
        Id = 0,
        AttendantId,
        ParkingId,
        Status,
        CreatedAt,
        UpdatedAt,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("attendant_parking"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int attendant_id READ getattendant_id WRITE setattendant_id)
    T_DEFINE_PROPERTY(int, attendant_id)
    Q_PROPERTY(int parking_id READ getparking_id WRITE setparking_id)
    T_DEFINE_PROPERTY(int, parking_id)
    Q_PROPERTY(int status READ getstatus WRITE setstatus)
    T_DEFINE_PROPERTY(int, status)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
};

#endif // ATTENDANTPARKINGOBJECT_H
