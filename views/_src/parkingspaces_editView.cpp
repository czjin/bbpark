#include <QtCore>
#include <TreeFrogView>
#include "parkingspaces.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkingspaces_editView : public TActionView
{
  Q_OBJECT
public:
  parkingspaces_editView() : TActionView() { }
  parkingspaces_editView(const parkingspaces_editView &) : TActionView() { }
  QString toString();
};

QString parkingspaces_editView::toString()
{
  responsebody.reserve(2198);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkingSpaces);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Parking Spaces</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", parkingSpaces["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"parkingSpaces[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingSpaces["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Parking ID<br /><input type=\"text\" name=\"parkingSpaces[parkingId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingSpaces["parkingId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Number<br /><input type=\"text\" name=\"parkingSpaces[number]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingSpaces["number"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input type=\"text\" name=\"parkingSpaces[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingSpaces["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Qrcode Path<br /><input type=\"text\" name=\"parkingSpaces[qrcodePath]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingSpaces["qrcodePath"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", parkingSpaces["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkingspaces_editView)
T_REGISTER_VIEW(parkingspaces_editView)

#include "parkingspaces_editView.moc"
