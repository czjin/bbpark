#ifndef ACCOUNTSRECHARGE_H
#define ACCOUNTSRECHARGE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AccountsRechargeObject;
class QJsonArray;


class T_MODEL_EXPORT AccountsRecharge : public TAbstractModel
{
public:
    AccountsRecharge();
    AccountsRecharge(const AccountsRecharge &other);
    AccountsRecharge(const AccountsRechargeObject &object);
    ~AccountsRecharge();

    int id() const;
    int userId() const;
    void setUserId(int userId);
    double amount() const;
    void setAmount(double amount);
    int source() const;
    void setSource(int source);
    QDateTime createdAt() const;
    QString memo() const;
    void setMemo(const QString &memo);
    AccountsRecharge &operator=(const AccountsRecharge &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static AccountsRecharge create(int userId, double amount, int source, const QString &memo);
    static AccountsRecharge create(const QVariantMap &values);
    static AccountsRecharge get(int id);
    static int count();
    static QList<AccountsRecharge> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<AccountsRechargeObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(AccountsRecharge)
Q_DECLARE_METATYPE(QList<AccountsRecharge>)

#endif // ACCOUNTSRECHARGE_H
