#include <QtCore>
#include <TreeFrogView>
#include "operatorparking.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT operatorparking_entryView : public TActionView
{
  Q_OBJECT
public:
  operatorparking_entryView() : TActionView() { }
  operatorparking_entryView(const operatorparking_entryView &) : TActionView() { }
  QString toString();
};

QString operatorparking_entryView::toString()
{
  responsebody.reserve(1572);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, operatorParking);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Operator Parking</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Operator ID<br /><input name=\"operatorParking[operatorId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(operatorParking["operatorId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Parking ID<br /><input name=\"operatorParking[parkingId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(operatorParking["parkingId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input name=\"operatorParking[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(operatorParking["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(operatorparking_entryView)
T_REGISTER_VIEW(operatorparking_entryView)

#include "operatorparking_entryView.moc"
