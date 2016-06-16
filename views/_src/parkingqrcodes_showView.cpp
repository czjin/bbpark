#include <QtCore>
#include <TreeFrogView>
#include "parkingqrcodes.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkingqrcodes_showView : public TActionView
{
  Q_OBJECT
public:
  parkingqrcodes_showView() : TActionView() { }
  parkingqrcodes_showView(const parkingqrcodes_showView &) : TActionView() { }
  QString toString();
};

QString parkingqrcodes_showView::toString()
{
  responsebody.reserve(1724);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(ParkingQrcodes, parkingQrcodes);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Parking Qrcodes</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingQrcodes.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Description</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingQrcodes.description());
  responsebody += QLatin1String("</dd><br />\n<dt>Path</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingQrcodes.path());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingQrcodes.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingQrcodes.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingQrcodes.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", parkingQrcodes.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkingqrcodes_showView)
T_REGISTER_VIEW(parkingqrcodes_showView)

#include "parkingqrcodes_showView.moc"
