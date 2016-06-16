#include <QtCore>
#include <TreeFrogView>
#include "parkcoupon.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkcoupon_entryView : public TActionView
{
  Q_OBJECT
public:
  parkcoupon_entryView() : TActionView() { }
  parkcoupon_entryView(const parkcoupon_entryView &) : TActionView() { }
  QString toString();
};

QString parkcoupon_entryView::toString()
{
  responsebody.reserve(2137);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkCoupon);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Park Coupon</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Coupon No<br /><input name=\"parkCoupon[couponNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkCoupon["couponNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Check Code<br /><input name=\"parkCoupon[checkCode]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkCoupon["checkCode"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Amount<br /><input name=\"parkCoupon[amount]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkCoupon["amount"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input name=\"parkCoupon[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkCoupon["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Use Time<br /><input name=\"parkCoupon[useTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkCoupon["useTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Valid till<br /><input name=\"parkCoupon[validTill]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkCoupon["validTill"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkcoupon_entryView)
T_REGISTER_VIEW(parkcoupon_entryView)

#include "parkcoupon_entryView.moc"
