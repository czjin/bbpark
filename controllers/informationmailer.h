#ifndef INFORMATIONMAILER_H
#define INFORMATIONMAILER_H

#include <TActionMailer>


class InformationMailer : public TActionMailer
{
public:
    InformationMailer() { }
    void send();
};

#endif // INFORMATIONMAILER_H
