#include "informationmailer.h"


void InformationMailer::send()
{
    QString to = "jcz_100@163.com";
    texport(to);
    deliver("mail");   // ← mail.erb Mail sent by template
}


