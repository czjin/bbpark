#include <QtCore>
#include <TreeFrogView>
#include "parkingqrcodes.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkingqrcodes_editView : public TActionView
{
  Q_OBJECT
public:
  parkingqrcodes_editView() : TActionView() { }
  parkingqrcodes_editView(const parkingqrcodes_editView &) : TActionView() { }
  QString toString();
};

QString parkingqrcodes_editView::toString()
{
  responsebody.reserve(1756);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkingQrcodes);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Parking Qrcodes</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", parkingQrcodes["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"parkingQrcodes[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingQrcodes["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Description<br /><input type=\"text\" name=\"parkingQrcodes[description]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingQrcodes["description"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Path<br /><input type=\"text\" name=\"parkingQrcodes[path]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkingQrcodes["path"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", parkingQrcodes["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkingqrcodes_editView)
T_REGISTER_VIEW(parkingqrcodes_editView)

#include "parkingqrcodes_editView.moc"
