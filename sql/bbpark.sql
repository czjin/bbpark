use bbpark;

create table admin (id INTEGER AUTO_INCREMENT PRIMARY KEY,username VARCHAR(32),password VARCHAR(32), created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, lock_revision INTEGER) DEFAULT CHARSET=utf8;

CREATE TABLE users (id INTEGER AUTO_INCREMENT PRIMARY KEY, name VARCHAR(16), code VARCHAR(64),real_name VARCHAR(32),sex INTEGER,avatar VARCHAR(256), created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, lock_revision INTEGER) DEFAULT CHARSET=utf8;

CREATE TABLE parkings (id INTEGER AUTO_INCREMENT PRIMARY KEY, name VARCHAR(64), description VARCHAR(64),addr VARCHAR(256),charge_standard VARCHAR(1024),longitude DOUBLE,latitude DOUBLE,type INTEGER,plan_path VARCHAR(256), space_start VARCHAR(16), space_total INTEGER, space_free INTEGER, qrcode_id INTEGER,memo VARCHAR(64),created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, lock_revision INTEGER) DEFAULT CHARSET=utf8;

CREATE TABLE parking_spaces (id INTEGER AUTO_INCREMENT PRIMARY KEY, parking_id integer, number VARCHAR(16), status integer,qrcode_path VARCHAR(256), created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, lock_revision INTEGER) DEFAULT CHARSET=utf8;

CREATE TABLE operators (id INTEGER AUTO_INCREMENT PRIMARY KEY, name VARCHAR(16), code VARCHAR(64),created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP) DEFAULT CHARSET=utf8;

CREATE TABLE operator_parking (id INTEGER AUTO_INCREMENT PRIMARY KEY, operator_id INTEGER, parking_id INTEGER, status INTEGER,created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP) DEFAULT CHARSET=utf8;

CREATE TABLE parking_accounts (id INTEGER AUTO_INCREMENT PRIMARY KEY, acc_no VARCHAR(32), balance float,parking_id INTEGER,status INTEGER,type INTEGER,issuer VARCHAR(64), created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, memo VARCHAR(64)) DEFAULT CHARSET=utf8;

CREATE TABLE park_attendants (id INTEGER AUTO_INCREMENT PRIMARY KEY, name VARCHAR(16), code VARCHAR(64),real_name VARCHAR(32),sex INTEGER, avatar VARCHAR(256), created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, lock_revision INTEGER) DEFAULT CHARSET=utf8;

CREATE TABLE attendant_parking (id INTEGER AUTO_INCREMENT PRIMARY KEY, attendant_id INTEGER, parking_id INTEGER, status INTEGER, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP) DEFAULT CHARSET=utf8;

CREATE TABLE parks (id INTEGER AUTO_INCREMENT PRIMARY KEY,session_id VARCHAR(64), user_id integer, vehicle_id INTEGER, parking_id integer, parking_space_no VARCHAR(16), start_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP, end_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP, park_fee float,prepaid float,order_duration int, status integer,pay_mode integer,pay_source integer,qrcode_path VARCHAR(256), memo VARCHAR(64)) DEFAULT CHARSET=utf8;

CREATE TABLE park_bills (id INTEGER AUTO_INCREMENT PRIMARY KEY,session_id VARCHAR(64), source INTEGER, amount float, status INTEGER, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP) DEFAULT CHARSET=utf8;

CREATE TABLE park_coupon (id INTEGER AUTO_INCREMENT PRIMARY KEY, coupon_no VARCHAR(64), check_code VARCHAR(64), amount float, status INTEGER, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, use_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP, valid_till TIMESTAMP DEFAULT CURRENT_TIMESTAMP) DEFAULT CHARSET=utf8;

CREATE TABLE parking_qrcodes (id INTEGER AUTO_INCREMENT PRIMARY KEY, description VARCHAR(1024),path VARCHAR(256),created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, lock_revision INTEGER) DEFAULT CHARSET=utf8;

CREATE TABLE vehicle (id INTEGER AUTO_INCREMENT PRIMARY KEY, plate VARCHAR(16),engine_no VARCHAR(32),frame_no VARCHAR(32),register_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP,vehicle_type int, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, lock_revision INTEGER) DEFAULT CHARSET=utf8;

CREATE TABLE accounts (id INTEGER AUTO_INCREMENT PRIMARY KEY, acc_no VARCHAR(32),user_id INTEGER,pay_code VARCHAR(64), balance float,credit float,credit_available float,status INTEGER,type INTEGER,issuer VARCHAR(64), created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, memo VARCHAR(64)) DEFAULT CHARSET=utf8;

CREATE TABLE accounts_recharge (id INTEGER AUTO_INCREMENT PRIMARY KEY, user_id INTEGER, amount float,source INTEGER, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, memo VARCHAR(64)) DEFAULT CHARSET=utf8;

CREATE TABLE park_prepay (id INTEGER AUTO_INCREMENT PRIMARY KEY, user_id INTEGER, session_id VARCHAR(64), prepaid float, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP) DEFAULT CHARSET=utf8;

CREATE TABLE user_vehicle (id INTEGER AUTO_INCREMENT PRIMARY KEY, user_id INTEGER, vehicle_id INTEGER, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, lock_revision INTEGER) DEFAULT CHARSET=utf8;

CREATE TABLE version (id INTEGER AUTO_INCREMENT PRIMARY KEY, appid VARCHAR(32), major_version INTEGER,minor_version INTEGER,revision INTEGER,content VARCHAR(1024), help VARCHAR(4096), download_url VARCHAR(256),created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP) DEFAULT CHARSET=utf8;

CREATE TABLE feedback (id INTEGER PRIMARY KEY,user_id INTEGER,content VARCHAR(1024), voice BLOB, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP) DEFAULT CHARSET=utf8;

CREATE TABLE sysinfo (id INTEGER PRIMARY KEY, company VARCHAR(64), slogan VARCHAR(64), website VARCHAR(128),contact_hotline VARCHAR(32),serv_ver VARCHAR(32), app_ver VARCHAR(32), handset_ver VARCHAR(32), created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP) DEFAULT CHARSET=utf8;

insert into admin (username, password, created_at, updated_at, lock_revision) values ("18686790476","8ddcff3a80f4189ca1c9d4d902c3c909",now(),now(),0);

insert into users (name, code, real_name, sex, avatar, created_at, updated_at, lock_revision) values ("18686790476","8ddcff3a80f4189ca1c9d4d902c3c909","金成柱",0,"",now(),now(),1);

insert into park_attendants (name, code, real_name, sex, avatar, created_at, updated_at, lock_revision) values ("13888888888","8ddcff3a80f4189ca1c9d4d902c3c909","张三",0,"",now(),now(),1);

insert into parkings (id, name,description,addr,charge_standard,longitude,latitude,type,plan_path,space_start,space_total, space_free, qrcode_id,memo,created_at, updated_at,lock_revision) values (1,"ZMAX潮漫酒店停车场","免费停车场","重庆市南岸区茶园同景路8号","(8时～20时)6￥/小时",106.656308,29.503437,0,"","000001",5, 5, 0,"",now(), now(),0);

insert into parking_spaces (id,parking_id, number, status,qrcode_path, created_at, updated_at, lock_revision) values (1,1, "000001", 0,"", now(), now(),0);
insert into parking_spaces (id,parking_id, number, status,qrcode_path, created_at, updated_at, lock_revision) values (2,1, "000002", 0,"", now(), now(),0);
insert into parking_spaces (id,parking_id, number, status,qrcode_path, created_at, updated_at, lock_revision) values (3,1, "000003", 0,"", now(), now(),0);
insert into parking_spaces (id,parking_id, number, status,qrcode_path, created_at, updated_at, lock_revision) values (4,1, "000004", 0,"", now(), now(),0);
insert into parking_spaces (id,parking_id, number, status,qrcode_path, created_at, updated_at, lock_revision) values (5,1, "000005", 0,"", now(), now(),0);

insert into operators (name, code, created_at) values ("重庆xx停车经营有限公司","8ddcff3a80f4189ca1c9d4d902c3c909",now());

insert into operator_parking (operator_id, parking_id, status,created_at,updated_at) values (1,1,0,now(),now());

insert into attendant_parking (attendant_id, parking_id, status,created_at,updated_at) values (1,1,0,now(),now());

insert into parking_accounts (id,acc_no,balance,parking_id,status,type,issuer,created_at,updated_at,memo) values (1,"88888888",0,1,0,0,"帮帮停车",now(),now(),"");

insert into accounts (id,acc_no,pay_code,balance,credit,credit_available,user_id,status,type,issuer,created_at,updated_at,memo) values (1,"18686790476","8ddcff3a80f4189ca1c9d4d902c3c909",100,50,50,1,0,0,"帮帮停车",now(),now(),"");

insert into vehicle (id, plate,engine_no,frame_no,register_time,vehicle_type, created_at, updated_at, lock_revision) values (1, "京A88888","","",now(),0, now(),now(),0);

insert into version (appid, major_version,minor_version,revision,content, help,created_at) values ("BBParkApp",0,5,0,"1.添加版本信息","",now());

insert into version (appid, major_version,minor_version,revision,content, help,created_at) values ("BBParkApp",0,5,1,"1.添加版本信息\n2.修改了注册bug\n3.添加地图功能","",now());

insert into version (appid, major_version,minor_version,revision,content, help,created_at) values ("BBParkApp",0,5,2,"1.添加版本信息\n2.修改了注册bug\n3.添加地图功能\n4.添加注册账户","",now());

insert into version (appid, major_version,minor_version,revision,content, help,created_at) values ("BBParkApp",0,8,2,"1.添加版本信息\n2.修改了注册bug\n3.添加注册账户","",now());

insert into version (appid, major_version,minor_version,revision,content, help,created_at) values ("BBParkApp",0,8,3,"1.添加版本信息\n2.修改了注册bug\n3.添加注册账户","",now());

insert into sysinfo (id,company, slogan, website,contact_hotline,serv_ver, app_ver, handset_ver, created_at) values (1,"重庆帮帮车联科技有限公司","智慧停车，方便你我！","www.bbpark.com.cn","18686790476","0.0.1","0.5.2","0.0.1",now());

update sysinfo set app_ver="0.8.3";

--CREATE TABLE session (id VARCHAR(50) PRIMARY KEY, data BLOB, status INTEGER, expired_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP, updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP);

--insert into user_account (id,user_id, account_id, created_at, updated_at, lock_revision) values (1,1, 1, now(), now(),0);






