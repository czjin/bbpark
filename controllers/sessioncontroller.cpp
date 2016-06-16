#include "sessioncontroller.h"
#include "admin.h"
#include <QCryptographicHash>

SessionController::SessionController(const SessionController &)
    : ApplicationController()
{ }

void SessionController::form()
{
    render("form", "notlogin");
}

void SessionController::login()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString password_md5;
    QByteArray bb;
    QString username = httpRequest().formItemValue("username");
    QString password = httpRequest().formItemValue("password");

    bb = QCryptographicHash::hash ( password.toLocal8Bit(), QCryptographicHash::Md5 );
    password_md5.append(bb.toHex());

    Admin admin = Admin::authenticate(username, password_md5);

    if(!admin.isNull()) {
        userLogin(&admin);
        redirect(QUrl("/admin/dashboard"));
    } else {
        QString message = "Login failed";
        texport(message);
        redirect(url("session", "form"));
    }
}

void SessionController::logout()
{
    userLogout();
    redirect(url("session", "form"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(sessioncontroller)
