#ifndef PARKINGS_H
#define PARKINGS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ParkingsObject;
class QJsonArray;


class T_MODEL_EXPORT Parkings : public TAbstractModel
{
public:
    Parkings();
    Parkings(const Parkings &other);
    Parkings(const ParkingsObject &object);
    ~Parkings();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QString description() const;
    void setDescription(const QString &description);
    QString addr() const;
    void setAddr(const QString &addr);
    QString chargeStandard() const;
    void setChargeStandard(const QString &chargeStandard);
    double longitude() const;
    void setLongitude(double longitude);
    double latitude() const;
    void setLatitude(double latitude);
    int type() const;
    void setType(int type);
    QString planPath() const;
    void setPlanPath(const QString &planPath);
    QString spaceStart() const;
    void setSpaceStart(const QString &spaceStart);
    int spaceTotal() const;
    void setSpaceTotal(int spaceTotal);
    int spaceFree() const;
    void setSpaceFree(int spaceFree);
    int qrcodeId() const;
    void setQrcodeId(int qrcodeId);
    QString memo() const;
    void setMemo(const QString &memo);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int lockRevision() const;
    Parkings &operator=(const Parkings &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Parkings create(const QString &name, const QString &description, const QString &addr, const QString &chargeStandard, double longitude, double latitude, int type, const QString &planPath, const QString &spaceStart, int spaceTotal, int spaceFree, int qrcodeId, const QString &memo);
    static Parkings create(const QVariantMap &values);
    static Parkings get(int id);
    static Parkings get(int id, int lockRevision);
    static int count();
    static QList<Parkings> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ParkingsObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Parkings)
Q_DECLARE_METATYPE(QList<Parkings>)

#endif // PARKINGS_H
