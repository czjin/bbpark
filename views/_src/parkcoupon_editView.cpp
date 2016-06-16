#include <QtCore>
#include <TreeFrogView>
#include "parkcoupon.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkcoupon_editView : public TActionView
{
  Q_OBJECT
public:
  parkcoupon_editView() : TActionView() { }
  parkcoupon_editView(const parkcoupon_editView &) : TActionView() { }
  QString toString();
};

QString parkcoupon_editView::toString()
{
  responsebody.reserve(2590);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkCoupon);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Park Coupon</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", parkCoupon["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"parkCoupon[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkCoupon["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Coupon No<br /><input type=\"text\" name=\"parkCoupon[couponNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkCoupon["couponNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Check Code<br /><input type=\"text\" name=\"parkCoupon[checkCode]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkCoupon["checkCode"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Amount<br /><input type=\"text\" name=\"parkCoupon[amount]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkCoupon["amount"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input type=\"text\" name=\"parkCoupon[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkCoupon["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Use Time<br /><input type=\"text\" name=\"parkCoupon[useTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkCoupon["useTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Valid till<br /><input type=\"text\" name=\"parkCoupon[validTill]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkCoupon["validTill"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", parkCoupon["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkcoupon_editView)
T_REGISTER_VIEW(parkcoupon_editView)

#include "parkcoupon_editView.moc"
