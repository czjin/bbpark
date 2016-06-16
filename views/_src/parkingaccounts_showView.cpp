#include <QtCore>
#include <TreeFrogView>
#include "parkingaccounts.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkingaccounts_showView : public TActionView
{
  Q_OBJECT
public:
  parkingaccounts_showView() : TActionView() { }
  parkingaccounts_showView(const parkingaccounts_showView &) : TActionView() { }
  QString toString();
};

QString parkingaccounts_showView::toString()
{
  responsebody.reserve(2271);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(ParkingAccounts, parkingAccounts);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Parking Accounts</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingAccounts.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Acc No</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingAccounts.accNo());
  responsebody += QLatin1String("</dd><br />\n<dt>Balance</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingAccounts.balance());
  responsebody += QLatin1String("</dd><br />\n<dt>Parking ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingAccounts.parkingId());
  responsebody += QLatin1String("</dd><br />\n<dt>Status</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingAccounts.status());
  responsebody += QLatin1String("</dd><br />\n<dt>Type</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingAccounts.type());
  responsebody += QLatin1String("</dd><br />\n<dt>Issuer</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingAccounts.issuer());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingAccounts.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingAccounts.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Memo</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkingAccounts.memo());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", parkingAccounts.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkingaccounts_showView)
T_REGISTER_VIEW(parkingaccounts_showView)

#include "parkingaccounts_showView.moc"
