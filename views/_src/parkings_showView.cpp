#include <QtCore>
#include <TreeFrogView>
#include "parkings.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkings_showView : public TActionView
{
  Q_OBJECT
public:
  parkings_showView() : TActionView() { }
  parkings_showView(const parkings_showView &) : TActionView() { }
  QString toString();
};

QString parkings_showView::toString()
{
  responsebody.reserve(3165);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Parkings, parkings);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Parkings</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.name());
  responsebody += QLatin1String("</dd><br />\n<dt>Description</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.description());
  responsebody += QLatin1String("</dd><br />\n<dt>Addr</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.addr());
  responsebody += QLatin1String("</dd><br />\n<dt>Charge Standard</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.chargeStandard());
  responsebody += QLatin1String("</dd><br />\n<dt>Longitude</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.longitude());
  responsebody += QLatin1String("</dd><br />\n<dt>Latitude</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.latitude());
  responsebody += QLatin1String("</dd><br />\n<dt>Type</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.type());
  responsebody += QLatin1String("</dd><br />\n<dt>Plan Path</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.planPath());
  responsebody += QLatin1String("</dd><br />\n<dt>Space Start</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.spaceStart());
  responsebody += QLatin1String("</dd><br />\n<dt>Space Total</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.spaceTotal());
  responsebody += QLatin1String("</dd><br />\n<dt>Space Free</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.spaceFree());
  responsebody += QLatin1String("</dd><br />\n<dt>Qrcode ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.qrcodeId());
  responsebody += QLatin1String("</dd><br />\n<dt>Memo</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.memo());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkings.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", parkings.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkings_showView)
T_REGISTER_VIEW(parkings_showView)

#include "parkings_showView.moc"
