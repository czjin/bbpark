#include <QtCore>
#include <TreeFrogView>
#include "parkprepay.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkprepay_entryView : public TActionView
{
  Q_OBJECT
public:
  parkprepay_entryView() : TActionView() { }
  parkprepay_entryView(const parkprepay_entryView &) : TActionView() { }
  QString toString();
};

QString parkprepay_entryView::toString()
{
  responsebody.reserve(1523);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkPrepay);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Park Prepay</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>User ID<br /><input name=\"parkPrepay[userId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkPrepay["userId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Session ID<br /><input name=\"parkPrepay[sessionId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkPrepay["sessionId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Prepaid<br /><input name=\"parkPrepay[prepaid]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkPrepay["prepaid"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkprepay_entryView)
T_REGISTER_VIEW(parkprepay_entryView)

#include "parkprepay_entryView.moc"
