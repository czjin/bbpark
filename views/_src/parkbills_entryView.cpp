#include <QtCore>
#include <TreeFrogView>
#include "parkbills.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkbills_entryView : public TActionView
{
  Q_OBJECT
public:
  parkbills_entryView() : TActionView() { }
  parkbills_entryView(const parkbills_entryView &) : TActionView() { }
  QString toString();
};

QString parkbills_entryView::toString()
{
  responsebody.reserve(1708);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkBills);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Park Bills</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Session ID<br /><input name=\"parkBills[sessionId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkBills["sessionId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Source<br /><input name=\"parkBills[source]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkBills["source"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Amount<br /><input name=\"parkBills[amount]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkBills["amount"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input name=\"parkBills[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkBills["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkbills_entryView)
T_REGISTER_VIEW(parkbills_entryView)

#include "parkbills_entryView.moc"
