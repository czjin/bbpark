#ifndef OPERATORSOBJECT_H
#define OPERATORSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT OperatorsObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString name;
    QString code;
    QDateTime created_at;

    enum PropertyIndex {
        Id = 0,
        Name,
        Code,
        CreatedAt,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("operators"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString name READ getname WRITE setname)
    T_DEFINE_PROPERTY(QString, name)
    Q_PROPERTY(QString code READ getcode WRITE setcode)
    T_DEFINE_PROPERTY(QString, code)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
};

#endif // OPERATORSOBJECT_H
