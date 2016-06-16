#include <TreeFrogModel>
#include "feedback.h"
#include "feedbackobject.h"

Feedback::Feedback()
    : TAbstractModel(), d(new FeedbackObject)
{
    d->id = 0;
    d->user_id = 0;
}

Feedback::Feedback(const Feedback &other)
    : TAbstractModel(), d(new FeedbackObject(*other.d))
{ }

Feedback::Feedback(const FeedbackObject &object)
    : TAbstractModel(), d(new FeedbackObject(object))
{ }

Feedback::~Feedback()
{
    // If the reference count becomes 0,
    // the shared data object 'FeedbackObject' is deleted.
}

int Feedback::id() const
{
    return d->id;
}

void Feedback::setId(int id)
{
    d->id = id;
}

int Feedback::userId() const
{
    return d->user_id;
}

void Feedback::setUserId(int userId)
{
    d->user_id = userId;
}

QString Feedback::content() const
{
    return d->content;
}

void Feedback::setContent(const QString &content)
{
    d->content = content;
}

QByteArray Feedback::voice() const
{
    return d->voice;
}

void Feedback::setVoice(const QByteArray &voice)
{
    d->voice = voice;
}

QDateTime Feedback::createdAt() const
{
    return d->created_at;
}

Feedback &Feedback::operator=(const Feedback &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Feedback Feedback::create(int id, int userId, const QString &content, const QByteArray &voice)
{
    FeedbackObject obj;
    obj.id = id;
    obj.user_id = userId;
    obj.content = content;
    obj.voice = voice;
    if (!obj.create()) {
        return Feedback();
    }
    return Feedback(obj);
}

Feedback Feedback::create(const QVariantMap &values)
{
    Feedback model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Feedback Feedback::get(int id)
{
    TSqlORMapper<FeedbackObject> mapper;
    return Feedback(mapper.findByPrimaryKey(id));
}

int Feedback::count()
{
    TSqlORMapper<FeedbackObject> mapper;
    return mapper.findCount();
}

QList<Feedback> Feedback::getAll()
{
    return tfGetModelListByCriteria<Feedback, FeedbackObject>(TCriteria());
}

QJsonArray Feedback::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<FeedbackObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<FeedbackObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Feedback(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Feedback::modelData()
{
    return d.data();
}

const TModelObject *Feedback::modelData() const
{
    return d.data();
}
