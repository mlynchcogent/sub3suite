#ifndef IP_H
#define IP_H

#include "src/core.h"
#include "IpEnumerator.h"
#include "src/Dialogs/ConfigDialog.h"

namespace Ui {
    class Ip;
}

class Ip : public QDialog
{
        Q_OBJECT

    private:
        Ui::Ip *ui;

    private:
        void startScan();
        //...
        ScanStatus *m_scanStatus;
        ScanConfig *m_scanConfig;
        ScanArguments_Ip *m_scanArguments;
        //...
        QStandardItemModel *m_model_results;
        //...
        int m_activeThreads = 0;

    public:
        explicit Ip(QWidget *parent = nullptr);
        ~Ip();

    signals:
        void stop();
        //...
        void sendStatus(QString status);
        void sendLog(QString log);

    public slots:
        void scanResult(QString subdomain, QString ipAddress);
        void scanThreadEnded();
        //...
        void logs(QString log);

    private slots:
        void on_pushButton_start_clicked();
        void on_pushButton_stop_clicked();
        void on_pushButton_get_clicked();
        void on_pushButton_action_clicked();
        void on_toolButton_config_clicked();
        void on_pushButton_clearResults_clicked();
        //...
        void on_pushButton_removeTargets_clicked();
        void on_pushButton_clearTargets_clicked();
        void on_pushButton_loadTargets_clicked();
        void on_pushButton_addTargets_clicked();
        void on_lineEdit_targets_returnPressed();
        //...
        void on_radioButton_hostname_clicked();
        void on_radioButton_ip_clicked();
        void on_comboBox_option_currentIndexChanged(int index);
        void on_tableView_results_customContextMenuRequested(const QPoint &pos);
        // context...
        void actionSendToMultiLevel();
        void actionSendToSave();
        void actionSendToDnsRecords();
        // cursor...
        void cursorSendToSave();
        void cursorSendToDnsRecords();
        void cursorOpenInBrowser();
        void on_pushButton_pause_clicked();
};

#endif // IP_H
