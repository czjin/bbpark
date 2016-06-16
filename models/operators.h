#ifndef OPERATORS_H
#define OPERATORS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class OperatorsObject;
class QJsonArray;


class T_MODEL_EXPORT Operators : public TAbstractModel
{
public:
    Operators();
    Operators(const Operators &other);
    Operators(const OperatorsObject &object);
    ~Operators();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QString code() const;
    void setCode(const QString &code);
    QDateTime createdAt() const;
    Operators &operator=(const Operators &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Operators create(const QString &name, const QString &code);
    static Operators create(const QVariantMap &values);
    static Operators get(int id);
    static int count();
    static QList<Operators> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<OperatorsObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Operators)
Q_DECLARE_METATYPE(QList<Operators>)

#endif // OPERATORS_H
