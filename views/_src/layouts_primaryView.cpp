#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT layouts_primaryView : public TActionView
{
  Q_OBJECT
public:
  layouts_primaryView() : TActionView() { }
  layouts_primaryView(const layouts_primaryView &) : TActionView() { }
  QString toString();
};

QString layouts_primaryView::toString()
{
  responsebody.reserve(677);
  responsebody += QLatin1String("<!DOCTYPE HTML>\n<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n    <link rel=\"stylesheet\" href=\"../css/bootstrap.min.css\">\n    <script src=\"../js/bootstrap.min.js\"></script>\n</head>\n<body>\n    ");
  responsebody += QVariant(linkTo("Log Out", QUrl("/Session/logout"))).toString();
  responsebody += QLatin1String("\n    ");
  responsebody += QVariant(yield()).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(layouts_primaryView)
T_REGISTER_VIEW(layouts_primaryView)

#include "layouts_primaryView.moc"
