#ifndef PARKS_H
#define PARKS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ParksObject;
class QJsonArray;


class T_MODEL_EXPORT Parks : public TAbstractModel
{
public:
    Parks();
    Parks(const Parks &other);
    Parks(const ParksObject &object);
    ~Parks();

    int id() const;
    QString sessionId() const;
    void setSessionId(const QString &sessionId);
    int userId() const;
    void setUserId(int userId);
    int vehicleId() const;
    void setVehicleId(int vehicleId);
    int parkingId() const;
    void setParkingId(int parkingId);
    QString parkingSpaceNo() const;
    void setParkingSpaceNo(const QString &parkingSpaceNo);
    QDateTime startTime() const;
    void setStartTime(const QDateTime &startTime);
    QDateTime endTime() const;
    void setEndTime(const QDateTime &endTime);
    double parkFee() const;
    void setParkFee(double parkFee);
    double prepaid() const;
    void setPrepaid(double prepaid);
    int orderDuration() const;
    void setOrderDuration(int orderDuration);
    int status() const;
    void setStatus(int status);
    int payMode() const;
    void setPayMode(int payMode);
    int paySource() const;
    void setPaySource(int paySource);
    QString qrcodePath() const;
    void setQrcodePath(const QString &qrcodePath);
    QString memo() const;
    void setMemo(const QString &memo);
    Parks &operator=(const Parks &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Parks create(const QString &sessionId, int userId, int vehicleId, int parkingId, const QString &parkingSpaceNo, const QDateTime &startTime, const QDateTime &endTime, double parkFee, double prepaid, int orderDuration, int status, int payMode, int paySource, const QString &qrcodePath, const QString &memo);
    static Parks create(const QVariantMap &values);
    static Parks get(int id);
    static int count();
    static QList<Parks> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ParksObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Parks)
Q_DECLARE_METATYPE(QList<Parks>)

#endif // PARKS_H
