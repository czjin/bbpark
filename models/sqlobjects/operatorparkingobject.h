#ifndef OPERATORPARKINGOBJECT_H
#define OPERATORPARKINGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT OperatorParkingObject : public TSqlObject, public QSharedData
{
public:
    int id;
    int operator_id;
    int parking_id;
    int status;
    QDateTime created_at;
    QDateTime updated_at;

    enum PropertyIndex {
        Id = 0,
        OperatorId,
        ParkingId,
        Status,
        CreatedAt,
        UpdatedAt,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("operator_parking"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int operator_id READ getoperator_id WRITE setoperator_id)
    T_DEFINE_PROPERTY(int, operator_id)
    Q_PROPERTY(int parking_id READ getparking_id WRITE setparking_id)
    T_DEFINE_PROPERTY(int, parking_id)
    Q_PROPERTY(int status READ getstatus WRITE setstatus)
    T_DEFINE_PROPERTY(int, status)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
};

#endif // OPERATORPARKINGOBJECT_H
