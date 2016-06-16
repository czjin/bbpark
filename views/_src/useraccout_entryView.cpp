#include <QtCore>
#include <TreeFrogView>
#include "useraccout.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT useraccout_entryView : public TActionView
{
  Q_OBJECT
public:
  useraccout_entryView() : TActionView() { }
  useraccout_entryView(const useraccout_entryView &) : TActionView() { }
  QString toString();
};

QString useraccout_entryView::toString()
{
  responsebody.reserve(1321);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, userAccout);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New User Accout</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>User ID<br /><input name=\"userAccout[userId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(userAccout["userId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Account ID<br /><input name=\"userAccout[accountId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(userAccout["accountId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(useraccout_entryView)
T_REGISTER_VIEW(useraccout_entryView)

#include "useraccout_entryView.moc"
