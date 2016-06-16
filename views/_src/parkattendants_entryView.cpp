#include <QtCore>
#include <TreeFrogView>
#include "parkattendants.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkattendants_entryView : public TActionView
{
  Q_OBJECT
public:
  parkattendants_entryView() : TActionView() { }
  parkattendants_entryView(const parkattendants_entryView &) : TActionView() { }
  QString toString();
};

QString parkattendants_entryView::toString()
{
  responsebody.reserve(1941);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, parkAttendants);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Park Attendants</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Name<br /><input name=\"parkAttendants[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkAttendants["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Code<br /><input name=\"parkAttendants[code]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkAttendants["code"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Real Name<br /><input name=\"parkAttendants[realName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkAttendants["realName"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Sex<br /><input name=\"parkAttendants[sex]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkAttendants["sex"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Avatar<br /><input name=\"parkAttendants[avatar]\" value=\"");
  responsebody += THttpUtility::htmlEscape(parkAttendants["avatar"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkattendants_entryView)
T_REGISTER_VIEW(parkattendants_entryView)

#include "parkattendants_entryView.moc"
