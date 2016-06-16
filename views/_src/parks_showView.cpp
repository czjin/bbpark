#include <QtCore>
#include <TreeFrogView>
#include "parks.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parks_showView : public TActionView
{
  Q_OBJECT
public:
  parks_showView() : TActionView() { }
  parks_showView(const parks_showView &) : TActionView() { }
  QString toString();
};

QString parks_showView::toString()
{
  responsebody.reserve(2975);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Parks, parks);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Parks</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Session ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.sessionId());
  responsebody += QLatin1String("</dd><br />\n<dt>User ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.userId());
  responsebody += QLatin1String("</dd><br />\n<dt>Vehicle ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.vehicleId());
  responsebody += QLatin1String("</dd><br />\n<dt>Parking ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.parkingId());
  responsebody += QLatin1String("</dd><br />\n<dt>Parking Space No</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.parkingSpaceNo());
  responsebody += QLatin1String("</dd><br />\n<dt>Start Time</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.startTime());
  responsebody += QLatin1String("</dd><br />\n<dt>End Time</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.endTime());
  responsebody += QLatin1String("</dd><br />\n<dt>Park Fee</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.parkFee());
  responsebody += QLatin1String("</dd><br />\n<dt>Prepaid</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.prepaid());
  responsebody += QLatin1String("</dd><br />\n<dt>Order Duration</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.orderDuration());
  responsebody += QLatin1String("</dd><br />\n<dt>Status</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.status());
  responsebody += QLatin1String("</dd><br />\n<dt>Pay Mode</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.payMode());
  responsebody += QLatin1String("</dd><br />\n<dt>Pay Source</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.paySource());
  responsebody += QLatin1String("</dd><br />\n<dt>Qrcode Path</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.qrcodePath());
  responsebody += QLatin1String("</dd><br />\n<dt>Memo</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parks.memo());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", parks.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parks_showView)
T_REGISTER_VIEW(parks_showView)

#include "parks_showView.moc"
