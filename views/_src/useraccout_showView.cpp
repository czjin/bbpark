#include <QtCore>
#include <TreeFrogView>
#include "useraccout.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT useraccout_showView : public TActionView
{
  Q_OBJECT
public:
  useraccout_showView() : TActionView() { }
  useraccout_showView(const useraccout_showView &) : TActionView() { }
  QString toString();
};

QString useraccout_showView::toString()
{
  responsebody.reserve(1686);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(UserAccout, userAccout);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing User Accout</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(userAccout.id());
  responsebody += QLatin1String("</dd><br />\n<dt>User ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(userAccout.userId());
  responsebody += QLatin1String("</dd><br />\n<dt>Account ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(userAccout.accountId());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(userAccout.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(userAccout.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(userAccout.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", userAccout.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(useraccout_showView)
T_REGISTER_VIEW(useraccout_showView)

#include "useraccout_showView.moc"
