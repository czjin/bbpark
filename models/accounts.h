#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AccountsObject;
class QJsonArray;


class T_MODEL_EXPORT Accounts : public TAbstractModel
{
public:
    Accounts();
    Accounts(const Accounts &other);
    Accounts(const AccountsObject &object);
    ~Accounts();

    int id() const;
    QString accNo() const;
    void setAccNo(const QString &accNo);
    int userId() const;
    void setUserId(int userId);
    QString payCode() const;
    void setPayCode(const QString &payCode);
    double balance() const;
    void setBalance(double balance);
    double credit() const;
    void setCredit(double credit);
    double creditAvailable() const;
    void setCreditAvailable(double creditAvailable);
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
    Accounts &operator=(const Accounts &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Accounts create(const QString &accNo, int userId, const QString &payCode, double balance, double credit, double creditAvailable, int status, int type, const QString &issuer, const QString &memo);
    static Accounts create(const QVariantMap &values);
    static Accounts get(int id);
    static int count();
    static QList<Accounts> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<AccountsObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Accounts)
Q_DECLARE_METATYPE(QList<Accounts>)

#endif // ACCOUNTS_H
