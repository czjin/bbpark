#ifndef ACCOUNTSOBJECT_H
#define ACCOUNTSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AccountsObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString acc_no;
    int user_id;
    QString pay_code;
    double balance;
    double credit;
    double credit_available;
    int status;
    int type;
    QString issuer;
    QDateTime created_at;
    QDateTime updated_at;
    QString memo;

    enum PropertyIndex {
        Id = 0,
        AccNo,
        UserId,
        PayCode,
        Balance,
        Credit,
        CreditAvailable,
        Status,
        Type,
        Issuer,
        CreatedAt,
        UpdatedAt,
        Memo,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("accounts"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString acc_no READ getacc_no WRITE setacc_no)
    T_DEFINE_PROPERTY(QString, acc_no)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QString pay_code READ getpay_code WRITE setpay_code)
    T_DEFINE_PROPERTY(QString, pay_code)
    Q_PROPERTY(double balance READ getbalance WRITE setbalance)
    T_DEFINE_PROPERTY(double, balance)
    Q_PROPERTY(double credit READ getcredit WRITE setcredit)
    T_DEFINE_PROPERTY(double, credit)
    Q_PROPERTY(double credit_available READ getcredit_available WRITE setcredit_available)
    T_DEFINE_PROPERTY(double, credit_available)
    Q_PROPERTY(int status READ getstatus WRITE setstatus)
    T_DEFINE_PROPERTY(int, status)
    Q_PROPERTY(int type READ gettype WRITE settype)
    T_DEFINE_PROPERTY(int, type)
    Q_PROPERTY(QString issuer READ getissuer WRITE setissuer)
    T_DEFINE_PROPERTY(QString, issuer)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString memo READ getmemo WRITE setmemo)
    T_DEFINE_PROPERTY(QString, memo)
};

#endif // ACCOUNTSOBJECT_H
