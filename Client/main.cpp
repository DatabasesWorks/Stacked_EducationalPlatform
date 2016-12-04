#include "client.h"
#include <QApplication>
#include <qfile.h>
#include <QTextStream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //Initializing style sheets
    QFile f(":qdarkstyle/style.qss");

    if (!f.exists()) {
        printf("Unable to set stylesheet, file not found\n");
    } else {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }
    f.close();

    Client w;
    w.show();

    return a.exec();
}
