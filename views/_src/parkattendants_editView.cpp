#include <QtCore>
#include <TreeFrogView>
#include "parkattendants.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkattendants_editView : public TActionView
{
  Q_OBJECT
public:
  parkattendants_editView() : TActionView() { }
  parkattendants_editView(const parkattendants_editView &) : TActionView() { }
  QString toString();
};

QString parkattendants_editView::toString()
{
  responsebody.reserve(2396);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkAttendants);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Park Attendants</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", parkAttendants["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"parkAttendants[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkAttendants["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Name<br /><input type=\"text\" name=\"parkAttendants[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkAttendants["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Code<br /><input type=\"text\" name=\"parkAttendants[code]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkAttendants["code"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Real Name<br /><input type=\"text\" name=\"parkAttendants[realName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkAttendants["realName"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Sex<br /><input type=\"text\" name=\"parkAttendants[sex]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkAttendants["sex"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Avatar<br /><input type=\"text\" name=\"parkAttendants[avatar]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkAttendants["avatar"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", parkAttendants["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkattendants_editView)
T_REGISTER_VIEW(parkattendants_editView)

#include "parkattendants_editView.moc"
