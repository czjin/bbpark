#include <QtCore>
#include <TreeFrogView>
#include "operators.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT operators_showView : public TActionView
{
  Q_OBJECT
public:
  operators_showView() : TActionView() { }
  operators_showView(const operators_showView &) : TActionView() { }
  QString toString();
};

QString operators_showView::toString()
{
  responsebody.reserve(1373);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Operators, operators);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Operators</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(operators.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(operators.name());
  responsebody += QLatin1String("</dd><br />\n<dt>Code</dt><dd>");
  responsebody += THttpUtility::htmlEscape(operators.code());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(operators.createdAt());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", operators.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(operators_showView)
T_REGISTER_VIEW(operators_showView)

#include "operators_showView.moc"
