#include <QtCore>
#include <TreeFrogView>
#include "accountsrecharge.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT accountsrecharge_showView : public TActionView
{
  Q_OBJECT
public:
  accountsrecharge_showView() : TActionView() { }
  accountsrecharge_showView(const accountsrecharge_showView &) : TActionView() { }
  QString toString();
};

QString accountsrecharge_showView::toString()
{
  responsebody.reserve(1715);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(AccountsRecharge, accountsRecharge);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Accounts Recharge</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accountsRecharge.id());
  responsebody += QLatin1String("</dd><br />\n<dt>User ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accountsRecharge.userId());
  responsebody += QLatin1String("</dd><br />\n<dt>Amount</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accountsRecharge.amount());
  responsebody += QLatin1String("</dd><br />\n<dt>Source</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accountsRecharge.source());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accountsRecharge.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Memo</dt><dd>");
  responsebody += THttpUtility::htmlEscape(accountsRecharge.memo());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", accountsRecharge.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(accountsrecharge_showView)
T_REGISTER_VIEW(accountsrecharge_showView)

#include "accountsrecharge_showView.moc"
