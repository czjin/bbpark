/************************************************************************
                        JsonUtil.cpp.cpp - Copyright by 重庆

/home/czjin/workspace/SSBT/headings/heading.cpp

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
The original location of this file is /home/czjin/workspace/SSBT/src/JsonUtil.cpp
**************************************************************************/

#include "jsonutil.h"

#include <QJsonDocument>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>
#include <QDebug>
#include "common.h"
#include "Utils.h"

// Constructors/Destructors
//  

JsonUtil::JsonUtil () {
}

JsonUtil::~JsonUtil () { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//
/**
 * @brief JsonUtil::stringfy_json
 * @param nCmd
 * @param pInData
 * @return
 */
QString JsonUtil::stringfy_json(int nCmd, void* pInData)
{

    switch(nCmd)
    {
    //------------------------车主端-------------------------------
    case Common::CMD_APP_REGISTER:
        return s_app_register(pInData);
    case Common::CMD_APP_LOGIN:
        return s_app_login(pInData);
    case Common::CMD_APP_LOGOUT:
        return s_app_logout(pInData);
    case Common::CMD_APP_RESET_PASSWD:
        return s_app_reset_passwd(pInData);
    case Common::CMD_APP_MODIFY_PASSWD:
        return s_app_modify_passwd(pInData);
    case Common::CMD_APP_SET_PAYCODE:
        return s_app_set_paycode(pInData);
    case Common::CMD_APP_RECHARGE:                  //账户充值
        return s_app_recharge(pInData);
    case Common::CMD_APP_GET_RECHARGE_RECORD:       //充值查询
        return s_app_get_recharge_record(pInData);
    case Common::CMD_APP_GET_CREDIT:                //获取信用额度
        return s_app_get_credit(pInData);
    case Common::CMD_APP_PARKING_NEAR:
        return s_app_parking_near(pInData);
    case Common::CMD_APP_PARKING:
        return s_app_parking(pInData);
    case Common::CMD_APP_PARK_CONFIRM:              //停车确认
        return s_app_park_confirm(pInData);
    case Common::CMD_APP_PARK_PREPAY:               //预付
        return s_app_park_prepay(pInData);
    case Common::CMD_APP_PARK_FEE:                  //停车费用计算
        return s_app_park_fee(pInData);
    case Common::CMD_APP_PARK_RESTTIME:
        return s_app_park_resttime(pInData);
    case Common::CMD_APP_PARK_SETTLE:               //停车结算
        return s_app_park_settle(pInData);
    case Common::CMD_APP_GET_PARK_UNPAY:             //停车逃逸
        return s_app_get_park_unpay(pInData);
    case Common::CMD_APP_PARK_PAY_IN_BACK:           //停车补缴
        return s_app_park_pay_in_back(pInData);
    case Common::CMD_APP_GET_PARK_RECORD:            //停车记录
        return s_app_get_park_record(pInData);
    case Common::CMD_APP_CHECK_FOR_UPDATE:           //检查更新
        return s_app_check_for_update(pInData);
    case Common::CMD_APP_GET_SYSINFO:                //系统信息
        return s_app_get_sysinfo(pInData);
    case Common::CMD_APP_FEEDBACK:                   //意见反馈
        return s_app_feedback(pInData);
    case Common::CMD_APP_CALL_ATTENDANT:             //呼叫管理员
        return s_app_call_attendant(pInData);
    case Common::CMD_APP_LOCATE:
        return s_app_locate(pInData);
    case Common::CMD_APP_ADD_VEHICLE:
        return s_app_add_vehicle(pInData);
    case Common::CMD_APP_DEL_VEHICLE:
        return s_app_del_vehicle(pInData);
    case Common::CMD_APP_UPDATE_VEHICLE:
        return s_app_update_vehicle(pInData);
    //------------------------管理员端-------------------------------
    case Common::CMD_HANDSET_REGISTER:               //停车管理员注册
        break;
    case Common::CMD_HANDSET_LOGIN:                  //停车管理员登录
        break;
    case Common::CMD_HANDSET_LOGOUT:                 //停车管理员登出
        break;
    case Common::CMD_HANDSET_ENQUIRY_SPACE:          //查询停车位
        break;
    case Common::CMD_HANDSET_PUSH_SPACEINFO:         //推送车位信息
        break;
    case Common::CMD_HANDSET_BIND_CAR_BAY:           //绑定车牌位
        break;
    case Common::CMD_HANDSET_PARK_CONFIRM:           //停车确认
        break;
    case Common::CMD_HANDSET_PARK_FEE:               //停车费用计算
        break;
    case Common::CMD_HANDSET_PARK_RESTTIME:          //停车剩余时间
        break;
    case Common::CMD_HANDSET_PARK_SETTLE:            //停车结算
        break;
    case Common::CMD_HANDSET_PARK_PAY_IN_BACK:         //停车补缴
        break;
    case Common::CMD_HANDSET_PARK_QUERY:             //查询纪录
        break;
    case Common::CMD_HANDSET_RESP_CALLING:           //呼叫回应
        break;
    default:
        break;
    }
    return "";

}

/**
 * @brief JsonUtil::parse_json
 * @param nCmd
 * @param pInData
 * @param pOutData
 * @return
 */
int JsonUtil::parse_json(int nCmd, QString pInData,void * pOutData)
{
    switch(nCmd)
    {
    //------------------------车主端-------------------------------
    case Common::CMD_APP_REGISTER:
        return p_app_register(pInData,pOutData);
    case Common::CMD_APP_LOGIN:
        return p_app_login(pInData,pOutData);
    case Common::CMD_APP_LOGOUT:
        return p_app_logout(pInData,pOutData);
    case Common::CMD_APP_RESET_PASSWD:
        return p_app_reset_passwd(pInData,pOutData);
    case Common::CMD_APP_MODIFY_PASSWD:
        return p_app_modify_passwd(pInData,pOutData);
    case Common::CMD_APP_SET_PAYCODE:
        return p_app_set_paycode(pInData,pOutData);
    case Common::CMD_APP_RECHARGE:                  //账户充值
        return p_app_recharge(pInData,pOutData);
    case Common::CMD_APP_GET_RECHARGE_RECORD:       //充值查询
        return p_app_get_recharge_record(pInData,pOutData);
    case Common::CMD_APP_GET_CREDIT:                //获取信用额度
        return p_app_get_credit(pInData,pOutData);
    case Common::CMD_APP_PARKING_NEAR:
        return p_app_parking_near(pInData,pOutData);
    case Common::CMD_APP_PARKING:
        return p_app_parking(pInData,pOutData);
    case Common::CMD_APP_PARK_CONFIRM:              //停车确认
        return p_app_park_confirm(pInData,pOutData);
    case Common::CMD_APP_PARK_PREPAY:               //预付
        return p_app_park_prepay(pInData,pOutData);
    case Common::CMD_APP_PARK_FEE:                  //停车费用计算
        return p_app_park_fee(pInData,pOutData);
    case Common::CMD_APP_PARK_RESTTIME:
        return p_app_park_resttime(pInData,pOutData);
    case Common::CMD_APP_PARK_SETTLE:               //停车结算
        return p_app_park_settle(pInData,pOutData);
    case Common::CMD_APP_GET_PARK_UNPAY:               //停车逃逸
        return p_app_get_park_unpay(pInData,pOutData);
    case Common::CMD_APP_PARK_PAY_IN_BACK:            //停车补缴
        return p_app_park_pay_in_back(pInData,pOutData);
    case Common::CMD_APP_GET_PARK_RECORD:                //停车记录
        return p_app_get_park_record(pInData,pOutData);
    case Common::CMD_APP_CHECK_FOR_UPDATE:           //检查更新
        return p_app_check_for_update(pInData,pOutData);
    case Common::CMD_APP_GET_SYSINFO:                //系统信息
        return p_app_get_sysinfo(pInData,pOutData);
    case Common::CMD_APP_FEEDBACK:                   //意见反馈
        return p_app_feedback(pInData,pOutData);
    case Common::CMD_APP_CALL_ATTENDANT:             //呼叫管理员
        return p_app_call_attendant(pInData,pOutData);
    case Common::CMD_APP_ADD_VEHICLE:             //
        return p_app_add_vehicle(pInData,pOutData);
    case Common::CMD_APP_DEL_VEHICLE:             //
        return p_app_del_vehicle(pInData,pOutData);
    case Common::CMD_APP_UPDATE_VEHICLE:             //
        return p_app_update_vehicle(pInData,pOutData);
    //------------------------管理员端-------------------------------
    case Common::CMD_HANDSET_REGISTER:               //停车管理员注册
        break;
    case Common::CMD_HANDSET_LOGIN:                  //停车管理员登录
        break;
    case Common::CMD_HANDSET_LOGOUT:                 //停车管理员登出
        break;
    case Common::CMD_HANDSET_ENQUIRY_SPACE:          //查询停车位
        break;
    case Common::CMD_HANDSET_PUSH_SPACEINFO:         //推送车位信息
        break;
    case Common::CMD_HANDSET_BIND_CAR_BAY:           //绑定车牌位
        break;
    case Common::CMD_HANDSET_PARK_CONFIRM:           //停车确认
        break;
    case Common::CMD_HANDSET_PARK_FEE:               //停车费用计算
        break;
    case Common::CMD_HANDSET_PARK_RESTTIME:          //停车剩余时间
        break;
    case Common::CMD_HANDSET_PARK_SETTLE:            //停车结算
        break;
    case Common::CMD_HANDSET_PARK_PAY_IN_BACK:         //停车补缴
        break;
    case Common::CMD_HANDSET_PARK_QUERY:             //查询纪录
        break;
    case Common::CMD_HANDSET_RESP_CALLING:           //呼叫回应
    default:
        break;
    }
    return 0;

}

/**
 * @brief JsonUtil::s_app_register
 * @param pInData
 */
QString JsonUtil::s_app_register(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_login
 * @param pInData
 */
QString JsonUtil::s_app_login(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_logout
 * @param pInData
 */
QString JsonUtil::s_app_logout(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_reset_passwd
 * @param pInData
 */
QString JsonUtil::s_app_reset_passwd(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_modify_passwd
 * @param pInData
 */
QString JsonUtil::s_app_modify_passwd(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_set_paycode
 * @param pInData
 */
QString JsonUtil::s_app_set_paycode(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_recharge
 * @param pInData
 */
QString JsonUtil::s_app_recharge(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;
    recharge_t* pRecharge;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_get_recharge_record
 * @param pInData
 */
QString JsonUtil::s_app_get_recharge_record(void* pInData)
{
    return "";
}

/**
 * @brief JsonUtil::s_app_get_credit
 * @param pInData
 */
QString JsonUtil::s_app_get_credit(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;
    account_t* pAccount;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    if(pResp->ret==Common::ERR_OK){
        pAccount = (account_t*)pResp->pData;
        json.insert("balance", pAccount->balance);
        json.insert("credit", pAccount->credit);
        json.insert("credit_available", pAccount->credit_available);
    }
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_parking_near
 * @param pInData
 */
QString JsonUtil::s_app_parking_near(void* pInData)
{  
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;
    parking_t* pParking;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_parking
 * @param pInData
 */
QString JsonUtil::s_app_parking(void* pInData)
{   
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;
    parking_t* pParking;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    if(pResp->ret==Common::ERR_OK){
        pParking = (parking_t*)pResp->pData;
        json.insert("id", pParking->id);
        json.insert("name", pParking->name);
        json.insert("description", pParking->description);
        json.insert("addr", pParking->addr);
        json.insert("longitude", pParking->longitude);
        json.insert("latitude", pParking->latitude);
        json.insert("type", pParking->type);
        json.insert("plan_path", pParking->plan_path);
        json.insert("space_start", pParking->space_start);
        json.insert("space_total", pParking->space_total);
        json.insert("space_free", pParking->space_free);
        json.insert("qrcode_id", pParking->qrcode_id);
        json.insert("memo", pParking->memo);
        json.insert("created_at", pParking->created_at);
        json.insert("updated_at", pParking->updated_at);
        json.insert("lock_revision", pParking->lock_revision);
        json.insert("charge_standard", pParking->charge_standard);
    }
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_park_confirm
 * @param pInData
 */
QString JsonUtil::s_app_park_confirm(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;
    park_t* pPark;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    if(pResp->ret==Common::ERR_OK){
        pPark = (park_t*)pResp->pData;
        json.insert("session_id", pPark->session_id);
    }
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_park_prepay
 * @param pInData
 */
QString JsonUtil::s_app_park_prepay(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_park_fee
 * @param pInData
 */
QString JsonUtil::s_app_park_fee(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    if(pResp->ret==Common::ERR_OK)
        json.insert("park_fee", *(float*)pResp->pData);

    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_park_resttime
 * @param pInData
 */
QString JsonUtil::s_app_park_resttime(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;
    park_t* pPark;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    if(pResp->ret==Common::ERR_OK){
        pPark = (park_t*)pResp->pData;
        json.insert("start_time", pPark->start_time);
        json.insert("order_duration", pPark->order_duration);
        json.insert("prepaid", pPark->prepaid);
        json.insert("parking_name", pPark->memo);
    }
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_park_settle
 * @param pInData
 */
QString JsonUtil::s_app_park_settle(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_get_park_unpay
 * @param pInData
 */
QString JsonUtil::s_app_get_park_unpay(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_park_pay_in_back
 * @param pInData
 */
QString JsonUtil::s_app_park_pay_in_back(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_get_park_record
 * @param pInData
 */
QString JsonUtil::s_app_get_park_record(void* pInData)
{
    return "";
}

/**
 * @brief JsonUtil::s_app_check_for_update
 * @param pInData
 */
QString JsonUtil::s_app_check_for_update(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;
    version_t* pVersion;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    if(pResp->ret==Common::ERR_OK){
        pVersion = (version_t*)pResp->pData;
        json.insert("appid", pVersion->appid);
        json.insert("major_version", pVersion->major_version);
        json.insert("minor_version", pVersion->minor_version);
        json.insert("revision", pVersion->revision);
        json.insert("content", pVersion->content);
        json.insert("help", pVersion->help);
        json.insert("download_url", pVersion->download_url);
        json.insert("created_at", pVersion->created_at);
    }
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);

}

/**
 * @brief JsonUtil::s_app_get_sysinfo
 * @param pInData
 */
QString JsonUtil::s_app_get_sysinfo(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;
    sysinfo_t* pSysinfo;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    if(pResp->ret==Common::ERR_OK){
        pSysinfo = (sysinfo_t*)pResp->pData;
        json.insert("company", pSysinfo->company);
        json.insert("slogan", pSysinfo->slogan);
        json.insert("website", pSysinfo->website);
        json.insert("contact_hotline", pSysinfo->contact_hotline);
        json.insert("serv_ver", pSysinfo->serv_ver);
        json.insert("app_ver", pSysinfo->app_ver);
        json.insert("handset_ver", pSysinfo->handset_ver);
        json.insert("created_at", pSysinfo->created_at);
    }
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);

}

/**
 * @brief JsonUtil::s_app_feedback
 * @param pInData
 */
QString JsonUtil::s_app_feedback(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_call_attendant
 * @param pInData
 */
QString JsonUtil::s_app_call_attendant(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_locate
 * @param pInData
 */
QString JsonUtil::s_app_locate(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;
    coordinate_t* pCoordinate;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    if(pInData!=NULL){
        pCoordinate =  (coordinate_t*)pInData;
        json.insert("longitude", pCoordinate->longitude);
        json.insert("latitude", pCoordinate->latitude);
    }
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_add_vehicle()
 * @param pInData
 */
QString JsonUtil::s_app_add_vehicle(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_del_vehicle()
 * @param pInData
 */
QString JsonUtil::s_app_del_vehicle(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

/**
 * @brief JsonUtil::s_app_update_vehicle()
 * @param pInData
 */
QString JsonUtil::s_app_update_vehicle(void* pInData)
{
    Resp* pResp;
    QJsonObject json;
    QJsonDocument document;

    pResp = (Resp*)pInData;
    json.insert("ret", pResp->ret);
    document.setObject(json);
    return document.toJson(QJsonDocument::Compact);
}

//--------------------------------------------------------------------//
/**
 * @brief JsonUtil::p_app_register
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_register(QString pInData,void * pOutData)
{
    register1_t* pRegister;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pRegister = (register1_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pRegister->username = result["username"].toString();
            pRegister->password = result["password"].toString();
            pRegister->verify_code = result["verify_code"].toString();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_login
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_login(QString pInData,void * pOutData)
{
    login_t* pLogin;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pLogin = (login_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pLogin->username = result["username"].toString();
            pLogin->password = result["password"].toString();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_logout
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_logout(QString pInData,void * pOutData)
{
    login_t* pLogin;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pLogin = (login_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pLogin->username = result["username"].toString();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_reset_passwd
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_reset_passwd(QString pInData,void * pOutData)
{
    login_t* pLogin;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pLogin = (login_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pLogin->username = result["username"].toString();
            pLogin->password = result["password"].toString();
            pLogin->check_code = result["check_code"].toString();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_modify_passwod
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_modify_passwd(QString pInData,void * pOutData)
{
    login_t* pLogin;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pLogin = (login_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pLogin->user_id = result["user_id"].toInt();
            pLogin->password = result["password"].toString();
            pLogin->new_pass = result["new_pass"].toString();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_set_paycode
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_set_paycode(QString pInData,void * pOutData)
{
    account_t* pAccount;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pAccount = (account_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pAccount->user_id = result["user_id"].toInt();
            pAccount->pay_code = result["pay_code"].toString();
            pAccount->check_code = result["check_code"].toString();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_recharge
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_recharge(QString pInData,void * pOutData)
{
    recharge_t* pRecharge;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pRecharge = (recharge_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pRecharge->user_id = result["user_id"].toInt();
            pRecharge->source = result["source"].toInt();
            pRecharge->amount = result["amount"].toFloat();
            return 0;
        }
        else if (json.isArray()) {
            return -1;
        }
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_get_recharge_record
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_get_recharge_record(QString pInData,void * pOutData)
{
    recharge_t* pRecharge;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pRecharge = (recharge_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pRecharge->user_id = result["user_id"].toInt();
            return 0;
        }
        else if (json.isArray()) {
            return -1;
        }
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_get_credit
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_get_credit(QString pInData,void * pOutData)
{
    account_t* pAccount;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pAccount = (account_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pAccount->user_id = result["user_id"].toInt();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_parking_near
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_parking_near(QString pInData,void * pOutData)
{
    parking_t* pParking;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pParking = (parking_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pParking->longitude = result["longitude"].toDouble();
            pParking->latitude = result["latitude"].toDouble();
            return 0;
        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;


    return -1;
}

/**
 * @brief JsonUtil::p_app_parking
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_parking(QString pInData,void * pOutData)
{
    parking_t* pParking;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pParking = (parking_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pParking->longitude = result["longitude"].toDouble();
            pParking->latitude = result["latitude"].toDouble();
            return 0;
        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_park_confirm
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_park_confirm(QString pInData,void * pOutData)
{
    Utils utils;
    park_t* pPark;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);
    QString curDateTime= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    pPark = (park_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pPark->session_id = utils.gen_session_id();
            pPark->user_id = result["user_id"].toInt();
            pPark->vehicle_id = result["vehicle_id"].toInt();
            pPark->parking_id = result["parking_id"].toInt();
            pPark->parking_space_no = result["parking_space_no"].toString();
            pPark->pay_mode = result["pay_mode"].toInt();
            pPark->start_time = curDateTime;
            return 0;
        }
        else if (json.isArray()) {
            return -1;
        }
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_park_prepay
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_park_prepay(QString pInData,void * pOutData)
{
    park_t* pPark;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pPark = (park_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pPark->user_id = result["user_id"].toInt();
            pPark->session_id = result["session_id"].toString();
            pPark->order_duration = result["order_duration"].toInt();
            pPark->prepaid = result["prepaid"].toFloat();
            return 0;
        }
        else if (json.isArray()) {
            return -1;
        }
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_park_fee
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_park_fee(QString pInData,void * pOutData)
{
    Utils utils;
    park_t* pPark;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pPark = (park_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pPark->parking_id = result["parking_id"].toInt();
            pPark->start_time = result["start_time"].toString();
            pPark->end_time = result["end_time"].toString();
            pPark->park_fee = utils.cal_park_fee(pPark->parking_id,pPark->start_time,pPark->end_time);
            return 0;
        }
        else if (json.isArray()) {
            return -1;
        }
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_park_resttime
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_park_resttime(QString pInData,void * pOutData)
{
    park_t* pPark;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pPark = (park_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pPark->session_id = result["session_id"].toString();
            return 0;
        }
        else if (json.isArray()) {
            return -1;
        }
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_park_settle
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_park_settle(QString pInData,void * pOutData)
{
    park_t* pPark;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pPark = (park_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pPark->session_id = result["session_id"].toString();
            pPark->park_fee = result["park_fee"].toFloat();
            pPark->user_id = result["user_id"].toInt();
            pPark->pay_source = result["pay_source"].toInt();
            pPark->pay_code = result["pay_code"].toString();
            //pPark->park_fee = utils.cal_park_fee(pPark->parking_id,pPark->start_time,pPark->end_time);
            return 0;
        }
        else if (json.isArray()) {
            return -1;
        }
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_get_park_unpay
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_get_park_unpay(QString pInData,void * pOutData)
{
    park_t* pPark;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pPark = (park_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pPark->user_id = result["user_id"].toInt();
            pPark->start_time = result["start_time"].toString();
            pPark->end_time = result["end_time"].toString();
            return 0;
        }
        else if (json.isArray()) {
            return -1;
        }
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_park_pay_in_back
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_park_pay_in_back(QString pInData,void * pOutData)
{
    park_t* pPark;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pPark = (park_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            return 0;
        }
        else if (json.isArray()) {
            return -1;
        }
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_get_park_record
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_get_park_record(QString pInData,void * pOutData)
{
    park_t* pPark;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pPark = (park_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pPark->user_id = result["user_id"].toInt();
            return 0;
        }
        else if (json.isArray()) {
            return -1;
        }
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_check_for_update
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_check_for_update(QString pInData,void * pOutData)
{
    version_t* pVersion;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pVersion = (version_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pVersion->appid = result["appid"].toString();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_get_sysinfo
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_get_sysinfo(QString pInData,void * pOutData)
{
    sysinfo_t* pSysinfo;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pSysinfo = (sysinfo_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            //result = json.toVariant().toMap();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_feedback
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_feedback(QString pInData,void * pOutData)
{
    feedback_t* pFeedback;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pFeedback = (feedback_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pFeedback->user_id = result["user_id"].toInt();
            pFeedback->content = result["content"].toString();
            pFeedback->voice = result["voice"].toByteArray();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_call_attendant
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_call_attendant(QString pInData,void * pOutData)
{
    call_info_t* pCallInfo;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pCallInfo = (call_info_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pCallInfo->attendant_id = result["attendant_id"].toInt();
            pCallInfo->content = result["content"].toString();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_add_vehicle()
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_add_vehicle(QString pInData,void * pOutData)
{
    vehicle_t* pVehicle;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pVehicle = (vehicle_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pVehicle->vehicle_id = result["vehicle_id"].toInt();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_del_vehicle()
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_del_vehicle(QString pInData,void * pOutData)
{
    vehicle_t* pVehicle;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pVehicle = (vehicle_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pVehicle->vehicle_id = result["vehicle_id"].toInt();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}

/**
 * @brief JsonUtil::p_app_update_vehicle()
 * @param pInData
 * @param pOutData
 */
int JsonUtil::p_app_update_vehicle(QString pInData,void * pOutData)
{
    vehicle_t* pVehicle;
    QVariantMap result;
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(pInData.toUtf8(), &err);

    pVehicle = (vehicle_t*)pOutData;
    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            pVehicle->vehicle_id = result["vehicle_id"].toInt();
            return 0;

        }
        else if (json.isArray())
            return -1;
    }
    else
        return -1;

    return -1;
}
