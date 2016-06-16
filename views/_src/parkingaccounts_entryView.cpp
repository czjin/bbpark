#include <QtCore>
#include <TreeFrogView>
#include "parkingaccounts.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkingaccounts_entryView : public TActionView
{
  Q_OBJECT
public:
  parkingaccounts_entryView() : TActionView() { }
  parkingaccounts_entryView(const parkingaccounts_entryView &) : TActionView() { }
  QString toString();
};

QString parkingaccounts_entryView::toString()
{
  responsebody.reserve(2384);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkingAccounts);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Parking Accounts</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Acc No<br /><input name=\"parkingAccounts[accNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["accNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Balance<br /><input name=\"parkingAccounts[balance]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["balance"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Parking ID<br /><input name=\"parkingAccounts[parkingId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["parkingId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input name=\"parkingAccounts[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Type<br /><input name=\"parkingAccounts[type]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["type"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Issuer<br /><input name=\"parkingAccounts[issuer]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["issuer"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Memo<br /><input name=\"parkingAccounts[memo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingAccounts["memo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkingaccounts_entryView)
T_REGISTER_VIEW(parkingaccounts_entryView)

#include "parkingaccounts_entryView.moc"
