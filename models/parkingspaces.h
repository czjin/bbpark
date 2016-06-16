#ifndef PARKINGSPACES_H
#define PARKINGSPACES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ParkingSpacesObject;
class QJsonArray;


class T_MODEL_EXPORT ParkingSpaces : public TAbstractModel
{
public:
    ParkingSpaces();
    ParkingSpaces(const ParkingSpaces &other);
    ParkingSpaces(const ParkingSpacesObject &object);
    ~ParkingSpaces();

    int id() const;
    int parkingId() const;
    void setParkingId(int parkingId);
    QString number() const;
    void setNumber(const QString &number);
    int status() const;
    void setStatus(int status);
    QString qrcodePath() const;
    void setQrcodePath(const QString &qrcodePath);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int lockRevision() const;
    ParkingSpaces &operator=(const ParkingSpaces &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static ParkingSpaces create(int parkingId, const QString &number, int status, const QString &qrcodePath);
    static ParkingSpaces create(const QVariantMap &values);
    static ParkingSpaces get(int id);
    static ParkingSpaces get(int id, int lockRevision);
    static int count();
    static QList<ParkingSpaces> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ParkingSpacesObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(ParkingSpaces)
Q_DECLARE_METATYPE(QList<ParkingSpaces>)

#endif // PARKINGSPACES_H
