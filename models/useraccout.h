#ifndef USERACCOUT_H
#define USERACCOUT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UserAccoutObject;
class QJsonArray;


class T_MODEL_EXPORT UserAccout : public TAbstractModel
{
public:
    UserAccout();
    UserAccout(const UserAccout &other);
    UserAccout(const UserAccoutObject &object);
    ~UserAccout();

    int id() const;
    int userId() const;
    void setUserId(int userId);
    int accountId() const;
    void setAccountId(int accountId);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int lockRevision() const;
    UserAccout &operator=(const UserAccout &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static UserAccout create(int userId, int accountId);
    static UserAccout create(const QVariantMap &values);
    static UserAccout get(int id);
    static UserAccout get(int id, int lockRevision);
    static int count();
    static QList<UserAccout> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<UserAccoutObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(UserAccout)
Q_DECLARE_METATYPE(QList<UserAccout>)

#endif // USERACCOUT_H
