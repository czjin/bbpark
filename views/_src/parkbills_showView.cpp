#include <QtCore>
#include <TreeFrogView>
#include "parkbills.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkbills_showView : public TActionView
{
  Q_OBJECT
public:
  parkbills_showView() : TActionView() { }
  parkbills_showView(const parkbills_showView &) : TActionView() { }
  QString toString();
};

QString parkbills_showView::toString()
{
  responsebody.reserve(1655);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(ParkBills, parkBills);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Park Bills</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkBills.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Session ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkBills.sessionId());
  responsebody += QLatin1String("</dd><br />\n<dt>Source</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkBills.source());
  responsebody += QLatin1String("</dd><br />\n<dt>Amount</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkBills.amount());
  responsebody += QLatin1String("</dd><br />\n<dt>Status</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkBills.status());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkBills.createdAt());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", parkBills.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkbills_showView)
T_REGISTER_VIEW(parkbills_showView)

#include "parkbills_showView.moc"
