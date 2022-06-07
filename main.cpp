#include <QApplication>
#include <QPushButton>

#include "UI.h"

int main(int argc, char *argv[]) {
    test_domain();
    test_repo();
    test_service();

    QApplication a(argc, argv);

    FileRepo rp{"data.txt"};
    Service srv{rp};
    GUI app{srv};

    app.show();

    return QApplication::exec();
}
