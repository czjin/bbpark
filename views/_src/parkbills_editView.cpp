#include <QtCore>
#include <TreeFrogView>
#include "parkbills.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkbills_editView : public TActionView
{
  Q_OBJECT
public:
  parkbills_editView() : TActionView() { }
  parkbills_editView(const parkbills_editView &) : TActionView() { }
  QString toString();
};

QString parkbills_editView::toString()
{
  responsebody.reserve(2129);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkBills);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Park Bills</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", parkBills["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"parkBills[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkBills["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Session ID<br /><input type=\"text\" name=\"parkBills[sessionId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkBills["sessionId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Source<br /><input type=\"text\" name=\"parkBills[source]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkBills["source"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Amount<br /><input type=\"text\" name=\"parkBills[amount]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkBills["amount"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input type=\"text\" name=\"parkBills[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkBills["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", parkBills["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkbills_editView)
T_REGISTER_VIEW(parkbills_editView)

#include "parkbills_editView.moc"
