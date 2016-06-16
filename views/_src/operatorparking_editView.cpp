#include <QtCore>
#include <TreeFrogView>
#include "operatorparking.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT operatorparking_editView : public TActionView
{
  Q_OBJECT
public:
  operatorparking_editView() : TActionView() { }
  operatorparking_editView(const operatorparking_editView &) : TActionView() { }
  QString toString();
};

QString operatorparking_editView::toString()
{
  responsebody.reserve(2003);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, operatorParking);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Operator Parking</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", operatorParking["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"operatorParking[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(operatorParking["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Operator ID<br /><input type=\"text\" name=\"operatorParking[operatorId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(operatorParking["operatorId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Parking ID<br /><input type=\"text\" name=\"operatorParking[parkingId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(operatorParking["parkingId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input type=\"text\" name=\"operatorParking[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(operatorParking["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", operatorParking["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(operatorparking_editView)
T_REGISTER_VIEW(operatorparking_editView)

#include "operatorparking_editView.moc"
