#include <QtCore>
#include <TreeFrogView>
#include "accountsrecharge.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT accountsrecharge_editView : public TActionView
{
  Q_OBJECT
public:
  accountsrecharge_editView() : TActionView() { }
  accountsrecharge_editView(const accountsrecharge_editView &) : TActionView() { }
  QString toString();
};

QString accountsrecharge_editView::toString()
{
  responsebody.reserve(2212);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, accountsRecharge);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Accounts Recharge</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", accountsRecharge["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"accountsRecharge[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accountsRecharge["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>User ID<br /><input type=\"text\" name=\"accountsRecharge[userId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accountsRecharge["userId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Amount<br /><input type=\"text\" name=\"accountsRecharge[amount]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accountsRecharge["amount"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Source<br /><input type=\"text\" name=\"accountsRecharge[source]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accountsRecharge["source"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Memo<br /><input type=\"text\" name=\"accountsRecharge[memo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accountsRecharge["memo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", accountsRecharge["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(accountsrecharge_editView)
T_REGISTER_VIEW(accountsrecharge_editView)

#include "accountsrecharge_editView.moc"
