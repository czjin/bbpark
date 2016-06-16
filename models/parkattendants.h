#ifndef PARKATTENDANTS_H
#define PARKATTENDANTS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ParkAttendantsObject;
class QJsonArray;


class T_MODEL_EXPORT ParkAttendants : public TAbstractModel
{
public:
    ParkAttendants();
    ParkAttendants(const ParkAttendants &other);
    ParkAttendants(const ParkAttendantsObject &object);
    ~ParkAttendants();

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
    ParkAttendants &operator=(const ParkAttendants &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static ParkAttendants create(const QString &name, const QString &code, const QString &realName, int sex, const QString &avatar);
    static ParkAttendants create(const QVariantMap &values);
    static ParkAttendants get(int id);
    static ParkAttendants get(int id, int lockRevision);
    static int count();
    static QList<ParkAttendants> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ParkAttendantsObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(ParkAttendants)
Q_DECLARE_METATYPE(QList<ParkAttendants>)

#endif // PARKATTENDANTS_H
