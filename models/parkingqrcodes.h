#ifndef PARKINGQRCODES_H
#define PARKINGQRCODES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ParkingQrcodesObject;
class QJsonArray;


class T_MODEL_EXPORT ParkingQrcodes : public TAbstractModel
{
public:
    ParkingQrcodes();
    ParkingQrcodes(const ParkingQrcodes &other);
    ParkingQrcodes(const ParkingQrcodesObject &object);
    ~ParkingQrcodes();

    int id() const;
    QString description() const;
    void setDescription(const QString &description);
    QString path() const;
    void setPath(const QString &path);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int lockRevision() const;
    ParkingQrcodes &operator=(const ParkingQrcodes &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static ParkingQrcodes create(const QString &description, const QString &path);
    static ParkingQrcodes create(const QVariantMap &values);
    static ParkingQrcodes get(int id);
    static ParkingQrcodes get(int id, int lockRevision);
    static int count();
    static QList<ParkingQrcodes> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ParkingQrcodesObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(ParkingQrcodes)
Q_DECLARE_METATYPE(QList<ParkingQrcodes>)

#endif // PARKINGQRCODES_H
