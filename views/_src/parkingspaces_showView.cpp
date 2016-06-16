#include <QtCore>
#include <TreeFrogView>
#include "parkingspaces.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkingspaces_showView : public TActionView
{
  Q_OBJECT
public:
  parkingspaces_showView() : TActionView() { }
  parkingspaces_showView(const parkingspaces_showView &) : TActionView() { }
  QString toString();
};

QString parkingspaces_showView::toString()
{
  responsebody.reserve(1998);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(ParkingSpaces, parkingSpaces);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Parking Spaces</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingSpaces.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Parking ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingSpaces.parkingId());
  responsebody += QLatin1String("</dd><br />\n<dt>Number</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingSpaces.number());
  responsebody += QLatin1String("</dd><br />\n<dt>Status</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingSpaces.status());
  responsebody += QLatin1String("</dd><br />\n<dt>Qrcode Path</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingSpaces.qrcodePath());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingSpaces.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingSpaces.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingSpaces.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", parkingSpaces.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkingspaces_showView)
T_REGISTER_VIEW(parkingspaces_showView)

#include "parkingspaces_showView.moc"
