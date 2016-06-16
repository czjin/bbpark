#include <QtCore>
#include <TreeFrogView>
#include "parks.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parks_entryView : public TActionView
{
  Q_OBJECT
public:
  parks_entryView() : TActionView() { }
  parks_entryView(const parks_entryView &) : TActionView() { }
  QString toString();
};

QString parks_entryView::toString()
{
  responsebody.reserve(3857);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parks);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Parks</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Session ID<br /><input name=\"parks[sessionId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["sessionId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>User ID<br /><input name=\"parks[userId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["userId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Vehicle ID<br /><input name=\"parks[vehicleId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["vehicleId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Parking ID<br /><input name=\"parks[parkingId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["parkingId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Parking Space No<br /><input name=\"parks[parkingSpaceNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["parkingSpaceNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Start Time<br /><input name=\"parks[startTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["startTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>End Time<br /><input name=\"parks[endTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["endTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Park Fee<br /><input name=\"parks[parkFee]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["parkFee"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Prepaid<br /><input name=\"parks[prepaid]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["prepaid"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Order Duration<br /><input name=\"parks[orderDuration]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["orderDuration"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input name=\"parks[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Pay Mode<br /><input name=\"parks[payMode]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["payMode"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Pay Source<br /><input name=\"parks[paySource]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["paySource"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Qrcode Path<br /><input name=\"parks[qrcodePath]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["qrcodePath"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Memo<br /><input name=\"parks[memo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parks["memo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parks_entryView)
T_REGISTER_VIEW(parks_entryView)

#include "parks_entryView.moc"
