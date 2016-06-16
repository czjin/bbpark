#include <QtCore>
#include <TreeFrogView>
#include "attendantparking.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT attendantparking_editView : public TActionView
{
  Q_OBJECT
public:
  attendantparking_editView() : TActionView() { }
  attendantparking_editView(const attendantparking_editView &) : TActionView() { }
  QString toString();
};

QString attendantparking_editView::toString()
{
  responsebody.reserve(2018);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, attendantParking);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Attendant Parking</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", attendantParking["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"attendantParking[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(attendantParking["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Attendant ID<br /><input type=\"text\" name=\"attendantParking[attendantId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(attendantParking["attendantId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Parking ID<br /><input type=\"text\" name=\"attendantParking[parkingId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(attendantParking["parkingId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input type=\"text\" name=\"attendantParking[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(attendantParking["status"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", attendantParking["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(attendantparking_editView)
T_REGISTER_VIEW(attendantparking_editView)

#include "attendantparking_editView.moc"
