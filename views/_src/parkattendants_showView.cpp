#include <QtCore>
#include <TreeFrogView>
#include "parkattendants.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT parkattendants_showView : public TActionView
{
  Q_OBJECT
public:
  parkattendants_showView() : TActionView() { }
  parkattendants_showView(const parkattendants_showView &) : TActionView() { }
  QString toString();
};

QString parkattendants_showView::toString()
{
  responsebody.reserve(2123);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(ParkAttendants, parkAttendants);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Park Attendants</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkAttendants.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkAttendants.name());
  responsebody += QLatin1String("</dd><br />\n<dt>Code</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkAttendants.code());
  responsebody += QLatin1String("</dd><br />\n<dt>Real Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkAttendants.realName());
  responsebody += QLatin1String("</dd><br />\n<dt>Sex</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkAttendants.sex());
  responsebody += QLatin1String("</dd><br />\n<dt>Avatar</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkAttendants.avatar());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkAttendants.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkAttendants.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(parkAttendants.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", parkAttendants.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(parkattendants_showView)
T_REGISTER_VIEW(parkattendants_showView)

#include "parkattendants_showView.moc"
