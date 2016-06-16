#include <QtCore>
#include <TreeFrogView>
#include "parkings.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkings_indexView : public TActionView
{
  Q_OBJECT
public:
  parkings_indexView() : TActionView() { }
  parkings_indexView(const parkings_indexView &) : TActionView() { }
  QString toString();
};

QString parkings_indexView::toString()
{
  responsebody.reserve(3132);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n\n<h1>Listing Parkings</h1>\n\n");
  responsebody += QVariant(linkTo("New entry", urla("entry"))).toString();
  responsebody += QLatin1String("<br />\n<br />\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>ID</th>\n    <th>Name</th>\n    <th>Description</th>\n    <th>Addr</th>\n    <th>Charge Standard</th>\n    <th>Longitude</th>\n    <th>Latitude</th>\n    <th>Type</th>\n    <th>Plan Path</th>\n    <th>Space Start</th>\n    <th>Space Total</th>\n    <th>Space Free</th>\n    <th>Qrcode ID</th>\n    <th>Memo</th>\n  </tr>\n");
  tfetch(QList<Parkings>, parkingsList);
  for (const auto &i : parkingsList) {;
  responsebody += QLatin1String("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.description());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.addr());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.chargeStandard());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.longitude());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.latitude());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.type());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.planPath());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.spaceStart());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.spaceTotal());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.spaceFree());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.qrcodeId());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.memo());
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

Q_DECLARE_METATYPE(parkings_indexView)
T_REGISTER_VIEW(parkings_indexView)

#include "parkings_indexView.moc"
