#include <QtCore>
#include <TreeFrogView>
#include "operators.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT operators_entryView : public TActionView
{
  Q_OBJECT
public:
  operators_entryView() : TActionView() { }
  operators_entryView(const operators_entryView &) : TActionView() { }
  QString toString();
};

QString operators_entryView::toString()
{
  responsebody.reserve(1291);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, operators);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Operators</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Name<br /><input name=\"operators[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(operators["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Code<br /><input name=\"operators[code]\" value=\"");
  responsebody += THttpUtility::htmlEscape(operators["code"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(operators_entryView)
T_REGISTER_VIEW(operators_entryView)

#include "operators_entryView.moc"
