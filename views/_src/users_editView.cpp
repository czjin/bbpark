#include <QtCore>
#include <TreeFrogView>
#include "users.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT users_editView : public TActionView
{
  Q_OBJECT
public:
  users_editView() : TActionView() { }
  users_editView(const users_editView &) : TActionView() { }
  QString toString();
};

QString users_editView::toString()
{
  responsebody.reserve(2251);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, users);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Users</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", users["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"users[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(users["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Name<br /><input type=\"text\" name=\"users[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(users["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Code<br /><input type=\"text\" name=\"users[code]\" value=\"");
  responsebody += THttpUtility::htmlEscape(users["code"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Real Name<br /><input type=\"text\" name=\"users[realName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(users["realName"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Sex<br /><input type=\"text\" name=\"users[sex]\" value=\"");
  responsebody += THttpUtility::htmlEscape(users["sex"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Avatar<br /><input type=\"text\" name=\"users[avatar]\" value=\"");
  responsebody += THttpUtility::htmlEscape(users["avatar"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", users["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(users_editView)
T_REGISTER_VIEW(users_editView)

#include "users_editView.moc"
