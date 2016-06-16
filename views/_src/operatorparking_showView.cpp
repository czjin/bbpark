#include <QtCore>
#include <TreeFrogView>
#include "operatorparking.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT operatorparking_showView : public TActionView
{
  Q_OBJECT
public:
  operatorparking_showView() : TActionView() { }
  operatorparking_showView(const operatorparking_showView &) : TActionView() { }
  QString toString();
};

QString operatorparking_showView::toString()
{
  responsebody.reserve(1731);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(OperatorParking, operatorParking);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Operator Parking</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(operatorParking.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Operator ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(operatorParking.operatorId());
  responsebody += QLatin1String("</dd><br />\n<dt>Parking ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(operatorParking.parkingId());
  responsebody += QLatin1String("</dd><br />\n<dt>Status</dt><dd>");
  responsebody += THttpUtility::htmlEscape(operatorParking.status());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(operatorParking.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(operatorParking.updatedAt());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", operatorParking.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(operatorparking_showView)
T_REGISTER_VIEW(operatorparking_showView)

#include "operatorparking_showView.moc"
