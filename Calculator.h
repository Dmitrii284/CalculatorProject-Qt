//
// Created by dmitriy on 07.01.24.
//
#pragma once
#include <QWidget>
#include <QStack>
class QLCDNumber;
class QPushButton;
#ifndef TASK_QT_CALCULATOR_CALCULATOR_H
#define TASK_QT_CALCULATOR_CALCULATOR_H


class Calculator : public  QWidget {
    Q_OBJECT
private:
    QLCDNumber* m_plcd{};
    QStack<QString> m_stk;
    QString m_strDisplay;
public:
    Calculator(QWidget* pwgt = 0);
    QPushButton* createButton(const QString& str);
    void calculate();
public slots:
    void slotButtonCliced();
};

#endif //TASK_QT_CALCULATOR_CALCULATOR_H
