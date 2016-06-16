#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT mailer_mailView : public TActionView
{
  Q_OBJECT
public:
  mailer_mailView() : TActionView() { }
  mailer_mailView(const mailer_mailView &) : TActionView() { }
  QString toString();
};

QString mailer_mailView::toString()
{
  responsebody.reserve(215);
  responsebody += QLatin1String("Subject: ");
  techoex(subject);
  responsebody += QLatin1String("\nFrom: jcz_100@163.com\nTo: ");
  techoex(to);
  responsebody += QLatin1String("\n\nHi,\nThis is a test mail.\n");

  return responsebody;
}

Q_DECLARE_METATYPE(mailer_mailView)
T_REGISTER_VIEW(mailer_mailView)

#include "mailer_mailView.moc"
