/*
 Copyright 2020-2022 Enock Nicholaus <3nock@protonmail.com>. All rights reserved.
 Use of this source code is governed by GPL-3.0 LICENSE that can be found in the LICENSE file.

 @brief :
*/

#ifndef NSITEM_H
#define NSITEM_H

#include <QStandardItem>
#include <QDate>
#include <QSet>

#define JSON_ARRAY "arr"
#define JSON_OBJECT "obj"

namespace s3s_struct {
struct NS {
    QString info_ns;
    QString info_ip;
    QSet<QString> domains;
};
}

namespace s3s_item {

class NS: public QStandardItem {
public:
    NS(): QStandardItem (),
        info(new QStandardItem("Info")),
        domains(new QStandardItem("Domains")),
        /* info */
        info_ns(new QStandardItem),
        info_ip(new QStandardItem)
    {
        this->setForeground(Qt::white);
        this->setIcon(QIcon(":/img/res/icons/folder.png"));

        info->setForeground(Qt::white);
        domains->setForeground(Qt::white);

        info->setWhatsThis(JSON_OBJECT);
        domains->setWhatsThis(JSON_ARRAY);

        info->setIcon(QIcon(":/img/res/icons/folder2.png"));
        domains->setIcon(QIcon(":/img/res/icons/folder2.png"));

        info->appendRow({new QStandardItem("NameServer"), info_ns});
        info->appendRow({new QStandardItem("Ip"), info_ip});

        /* append to the NS */
        this->appendRow(info);
        this->appendRow(domains);
    }
    ~NS()
    {
    }

public:
    QStandardItem *info;
    QStandardItem *domains;
    /* info */
    QStandardItem *info_ns;
    QStandardItem *info_ip;

    /* summary */
    QString last_modified;
    QString comment;

    void setValues(const s3s_struct::NS &ns){
        this->setText(ns.info_ns);

        /* info */
        info_ns->setText(ns.info_ns);
        info_ip->setText(ns.info_ip);

        /* domains */
        int count = domains->rowCount();
        foreach(const QString &domain, ns.domains){
            domains->appendRow({new QStandardItem(QString::number(count)),
                                new QStandardItem(domain)});
            count++;
        }

        /* last modified */
        last_modified = QDate::currentDate().toString();
    }
};

}

s3s_struct::NS ns_to_struct(s3s_item::NS*);

QJsonObject ns_to_json(s3s_item::NS*);

void json_to_ns(const QJsonObject&, s3s_item::NS*);

#endif // NSITEM_H
