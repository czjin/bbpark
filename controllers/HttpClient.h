#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QTimer>

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = 0);
    ~HttpClient();
    //http get请求
    QString get(QNetworkRequest& request);
    //http post请求
    QString post(QNetworkRequest& request, const QByteArray& data);
    //是否发生网络错误
    bool hasNetworkError(){ return this->m_hasNetworkError; }
    //获取网络连接错误代码
    int getNetworkErrorCode(){ return this->m_networkErrorCode; }
    //网络连接是否完成
    bool isHttpFinish(){ return this->m_isFinished; }
    //设置超时
    void setTimeOutLimit(int time);
signals:

public slots:
    //http请求完成
    void httpRequestFinished(QNetworkReply* reply);
    //请求超时处理
    void timeOutHandler();
    //网络错误处理
    void networkErrorHandler(QNetworkReply::NetworkError error);

private:
    QNetworkReply* m_pNetworkReply;
    QNetworkAccessManager *m_pNetworkMgr;
    bool m_hasNetworkError;//是否发生网络错误
    int m_networkErrorCode;//错误代码.如果发生网络错误,该值不为0
    QByteArray m_contentInByteArray;//请求到的内容
    QEventLoop* m_pEventLoop;//接受内容时保持响应
    volatile bool m_isFinished;
    QTimer* m_timer;//定时,用于超时检测
    int m_timeLimit;//用于设置超时

};

#endif // HTTPCLIENT_H
