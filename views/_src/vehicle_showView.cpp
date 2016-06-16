#include <QtCore>
#include <TreeFrogView>
#include "vehicle.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT vehicle_showView : public TActionView
{
  Q_OBJECT
public:
  vehicle_showView() : TActionView() { }
  vehicle_showView(const vehicle_showView &) : TActionView() { }
  QString toString();
};

QString vehicle_showView::toString()
{
  responsebody.reserve(2070);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Vehicle, vehicle);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Vehicle</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Plate</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.plate());
  responsebody += QLatin1String("</dd><br />\n<dt>Engine No</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.engineNo());
  responsebody += QLatin1String("</dd><br />\n<dt>Frame No</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.frameNo());
  responsebody += QLatin1String("</dd><br />\n<dt>Register Time</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.registerTime());
  responsebody += QLatin1String("</dd><br />\n<dt>Vehicle Type</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.vehicleType());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", vehicle.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(vehicle_showView)
T_REGISTER_VIEW(vehicle_showView)

#include "vehicle_showView.moc"
