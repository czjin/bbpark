#ifndef PARKSOBJECT_H
#define PARKSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ParksObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString session_id;
    int user_id;
    int vehicle_id;
    int parking_id;
    QString parking_space_no;
    QDateTime start_time;
    QDateTime end_time;
    double park_fee;
    double prepaid;
    int order_duration;
    int status;
    int pay_mode;
    int pay_source;
    QString qrcode_path;
    QString memo;

    enum PropertyIndex {
        Id = 0,
        SessionId,
        UserId,
        VehicleId,
        ParkingId,
        ParkingSpaceNo,
        StartTime,
        EndTime,
        ParkFee,
        Prepaid,
        OrderDuration,
        Status,
        PayMode,
        PaySource,
        QrcodePath,
        Memo,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("parks"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString session_id READ getsession_id WRITE setsession_id)
    T_DEFINE_PROPERTY(QString, session_id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(int vehicle_id READ getvehicle_id WRITE setvehicle_id)
    T_DEFINE_PROPERTY(int, vehicle_id)
    Q_PROPERTY(int parking_id READ getparking_id WRITE setparking_id)
    T_DEFINE_PROPERTY(int, parking_id)
    Q_PROPERTY(QString parking_space_no READ getparking_space_no WRITE setparking_space_no)
    T_DEFINE_PROPERTY(QString, parking_space_no)
    Q_PROPERTY(QDateTime start_time READ getstart_time WRITE setstart_time)
    T_DEFINE_PROPERTY(QDateTime, start_time)
    Q_PROPERTY(QDateTime end_time READ getend_time WRITE setend_time)
    T_DEFINE_PROPERTY(QDateTime, end_time)
    Q_PROPERTY(double park_fee READ getpark_fee WRITE setpark_fee)
    T_DEFINE_PROPERTY(double, park_fee)
    Q_PROPERTY(double prepaid READ getprepaid WRITE setprepaid)
    T_DEFINE_PROPERTY(double, prepaid)
    Q_PROPERTY(int order_duration READ getorder_duration WRITE setorder_duration)
    T_DEFINE_PROPERTY(int, order_duration)
    Q_PROPERTY(int status READ getstatus WRITE setstatus)
    T_DEFINE_PROPERTY(int, status)
    Q_PROPERTY(int pay_mode READ getpay_mode WRITE setpay_mode)
    T_DEFINE_PROPERTY(int, pay_mode)
    Q_PROPERTY(int pay_source READ getpay_source WRITE setpay_source)
    T_DEFINE_PROPERTY(int, pay_source)
    Q_PROPERTY(QString qrcode_path READ getqrcode_path WRITE setqrcode_path)
    T_DEFINE_PROPERTY(QString, qrcode_path)
    Q_PROPERTY(QString memo READ getmemo WRITE setmemo)
    T_DEFINE_PROPERTY(QString, memo)
};

#endif // PARKSOBJECT_H
