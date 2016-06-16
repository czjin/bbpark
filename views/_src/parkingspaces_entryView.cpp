#include <QtCore>
#include <TreeFrogView>
#include "parkingspaces.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkingspaces_entryView : public TActionView
{
  Q_OBJECT
public:
  parkingspaces_entryView() : TActionView() { }
  parkingspaces_entryView(const parkingspaces_entryView &) : TActionView() { }
  QString toString();
};

QString parkingspaces_entryView::toString()
{
  responsebody.reserve(1761);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkingSpaces);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Parking Spaces</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Parking ID<br /><input name=\"parkingSpaces[parkingId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingSpaces["parkingId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Number<br /><input name=\"parkingSpaces[number]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingSpaces["number"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input name=\"parkingSpaces[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingSpaces["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Qrcode Path<br /><input name=\"parkingSpaces[qrcodePath]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingSpaces["qrcodePath"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkingspaces_entryView)
T_REGISTER_VIEW(parkingspaces_entryView)

#include "parkingspaces_entryView.moc"
