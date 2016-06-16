#include <QtCore>
#include <TreeFrogView>
#include "parkingqrcodes.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkingqrcodes_entryView : public TActionView
{
  Q_OBJECT
public:
  parkingqrcodes_entryView() : TActionView() { }
  parkingqrcodes_entryView(const parkingqrcodes_entryView &) : TActionView() { }
  QString toString();
};

QString parkingqrcodes_entryView::toString()
{
  responsebody.reserve(1343);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkingQrcodes);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Parking Qrcodes</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Description<br /><input name=\"parkingQrcodes[description]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingQrcodes["description"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Path<br /><input name=\"parkingQrcodes[path]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingQrcodes["path"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkingqrcodes_entryView)
T_REGISTER_VIEW(parkingqrcodes_entryView)

#include "parkingqrcodes_entryView.moc"
