#include <QtCore>
#include <TreeFrogView>
#include "operators.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT operators_editView : public TActionView
{
  Q_OBJECT
public:
  operators_editView() : TActionView() { }
  operators_editView(const operators_editView &) : TActionView() { }
  QString toString();
};

QString operators_editView::toString()
{
  responsebody.reserve(1684);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, operators);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Operators</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", operators["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"operators[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(operators["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Name<br /><input type=\"text\" name=\"operators[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(operators["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Code<br /><input type=\"text\" name=\"operators[code]\" value=\"");
  responsebody += THttpUtility::htmlEscape(operators["code"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", operators["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(operators_editView)
T_REGISTER_VIEW(operators_editView)

#include "operators_editView.moc"
