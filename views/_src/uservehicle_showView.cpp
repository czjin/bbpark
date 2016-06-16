#include <QtCore>
#include <TreeFrogView>
#include "uservehicle.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT uservehicle_showView : public TActionView
{
  Q_OBJECT
public:
  uservehicle_showView() : TActionView() { }
  uservehicle_showView(const uservehicle_showView &) : TActionView() { }
  QString toString();
};

QString uservehicle_showView::toString()
{
  responsebody.reserve(1696);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(UserVehicle, userVehicle);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing User Vehicle</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(userVehicle.id());
  responsebody += QLatin1String("</dd><br />\n<dt>User ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(userVehicle.userId());
  responsebody += QLatin1String("</dd><br />\n<dt>Vehicle ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(userVehicle.vehicleId());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(userVehicle.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(userVehicle.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(userVehicle.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", userVehicle.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(uservehicle_showView)
T_REGISTER_VIEW(uservehicle_showView)

#include "uservehicle_showView.moc"
