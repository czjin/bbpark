TARGET = controller
TEMPLATE = lib
CONFIG += shared c++11 x86_64
QT += network sql xml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers ../models ../../common
DEPENDPATH  += ../helpers ../models
LIBS += -L../lib -lhelper -lmodel

include(../appbase.pri)

HEADERS += applicationcontroller.h \
    ../../common/common.h \
    ../../common/Utils.h \
    jsonutil.h \
    ../../common/xxtea.h

SOURCES += applicationcontroller.cpp \
    ../../common/common.cpp \
    ../../common/Utils.cpp \
    jsonutil.cpp \
    ../../common/xxtea.cpp

HEADERS += userscontroller.h
SOURCES += userscontroller.cpp
HEADERS += applicationendpoint.h
SOURCES += applicationendpoint.cpp
HEADERS += parkendpoint.h
SOURCES += parkendpoint.cpp
HEADERS += parkingscontroller.h
SOURCES += parkingscontroller.cpp
HEADERS +=
SOURCES +=
HEADERS += parkscontroller.h
SOURCES += parkscontroller.cpp
HEADERS += parkingqrcodescontroller.h
SOURCES += parkingqrcodescontroller.cpp

HEADERS += vehiclescontroller.h
SOURCES += vehiclescontroller.cpp
HEADERS += informationmailer.h
SOURCES += informationmailer.cpp
HEADERS += accountscontroller.h
SOURCES += accountscontroller.cpp
HEADERS += parkingspacescontroller.h
SOURCES += parkingspacescontroller.cpp
HEADERS += useraccoutcontroller.h
SOURCES += useraccoutcontroller.cpp
HEADERS += uservehiclecontroller.h
SOURCES += uservehiclecontroller.cpp

HEADERS += HttpClient.h
SOURCES += HttpClient.cpp
HEADERS += operatorscontroller.h
SOURCES += operatorscontroller.cpp
HEADERS += operatorparkingcontroller.h
SOURCES += operatorparkingcontroller.cpp
HEADERS += parkingaccountscontroller.h
SOURCES += parkingaccountscontroller.cpp
HEADERS += parkattendantscontroller.h
SOURCES += parkattendantscontroller.cpp
HEADERS += attendantparkingcontroller.h
SOURCES += attendantparkingcontroller.cpp
HEADERS += parkbillscontroller.h
SOURCES += parkbillscontroller.cpp
HEADERS += parkcouponcontroller.h
SOURCES += parkcouponcontroller.cpp
HEADERS += vehiclecontroller.h
SOURCES += vehiclecontroller.cpp
HEADERS += accountsrechargecontroller.h
SOURCES += accountsrechargecontroller.cpp
HEADERS += parkprepaycontroller.h
SOURCES += parkprepaycontroller.cpp
HEADERS += sessioncontroller.h
SOURCES += sessioncontroller.cpp
HEADERS += versioncontroller.h
SOURCES += versioncontroller.cpp
HEADERS += feedbackcontroller.h
SOURCES += feedbackcontroller.cpp
HEADERS += sysinfocontroller.h
SOURCES += sysinfocontroller.cpp
HEADERS += admincontroller.h
SOURCES += admincontroller.cpp
