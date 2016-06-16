#include <QtCore>
#include <TreeFrogView>
#include "users.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT users_entryView : public TActionView
{
  Q_OBJECT
public:
  users_entryView() : TActionView() { }
  users_entryView(const users_entryView &) : TActionView() { }
  QString toString();
};

QString users_entryView::toString()
{
  responsebody.reserve(1832);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, users);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Users</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Name<br /><input name=\"users[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(users["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Code<br /><input name=\"users[code]\" value=\"");
  responsebody += THttpUtility::htmlEscape(users["code"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Real Name<br /><input name=\"users[realName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(users["realName"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Sex<br /><input name=\"users[sex]\" value=\"");
  responsebody += THttpUtility::htmlEscape(users["sex"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Avatar<br /><input name=\"users[avatar]\" value=\"");
  responsebody += THttpUtility::htmlEscape(users["avatar"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(users_entryView)
T_REGISTER_VIEW(users_entryView)

#include "users_entryView.moc"
