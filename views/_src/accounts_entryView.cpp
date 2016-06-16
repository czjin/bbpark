#include <QtCore>
#include <TreeFrogView>
#include "accounts.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT accounts_entryView : public TActionView
{
  Q_OBJECT
public:
  accounts_entryView() : TActionView() { }
  accounts_entryView(const accounts_entryView &) : TActionView() { }
  QString toString();
};

QString accounts_entryView::toString()
{
  responsebody.reserve(2879);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, accounts);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Accounts</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Acc No<br /><input name=\"accounts[accNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accounts["accNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>User ID<br /><input name=\"accounts[userId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accounts["userId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Pay Code<br /><input name=\"accounts[payCode]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accounts["payCode"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Balance<br /><input name=\"accounts[balance]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accounts["balance"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Credit<br /><input name=\"accounts[credit]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accounts["credit"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Credit Available<br /><input name=\"accounts[creditAvailable]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accounts["creditAvailable"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input name=\"accounts[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accounts["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Type<br /><input name=\"accounts[type]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accounts["type"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Issuer<br /><input name=\"accounts[issuer]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accounts["issuer"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Memo<br /><input name=\"accounts[memo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(accounts["memo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(accounts_entryView)
T_REGISTER_VIEW(accounts_entryView)

#include "accounts_entryView.moc"
