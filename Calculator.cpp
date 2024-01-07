
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include "Calculator.h"

//
// Created by dmitriy on 07.01.24.
//

Calculator::Calculator(QWidget* pwgt) : QWidget(pwgt)
{
m_plcd = new QLCDNumber(12);
m_plcd->setSegmentStyle(QLCDNumber::Flat);
m_plcd->setMinimumSize(150, 50);

QChar aButtons[4][4] = {
        {'7','8','/'}
        ,{'4','5','6','*'}
        ,{'1','2','3','-'}
        ,{'0','.','=','+'}
};
QGridLayout* potopLayput =new QGridLayout;
    potopLayput->addWidget(m_plcd, 0, 0, 1, 4);
    potopLayput->addWidget(createButton("CE"), 1 , 3);
    for(int i=0; i<4;++i){
        for (int j = 0; j < 4; ++j) {
            potopLayput->addWidget(createButton(aButtons[i][j]), i + 2, j);
        }
    }
    setLayout(potopLayput);
}

QPushButton *Calculator::createButton(const QString &str) {
    QPushButton* pcmd = new QPushButton(str);
    pcmd->setMinimumSize(40,40);
    connect(pcmd, SIGNAL(cliced()), SLOT(slotButtonClicked()));
    return pcmd;
}

void Calculator::calculate() {
qreal fOperand2 = m_stk.pop().toFloat();
QString stringOperation =m_stk.pop();
qreal  fOperand1 = m_stk.pop().toFloat();
qreal fResult = 0;
if(stringOperation =='+') {
    fResult = fOperand1 + fOperand2;
}
if(stringOperation == '-'){
    fResult = fOperand1 - fOperand2;
}
    if(stringOperation == '*'){
        fResult = fOperand1 * fOperand2;
    }
    if(stringOperation == '/'){
        fResult = fOperand1 / fOperand2;
    }
    m_plcd->display(fResult);
}

void Calculator::slotButtonCliced() {
        QString str;
        str = ((QPushButton *) sender())->text();
     if(str =="CE"){
         m_stk.clear();
         m_strDisplay="";
         m_plcd->display("0");
         return;
     }
     if(str.contains(QRegExp("[0-9]"))){
         m_strDisplay +=str;
         m_plcd->display(m_strDisplay.toDouble());
     } else {
         if(m_stk.count()>=2){
             m_stk.push(QString().setNum(m_plcd->value()));
             calculate();
             m_stk.clear();
             m_stk.push(QString().setNum(m_plcd->value()));
             if(str != "="){
                 m_stk.push(str);
             }
         } else{
             m_stk.push(str);
             m_strDisplay = "";
         }
     }
}
