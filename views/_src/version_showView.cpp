#include <QtCore>
#include <TreeFrogView>
#include "version.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT version_showView : public TActionView
{
  Q_OBJECT
public:
  version_showView() : TActionView() { }
  version_showView(const version_showView &) : TActionView() { }
  QString toString();
};

QString version_showView::toString()
{
  responsebody.reserve(2057);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Version, version);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Version</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(version.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Appid</dt><dd>");
  responsebody += THttpUtility::htmlEscape(version.appid());
  responsebody += QLatin1String("</dd><br />\n<dt>Major Version</dt><dd>");
  responsebody += THttpUtility::htmlEscape(version.majorVersion());
  responsebody += QLatin1String("</dd><br />\n<dt>Minor Version</dt><dd>");
  responsebody += THttpUtility::htmlEscape(version.minorVersion());
  responsebody += QLatin1String("</dd><br />\n<dt>Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(version.revision());
  responsebody += QLatin1String("</dd><br />\n<dt>Content</dt><dd>");
  responsebody += THttpUtility::htmlEscape(version.content());
  responsebody += QLatin1String("</dd><br />\n<dt>Help</dt><dd>");
  responsebody += THttpUtility::htmlEscape(version.help());
  responsebody += QLatin1String("</dd><br />\n<dt>Download Url</dt><dd>");
  responsebody += THttpUtility::htmlEscape(version.downloadUrl());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(version.createdAt());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", version.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(version_showView)
T_REGISTER_VIEW(version_showView)

#include "version_showView.moc"
