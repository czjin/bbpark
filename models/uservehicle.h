#ifndef USERVEHICLE_H
#define USERVEHICLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UserVehicleObject;
class QJsonArray;


class T_MODEL_EXPORT UserVehicle : public TAbstractModel
{
public:
    UserVehicle();
    UserVehicle(const UserVehicle &other);
    UserVehicle(const UserVehicleObject &object);
    ~UserVehicle();

    int id() const;
    int userId() const;
    void setUserId(int userId);
    int vehicleId() const;
    void setVehicleId(int vehicleId);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int lockRevision() const;
    UserVehicle &operator=(const UserVehicle &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static UserVehicle create(int userId, int vehicleId);
    static UserVehicle create(const QVariantMap &values);
    static UserVehicle get(int id);
    static UserVehicle get(int id, int lockRevision);
    static int count();
    static QList<UserVehicle> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<UserVehicleObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(UserVehicle)
Q_DECLARE_METATYPE(QList<UserVehicle>)

#endif // USERVEHICLE_H
