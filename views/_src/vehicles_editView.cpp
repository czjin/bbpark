#include <QtCore>
#include <TreeFrogView>
#include "vehicles.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT vehicles_editView : public TActionView
{
  Q_OBJECT
public:
  vehicles_editView() : TActionView() { }
  vehicles_editView(const vehicles_editView &) : TActionView() { }
  QString toString();
};

QString vehicles_editView::toString()
{
  responsebody.reserve(2356);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, vehicles);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Vehicles</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", vehicles["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"vehicles[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicles["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Plate<br /><input type=\"text\" name=\"vehicles[plate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicles["plate"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Engine No<br /><input type=\"text\" name=\"vehicles[engineNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicles["engineNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Frame No<br /><input type=\"text\" name=\"vehicles[frameNo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicles["frameNo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Register Time<br /><input type=\"text\" name=\"vehicles[registerTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicles["registerTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Vehicle Type<br /><input type=\"text\" name=\"vehicles[vehicleType]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vehicles["vehicleType"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", vehicles["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(vehicles_editView)
T_REGISTER_VIEW(vehicles_editView)

#include "vehicles_editView.moc"
