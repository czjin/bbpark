#include "parkendpoint.h"
#include <QDebug>
#include <QJsonDocument>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>

#include <TSqlQuery>

#include "common.h"
#include "Utils.h"
#include "xxtea.h"
#include "jsonutil.h"
#include "informationmailer.h"
/*
#include <QTextStream>
#include <QFile>
#include <QIODevice>
*/

#define TOPIC_NAME Common::EndPoint

ParkEndpoint::ParkEndpoint(const ParkEndpoint &)
    : ApplicationEndpoint()
{ }

bool ParkEndpoint::onOpen(const TSession &)
{
    subscribe(TOPIC_NAME);
    //publish(TOPIC_NAME, QString(" [ New person joined ]\n"));
    return true;
}

void ParkEndpoint::onClose(int)
{ 
    unsubscribe(TOPIC_NAME);
    //publish(TOPIC_NAME, QString(" [ A person left ]\n"));
}

void ParkEndpoint::onTextReceived(const QString &text)
{
    //publish(TOPIC_NAME, text);
    Q_UNUSED(text)
}

/**
 * @brief ParkEndpoint::onBinaryReceived
 * @param text
 */
void ParkEndpoint::onBinaryReceived(const QByteArray &text)
{
    int cmd;
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString msg;
    QVariantMap result;
    QJsonParseError err;
    //InformationMailer().send();

    out = (uint8_t*)m_XXTEA.xxtea_decrypt(text.data(),text.length(),Common::key.toLocal8Bit().data(),&nLen);
    msg = QString((char*)out);
    QJsonDocument json = QJsonDocument::fromJson(msg.toUtf8(), &err);

    if (err.error == QJsonParseError::NoError) {
        if (json.isObject()) {
            result = json.toVariant().toMap();
            cmd = result["cmd"].toInt();

            switch(cmd)
            {
            case Common::CMD_APP_REGISTER:                  //注册
                app_register(cmd, msg);
                break;
            case Common::CMD_APP_LOGIN:                     //登陆
                app_login(cmd, msg);
                break;
            case Common::CMD_APP_LOGOUT:                    //登出
                app_logout(cmd, msg);
                break;
            case Common::CMD_APP_RESET_PASSWD:             //重置密码
                app_reset_passwd(cmd, msg);
                break;
            case Common::CMD_APP_MODIFY_PASSWD:             //修改密码
                app_modify_passwd(cmd, msg);
                break;
            case Common::CMD_APP_SET_PAYCODE:               //设置支付密码
                app_set_paycode(cmd, msg);
                break;
            case Common::CMD_APP_RECHARGE:                  //账户充值
                app_recharge(cmd,msg);
                break;
            case Common::CMD_APP_GET_RECHARGE_RECORD:       //查看充值记录
                app_get_recharge_record(cmd,msg);
                break;
            case Common::CMD_APP_GET_CREDIT:                //获取信用额度
                app_get_credit(cmd,msg);
                break;
            case Common::CMD_APP_PARKING_NEAR:              //获取周边停车场
                app_parking_near(cmd,msg);
                break;
            case Common::CMD_APP_PARKING:                   //查询停车场明细
                app_parking(cmd,msg);
                break;
            case Common::CMD_APP_PARK_CONFIRM:              //停车确认
                app_park_confirm(cmd,msg);
                break;
            case Common::CMD_APP_PARK_PREPAY:               //预付
                app_park_prepay(cmd,msg);
                break;
            case Common::CMD_APP_PARK_FEE:                  //停车费用计算
                app_park_fee(cmd,msg);
                break;
            case Common::CMD_APP_PARK_RESTTIME:            //停车剩余时间
                app_park_resttime(cmd,msg);
                break;
            case Common::CMD_APP_PARK_SETTLE:               //停车结算
                app_park_settle(cmd,msg);
                break;
            case Common::CMD_APP_GET_PARK_UNPAY:               //停车逃逸
                app_get_park_unpay(cmd,msg);
                break;
            case Common::CMD_APP_PARK_PAY_IN_BACK:            //停车补缴
                app_park_pay_in_back(cmd,msg);
                break;
            case Common::CMD_APP_GET_PARK_RECORD:               //停车记录
                app_get_park_record(cmd,msg);
                break;  
            case Common::CMD_APP_CHECK_FOR_UPDATE:           //检查更新
                app_check_for_update(cmd,msg);
                break;
            case Common::CMD_APP_GET_SYSINFO:                //系统信息
                app_get_sysinfo(cmd,msg);
                break;
            case Common::CMD_APP_FEEDBACK:                   //意见反馈
                app_feedback(cmd,msg);
                break;
            case Common::CMD_APP_ADD_VEHICLE:
                app_add_vehicle(cmd,msg);
                break;
            case Common::CMD_APP_DEL_VEHICLE:
                app_del_vehicle(cmd,msg);
                break;
            case Common::CMD_APP_UPDATE_VEHICLE:
                app_update_vehicle(cmd,msg);
                break;
            default:
                //publish(TOPIC_NAME, msg);
                break;
            }          
        }
        else if (json.isArray()) {
            // ...
        }
    }
}

/**
 * @brief ParkEndpoint::app_register
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_register(int cmd,QString msg)
{
    uint8_t* out=NULL;
    int user_id = 0;
    int user_count = 0;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    QString szQuery0;
    QString szQuery1;
    QString szQuery2;
    Resp* pResp=NULL;
    register1_t* pRegister=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_REGISTER;
        goto end_app_register;
    }
    pRegister = new register1_t;
    if(pRegister==NULL){
        pResp->ret = Common::ERR_APP_REGISTER;
        goto end_app_register;
    }

    if(pJsonUtil.parse_json(cmd, msg,pRegister)<0)
        pResp->ret = Common::ERR_APP_REGISTER;
    else{
        szQuery0 = QString("select count(*) from bbpark.users where name=\"%1\";")
                .arg(pRegister->username);
        query.exec(szQuery0);
        if (query.next()){
            user_count = query.value(0).toInt();
            if(user_count>0){
                 pResp->ret = Common::ERR_APP_REGISTER;
                goto end_app_register;                
            }
        }

        szQuery = QString("insert into bbpark.users (name, code, real_name,sex,created_at, updated_at, lock_revision)  values (\"%1\",\"%2\",\"\",0,now(),now(),1);")
                .arg(pRegister->username)
                .arg(pRegister->password);
/*
        QString sFilePath = "/home/czjin/test.txt";
        QFile file(sFilePath);
        //方式：Append为追加，WriteOnly，ReadOnly
        if (!file.open(QIODevice::WriteOnly|QIODevice::Text)) {
            return;
        }
        QTextStream out(&file);
        out << szQuery << "\n";
        out.flush();
        file.close();
*/
        //pay_code 默认为加密的666666
        if (query.exec(szQuery)){
            szQuery1 = QString("select id from bbpark.users where name=\"%1\";")
                .arg(pRegister->username);
            query.exec(szQuery1);
            if (query.next()){
                user_id = query.value(0).toInt();
                szQuery2 = QString("insert into bbpark.accounts (acc_no,balance,credit,credit_available,user_id,pay_code,status,type,issuer,created_at,updated_at,memo)  values (\"%1\",%2,%3,%4,%5,\"%6\",0,0,\"%7\",now(),now(),\"\");")
                    .arg(pRegister->username)
                    .arg(0)
                    .arg(Common::user_credit)
                    .arg(Common::user_credit)
                    .arg(user_id)
                    .arg("f379eaf3c831b04de153469d1bec345e")
                    .arg("帮帮停车");
                if (query.exec(szQuery2))
                    pResp->ret = Common::ERR_OK;
                else
                    pResp->ret = Common::ERR_APP_REGISTER;
            }
            else{
                 pResp->ret = Common::ERR_APP_REGISTER;
            }
        }
        else
            pResp->ret = Common::ERR_APP_REGISTER;
    }
end_app_register:
    respData = pJsonUtil.stringfy_json(cmd,pResp);

    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    //out1 = (uint8_t*)m_XXTEA.xxtea_decrypt(out,nLen,Common::key.toLocal8Bit().data(),&nLen1);
    //recv = QString((char*)out1);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pRegister!=NULL)
        delete pRegister;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_login
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_login(int cmd,QString msg)
{
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    login_t* pLogin=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_LOGIN;
        goto end_app_login;
    }
    pLogin = new login_t;
    if(pLogin==NULL){
        pResp->ret = Common::ERR_APP_LOGIN;
        goto end_app_login;
    }

    if(pJsonUtil.parse_json(cmd, msg,pLogin)<0)
        pResp->ret = Common::ERR_APP_LOGIN;
    else{
        szQuery = QString("SELECT id,name,code FROM bbpark.users where name=%1;").arg(pLogin->username);
        query.exec(szQuery);
        if (query.next()) {
            if(pLogin->password.compare(query.value(2).toString())==0 &&
                    pLogin->username.compare(query.value(1).toString())==0)
                pResp->ret = query.value(0).toInt();
            else
                pResp->ret = Common::ERR_APP_LOGIN;
        }
        else
            pResp->ret = Common::ERR_APP_LOGIN;
    }
end_app_login:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);

    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pLogin!=NULL)
        delete pLogin;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_logout
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_logout(int cmd,QString msg)
{

}

/**
 * @brief ParkEndpoint::app_reset_passwd
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_reset_passwd(int cmd,QString msg)
{
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    login_t* pLogin=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_RESET_PASSWD;
        goto end_app_modify_passwd;
    }
    pLogin = new login_t;
    if(pLogin==NULL){
        pResp->ret = Common::ERR_APP_RESET_PASSWD;
        goto end_app_modify_passwd;
    }

    if(pJsonUtil.parse_json(cmd, msg,pLogin)<0)
        pResp->ret = Common::ERR_APP_SET_PAYCODE;
    else{
        szQuery = QString("update bbpark.users set code=\"%1\" where name=%2;")
            .arg(pLogin->password)
            .arg(pLogin->username);
        if (query.exec(szQuery)) {
            pResp->ret = Common::ERR_OK;
        }
        else
            pResp->ret = Common::ERR_APP_RESET_PASSWD;
    }
end_app_modify_passwd:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);

    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pLogin!=NULL)
        delete pLogin;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_modify_passwd
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_modify_passwd(int cmd,QString msg)
{
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    login_t* pLogin=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_MODIFY_PASSWD;
        goto end_app_modify_passwd;
    }
    pLogin = new login_t;
    if(pLogin==NULL){
        pResp->ret = Common::ERR_APP_MODIFY_PASSWD;
        goto end_app_modify_passwd;
    }

    if(pJsonUtil.parse_json(cmd, msg,pLogin)<0)
        pResp->ret = Common::ERR_APP_MODIFY_PASSWD;
    else{
        szQuery = QString("update bbpark.users set code=\"%1\" where id=%2 and code=\"%3\";")
            .arg(pLogin->new_pass)
            .arg(pLogin->user_id)
            .arg(pLogin->password);
        if (query.exec(szQuery)) {
            pResp->ret = Common::ERR_OK;
        }
        else
            pResp->ret = Common::ERR_APP_MODIFY_PASSWD;
    }
end_app_modify_passwd:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);

    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pLogin!=NULL)
        delete pLogin;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_set_paycode
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_set_paycode(int cmd,QString msg)
{
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    account_t* pAccount=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_SET_PAYCODE;
        goto end_app_modify_passwd;
    }
    pAccount = new account_t;
    if(pAccount==NULL){
        pResp->ret = Common::ERR_APP_SET_PAYCODE;
        goto end_app_modify_passwd;
    }

    if(pJsonUtil.parse_json(cmd, msg,pAccount)<0)
        pResp->ret = Common::ERR_APP_SET_PAYCODE;
    else{
        szQuery = QString("update bbpark.accounts set pay_code=\"%1\" where user_id=%2;")
            .arg(pAccount->pay_code)
            .arg(pAccount->user_id);
        if (query.exec(szQuery)) {
            pResp->ret = Common::ERR_OK;
        }
        else
            pResp->ret = Common::ERR_APP_SET_PAYCODE;
    }
end_app_modify_passwd:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);

    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pAccount!=NULL)
        delete pAccount;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_recharge
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_recharge(int cmd,QString msg)
{
    float balance = 0;
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    QString szQuery1;
    Resp* pResp=NULL;
    recharge_t* pRecharge=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_RECHARGE;
        goto end_app_recharge;
    }
    pRecharge = new recharge_t;
    if(pRecharge==NULL){
        pResp->ret = Common::ERR_APP_RECHARGE;
        goto end_app_recharge;
    }

    if(pJsonUtil.parse_json(cmd, msg,pRecharge)<0)
        pResp->ret = Common::ERR_APP_RECHARGE;
    else{
        szQuery = QString(" update bbpark.accounts set balance=balance+%1,updated_at=now() WHERE user_id=%2;")
                .arg(pRecharge->amount)
                .arg(pRecharge->user_id);
        
        if (query.exec(szQuery)) {
            szQuery1 = QString(" insert into bbpark.accounts_recharge (user_id,amount,source,created_at) values (%1,%2,%3,now());")
                .arg(pRecharge->user_id)
                .arg(pRecharge->amount)
                .arg(pRecharge->source);

            if (query.exec(szQuery1)) {
                pResp->ret = Common::ERR_OK;
            }
            else{
                pResp->ret = Common::ERR_APP_RECHARGE;
            }
        }
        else
            pResp->ret = Common::ERR_APP_RECHARGE;
    }
end_app_recharge:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pRecharge!=NULL)
        delete pRecharge;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_get_recharge_record
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_get_recharge_record(int cmd,QString msg)
{
    float balance = 0;
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    QString szQuery1;
    Resp* pResp=NULL;
    recharge_t* pRecharge=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;
    QJsonDocument  json;
    QJsonObject jsonObject;
    QJsonArray recordsArray;
    QJsonObject recordObject;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_RECHARGE;
        respData = pJsonUtil.stringfy_json(cmd,pResp);
        goto end_app_recharge;
    }
    pRecharge = new recharge_t;
    if(pRecharge==NULL){
        pResp->ret = Common::ERR_APP_RECHARGE;
        respData = pJsonUtil.stringfy_json(cmd,pResp);
        goto end_app_recharge;
    }

    if(pJsonUtil.parse_json(cmd, msg,pRecharge)<0){
        pResp->ret = Common::ERR_APP_RECHARGE;
        respData = pJsonUtil.stringfy_json(cmd,pResp);
    }
    else{
        
        szQuery = QString("select amount,source, created_at from bbpark.accounts_recharge where user_id=%1")
                .arg(pRecharge->user_id);
        
        query.exec(szQuery);

        jsonObject.insert("ret", Common::ERR_OK);
        while(query.next()) {        
            for(int x=0; x < query.record().count(); x++) {
                recordObject.insert( query.record().fieldName(x), 
                    QJsonValue::fromVariant(query.value(x)) );   
            }
            recordsArray.push_back(recordObject);
        }
        jsonObject.insert("record", recordsArray);
        json.setObject(jsonObject);
        //json.setArray(recordsArray);

        respData = json.toJson();       

    }   
end_app_recharge:
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pRecharge!=NULL)
        delete pRecharge;
    if(pResp!=NULL)
        delete pResp;
}


/**
 * @brief ParkEndpoint::app_get_credit
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_get_credit(int cmd,QString msg)
{
    float balance = 0;
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    account_t* pAccount=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_GET_CREDIT;
        goto end_app_get_credit;
    }
    pAccount = new account_t;
    if(pAccount==NULL){
        pResp->ret = Common::ERR_APP_GET_CREDIT;
        goto end_app_get_credit;
    }

    if(pJsonUtil.parse_json(cmd, msg,pAccount)<0)
        pResp->ret = Common::ERR_APP_GET_CREDIT;
    else{
        szQuery = QString("SELECT balance,credit,credit_available FROM bbpark.accounts WHERE user_id=%1;")
                .arg(pAccount->user_id);
        query.exec(szQuery);
        if (query.next()) {
            pAccount->balance = query.value(0).toFloat();
            pAccount->credit = query.value(1).toFloat();
            pAccount->credit_available = query.value(2).toFloat();
            pResp->pData = pAccount;
            pResp->ret = Common::ERR_OK;
        }
        else
            pResp->ret = Common::ERR_APP_GET_CREDIT;
    }
end_app_get_credit:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pAccount!=NULL)
        delete pAccount;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_parking_near
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_parking_near(int cmd,QString msg)
{
    int count=20;
    int index_min=0;
    double norm_min=0;
    double norm[20]={0};
    double lng_begin;
    double lng_end;
    double lat_begin;
    double lat_end;
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;
    parking_t parking[20];
    parking_t parking1;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_PARKING_NEAR;
        goto end_app_parking_near;
    }

    pJsonUtil.parse_json(cmd, msg,&parking1);

    lng_begin = parking1.longitude - Common::lng_offset;
    lng_end = parking1.longitude + Common::lng_offset;
    lat_begin = parking1.latitude - Common::lat_offset;
    lat_end = parking1.latitude + Common::lat_offset;
    szQuery = QString("SELECT id, name,description,addr,longitude,latitude,type,plan_path,space_start,"
                      "space_total, space_free, qrcode_id,memo,created_at, updated_at, "
                      "lock_revision,charge_standard FROM bbpark.parkings where longitude between %1 and %2 "
                      "and latitude between %3 and %4;").arg(lng_begin).arg(lng_end).arg(lat_begin).arg(lat_end);
    query.exec(szQuery);  // Query execution
    count = 0;
    if (query.next()) {
        parking[count].id = query.value(0).toInt();
        parking[count].name = query.value(1).toString();
        parking[count].description = query.value(2).toString();
        parking[count].addr = query.value(3).toString();
        parking[count].longitude = query.value(4).toDouble();
        parking[count].latitude = query.value(5).toDouble();
        parking[count].type = query.value(6).toInt();
        parking[count].plan_path = query.value(7).toString();
        parking[count].space_start = query.value(8).toString();
        parking[count].space_total = query.value(9).toInt();
        parking[count].space_free = query.value(10).toInt();
        parking[count].qrcode_id = query.value(11).toInt();
        parking[count].memo = query.value(12).toString();
        parking[count].created_at = query.value(13).toString();
        parking[count].updated_at = query.value(14).toString();
        parking[count].lock_revision = query.value(15).toInt();
        parking[count].charge_standard = query.value(16).toString();

        norm[count] = pow(parking1.longitude - parking[count].longitude,2) +
                pow(parking1.latitude - parking[count].latitude,2);
        count++;

    }
    if(count>0){
        norm_min = norm[0];
        index_min = 0;
        for(int i=1;i<count;i++){
            if(norm[i]<norm_min){
               norm_min = norm[i];
               index_min = i;
            }
        }
        pResp->pData = &parking[0];
        pResp->ret = Common::ERR_OK;
    }
    else
        pResp->ret = Common::ERR_APP_PARKING_NEAR;
end_app_parking_near:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_parking
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_parking(int cmd,QString msg)
{
    int count=20;
    int index_min=0;
    double norm_min=0;
    double norm[20]={0};
    double lng_begin;
    double lng_end;
    double lat_begin;
    double lat_end;
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;
    parking_t parking[20];
    parking_t parking1;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_PARKING;
        goto end_app_parking;
    }

    pJsonUtil.parse_json(cmd, msg,&parking1);

    lng_begin = parking1.longitude - Common::lng_offset;
    lng_end = parking1.longitude + Common::lng_offset;
    lat_begin = parking1.latitude - Common::lat_offset;
    lat_end = parking1.latitude + Common::lat_offset;
    szQuery = QString("SELECT id, name,description,addr,longitude,latitude,type,plan_path,space_start,"
                      "space_total, space_free, qrcode_id,memo,created_at, updated_at, "
                      "lock_revision,charge_standard FROM bbpark.parkings where longitude between %1 and %2 "
                      "and latitude between %3 and %4;").arg(lng_begin).arg(lng_end).arg(lat_begin).arg(lat_end);
    query.exec(szQuery);  // Query execution
    count = 0;
    if (query.next()) {
        parking[count].id = query.value(0).toInt();
        parking[count].name = query.value(1).toString();
        parking[count].description = query.value(2).toString();
        parking[count].addr = query.value(3).toString();
        parking[count].longitude = query.value(4).toDouble();
        parking[count].latitude = query.value(5).toDouble();
        parking[count].type = query.value(6).toInt();
        parking[count].plan_path = query.value(7).toString();
        parking[count].space_start = query.value(8).toString();
        parking[count].space_total = query.value(9).toInt();
        parking[count].space_free = query.value(10).toInt();
        parking[count].qrcode_id = query.value(11).toInt();
        parking[count].memo = query.value(12).toString();
        parking[count].created_at = query.value(13).toString();
        parking[count].updated_at = query.value(14).toString();
        parking[count].lock_revision = query.value(15).toInt();
        parking[count].charge_standard = query.value(16).toString();

        norm[count] = pow(parking1.longitude - parking[count].longitude,2) +
                pow(parking1.latitude - parking[count].latitude,2);
        count++;

    }
    if(count>0){
        norm_min = norm[0];
        index_min = 0;
        for(int i=1;i<count;i++){
            if(norm[i]<norm_min){
               norm_min = norm[i];
               index_min = i;
            }
        }
        pResp->pData = &parking[index_min];
        pResp->ret = Common::ERR_OK;
    }
    else
        pResp->ret = Common::ERR_APP_PARKING;
end_app_parking:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_park_confirm
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_park_confirm(int cmd,QString msg)
{
    uint8_t* out=NULL;
    bool bUpdateAccount;
    bool bInsertPrepaid;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    QString szQuery1;
    QString szQuery2;
    Resp* pResp=NULL;
    park_t* pPark=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;
    QDateTime time = QDateTime::currentDateTime();
    QString start_time = time.toString("yyyy-MM-dd hh:mm:ss");

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_PARK_CONFIRM;
        goto end_app_park_confirm;
    }
    pPark = new park_t;
    if(pPark==NULL){
        pResp->ret = Common::ERR_APP_PARK_CONFIRM;
        goto end_app_park_confirm;
    }
    //默认使用停车账户
    pPark->pay_source = Common::PAY_SOURCE_USER_PARK;

    if(pJsonUtil.parse_json(cmd, msg,pPark)<0)
        pResp->ret = Common::ERR_APP_PARK_CONFIRM;
    else{
        szQuery = QString("insert into bbpark.parks(session_id,user_id, vehicle_id, parking_id, parking_space_no,start_time,status,pay_mode,pay_source,order_duration,prepaid) "
                          "values (\"%1\",%2,%3,%4,\"%5\",\"%6\",%7,%8,%9,%10,%11);")
                .arg(pPark->session_id)
                .arg(pPark->user_id)
                .arg(pPark->vehicle_id)
                .arg(pPark->parking_id)
                .arg(pPark->parking_space_no)
                .arg(start_time)
                .arg(0)
                .arg(pPark->pay_mode)
                .arg(pPark->pay_source)
                .arg(0)
                .arg(0);     
        if(query.exec(szQuery)) {
            pResp->pData = pPark;
            pResp->ret = Common::ERR_OK;
        }
        else
            pResp->ret = Common::ERR_APP_PARK_CONFIRM;
    }
end_app_park_confirm:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pPark!=NULL)
        delete pPark;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_park_prepay
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_park_prepay(int cmd,QString msg)
{
    uint8_t* out=NULL;
    bool bUpdateAccount;
    bool bInsertPrepaid;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    QString szQuery1;
    QString szQuery2;
    Resp* pResp=NULL;
    park_t* pPark=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;
    QDateTime time = QDateTime::currentDateTime();
    QString start_time = time.toString("yyyy-MM-dd hh:mm:ss");

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_PARK_PREPAY;
        goto end_app_park_prepay;
    }
    pPark = new park_t;
    if(pPark==NULL){
        pResp->ret = Common::ERR_APP_PARK_PREPAY;
        goto end_app_park_prepay;
    }
    
    if(pJsonUtil.parse_json(cmd, msg,pPark)<0)
        pResp->ret = Common::ERR_APP_PARK_PREPAY;
    else{
        szQuery = QString("update bbpark.parks set order_duration=order_duration+%2,prepaid=prepaid+%3 where session_id=\"%1\";")
                .arg(pPark->session_id)
                .arg(pPark->order_duration)
                .arg(pPark->prepaid);    
        if(query.exec(szQuery)){
            szQuery1 = QString("update bbpark.accounts set balance=balance-%1,updated_at=\"%2\" where user_id=%3;")
                .arg(pPark->prepaid)
                .arg(start_time)
                .arg(pPark->user_id);
             bUpdateAccount = query.exec(szQuery1);

             szQuery2 = QString("insert into bbpark.park_prepay (user_id,session_id,prepaid,created_at) values (%1,\"%2\",%3,\"%4\");")
                .arg(pPark->user_id)
                .arg(pPark->session_id)
                .arg(pPark->prepaid)
                .arg(start_time);       
             bInsertPrepaid = query.exec(szQuery2);

            if(bUpdateAccount && bInsertPrepaid){
                pResp->pData = pPark;
                pResp->ret = Common::ERR_OK;
            }
            else
                pResp->ret = Common::ERR_APP_PARK_PREPAY;
        }
        else
            pResp->ret = Common::ERR_APP_PARK_PREPAY;
    }
end_app_park_prepay:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pPark!=NULL)
        delete pPark;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_park_fee
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_park_fee(int cmd,QString msg)
{
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    park_t* pPark=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_PARK_FEE;
        goto end_app_park_fee;
    }
    pPark = new park_t;
    if(pPark==NULL){
        pResp->ret = Common::ERR_APP_PARK_FEE;
        goto end_app_park_fee;
    }

    if(pJsonUtil.parse_json(cmd, msg,pPark)<0)
        pResp->ret = Common::ERR_APP_PARK_FEE;
    else{
        pResp->pData = &pPark->park_fee;
        pResp->ret = Common::ERR_OK;
    }
end_app_park_fee:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pPark!=NULL)
        delete pPark;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_park_resttime
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_park_resttime(int cmd,QString msg)
{
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    park_t* pPark=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_PARK_RESTTIME;
        goto end_app_park_resttime;
    }
    pPark = new park_t;
    if(pPark==NULL){
        pResp->ret = Common::ERR_APP_PARK_RESTTIME;
        goto end_app_park_resttime;
    }

    if(pJsonUtil.parse_json(cmd, msg,pPark)<0)
        pResp->ret = Common::ERR_APP_PARK_RESTTIME;
    else{
        szQuery = QString("SELECT A.start_time,A.order_duration,A.prepaid,B.name FROM bbpark.parks A,bbpark.parkings B WHERE A.parking_id=B.id and A.session_id=\"%1\" and A.status=%2;")
                .arg(pPark->session_id)
                .arg(0);
        query.exec(szQuery);
        if (query.next()) {
            pPark->start_time = query.value(0).toString();
            pPark->order_duration = query.value(1).toInt();
            pPark->prepaid = query.value(2).toFloat();
            pPark->memo = query.value(3).toString();
            pResp->pData = pPark;
            pResp->ret = Common::ERR_OK;
        }
        else
            pResp->ret = Common::ERR_APP_PARK_RESTTIME;
    }
end_app_park_resttime:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pPark!=NULL)
        delete pPark;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_park_settle
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_park_settle(int cmd,QString msg)
{
    bool bUpdateUserAcc = false;
    bool bUpdateParkingAcc = false;
    uint8_t* out=NULL;
    size_t nLen = 0;
    float prepaid = 0;
    QString respData="";
    QString szQuery;
    QString szQuery1;
    QString szQuery2;
    QString szQuery3;
    Resp* pResp=NULL;
    park_t* pPark=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;
    QDateTime time = QDateTime::currentDateTime();
    QString end_time = time.toString("yyyy-MM-dd hh:mm:ss");

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_PARK_CONFIRM;
        goto end_app_park_settle;
    }
    pPark = new park_t;
    if(pPark==NULL){
        pResp->ret = Common::ERR_APP_PARK_CONFIRM;
        goto end_app_park_settle;
    }

    pJsonUtil.parse_json(cmd, msg,pPark);

    szQuery = QString("update bbpark.parks set end_time=\"%1\",park_fee=%2,status=%3,pay_source=%4,qrcode_path=\"%5\" "
                      "where session_id=\"%6\" and status=%7;")
            .arg(end_time)
            .arg(pPark->park_fee)
            .arg(1)
            .arg(pPark->pay_source)
            .arg("")
            .arg(pPark->session_id)
            .arg(0);
    if(query.exec(szQuery)) {
        szQuery1 = QString("select prepaid from bbpark.parks where session_id=\"%1\";")
                .arg(pPark->session_id);
        query.exec(szQuery1);
        if(query.next()){
            prepaid = query.value(0).toFloat();
            szQuery2 = QString("update bbpark.accounts set balance=balance+%1-%2,updated_at=\"%3\" where user_id=%4;")
                .arg(prepaid)
                .arg(pPark->park_fee)
                .arg(end_time)
                .arg(pPark->user_id);
            bUpdateUserAcc = query.exec(szQuery2);
            szQuery3 = QString("update bbpark.parking_accounts set balance=balance+%1,updated_at=\"%2\" where parking_id=%3;")
                .arg(pPark->park_fee)
                .arg(end_time)
                .arg(pPark->parking_id);
            bUpdateParkingAcc = query.exec(szQuery3);
            if(bUpdateUserAcc && bUpdateParkingAcc)
                pResp->ret = Common::ERR_OK;
            else
                pResp->ret = Common::ERR_APP_PARK_CONFIRM;
        }
        else
            pResp->ret = Common::ERR_APP_PARK_CONFIRM;
    }
    else
        pResp->ret = Common::ERR_APP_PARK_CONFIRM;
end_app_park_settle:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pPark!=NULL)
        delete pPark;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_get_park_unpay
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_get_park_unpay(int cmd,QString msg)
{
    uint8_t* out=NULL;
    int i=0;
    int nRowCoount = 0;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    park_t* pPark=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;
    QJsonDocument  json;
    QJsonObject jsonObject;
    QJsonArray recordsArray;
    QJsonObject recordObject;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_GET_PARK_UNPAY;
        respData = pJsonUtil.stringfy_json(cmd,pResp);
        goto end_app_get_park_unpay;
    }
    pPark = new park_t;
    if(pPark==NULL){
        pResp->ret = Common::ERR_APP_GET_PARK_UNPAY;
        respData = pJsonUtil.stringfy_json(cmd,pResp);
        goto end_app_get_park_unpay;
    }

    if(pJsonUtil.parse_json(cmd, msg,pPark)<0){
        pResp->ret = Common::ERR_APP_GET_PARK_UNPAY;
        respData = pJsonUtil.stringfy_json(cmd,pResp);
    }
    else{
        szQuery = QString("select A.session_id,A.user_id, A.vehicle_id, A.parking_id,B.name,B.addr,B.charge_standard, A.parking_space_no, A.start_time, "
                      "A.end_time, A.park_fee,A.prepaid,A.order_duration, A.status,A.pay_mode,A.pay_source,A.qrcode_path, A.memo"
                      " from bbpark.parks A,bbpark.parkings B where A.parking_id=B.id and A.user_id=%1 and A.status=0 order by A.start_time desc")
                .arg(pPark->user_id);
        query.exec(szQuery);

        jsonObject.insert("ret", Common::ERR_OK);

        while(query.next()) {    
            for(int x=0; x < query.record().count(); x++) {
                recordObject.insert( query.record().fieldName(x), 
                        QJsonValue::fromVariant(query.value(x)) );   
            }
            recordsArray.push_back(recordObject);
        }
        //if(query.size()>0)
        jsonObject.insert("record", recordsArray);

        json.setObject(jsonObject);
        //json.setArray(recordsArray);

        respData = json.toJson();   
    }
    
end_app_get_park_unpay:
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pPark!=NULL)
        delete pPark;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_park_pay_in_back
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_park_pay_in_back(int cmd,QString msg)
{

}

/**
 * @brief ParkEndpoint::app_get_park_record
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_get_park_record(int cmd,QString msg)
{
    uint8_t* out=NULL;
    int i=0;
    int nRowCoount = 0;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    park_t* pPark=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;
    QJsonDocument  json;
    QJsonObject jsonObject;
    QJsonArray recordsArray;
    QJsonObject recordObject;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_GET_PARK_RECORD;
        respData = pJsonUtil.stringfy_json(cmd,pResp);
        goto end_app_get_park_record;
    }
    pPark = new park_t;
    if(pPark==NULL){
        pResp->ret = Common::ERR_APP_GET_PARK_RECORD;
        respData = pJsonUtil.stringfy_json(cmd,pResp);
        goto end_app_get_park_record;
    }

    if(pJsonUtil.parse_json(cmd, msg,pPark)<0){
        pResp->ret = Common::ERR_APP_GET_PARK_RECORD;
        respData = pJsonUtil.stringfy_json(cmd,pResp);
    }
    else{
        szQuery = QString("select A.session_id,A.user_id, A.vehicle_id, A.parking_id,B.name,B.addr,B.charge_standard, A.parking_space_no, A.start_time, "
                      "A.end_time, A.park_fee,A.prepaid,A.order_duration, A.status,A.pay_mode,A.pay_source,A.qrcode_path, A.memo"
                      " from bbpark.parks A,bbpark.parkings B where A.parking_id=B.id and A.user_id=%1 and A.status=1 order by A.end_time desc")
                .arg(pPark->user_id);
        query.exec(szQuery);

        jsonObject.insert("ret", Common::ERR_OK);

        while(query.next()) {    
            for(int x=0; x < query.record().count(); x++) {
                recordObject.insert( query.record().fieldName(x), 
                        QJsonValue::fromVariant(query.value(x)) );   
            }
            recordsArray.push_back(recordObject);
        }
        //if(query.size()>0)
        jsonObject.insert("record", recordsArray);

        json.setObject(jsonObject);
        //json.setArray(recordsArray);

        respData = json.toJson();   
    }
    
end_app_get_park_record:
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pPark!=NULL)
        delete pPark;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_check_for_update
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_check_for_update(int cmd,QString msg)
{
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    version_t* pVersion=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_CHECK_FOR_UPDATE;
        goto end_app_check_for_update;
    }
    pVersion = new version_t;
    if(pVersion==NULL){
        pResp->ret = Common::ERR_APP_CHECK_FOR_UPDATE;
        goto end_app_check_for_update;
    }

    if(pJsonUtil.parse_json(cmd, msg,pVersion)<0)
        pResp->ret = Common::ERR_APP_CHECK_FOR_UPDATE;
    else{
        szQuery = QString("SELECT appid, major_version,minor_version,revision,content, help,download_url,created_at FROM bbpark.version WHERE appid=\"%1\" order by created_at desc limit 1;")
                .arg(pVersion->appid);
        query.exec(szQuery);
        if (query.next()) {
            pVersion->appid = query.value(0).toString();
            pVersion->major_version = query.value(1).toInt();
            pVersion->minor_version = query.value(2).toInt();
            pVersion->revision = query.value(3).toInt();
            pVersion->content = query.value(4).toString();
            pVersion->help = query.value(5).toString();
            pVersion->download_url = query.value(6).toString();
            pVersion->created_at = query.value(7).toString();
            pResp->pData = pVersion;
            pResp->ret = Common::ERR_OK;
        }
        else
            pResp->ret = Common::ERR_APP_CHECK_FOR_UPDATE;
    }
end_app_check_for_update:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pVersion!=NULL)
        delete pVersion;
    if(pResp!=NULL)
        delete pResp;

}

/**
 * @brief ParkEndpoint::app_get_sysinfo
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_get_sysinfo(int cmd,QString msg)
{
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    sysinfo_t* pSysinfo=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_GET_SYSINFO;
        goto end_app_get_sysinfo;
    }
    pSysinfo = new sysinfo_t;
    if(pSysinfo==NULL){
        pResp->ret = Common::ERR_APP_GET_SYSINFO;
        goto end_app_get_sysinfo;
    }
/*
    if(pJsonUtil.parse_json(cmd, msg,pSysinfo)<0)
        pResp->ret = Common::ERR_APP_GET_SYSINFO;
    else{*/
        szQuery = QString("SELECT company, slogan, website, contact_hotline,serv_ver, app_ver, handset_ver, created_at FROM bbpark.sysinfo;");
        query.exec(szQuery);
        if (query.next()) {
            pSysinfo->company = query.value(0).toString();
            pSysinfo->slogan = query.value(1).toString();
            pSysinfo->website = query.value(2).toString();
            pSysinfo->contact_hotline = query.value(3).toString();
            pSysinfo->serv_ver = query.value(4).toString();
            pSysinfo->app_ver = query.value(5).toString();
            pSysinfo->handset_ver = query.value(6).toString();
            pSysinfo->created_at = query.value(7).toString();
            pResp->pData = pSysinfo;
            pResp->ret = Common::ERR_OK;
        }
        else
            pResp->ret = Common::ERR_APP_GET_SYSINFO;
//    }
end_app_get_sysinfo:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pSysinfo!=NULL)
        delete pSysinfo;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_feedback
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_feedback(int cmd,QString msg)
{
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    Resp* pResp=NULL;
    feedback_t* pFeedback=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_FEEDBACK;
        goto end_app_feedback;
    }
    pFeedback = new feedback_t;
    if(pFeedback==NULL){
        pResp->ret = Common::ERR_APP_FEEDBACK;
        goto end_app_feedback;
    }

    if(pJsonUtil.parse_json(cmd, msg,pFeedback)<0)
        pResp->ret = Common::ERR_APP_FEEDBACK;
    else{
        //szQuery = QString("insert into bbpark.feedback (user_id,content, voice BLOB, created_at) values (%1,\"%2\",%3,now());")
        szQuery = QString("insert into bbpark.feedback (user_id,content, created_at) values (%1,\"%2\",now());")
                    .arg(pFeedback->user_id)
                    .arg(pFeedback->content);
        if (query.exec(szQuery))
            pResp->ret = Common::ERR_OK;
        else
            pResp->ret = Common::ERR_APP_FEEDBACK;
    }
end_app_feedback:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pFeedback!=NULL)
        delete pFeedback;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_add_vehicle
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_add_vehicle(int cmd,QString msg)
{
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    QString szQuery1;
    QString szQuery2;
    Resp* pResp=NULL;
    vehicle_t* pVehicle=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_ADD_VEHICLE;
        goto end_app_add_vehicle;
    }
    pVehicle = new vehicle_t;
    if(pVehicle==NULL){
        pResp->ret = Common::ERR_APP_ADD_VEHICLE;
        goto end_app_add_vehicle;
    }

    if(pJsonUtil.parse_json(cmd, msg,pVehicle)<0)
        pResp->ret = Common::ERR_APP_ADD_VEHICLE;
    else{
        szQuery = QString("insert into bbpark.vehicle (plae,engine_no,frame_no,vehicle_type,register_at, created_at,updated_at,lock_revision) values (\"%1\",\"%2\",\"%3\",%4,now(),now(),now(),0);")
                    .arg(pVehicle->plate)
                 .arg(pVehicle->engine_no)
                 .arg(pVehicle->frame_no)
                 .arg(pVehicle->vehicle_type)
                    .arg(pVehicle->register_time);
        if (query.exec(szQuery)){
             szQuery1="select @@IDENTITY";
                query.exec(szQuery1);
                if(query.next()) {
                    pVehicle->vehicle_id = query.value(0).toInt();
                    szQuery = QString("insert into bbpark.user_vehicle (user_id,vehicle_id, created_at) values (%1,%2,now());")
                                .arg(pVehicle->user_id)
                                .arg(pVehicle->vehicle_id);
                     pResp->ret = Common::ERR_OK;
                }
                else
                     pResp->ret = Common::ERR_APP_ADD_VEHICLE;
        }
        else
            pResp->ret = Common::ERR_APP_ADD_VEHICLE;
    }
end_app_add_vehicle:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pVehicle!=NULL)
        delete pVehicle;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_del_vehicle
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_del_vehicle(int cmd,QString msg)
{
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    QString szQuery1;
    QString szQuery2;
    Resp* pResp=NULL;
    vehicle_t* pVehicle=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_DEL_VEHICLE;
        goto end_app_del_vehicle;
    }
    pVehicle = new vehicle_t;
    if(pVehicle==NULL){
        pResp->ret = Common::ERR_APP_DEL_VEHICLE;
        goto end_app_del_vehicle;
    }

    if(pJsonUtil.parse_json(cmd, msg,pVehicle)<0)
        pResp->ret = Common::ERR_APP_DEL_VEHICLE;
    else{
        szQuery = QString("delete from bbpark.vehicle where id=%1);")
                    .arg(pVehicle->vehicle_id);
        if (query.exec(szQuery)){
             pResp->ret = Common::ERR_OK;
        }
        else
            pResp->ret = Common::ERR_APP_DEL_VEHICLE;
    }
end_app_del_vehicle:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pVehicle!=NULL)
        delete pVehicle;
    if(pResp!=NULL)
        delete pResp;
}

/**
 * @brief ParkEndpoint::app_update_vehicle
 * @param cmd
 * @param msg
 */
void ParkEndpoint::app_update_vehicle(int cmd,QString msg)
{
    uint8_t* out=NULL;
    size_t nLen = 0;
    QString respData="";
    QString szQuery;
    QString szQuery1;
    Resp* pResp=NULL;
    vehicle_t* pVehicle=NULL;
    TSqlQuery query;
    JsonUtil pJsonUtil;

    pResp = new Resp;
    if(pResp==NULL){
        pResp->ret = Common::ERR_APP_UPDATE_VEHICLE;
        goto end_app_update_vehicle;
    }
    pVehicle = new vehicle_t;
    if(pVehicle==NULL){
        pResp->ret = Common::ERR_APP_UPDATE_VEHICLE;
        goto end_app_update_vehicle;
    }

    if(pJsonUtil.parse_json(cmd, msg,pVehicle)<0)
        pResp->ret = Common::ERR_APP_UPDATE_VEHICLE;
    else{
        szQuery = QString("update bbpark.vehicle set plate=\"%1\",engine_no=\"%2\",frame_no=\"%3\",vehicle_type=%4,register_time=\"%5\" where id=%6;")
                    .arg(pVehicle->plate)
                 .arg(pVehicle->engine_no)
                 .arg(pVehicle->frame_no)
                 .arg(pVehicle->vehicle_type)
                 .arg(pVehicle->register_time)
                .arg(pVehicle->vehicle_id);
        if (query.exec(szQuery))
            pResp->ret = Common::ERR_OK;
        else
            pResp->ret = Common::ERR_APP_UPDATE_VEHICLE;
    }
end_app_update_vehicle:
    respData = pJsonUtil.stringfy_json(cmd,pResp);
    out = (uint8_t*)m_XXTEA.xxtea_encrypt(respData.toLocal8Bit().data(),respData.toLocal8Bit().length(),
                                          Common::key.toLocal8Bit().data(),&nLen);
    publish(TOPIC_NAME, QByteArray((char*)out,nLen));

    if(pVehicle!=NULL)
        delete pVehicle;
    if(pResp!=NULL)
        delete pResp;
}

// Don't remove below this line
T_REGISTER_CONTROLLER(parkendpoint)
