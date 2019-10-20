/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jul 25 13:36:37 2019
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableView *tableView;
    QTableWidget *tableWidget;
    QListView *listView;
    QTreeView *treeView;
    QTreeView *treeView_2;
    QTreeView *treeView_3;
    QTreeView *treeView_4;
    QTreeView *treeView_5;
    QTreeView *treeView_6;
    QTreeView *treeView_7;
    QTreeView *treeView_8;
    QTreeView *treeView_9;
    QTreeView *treeView_10;
    QTreeView *treeView_11;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1302, 692);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 521, 641));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(740, 10, 551, 641));
        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(20, 20, 161, 41));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(40, 70, 111, 31));
        treeView_2 = new QTreeView(centralWidget);
        treeView_2->setObjectName(QString::fromUtf8("treeView_2"));
        treeView_2->setGeometry(QRect(40, 120, 111, 31));
        treeView_3 = new QTreeView(centralWidget);
        treeView_3->setObjectName(QString::fromUtf8("treeView_3"));
        treeView_3->setGeometry(QRect(40, 170, 111, 31));
        treeView_4 = new QTreeView(centralWidget);
        treeView_4->setObjectName(QString::fromUtf8("treeView_4"));
        treeView_4->setGeometry(QRect(40, 220, 111, 31));
        treeView_5 = new QTreeView(centralWidget);
        treeView_5->setObjectName(QString::fromUtf8("treeView_5"));
        treeView_5->setGeometry(QRect(40, 320, 111, 31));
        treeView_6 = new QTreeView(centralWidget);
        treeView_6->setObjectName(QString::fromUtf8("treeView_6"));
        treeView_6->setGeometry(QRect(40, 270, 111, 31));
        treeView_7 = new QTreeView(centralWidget);
        treeView_7->setObjectName(QString::fromUtf8("treeView_7"));
        treeView_7->setGeometry(QRect(40, 370, 111, 31));
        treeView_8 = new QTreeView(centralWidget);
        treeView_8->setObjectName(QString::fromUtf8("treeView_8"));
        treeView_8->setGeometry(QRect(40, 420, 111, 31));
        treeView_9 = new QTreeView(centralWidget);
        treeView_9->setObjectName(QString::fromUtf8("treeView_9"));
        treeView_9->setGeometry(QRect(40, 470, 111, 31));
        treeView_10 = new QTreeView(centralWidget);
        treeView_10->setObjectName(QString::fromUtf8("treeView_10"));
        treeView_10->setGeometry(QRect(40, 570, 111, 31));
        treeView_11 = new QTreeView(centralWidget);
        treeView_11->setObjectName(QString::fromUtf8("treeView_11"));
        treeView_11->setGeometry(QRect(40, 520, 111, 31));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
