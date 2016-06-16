#include <QtCore>
#include <TreeFrogView>
#include "attendantparking.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT attendantparking_showView : public TActionView
{
  Q_OBJECT
public:
  attendantparking_showView() : TActionView() { }
  attendantparking_showView(const attendantparking_showView &) : TActionView() { }
  QString toString();
};

QString attendantparking_showView::toString()
{
  responsebody.reserve(1743);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(AttendantParking, attendantParking);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Attendant Parking</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(attendantParking.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Attendant ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(attendantParking.attendantId());
  responsebody += QLatin1String("</dd><br />\n<dt>Parking ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(attendantParking.parkingId());
  responsebody += QLatin1String("</dd><br />\n<dt>Status</dt><dd>");
  responsebody += THttpUtility::htmlEscape(attendantParking.status());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(attendantParking.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(attendantParking.updatedAt());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", attendantParking.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(attendantparking_showView)
T_REGISTER_VIEW(attendantparking_showView)

#include "attendantparking_showView.moc"
