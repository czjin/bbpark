#ifndef ACCOUNTSRECHARGEOBJECT_H
#define ACCOUNTSRECHARGEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AccountsRechargeObject : public TSqlObject, public QSharedData
{
public:
    int id;
    int user_id;
    double amount;
    int source;
    QDateTime created_at;
    QString memo;

    enum PropertyIndex {
        Id = 0,
        UserId,
        Amount,
        Source,
        CreatedAt,
        Memo,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("accounts_recharge"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(double amount READ getamount WRITE setamount)
    T_DEFINE_PROPERTY(double, amount)
    Q_PROPERTY(int source READ getsource WRITE setsource)
    T_DEFINE_PROPERTY(int, source)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString memo READ getmemo WRITE setmemo)
    T_DEFINE_PROPERTY(QString, memo)
};

#endif // ACCOUNTSRECHARGEOBJECT_H
