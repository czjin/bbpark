#ifndef PARKPREPAYOBJECT_H
#define PARKPREPAYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ParkPrepayObject : public TSqlObject, public QSharedData
{
public:
    int id;
    int user_id;
    QString session_id;
    double prepaid;
    QDateTime created_at;

    enum PropertyIndex {
        Id = 0,
        UserId,
        SessionId,
        Prepaid,
        CreatedAt,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("park_prepay"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QString session_id READ getsession_id WRITE setsession_id)
    T_DEFINE_PROPERTY(QString, session_id)
    Q_PROPERTY(double prepaid READ getprepaid WRITE setprepaid)
    T_DEFINE_PROPERTY(double, prepaid)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
};

#endif // PARKPREPAYOBJECT_H
