#include <QtCore>
#include <TreeFrogView>
#include "parkings.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkings_editView : public TActionView
{
  Q_OBJECT
public:
  parkings_editView() : TActionView() { }
  parkings_editView(const parkings_editView &) : TActionView() { }
  QString toString();
};

QString parkings_editView::toString()
{
  responsebody.reserve(4066);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkings);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Parkings</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", parkings["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"parkings[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Name<br /><input type=\"text\" name=\"parkings[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Description<br /><input type=\"text\" name=\"parkings[description]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["description"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Addr<br /><input type=\"text\" name=\"parkings[addr]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["addr"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Charge Standard<br /><input type=\"text\" name=\"parkings[chargeStandard]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["chargeStandard"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Longitude<br /><input type=\"text\" name=\"parkings[longitude]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["longitude"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Latitude<br /><input type=\"text\" name=\"parkings[latitude]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["latitude"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Type<br /><input type=\"text\" name=\"parkings[type]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["type"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Plan Path<br /><input type=\"text\" name=\"parkings[planPath]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["planPath"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Space Start<br /><input type=\"text\" name=\"parkings[spaceStart]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["spaceStart"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Space Total<br /><input type=\"text\" name=\"parkings[spaceTotal]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["spaceTotal"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Space Free<br /><input type=\"text\" name=\"parkings[spaceFree]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["spaceFree"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Qrcode ID<br /><input type=\"text\" name=\"parkings[qrcodeId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["qrcodeId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Memo<br /><input type=\"text\" name=\"parkings[memo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkings["memo"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", parkings["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkings_editView)
T_REGISTER_VIEW(parkings_editView)

#include "parkings_editView.moc"
