#ifndef ATTENDANTPARKING_H
#define ATTENDANTPARKING_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AttendantParkingObject;
class QJsonArray;


class T_MODEL_EXPORT AttendantParking : public TAbstractModel
{
public:
    AttendantParking();
    AttendantParking(const AttendantParking &other);
    AttendantParking(const AttendantParkingObject &object);
    ~AttendantParking();

    int id() const;
    int attendantId() const;
    void setAttendantId(int attendantId);
    int parkingId() const;
    void setParkingId(int parkingId);
    int status() const;
    void setStatus(int status);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    AttendantParking &operator=(const AttendantParking &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static AttendantParking create(int attendantId, int parkingId, int status);
    static AttendantParking create(const QVariantMap &values);
    static AttendantParking get(int id);
    static int count();
    static QList<AttendantParking> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<AttendantParkingObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(AttendantParking)
Q_DECLARE_METATYPE(QList<AttendantParking>)

#endif // ATTENDANTPARKING_H
