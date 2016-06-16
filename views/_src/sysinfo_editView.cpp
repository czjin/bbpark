#include <QtCore>
#include <TreeFrogView>
#include "sysinfo.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT sysinfo_editView : public TActionView
{
  Q_OBJECT
public:
  sysinfo_editView() : TActionView() { }
  sysinfo_editView(const sysinfo_editView &) : TActionView() { }
  QString toString();
};

QString sysinfo_editView::toString()
{
  responsebody.reserve(2760);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, sysinfo);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Sysinfo</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", sysinfo["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"sysinfo[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(sysinfo["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Company<br /><input type=\"text\" name=\"sysinfo[company]\" value=\"");
  responsebody += THttpUtility::htmlEscape(sysinfo["company"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Slogan<br /><input type=\"text\" name=\"sysinfo[slogan]\" value=\"");
  responsebody += THttpUtility::htmlEscape(sysinfo["slogan"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Website<br /><input type=\"text\" name=\"sysinfo[website]\" value=\"");
  responsebody += THttpUtility::htmlEscape(sysinfo["website"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Contact Hotline<br /><input type=\"text\" name=\"sysinfo[contactHotline]\" value=\"");
  responsebody += THttpUtility::htmlEscape(sysinfo["contactHotline"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Serv Ver<br /><input type=\"text\" name=\"sysinfo[servVer]\" value=\"");
  responsebody += THttpUtility::htmlEscape(sysinfo["servVer"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>App Ver<br /><input type=\"text\" name=\"sysinfo[appVer]\" value=\"");
  responsebody += THttpUtility::htmlEscape(sysinfo["appVer"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Handset Ver<br /><input type=\"text\" name=\"sysinfo[handsetVer]\" value=\"");
  responsebody += THttpUtility::htmlEscape(sysinfo["handsetVer"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", sysinfo["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(sysinfo_editView)
T_REGISTER_VIEW(sysinfo_editView)

#include "sysinfo_editView.moc"
