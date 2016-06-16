#include <QtCore>
#include <TreeFrogView>
#include "vehicles.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT vehicles_showView : public TActionView
{
  Q_OBJECT
public:
  vehicles_showView() : TActionView() { }
  vehicles_showView(const vehicles_showView &) : TActionView() { }
  QString toString();
};

QString vehicles_showView::toString()
{
  responsebody.reserve(2083);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Vehicles, vehicles);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Vehicles</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicles.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Plate</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicles.plate());
  responsebody += QLatin1String("</dd><br />\n<dt>Engine No</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicles.engineNo());
  responsebody += QLatin1String("</dd><br />\n<dt>Frame No</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicles.frameNo());
  responsebody += QLatin1String("</dd><br />\n<dt>Register Time</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicles.registerTime());
  responsebody += QLatin1String("</dd><br />\n<dt>Vehicle Type</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicles.vehicleType());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicles.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicles.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicles.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", vehicles.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(vehicles_showView)
T_REGISTER_VIEW(vehicles_showView)

#include "vehicles_showView.moc"
