#include <QtCore>
#include <TreeFrogView>
#include "parkingaccounts.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkingaccounts_editView : public TActionView
{
  Q_OBJECT
public:
  parkingaccounts_editView() : TActionView() { }
  parkingaccounts_editView(const parkingaccounts_editView &) : TActionView() { }
  QString toString();
};

QString parkingaccounts_editView::toString()
{
  responsebody.reserve(2871);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkingAccounts);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Parking Accounts</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", parkingAccounts["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"parkingAccounts[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Acc No<br /><input type=\"text\" name=\"parkingAccounts[accNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["accNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Balance<br /><input type=\"text\" name=\"parkingAccounts[balance]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["balance"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Parking ID<br /><input type=\"text\" name=\"parkingAccounts[parkingId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["parkingId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input type=\"text\" name=\"parkingAccounts[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Type<br /><input type=\"text\" name=\"parkingAccounts[type]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["type"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Issuer<br /><input type=\"text\" name=\"parkingAccounts[issuer]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["issuer"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Memo<br /><input type=\"text\" name=\"parkingAccounts[memo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["memo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", parkingAccounts["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkingaccounts_editView)
T_REGISTER_VIEW(parkingaccounts_editView)

#include "parkingaccounts_editView.moc"
