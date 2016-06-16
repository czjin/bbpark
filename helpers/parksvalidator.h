#ifndef PARKSVALIDATOR_H
#define PARKSVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT ParksValidator : public TFormValidator
{
public:
    ParksValidator();
    bool validate(const QVariantMap &hash);
};

#endif // PARKSVALIDATOR_H
