#ifndef PARKINGACCOUNTS_H
#define PARKINGACCOUNTS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ParkingAccountsObject;
class QJsonArray;


class T_MODEL_EXPORT ParkingAccounts : public TAbstractModel
{
public:
    ParkingAccounts();
    ParkingAccounts(const ParkingAccounts &other);
    ParkingAccounts(const ParkingAccountsObject &object);
    ~ParkingAccounts();

    int id() const;
    QString accNo() const;
    void setAccNo(const QString &accNo);
    double balance() const;
    void setBalance(double balance);
    int parkingId() const;
    void setParkingId(int parkingId);
    int status() const;
    void setStatus(int status);
    int type() const;
    void setType(int type);
    QString issuer() const;
    void setIssuer(const QString &issuer);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    QString memo() const;
    void setMemo(const QString &memo);
    ParkingAccounts &operator=(const ParkingAccounts &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static ParkingAccounts create(const QString &accNo, double balance, int parkingId, int status, int type, const QString &issuer, const QString &memo);
    static ParkingAccounts create(const QVariantMap &values);
    static ParkingAccounts get(int id);
    static int count();
    static QList<ParkingAccounts> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ParkingAccountsObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(ParkingAccounts)
Q_DECLARE_METATYPE(QList<ParkingAccounts>)

#endif // PARKINGACCOUNTS_H
