#include <TreeFrogModel>
#include "operators.h"
#include "operatorsobject.h"

Operators::Operators()
    : TAbstractModel(), d(new OperatorsObject)
{
    d->id = 0;
}

Operators::Operators(const Operators &other)
    : TAbstractModel(), d(new OperatorsObject(*other.d))
{ }

Operators::Operators(const OperatorsObject &object)
    : TAbstractModel(), d(new OperatorsObject(object))
{ }

Operators::~Operators()
{
    // If the reference count becomes 0,
    // the shared data object 'OperatorsObject' is deleted.
}

int Operators::id() const
{
    return d->id;
}

QString Operators::name() const
{
    return d->name;
}

void Operators::setName(const QString &name)
{
    d->name = name;
}

QString Operators::code() const
{
    return d->code;
}

void Operators::setCode(const QString &code)
{
    d->code = code;
}

QDateTime Operators::createdAt() const
{
    return d->created_at;
}

Operators &Operators::operator=(const Operators &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Operators Operators::create(const QString &name, const QString &code)
{
    OperatorsObject obj;
    obj.name = name;
    obj.code = code;
    if (!obj.create()) {
        return Operators();
    }
    return Operators(obj);
}

Operators Operators::create(const QVariantMap &values)
{
    Operators model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Operators Operators::get(int id)
{
    TSqlORMapper<OperatorsObject> mapper;
    return Operators(mapper.findByPrimaryKey(id));
}

int Operators::count()
{
    TSqlORMapper<OperatorsObject> mapper;
    return mapper.findCount();
}

QList<Operators> Operators::getAll()
{
    return tfGetModelListByCriteria<Operators, OperatorsObject>(TCriteria());
}

QJsonArray Operators::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<OperatorsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<OperatorsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Operators(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Operators::modelData()
{
    return d.data();
}

const TModelObject *Operators::modelData() const
{
    return d.data();
}
