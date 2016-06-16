#ifndef PARKATTENDANTSOBJECT_H
#define PARKATTENDANTSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ParkAttendantsObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString name;
    QString code;
    QString real_name;
    int sex;
    QString avatar;
    QDateTime created_at;
    QDateTime updated_at;
    int lock_revision;

    enum PropertyIndex {
        Id = 0,
        Name,
        Code,
        RealName,
        Sex,
        Avatar,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("park_attendants"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString name READ getname WRITE setname)
    T_DEFINE_PROPERTY(QString, name)
    Q_PROPERTY(QString code READ getcode WRITE setcode)
    T_DEFINE_PROPERTY(QString, code)
    Q_PROPERTY(QString real_name READ getreal_name WRITE setreal_name)
    T_DEFINE_PROPERTY(QString, real_name)
    Q_PROPERTY(int sex READ getsex WRITE setsex)
    T_DEFINE_PROPERTY(int, sex)
    Q_PROPERTY(QString avatar READ getavatar WRITE setavatar)
    T_DEFINE_PROPERTY(QString, avatar)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // PARKATTENDANTSOBJECT_H
