#include <QtCore>
#include <TreeFrogView>
#include "accountsrecharge.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT accountsrecharge_indexView : public TActionView
{
  Q_OBJECT
public:
  accountsrecharge_indexView() : TActionView() { }
  accountsrecharge_indexView(const accountsrecharge_indexView &) : TActionView() { }
  QString toString();
};

QString accountsrecharge_indexView::toString()
{
  responsebody.reserve(1945);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n\n<h1>Listing Accounts Recharge</h1>\n\n");
  responsebody += QVariant(linkTo("New entry", urla("entry"))).toString();
  responsebody += QLatin1String("<br />\n<br />\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>ID</th>\n    <th>User ID</th>\n    <th>Amount</th>\n    <th>Source</th>\n    <th>Memo</th>\n  </tr>\n");
  tfetch(QList<AccountsRecharge>, accountsRechargeList);
  for (const auto &i : accountsRechargeList) {;
  responsebody += QLatin1String("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.userId());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.amount());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.source());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.memo());
  responsebody += QLatin1String("</td>\n    <td>\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", i.id()))).toString();
  responsebody += QLatin1String("\n      ");
  responsebody += QVariant(linkTo("Edit", urla("edit", i.id()))).toString();
  responsebody += QLatin1String("\n      ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QLatin1String("\n    </td>\n  </tr>\n");
  };
  responsebody += QLatin1String("</table>\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(accountsrecharge_indexView)
T_REGISTER_VIEW(accountsrecharge_indexView)

#include "accountsrecharge_indexView.moc"
