#include <QtCore>
#include <TreeFrogView>
#include "parkcoupon.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkcoupon_showView : public TActionView
{
  Q_OBJECT
public:
  parkcoupon_showView() : TActionView() { }
  parkcoupon_showView(const parkcoupon_showView &) : TActionView() { }
  QString toString();
};

QString parkcoupon_showView::toString()
{
  responsebody.reserve(1948);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(ParkCoupon, parkCoupon);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Park Coupon</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkCoupon.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Coupon No</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkCoupon.couponNo());
  responsebody += QLatin1String("</dd><br />\n<dt>Check Code</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkCoupon.checkCode());
  responsebody += QLatin1String("</dd><br />\n<dt>Amount</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkCoupon.amount());
  responsebody += QLatin1String("</dd><br />\n<dt>Status</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkCoupon.status());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkCoupon.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Use Time</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkCoupon.useTime());
  responsebody += QLatin1String("</dd><br />\n<dt>Valid till</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkCoupon.validTill());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", parkCoupon.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkcoupon_showView)
T_REGISTER_VIEW(parkcoupon_showView)

#include "parkcoupon_showView.moc"
