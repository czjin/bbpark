#ifndef PARKBILLSOBJECT_H
#define PARKBILLSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ParkBillsObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString session_id;
    int source;
    double amount;
    int status;
    QDateTime created_at;

    enum PropertyIndex {
        Id = 0,
        SessionId,
        Source,
        Amount,
        Status,
        CreatedAt,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("park_bills"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString session_id READ getsession_id WRITE setsession_id)
    T_DEFINE_PROPERTY(QString, session_id)
    Q_PROPERTY(int source READ getsource WRITE setsource)
    T_DEFINE_PROPERTY(int, source)
    Q_PROPERTY(double amount READ getamount WRITE setamount)
    T_DEFINE_PROPERTY(double, amount)
    Q_PROPERTY(int status READ getstatus WRITE setstatus)
    T_DEFINE_PROPERTY(int, status)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
};

#endif // PARKBILLSOBJECT_H
