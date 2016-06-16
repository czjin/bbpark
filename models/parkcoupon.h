#ifndef PARKCOUPON_H
#define PARKCOUPON_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ParkCouponObject;
class QJsonArray;


class T_MODEL_EXPORT ParkCoupon : public TAbstractModel
{
public:
    ParkCoupon();
    ParkCoupon(const ParkCoupon &other);
    ParkCoupon(const ParkCouponObject &object);
    ~ParkCoupon();

    int id() const;
    QString couponNo() const;
    void setCouponNo(const QString &couponNo);
    QString checkCode() const;
    void setCheckCode(const QString &checkCode);
    double amount() const;
    void setAmount(double amount);
    int status() const;
    void setStatus(int status);
    QDateTime createdAt() const;
    QDateTime useTime() const;
    void setUseTime(const QDateTime &useTime);
    QDateTime validTill() const;
    void setValidTill(const QDateTime &validTill);
    ParkCoupon &operator=(const ParkCoupon &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static ParkCoupon create(const QString &couponNo, const QString &checkCode, double amount, int status, const QDateTime &useTime, const QDateTime &validTill);
    static ParkCoupon create(const QVariantMap &values);
    static ParkCoupon get(int id);
    static int count();
    static QList<ParkCoupon> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ParkCouponObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(ParkCoupon)
Q_DECLARE_METATYPE(QList<ParkCoupon>)

#endif // PARKCOUPON_H
