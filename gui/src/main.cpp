#include "MainWindow.h"
#include <QApplication>

///
/// perform some checkups when initializing eg. missing files...
///
void initializationCheckUp();
void initializationCheckUp(){
    return;
}

int main(int argc, char *argv[]){
    ///
    /// initialization...
    ///
    initializationCheckUp();
    QApplication app(argc, argv);
    ///
    /// removing all the question mark buttons on dialogs...
    ///
    QApplication::setAttribute(Qt::AA_DisableWindowContextHelpButton);
    ///
    /// starting the application...
    ///
    MainWindow w;
    ///
    /// setting the app to the center of Screen on start...
    ///
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-w.width()) / 2;
    int y = (screenGeometry.height()-w.height()) / 2;
    w.move(x, y-35);
    w.show();
    ///
    /// set styleSheet...
    ///
    /*
    QFile file(":/themes/res/themes/native.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    app.setStyleSheet(styleSheet);
    */
    ///
    /// starting the app...
    ///
    return app.exec();
}
