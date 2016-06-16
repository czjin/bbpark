#ifndef PARKENDPOINT_H
#define PARKENDPOINT_H

#include "applicationendpoint.h"
#include "xxtea.h"

class T_CONTROLLER_EXPORT ParkEndpoint : public ApplicationEndpoint
{
public:
    ParkEndpoint() { }
    ParkEndpoint(const ParkEndpoint &other);

    XXTEA  m_XXTEA;

protected:
    bool onOpen(const TSession &httpSession);
    void onClose(int closeCode);
    void onTextReceived(const QString &text);
    void onBinaryReceived(const QByteArray &binary);

    void app_register(int cmd,QString msg);
    void app_login(int cmd,QString msg);
    void app_logout(int cmd,QString msg);
    void app_reset_passwd(int cmd,QString msg);
    void app_modify_passwd(int cmd,QString msg);
    void app_set_paycode(int cmd,QString msg);
    void app_recharge(int cmd,QString msg);
    void app_get_recharge_record(int cmd,QString msg);
    void app_get_credit(int cmd,QString msg);
    void app_parking_near(int cmd,QString msg);
    void app_parking(int cmd,QString msg);
    void app_park_confirm(int cmd,QString msg);
    void app_park_prepay(int cmd,QString msg);
    void app_park_fee(int cmd,QString msg);
    void app_park_resttime(int cmd,QString msg);
    void app_park_settle(int cmd,QString msg);
    void app_get_park_unpay(int cmd,QString msg);
    void app_park_pay_in_back(int cmd,QString msg);
    void app_get_park_record(int cmd,QString msg);
    void app_check_for_update(int cmd,QString msg);
    void app_get_sysinfo(int cmd,QString msg);
    void app_feedback(int cmd,QString msg);
    void app_add_vehicle(int cmd,QString msg);
     void app_del_vehicle(int cmd,QString msg);
    void app_update_vehicle(int cmd,QString msg);

};

T_DECLARE_CONTROLLER(ParkEndpoint, parkendpoint)

#endif // PARKENDPOINT_H
