#include <QtCore>
#include <TreeFrogView>
#include "version.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT version_entryView : public TActionView
{
  Q_OBJECT
public:
  version_entryView() : TActionView() { }
  version_entryView(const version_entryView &) : TActionView() { }
  QString toString();
};

QString version_entryView::toString()
{
  responsebody.reserve(2310);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, version);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Version</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Appid<br /><input name=\"version[appid]\" value=\"");
  responsebody += THttpUtility::htmlEscape(version["appid"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Major Version<br /><input name=\"version[majorVersion]\" value=\"");
  responsebody += THttpUtility::htmlEscape(version["majorVersion"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Minor Version<br /><input name=\"version[minorVersion]\" value=\"");
  responsebody += THttpUtility::htmlEscape(version["minorVersion"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Revision<br /><input name=\"version[revision]\" value=\"");
  responsebody += THttpUtility::htmlEscape(version["revision"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Content<br /><input name=\"version[content]\" value=\"");
  responsebody += THttpUtility::htmlEscape(version["content"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Help<br /><input name=\"version[help]\" value=\"");
  responsebody += THttpUtility::htmlEscape(version["help"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Download Url<br /><input name=\"version[downloadUrl]\" value=\"");
  responsebody += THttpUtility::htmlEscape(version["downloadUrl"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(version_entryView)
T_REGISTER_VIEW(version_entryView)

#include "version_entryView.moc"
