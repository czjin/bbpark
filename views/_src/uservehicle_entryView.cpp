#include <QtCore>
#include <TreeFrogView>
#include "uservehicle.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT uservehicle_entryView : public TActionView
{
  Q_OBJECT
public:
  uservehicle_entryView() : TActionView() { }
  uservehicle_entryView(const uservehicle_entryView &) : TActionView() { }
  QString toString();
};

QString uservehicle_entryView::toString()
{
  responsebody.reserve(1327);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, userVehicle);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New User Vehicle</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>User ID<br /><input name=\"userVehicle[userId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(userVehicle["userId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Vehicle ID<br /><input name=\"userVehicle[vehicleId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(userVehicle["vehicleId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(uservehicle_entryView)
T_REGISTER_VIEW(uservehicle_entryView)

#include "uservehicle_entryView.moc"
