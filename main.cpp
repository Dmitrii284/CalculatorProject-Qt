#include <iostream>
#include <QApplication>
#include "Calculator.h"

int main(int argc, char** argv) {
    QApplication app(argc,argv);
    Calculator calculator;
    calculator.setWindowTitle("Calculator");
    calculator.raise();
    calculator.show();
    return app.exec();

}
