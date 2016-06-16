#include <QtCore>
#include <TreeFrogView>
#include "parkprepay.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkprepay_showView : public TActionView
{
  Q_OBJECT
public:
  parkprepay_showView() : TActionView() { }
  parkprepay_showView(const parkprepay_showView &) : TActionView() { }
  QString toString();
};

QString parkprepay_showView::toString()
{
  responsebody.reserve(1534);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(ParkPrepay, parkPrepay);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Park Prepay</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkPrepay.id());
  responsebody += QLatin1String("</dd><br />\n<dt>User ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkPrepay.userId());
  responsebody += QLatin1String("</dd><br />\n<dt>Session ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkPrepay.sessionId());
  responsebody += QLatin1String("</dd><br />\n<dt>Prepaid</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkPrepay.prepaid());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkPrepay.createdAt());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", parkPrepay.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkprepay_showView)
T_REGISTER_VIEW(parkprepay_showView)

#include "parkprepay_showView.moc"
