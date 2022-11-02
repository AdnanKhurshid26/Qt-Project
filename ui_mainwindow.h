/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QPushButton *found_1;
    QPushButton *found_2;
    QPushButton *found_3;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *new_btn;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *copyBtn;
    QPushButton *cutBtn;
    QPushButton *pasteBtn;
    QTextEdit *find_word;
    QPushButton *findreplace;
    QTextEdit *replace_word;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *findreplaceall;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1215, 615);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 40, 961, 521));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        found_1 = new QPushButton(centralwidget);
        found_1->setObjectName(QString::fromUtf8("found_1"));
        found_1->setGeometry(QRect(1000, 80, 191, 41));
        found_2 = new QPushButton(centralwidget);
        found_2->setObjectName(QString::fromUtf8("found_2"));
        found_2->setGeometry(QRect(1000, 140, 191, 41));
        found_3 = new QPushButton(centralwidget);
        found_3->setObjectName(QString::fromUtf8("found_3"));
        found_3->setGeometry(QRect(1000, 200, 191, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1000, 30, 191, 31));
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 731, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        new_btn = new QPushButton(layoutWidget);
        new_btn->setObjectName(QString::fromUtf8("new_btn"));

        horizontalLayout->addWidget(new_btn);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        copyBtn = new QPushButton(layoutWidget);
        copyBtn->setObjectName(QString::fromUtf8("copyBtn"));

        horizontalLayout->addWidget(copyBtn);

        cutBtn = new QPushButton(layoutWidget);
        cutBtn->setObjectName(QString::fromUtf8("cutBtn"));

        horizontalLayout->addWidget(cutBtn);

        pasteBtn = new QPushButton(layoutWidget);
        pasteBtn->setObjectName(QString::fromUtf8("pasteBtn"));

        horizontalLayout->addWidget(pasteBtn);

        find_word = new QTextEdit(centralwidget);
        find_word->setObjectName(QString::fromUtf8("find_word"));
        find_word->setGeometry(QRect(1010, 310, 181, 31));
        findreplace = new QPushButton(centralwidget);
        findreplace->setObjectName(QString::fromUtf8("findreplace"));
        findreplace->setGeometry(QRect(1020, 430, 171, 41));
        replace_word = new QTextEdit(centralwidget);
        replace_word->setObjectName(QString::fromUtf8("replace_word"));
        replace_word->setGeometry(QRect(1013, 380, 181, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1080, 280, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1070, 350, 63, 20));
        findreplaceall = new QPushButton(centralwidget);
        findreplaceall->setObjectName(QString::fromUtf8("findreplaceall"));
        findreplaceall->setGeometry(QRect(1020, 480, 171, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1215, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        found_1->setText(QString());
        found_2->setText(QString());
        found_3->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Word Suggestions", nullptr));
        new_btn->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        copyBtn->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        cutBtn->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
        pasteBtn->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        findreplace->setText(QCoreApplication::translate("MainWindow", "Find and Replace", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Replace", nullptr));
        findreplaceall->setText(QCoreApplication::translate("MainWindow", "Find and Replace All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
