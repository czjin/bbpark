#include <QtCore>
#include <TreeFrogView>
#include "operatorparking.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT operatorparking_indexView : public TActionView
{
  Q_OBJECT
public:
  operatorparking_indexView() : TActionView() { }
  operatorparking_indexView(const operatorparking_indexView &) : TActionView() { }
  QString toString();
};

QString operatorparking_indexView::toString()
{
  responsebody.reserve(1831);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n\n<h1>Listing Operator Parking</h1>\n\n");
  responsebody += QVariant(linkTo("New entry", urla("entry"))).toString();
  responsebody += QLatin1String("<br />\n<br />\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>ID</th>\n    <th>Operator ID</th>\n    <th>Parking ID</th>\n    <th>Status</th>\n  </tr>\n");
  tfetch(QList<OperatorParking>, operatorParkingList);
  for (const auto &i : operatorParkingList) {;
  responsebody += QLatin1String("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.operatorId());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.parkingId());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.status());
  responsebody += QLatin1String("</td>\n    <td>\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", i.id()))).toString();
  responsebody += QLatin1String("\n      ");
  responsebody += QVariant(linkTo("Edit", urla("edit", i.id()))).toString();
  responsebody += QLatin1String("\n      ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QLatin1String("\n    </td>\n  </tr>\n");
  };
  responsebody += QLatin1String("</table>\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(operatorparking_indexView)
T_REGISTER_VIEW(operatorparking_indexView)

#include "operatorparking_indexView.moc"
