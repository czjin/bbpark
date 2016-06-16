#include <QtCore>
#include <TreeFrogView>
#include "useraccout.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT useraccout_editView : public TActionView
{
  Q_OBJECT
public:
  useraccout_editView() : TActionView() { }
  useraccout_editView(const useraccout_editView &) : TActionView() { }
  QString toString();
};

QString useraccout_editView::toString()
{
  responsebody.reserve(1718);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, userAccout);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing User Accout</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", userAccout["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"userAccout[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(userAccout["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>User ID<br /><input type=\"text\" name=\"userAccout[userId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(userAccout["userId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Account ID<br /><input type=\"text\" name=\"userAccout[accountId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(userAccout["accountId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", userAccout["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(useraccout_editView)
T_REGISTER_VIEW(useraccout_editView)

#include "useraccout_editView.moc"
