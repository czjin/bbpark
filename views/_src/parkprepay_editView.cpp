#include <QtCore>
#include <TreeFrogView>
#include "parkprepay.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkprepay_editView : public TActionView
{
  Q_OBJECT
public:
  parkprepay_editView() : TActionView() { }
  parkprepay_editView(const parkprepay_editView &) : TActionView() { }
  QString toString();
};

QString parkprepay_editView::toString()
{
  responsebody.reserve(1934);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkPrepay);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Park Prepay</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", parkPrepay["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"parkPrepay[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkPrepay["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>User ID<br /><input type=\"text\" name=\"parkPrepay[userId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkPrepay["userId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Session ID<br /><input type=\"text\" name=\"parkPrepay[sessionId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkPrepay["sessionId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Prepaid<br /><input type=\"text\" name=\"parkPrepay[prepaid]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkPrepay["prepaid"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", parkPrepay["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkprepay_editView)
T_REGISTER_VIEW(parkprepay_editView)

#include "parkprepay_editView.moc"
