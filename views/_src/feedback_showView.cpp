#include <QtCore>
#include <TreeFrogView>
#include "feedback.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT feedback_showView : public TActionView
{
  Q_OBJECT
public:
  feedback_showView() : TActionView() { }
  feedback_showView(const feedback_showView &) : TActionView() { }
  QString toString();
};

QString feedback_showView::toString()
{
  responsebody.reserve(1506);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Feedback, feedback);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Feedback</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(feedback.id());
  responsebody += QLatin1String("</dd><br />\n<dt>User ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(feedback.userId());
  responsebody += QLatin1String("</dd><br />\n<dt>Content</dt><dd>");
  responsebody += THttpUtility::htmlEscape(feedback.content());
  responsebody += QLatin1String("</dd><br />\n<dt>Voice</dt><dd>");
  responsebody += THttpUtility::htmlEscape(feedback.voice());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(feedback.createdAt());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", feedback.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(feedback_showView)
T_REGISTER_VIEW(feedback_showView)

#include "feedback_showView.moc"
