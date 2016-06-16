#ifndef USERS_H
#define USERS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UsersObject;
class QJsonArray;


class T_MODEL_EXPORT Users : public TAbstractModel
{
public:
    Users();
    Users(const Users &other);
    Users(const UsersObject &object);
    ~Users();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QString code() const;
    void setCode(const QString &code);
    QString realName() const;
    void setRealName(const QString &realName);
    int sex() const;
    void setSex(int sex);
    QString avatar() const;
    void setAvatar(const QString &avatar);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int lockRevision() const;
    Users &operator=(const Users &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Users create(const QString &name, const QString &code, const QString &realName, int sex, const QString &avatar);
    static Users create(const QVariantMap &values);
    static Users get(int id);
    static Users get(int id, int lockRevision);
    static int count();
    static QList<Users> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<UsersObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Users)
Q_DECLARE_METATYPE(QList<Users>)

#endif // USERS_H
