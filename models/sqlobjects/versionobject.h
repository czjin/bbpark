#ifndef VERSIONOBJECT_H
#define VERSIONOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VersionObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString appid;
    int major_version;
    int minor_version;
    int revision;
    QString content;
    QString help;
    QString download_url;
    QDateTime created_at;

    enum PropertyIndex {
        Id = 0,
        Appid,
        MajorVersion,
        MinorVersion,
        Revision,
        Content,
        Help,
        DownloadUrl,
        CreatedAt,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("version"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString appid READ getappid WRITE setappid)
    T_DEFINE_PROPERTY(QString, appid)
    Q_PROPERTY(int major_version READ getmajor_version WRITE setmajor_version)
    T_DEFINE_PROPERTY(int, major_version)
    Q_PROPERTY(int minor_version READ getminor_version WRITE setminor_version)
    T_DEFINE_PROPERTY(int, minor_version)
    Q_PROPERTY(int revision READ getrevision WRITE setrevision)
    T_DEFINE_PROPERTY(int, revision)
    Q_PROPERTY(QString content READ getcontent WRITE setcontent)
    T_DEFINE_PROPERTY(QString, content)
    Q_PROPERTY(QString help READ gethelp WRITE sethelp)
    T_DEFINE_PROPERTY(QString, help)
    Q_PROPERTY(QString download_url READ getdownload_url WRITE setdownload_url)
    T_DEFINE_PROPERTY(QString, download_url)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
};

#endif // VERSIONOBJECT_H
