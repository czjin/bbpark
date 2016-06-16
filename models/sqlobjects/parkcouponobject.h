#ifndef PARKCOUPONOBJECT_H
#define PARKCOUPONOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ParkCouponObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString coupon_no;
    QString check_code;
    double amount;
    int status;
    QDateTime created_at;
    QDateTime use_time;
    QDateTime valid_till;

    enum PropertyIndex {
        Id = 0,
        CouponNo,
        CheckCode,
        Amount,
        Status,
        CreatedAt,
        UseTime,
        ValidTill,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("park_coupon"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString coupon_no READ getcoupon_no WRITE setcoupon_no)
    T_DEFINE_PROPERTY(QString, coupon_no)
    Q_PROPERTY(QString check_code READ getcheck_code WRITE setcheck_code)
    T_DEFINE_PROPERTY(QString, check_code)
    Q_PROPERTY(double amount READ getamount WRITE setamount)
    T_DEFINE_PROPERTY(double, amount)
    Q_PROPERTY(int status READ getstatus WRITE setstatus)
    T_DEFINE_PROPERTY(int, status)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime use_time READ getuse_time WRITE setuse_time)
    T_DEFINE_PROPERTY(QDateTime, use_time)
    Q_PROPERTY(QDateTime valid_till READ getvalid_till WRITE setvalid_till)
    T_DEFINE_PROPERTY(QDateTime, valid_till)
};

#endif // PARKCOUPONOBJECT_H
