#include <QApplication>
#include <QTextEdit>
#include <QtGui>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QTextEdit textEdit;
    QPushButton quitButton("Quit");

    /* 10 */ QObject::connect(&quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    /* 12 */ QVBoxLayout layout;
    /* 13 */ layout.addWidget(&textEdit);
    /* 14 */ layout.addWidget(&quitButton);

    QWidget window;
    /* 17 */ window.setLayout(&layout);

    window.show();

    return app.exec();
}
