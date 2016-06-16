#include <QtCore>
#include <TreeFrogView>
#include "users.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT users_showView : public TActionView
{
  Q_OBJECT
public:
  users_showView() : TActionView() { }
  users_showView(const users_showView &) : TActionView() { }
  QString toString();
};

QString users_showView::toString()
{
  responsebody.reserve(2005);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Users, users);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Users</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(users.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(users.name());
  responsebody += QLatin1String("</dd><br />\n<dt>Code</dt><dd>");
  responsebody += THttpUtility::htmlEscape(users.code());
  responsebody += QLatin1String("</dd><br />\n<dt>Real Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(users.realName());
  responsebody += QLatin1String("</dd><br />\n<dt>Sex</dt><dd>");
  responsebody += THttpUtility::htmlEscape(users.sex());
  responsebody += QLatin1String("</dd><br />\n<dt>Avatar</dt><dd>");
  responsebody += THttpUtility::htmlEscape(users.avatar());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(users.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(users.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(users.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", users.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(users_showView)
T_REGISTER_VIEW(users_showView)

#include "users_showView.moc"
