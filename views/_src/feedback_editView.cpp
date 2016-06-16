#include <QtCore>
#include <TreeFrogView>
#include "feedback.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT feedback_editView : public TActionView
{
  Q_OBJECT
public:
  feedback_editView() : TActionView() { }
  feedback_editView(const feedback_editView &) : TActionView() { }
  QString toString();
};

QString feedback_editView::toString()
{
  responsebody.reserve(1896);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, feedback);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Feedback</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", feedback["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"feedback[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(feedback["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>User ID<br /><input type=\"text\" name=\"feedback[userId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(feedback["userId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Content<br /><input type=\"text\" name=\"feedback[content]\" value=\"");
  responsebody += THttpUtility::htmlEscape(feedback["content"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Voice<br /><input type=\"text\" name=\"feedback[voice]\" value=\"");
  responsebody += THttpUtility::htmlEscape(feedback["voice"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", feedback["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(feedback_editView)
T_REGISTER_VIEW(feedback_editView)

#include "feedback_editView.moc"
