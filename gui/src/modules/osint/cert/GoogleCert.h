#ifndef GOOGLECERT_H
#define GOOGLECERT_H

#include "../AbstractOsintModule.h"

namespace ModuleInfo {
    struct GoogleCert{
        QString name = "GoogleCert";
        QString url = "https://transparencyreport.google.com/";
        QString url_apiDoc = "https://transparencyreport.google.com/";
        QString summary = "Sharing data that sheds light on how the policies and actions of governments and \n"
                          "corporations affect privacy, security, and access to information.";

        QMap<QString, QStringList> flags = {{"Domain cert",
                                             {PLACEHOLDERTEXT_DOMAIN, "Search SSL cert by domain name"}}};
    };
}

class GoogleCert: public AbstractOsintModule{

    public:
        GoogleCert(ScanArgs *args);
        ~GoogleCert() override;

    public slots:
        void start() override;
        void replyFinishedSubdomain(QNetworkReply *reply) override;
        void replyFinishedSSLCert(QNetworkReply *reply) override;

    private:
        void m_getToken(QJsonArray tokenArray);
};

#endif // GOOGLECERT_H
