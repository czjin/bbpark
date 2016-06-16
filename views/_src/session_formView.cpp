#include <QtCore>
#include <TreeFrogView>
#include "admin.h" 
#include "applicationhelper.h"
#include "parksvalidator.h"

class T_VIEW_EXPORT session_formView : public TActionView
{
  Q_OBJECT
public:
  session_formView() : TActionView() { }
  session_formView(const session_formView &) : TActionView() { }
  QString toString();
};

QString session_formView::toString()
{
  responsebody.reserve(4131);
  responsebody += tr("\n<!DOCTYPE html>\n<!--\nThis is a starter template page. Use this page to start your new project from\nscratch. This page gets rid of all links and provides the needed markup only.\n-->\n<html>\n<head>\n  <meta charset=\"utf-8\">\n  <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n  <meta name=\"viewport\" content=\"initial-scale=1.0, user-scalable=no\" />\n  <style type=\"text/css\">\n    body, html,#allmap {width: 100%;height: 100%;overflow: hidden;margin:0;font-family:\"微软雅黑\";}\n  </style>\n  <script type=\"text/javascript\" src=\"http://api.map.baidu.com/api?v=2.0&ak=aX3kBvoTYz4GxzSiviZ26qtD\"></script>\n  <title>帮帮停车管理系统</title>\n  <!-- Tell the browser to be responsive to screen width -->\n  <meta content=\"width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no\" name=\"viewport\">\n  <!-- Bootstrap 3.3.5 -->\n  <link rel=\"stylesheet\" href=\"bootstrap/css/bootstrap.min.css\">\n  <!-- Font Awesome -->\n  <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/font-awesome/4.4.0/css/font-awesome.min.css\">\n  <!-- Ionicons -->\n  <link rel=\"stylesheet\" href=\"https://code.ionicframework.com/ionicons/2.0.1/css/ionicons.min.css\">\n  <!-- Theme style -->\n  <link rel=\"stylesheet\" href=\"dist/css/AdminLTE.min.css\">\n  <!-- AdminLTE Skins. We have chosen the skin-blue for this starter\n        page. However, you can choose any other skin. Make sure you\n        apply the skin class to the body tag so the changes take effect.\n  -->\n  <link rel=\"stylesheet\" href=\"dist/css/skins/skin-yellow.min.css\">\n\n  <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n  <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n  <!--[if lt IE 9]>\n  <script src=\"https://oss.maxcdn.com/html5shiv/3.7.3/html5shiv.min.js\"></script>\n  <script src=\"https://oss.maxcdn.com/respond/1.4.2/respond.min.js\"></script>\n  <![endif]-->\n</head>\n");
    responsebody += QLatin1String("\n<!--\nBODY TAG OPTIONS:\n=================\nApply one or more of the following classes to get the\ndesired effect\n|---------------------------------------------------------|\n| SKINS         | skin-blue                               |\n|               | skin-black                              |\n|               | skin-purple                             |\n|               | skin-yellow                             |\n|               | skin-red                                |\n|               | skin-green                              |\n|---------------------------------------------------------|\n|LAYOUT OPTIONS | fixed                                   |\n|               | layout-boxed                            |\n|               | layout-top-nav                          |\n|               | sidebar-collapse                        |\n|               | sidebar-mini                            |\n|---------------------------------------------------------|\n-->\n<body class=\"hold-transition skin-yellow sidebar-mini\">\n<!--\n<div id=\"allmap\"></div>\n-->\n<div class=\"wrapper\">\n  <!-- Main Header -->\n\n<h1>Login</h1>\n<div style=\"color: red;\">");
  techoex(message);
  responsebody += QLatin1String("</div>\n");
  responsebody += QVariant(formTag(url("session","login"), Tf::Post)).toString();
  responsebody += tr("\n    <p>\n        <label>用户名<br /><input type=\"text\" name=\"username\"/></label>\n    </p>\n    <p>\n      <label>密码<br /><input type=\"password\" name=\"password\"/></label>\n    </p>\n        <input type=\"submit\" text=\"Login\">\n</form>\n\n</div>\n<!-- ./wrapper -->\n\n<!-- REQUIRED JS SCRIPTS -->\n\n<!-- jQuery 2.1.4 -->\n<script src=\"plugins/jQuery/jQuery-2.1.4.min.js\"></script>\n<!-- Bootstrap 3.3.5 -->\n<script src=\"bootstrap/js/bootstrap.min.js\"></script>\n<!-- AdminLTE App -->\n<script src=\"dist/js/app.min.js\"></script>\n\n<!-- Optionally, you can add Slimscroll and FastClick plugins.\n     Both of these plugins are recommended to enhance the\n     user experience. Slimscroll is required when using the\n     fixed layout. -->\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(session_formView)
T_REGISTER_VIEW(session_formView)

#include "session_formView.moc"
