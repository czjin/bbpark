#include <QtCore>
#include <TreeFrogView>
#include "vehicles.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT vehicles_entryView : public TActionView
{
  Q_OBJECT
public:
  vehicles_entryView() : TActionView() { }
  vehicles_entryView(const vehicles_entryView &) : TActionView() { }
  QString toString();
};

QString vehicles_entryView::toString()
{
  responsebody.reserve(1925);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, vehicles);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Vehicles</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Plate<br /><input name=\"vehicles[plate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicles["plate"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Engine No<br /><input name=\"vehicles[engineNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicles["engineNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Frame No<br /><input name=\"vehicles[frameNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicles["frameNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Register Time<br /><input name=\"vehicles[registerTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicles["registerTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Vehicle Type<br /><input name=\"vehicles[vehicleType]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicles["vehicleType"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(vehicles_entryView)
T_REGISTER_VIEW(vehicles_entryView)

#include "vehicles_entryView.moc"
