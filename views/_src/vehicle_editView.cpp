#include <QtCore>
#include <TreeFrogView>
#include "vehicle.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT vehicle_editView : public TActionView
{
  Q_OBJECT
public:
  vehicle_editView() : TActionView() { }
  vehicle_editView(const vehicle_editView &) : TActionView() { }
  QString toString();
};

QString vehicle_editView::toString()
{
  responsebody.reserve(2340);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, vehicle);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Vehicle</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", vehicle["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"vehicle[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Plate<br /><input type=\"text\" name=\"vehicle[plate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["plate"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Engine No<br /><input type=\"text\" name=\"vehicle[engineNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["engineNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Frame No<br /><input type=\"text\" name=\"vehicle[frameNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["frameNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Register Time<br /><input type=\"text\" name=\"vehicle[registerTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["registerTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Vehicle Type<br /><input type=\"text\" name=\"vehicle[vehicleType]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicle["vehicleType"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", vehicle["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(vehicle_editView)
T_REGISTER_VIEW(vehicle_editView)

#include "vehicle_editView.moc"
