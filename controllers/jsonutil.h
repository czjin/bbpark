/************************************************************************
                        JsonUtil.h.h - Copyright by BBHelp parking Technology Co.,Ltd

/home/czjin/workspace/SSBT/headings/heading.h

-->Code Generators searches for heading files based on the file extension
   i.e. it will look for a file name ending in ".h" to include in C++ header
   files, and for a file name ending in ".java" to include in all generated
   java code.
   If you name the file "heading.<extension>", Code Generator will always
   choose this file even if there are other files with the same extension in the
   directory. If you name the file something else, it must be the only one with that
   extension in the directory to guarantee that Code Generator will choose it.

you can use variables in your heading files which are replaced at generation
time. possible variables are : author, date, time, filename and filepath.
just write %variable_name%

This file was generated on 周二 8月 18 2015 at 12:50:13
The original location of this file is /home/czjin/workspace/SSBT/src/JsonUtil.h
**************************************************************************/


#ifndef JSONUTIL_H
#define JSONUTIL_H

#include <QString>


/**
  * class JsonUtil
  * 
  */

class JsonUtil
{
public:

    // Constructors/Destructors
    //  


    /**
     * Empty Constructor
     */
    JsonUtil ();

    /**
     * Empty Destructor
     */
    virtual ~JsonUtil ();

    // Static Public attributes
    //  

    // Public attributes
    //  


    // Public attribute accessor methods
    //  


    // Public attribute accessor methods
    //  



    /**
     * @return QString
     * @param  nCmd
     * @param  pInData
     */
    QString  stringfy_json(int nCmd, void* pInData);


    /**
     * @return int
     * @param  nCmd
     * @param  pInData
     * @param  pOutData
     */
    int parse_json(int nCmd,QString pInData,void* pOutData);

protected:

    // Static Protected attributes
    //  

    // Protected attributes
    //  

public:


    // Protected attribute accessor methods
    //  

protected:

public:


    // Protected attribute accessor methods
    //  

protected:


private:

    // Static Private attributes
    //  

    // Private attributes
    //  

public:


    // Private attribute accessor methods
    //  

private:

public:


    // Private attribute accessor methods
    //  

private:
    QString s_app_register(void* pInData);
    QString s_app_login(void* pInData);
    QString s_app_logout(void* pInData);
    QString s_app_reset_passwd(void* pInData);
    QString s_app_modify_passwd(void* pInData);
    QString s_app_set_paycode(void* pInData);
    QString s_app_recharge(void* pInData);
    QString s_app_get_recharge_record(void* pInData);
    QString s_app_get_credit(void* pInData);
    QString s_app_parking_near(void* pInData);
    QString s_app_parking(void* pInData);
    QString s_app_park_confirm(void* pInData);
    QString s_app_park_prepay(void* pInData);
    QString s_app_park_fee(void* pInData);
    QString s_app_park_resttime(void* pInData);
    QString s_app_park_settle(void* pInData);
    QString s_app_get_park_unpay(void* pInData);
    QString s_app_park_pay_in_back(void* pInData);
    QString s_app_get_park_record(void* pInData);
    QString s_app_check_for_update(void* pInData);
    QString s_app_get_sysinfo(void* pInData);
    QString s_app_feedback(void* pInData);
    QString s_app_call_attendant(void* pInData);  
    QString s_app_locate(void* pInData);
    QString s_app_add_vehicle(void* pInData);
    QString s_app_del_vehicle(void* pInData);
    QString s_app_update_vehicle(void* pInData);

    int p_app_register(QString pInData,void * pOutData);
    int p_app_login(QString pInData,void * pOutData);
    int p_app_logout(QString pInData,void * pOutData);
    int p_app_reset_passwd(QString pInData,void * pOutData);
    int p_app_modify_passwd(QString pInData,void * pOutData);
    int p_app_set_paycode(QString pInData,void * pOutData);
    int p_app_recharge(QString pInData,void * pOutData);
    int p_app_get_recharge_record(QString pInData,void * pOutData);
    int p_app_get_credit(QString pInData,void * pOutData);
    int p_app_parking_near(QString pInData,void * pOutData);
    int p_app_parking(QString pInData,void * pOutData);
    int p_app_park_confirm(QString pInData,void * pOutData);
    int p_app_park_prepay(QString pInData,void * pOutData);
    int p_app_park_fee(QString pInData,void * pOutData);
    int p_app_park_resttime(QString pInData,void * pOutData);
    int p_app_park_settle(QString pInData,void * pOutData);
    int p_app_get_park_unpay(QString pInData,void * pOutData);
    int p_app_park_pay_in_back(QString pInData,void * pOutData);
    int p_app_get_park_record(QString pInData,void * pOutData);
    int p_app_check_for_update(QString pInData,void * pOutData);
    int p_app_get_sysinfo(QString pInData,void * pOutData);
    int p_app_feedback(QString pInData,void * pOutData);
    int p_app_call_attendant(QString pInData,void * pOutData);
    int p_app_add_vehicle(QString pInData,void * pOutData);
    int p_app_del_vehicle(QString pInData,void * pOutData);
    int p_app_update_vehicle(QString pInData,void * pOutData);

};

#endif // JSONUTIL_H
