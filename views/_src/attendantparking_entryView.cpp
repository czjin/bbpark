#include <QtCore>
#include <TreeFrogView>
#include "attendantparking.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT attendantparking_entryView : public TActionView
{
  Q_OBJECT
public:
  attendantparking_entryView() : TActionView() { }
  attendantparking_entryView(const attendantparking_entryView &) : TActionView() { }
  QString toString();
};

QString attendantparking_entryView::toString()
{
  responsebody.reserve(1583);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, attendantParking);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Attendant Parking</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Attendant ID<br /><input name=\"attendantParking[attendantId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(attendantParking["attendantId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Parking ID<br /><input name=\"attendantParking[parkingId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(attendantParking["parkingId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input name=\"attendantParking[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(attendantParking["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(attendantparking_entryView)
T_REGISTER_VIEW(attendantparking_entryView)

#include "attendantparking_entryView.moc"
