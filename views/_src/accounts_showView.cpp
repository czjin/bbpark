#include <QtCore>
#include <TreeFrogView>
#include "accounts.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT accounts_showView : public TActionView
{
  Q_OBJECT
public:
  accounts_showView() : TActionView() { }
  accounts_showView(const accounts_showView &) : TActionView() { }
  QString toString();
};

QString accounts_showView::toString()
{
  responsebody.reserve(2584);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Accounts, accounts);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Accounts</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accounts.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Acc No</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accounts.accNo());
  responsebody += QLatin1String("</dd><br />\n<dt>User ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accounts.userId());
  responsebody += QLatin1String("</dd><br />\n<dt>Pay Code</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accounts.payCode());
  responsebody += QLatin1String("</dd><br />\n<dt>Balance</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accounts.balance());
  responsebody += QLatin1String("</dd><br />\n<dt>Credit</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accounts.credit());
  responsebody += QLatin1String("</dd><br />\n<dt>Credit Available</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accounts.creditAvailable());
  responsebody += QLatin1String("</dd><br />\n<dt>Status</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accounts.status());
  responsebody += QLatin1String("</dd><br />\n<dt>Type</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accounts.type());
  responsebody += QLatin1String("</dd><br />\n<dt>Issuer</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accounts.issuer());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accounts.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accounts.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Memo</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accounts.memo());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", accounts.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(accounts_showView)
T_REGISTER_VIEW(accounts_showView)

#include "accounts_showView.moc"
