#include <QtCore>
#include <TreeFrogView>
#include "vehicle.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT vehicle_entryView : public TActionView
{
  Q_OBJECT
public:
  vehicle_entryView() : TActionView() { }
  vehicle_entryView(const vehicle_entryView &) : TActionView() { }
  QString toString();
};

QString vehicle_entryView::toString()
{
  responsebody.reserve(1913);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, vehicle);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Vehicle</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Plate<br /><input name=\"vehicle[plate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["plate"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Engine No<br /><input name=\"vehicle[engineNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["engineNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Frame No<br /><input name=\"vehicle[frameNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["frameNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Register Time<br /><input name=\"vehicle[registerTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["registerTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Vehicle Type<br /><input name=\"vehicle[vehicleType]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["vehicleType"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(vehicle_entryView)
T_REGISTER_VIEW(vehicle_entryView)

#include "vehicle_entryView.moc"
