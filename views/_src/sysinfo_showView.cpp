#include <QtCore>
#include <TreeFrogView>
#include "sysinfo.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT sysinfo_showView : public TActionView
{
  Q_OBJECT
public:
  sysinfo_showView() : TActionView() { }
  sysinfo_showView(const sysinfo_showView &) : TActionView() { }
  QString toString();
};

QString sysinfo_showView::toString()
{
  responsebody.reserve(2054);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Sysinfo, sysinfo);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Sysinfo</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(sysinfo.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Company</dt><dd>");
  responsebody += THttpUtility::htmlEscape(sysinfo.company());
  responsebody += QLatin1String("</dd><br />\n<dt>Slogan</dt><dd>");
  responsebody += THttpUtility::htmlEscape(sysinfo.slogan());
  responsebody += QLatin1String("</dd><br />\n<dt>Website</dt><dd>");
  responsebody += THttpUtility::htmlEscape(sysinfo.website());
  responsebody += QLatin1String("</dd><br />\n<dt>Contact Hotline</dt><dd>");
  responsebody += THttpUtility::htmlEscape(sysinfo.contactHotline());
  responsebody += QLatin1String("</dd><br />\n<dt>Serv Ver</dt><dd>");
  responsebody += THttpUtility::htmlEscape(sysinfo.servVer());
  responsebody += QLatin1String("</dd><br />\n<dt>App Ver</dt><dd>");
  responsebody += THttpUtility::htmlEscape(sysinfo.appVer());
  responsebody += QLatin1String("</dd><br />\n<dt>Handset Ver</dt><dd>");
  responsebody += THttpUtility::htmlEscape(sysinfo.handsetVer());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(sysinfo.createdAt());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", sysinfo.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(sysinfo_showView)
T_REGISTER_VIEW(sysinfo_showView)

#include "sysinfo_showView.moc"
