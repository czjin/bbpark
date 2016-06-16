#include "HttpClient.h"
#include <QTextCodec>
#include <QDebug>

HttpClient::HttpClient(QObject *parent) :
    QObject(parent)
{
    this->m_contentInByteArray.clear();
    this->m_hasNetworkError = false;
    this->m_isFinished = false;
    this->m_networkErrorCode = QNetworkReply::NoError;
    this->m_pEventLoop = new QEventLoop(this);
    this->m_pNetworkMgr = new QNetworkAccessManager(this);
    this->m_pNetworkReply = NULL;
    this->m_timeLimit = 60*1000;
    this->m_timer = new QTimer(this);
    QObject::connect( this->m_pNetworkMgr, SIGNAL(finished(QNetworkReply*)), this, SLOT(httpRequestFinished(QNetworkReply*)));
    //QObject::connect( network, SIGNAL(finished(QNetworkReply*)), this, SIGNAL(finished()));
    QObject::connect( this->m_timer, SIGNAL(timeout()), this, SLOT(timeOutHandler()));
}
HttpClient::~HttpClient()
{
    delete this->m_pEventLoop;
    this->m_pEventLoop = NULL;
    delete this->m_pNetworkMgr;
    this->m_pNetworkMgr = NULL;
    delete this->m_timer;
    this->m_timer = NULL;
}
QString HttpClient::get(QNetworkRequest &request)
{
    this->m_pNetworkReply = this->m_pNetworkMgr->get(request);
    QObject::connect(this->m_pNetworkReply, SIGNAL(error(QNetworkReply::NetworkError)),
                     this, SLOT(networkErrorHandler(QNetworkReply::NetworkError)));
    //计时器启动
    this->m_timer->start(this->m_timeLimit);
    this->m_pEventLoop->exec();
    this->m_pNetworkReply->close();
    delete this->m_pNetworkReply;
    this->m_pNetworkReply = NULL;
    if(!this->hasNetworkError()){
        //QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        //return codec->toUnicode(this->m_contentInByteArray);
        return QString(this->m_contentInByteArray);
    }
    else
    {
        return QString::null;
    }
}
QString HttpClient::post(QNetworkRequest &request, const QByteArray &data)
{
    this->m_pNetworkReply = this->m_pNetworkMgr->post(request,data);
    QObject::connect(this->m_pNetworkReply, SIGNAL(error(QNetworkReply::NetworkError)),
                     this, SLOT(networkErrorHandler(QNetworkReply::NetworkError)));
    //计时器启动
    m_timer->start(this->m_timeLimit);
    m_pEventLoop->exec();
    this->m_pNetworkReply->close();
    delete this->m_pNetworkReply;
    this->m_pNetworkReply = NULL;
    if(!this->hasNetworkError()) {
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        return codec->toUnicode(this->m_contentInByteArray);
    }
    else
        return QString::null;
}
void HttpClient::httpRequestFinished(QNetworkReply *reply)
{

    this->m_isFinished = true;
    this->m_contentInByteArray = reply->readAll();

    this->m_timer->stop();
    this->m_pEventLoop->exit();
}
void HttpClient::timeOutHandler()
{
    this->m_hasNetworkError = true;
    this->m_networkErrorCode = QNetworkReply::TimeoutError;
    this->m_contentInByteArray = this->m_pNetworkReply->readAll();
    this->m_timer->stop();
    this->m_pEventLoop->exit();
}
void HttpClient::networkErrorHandler(QNetworkReply::NetworkError error)
{
    this->m_hasNetworkError = true;
    this->m_networkErrorCode = error;
    qDebug()<<"网络错误描述:"<<this->m_pNetworkReply->errorString();
    qDebug()<<"网络错误代码:"<<this->m_pNetworkReply->error();
}
void HttpClient::setTimeOutLimit(int time)
{
    this->m_timeLimit = time;
}

