#ifndef FEEDBACKOBJECT_H
#define FEEDBACKOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT FeedbackObject : public TSqlObject, public QSharedData
{
public:
    int id;
    int user_id;
    QString content;
    QByteArray voice;
    QDateTime created_at;

    enum PropertyIndex {
        Id = 0,
        UserId,
        Content,
        Voice,
        CreatedAt,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return -1; }
    QString tableName() const { return QLatin1String("feedback"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QString content READ getcontent WRITE setcontent)
    T_DEFINE_PROPERTY(QString, content)
    Q_PROPERTY(QByteArray voice READ getvoice WRITE setvoice)
    T_DEFINE_PROPERTY(QByteArray, voice)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
};

#endif // FEEDBACKOBJECT_H
