#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT layouts_notloginView : public TActionView
{
  Q_OBJECT
public:
  layouts_notloginView() : TActionView() { }
  layouts_notloginView(const layouts_notloginView &) : TActionView() { }
  QString toString();
};

QString layouts_notloginView::toString()
{
  responsebody.reserve(551);
  responsebody += QLatin1String("<!DOCTYPE HTML>\n<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n    <link rel=\"stylesheet\" href=\"../css/bootstrap.min.css\">\n    <script src=\"../js/bootstrap.min.js\"></script>\n</head>\n<body>\n    ");
  responsebody += QVariant(yield()).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(layouts_notloginView)
T_REGISTER_VIEW(layouts_notloginView)

#include "layouts_notloginView.moc"
