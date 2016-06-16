#include <QtCore>
#include <TreeFrogView>
#include "accountsrecharge.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT accountsrecharge_entryView : public TActionView
{
  Q_OBJECT
public:
  accountsrecharge_entryView() : TActionView() { }
  accountsrecharge_entryView(const accountsrecharge_entryView &) : TActionView() { }
  QString toString();
};

QString accountsrecharge_entryView::toString()
{
  responsebody.reserve(1763);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, accountsRecharge);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Accounts Recharge</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>User ID<br /><input name=\"accountsRecharge[userId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accountsRecharge["userId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Amount<br /><input name=\"accountsRecharge[amount]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accountsRecharge["amount"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Source<br /><input name=\"accountsRecharge[source]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accountsRecharge["source"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Memo<br /><input name=\"accountsRecharge[memo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accountsRecharge["memo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(accountsrecharge_entryView)
T_REGISTER_VIEW(accountsrecharge_entryView)

#include "accountsrecharge_entryView.moc"
