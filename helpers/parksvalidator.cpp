#include "parksvalidator.h"
#include <TFormValidator>
#include <QDateTime>

ParksValidator::ParksValidator() : TFormValidator()
{
    // Set the rules below
    //setRule("xxxx", Tf::MaxLength, 20);
    //  :
    setRule("plate", Tf::MinLength, 4);
   	setRule("plate", Tf::MaxLength, 20); 
   	setRule("plate", Tf::Required, true);
}

bool ParksValidator::validate(const QVariantMap &hash)
 {
   bool ret = TFormValidator::validate(hash);  // ←Validation of static rules
   if (ret) {
     QDateTime startDateTime = hash.value("start_time").toDateTime();
     QDateTime endDateTime = hash.value("end_time").toDateTime();
     if (endDateTime < startDateTime) {
       setValidationError("error");
       return false;
     }
   }
   return ret;
 }
