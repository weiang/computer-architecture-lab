/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_10;
    QRadioButton *addressStreamFile;
    QRadioButton *inputByHand;
    QCommandLinkButton *stepByStep;
    QCommandLinkButton *run;
    QFrame *line;
    QLabel *label_11;
    QFrame *line_2;
    QLabel *label_12;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *uniCacheSelected;
    QComboBox *sizeCache;
    QRadioButton *idCacheSelected;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *dCacheSize;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *iCacheSize;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *sizeBlock;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *sizeWay;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QComboBox *replaceMethod;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QComboBox *prefetchMethod;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QComboBox *writeMethod;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QComboBox *blockFetchMethod;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label;
    QCommandLinkButton *reset;
    QCommandLinkButton *lookUp;
    QLineEdit *filePath;
    QLabel *label_13;
    QLabel *label_17;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_14;
    QLabel *totalAccessNum;
    QLabel *label_16;
    QLabel *totalMissNum;
    QLabel *label_19;
    QLabel *totalMissRate;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_26;
    QLabel *readINum;
    QLabel *label_25;
    QLabel *readIMissNum;
    QLabel *label_22;
    QLabel *readIMissRate;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_32;
    QLabel *readDNum;
    QLabel *label_31;
    QLabel *readDMissNum;
    QLabel *label_28;
    QLabel *readDMissRate;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_38;
    QLabel *writeNum;
    QLabel *label_37;
    QLabel *writeMissNum;
    QLabel *label_34;
    QLabel *writeMissRate;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_15;
    QComboBox *cmdKind;
    QLineEdit *address;
    QLabel *label_15;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(939, 732);
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 520, 67, 17));
        addressStreamFile = new QRadioButton(centralWidget);
        addressStreamFile->setObjectName(QStringLiteral("addressStreamFile"));
        addressStreamFile->setGeometry(QRect(50, 550, 117, 22));
        inputByHand = new QRadioButton(centralWidget);
        inputByHand->setObjectName(QStringLiteral("inputByHand"));
        inputByHand->setGeometry(QRect(50, 620, 117, 22));
        stepByStep = new QCommandLinkButton(centralWidget);
        stepByStep->setObjectName(QStringLiteral("stepByStep"));
        stepByStep->setGeometry(QRect(430, 120, 81, 31));
        run = new QCommandLinkButton(centralWidget);
        run->setObjectName(QStringLiteral("run"));
        run->setGeometry(QRect(510, 120, 91, 31));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 60, 981, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(300, 10, 181, 41));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(350, 70, 20, 801));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(380, 80, 101, 41));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 140, 235, 60));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        uniCacheSelected = new QRadioButton(layoutWidget);
        uniCacheSelected->setObjectName(QStringLiteral("uniCacheSelected"));

        horizontalLayout_3->addWidget(uniCacheSelected);

        sizeCache = new QComboBox(layoutWidget);
        sizeCache->setObjectName(QStringLiteral("sizeCache"));

        horizontalLayout_3->addWidget(sizeCache);


        verticalLayout->addLayout(horizontalLayout_3);

        idCacheSelected = new QRadioButton(layoutWidget);
        idCacheSelected->setObjectName(QStringLiteral("idCacheSelected"));

        verticalLayout->addWidget(idCacheSelected);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(60, 210, 201, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        dCacheSize = new QComboBox(layoutWidget1);
        dCacheSize->setObjectName(QStringLiteral("dCacheSize"));

        horizontalLayout->addWidget(dCacheSize);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(60, 250, 200, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        iCacheSize = new QComboBox(layoutWidget2);
        iCacheSize->setObjectName(QStringLiteral("iCacheSize"));

        horizontalLayout_2->addWidget(iCacheSize);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 290, 265, 221));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        sizeBlock = new QComboBox(layoutWidget3);
        sizeBlock->setObjectName(QStringLiteral("sizeBlock"));

        horizontalLayout_4->addWidget(sizeBlock);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        sizeWay = new QComboBox(layoutWidget3);
        sizeWay->setObjectName(QStringLiteral("sizeWay"));

        horizontalLayout_5->addWidget(sizeWay);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        replaceMethod = new QComboBox(layoutWidget3);
        replaceMethod->setObjectName(QStringLiteral("replaceMethod"));

        horizontalLayout_6->addWidget(replaceMethod);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        prefetchMethod = new QComboBox(layoutWidget3);
        prefetchMethod->setObjectName(QStringLiteral("prefetchMethod"));

        horizontalLayout_7->addWidget(prefetchMethod);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        writeMethod = new QComboBox(layoutWidget3);
        writeMethod->setObjectName(QStringLiteral("writeMethod"));

        horizontalLayout_8->addWidget(writeMethod);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_9->addWidget(label_9);

        blockFetchMethod = new QComboBox(layoutWidget3);
        blockFetchMethod->setObjectName(QStringLiteral("blockFetchMethod"));

        horizontalLayout_9->addWidget(blockFetchMethod);


        verticalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout_3->addLayout(verticalLayout_2);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 80, 280, 38));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget4);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_10->addWidget(label);

        reset = new QCommandLinkButton(layoutWidget4);
        reset->setObjectName(QStringLiteral("reset"));

        horizontalLayout_10->addWidget(reset);

        lookUp = new QCommandLinkButton(centralWidget);
        lookUp->setObjectName(QStringLiteral("lookUp"));
        lookUp->setGeometry(QRect(240, 580, 61, 31));
        filePath = new QLineEdit(centralWidget);
        filePath->setObjectName(QStringLiteral("filePath"));
        filePath->setGeometry(QRect(80, 580, 131, 31));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(950, -510, 81, 31));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(420, 320, 67, 17));
        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(413, 268, 457, 41));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(layoutWidget5);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_11->addWidget(label_14);

        totalAccessNum = new QLabel(layoutWidget5);
        totalAccessNum->setObjectName(QStringLiteral("totalAccessNum"));

        horizontalLayout_11->addWidget(totalAccessNum);

        label_16 = new QLabel(layoutWidget5);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_11->addWidget(label_16);

        totalMissNum = new QLabel(layoutWidget5);
        totalMissNum->setObjectName(QStringLiteral("totalMissNum"));

        horizontalLayout_11->addWidget(totalMissNum);

        label_19 = new QLabel(layoutWidget5);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_11->addWidget(label_19);

        totalMissRate = new QLabel(layoutWidget5);
        totalMissRate->setObjectName(QStringLiteral("totalMissRate"));

        horizontalLayout_11->addWidget(totalMissRate);

        layoutWidget6 = new QWidget(centralWidget);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(415, 340, 451, 141));
        verticalLayout_4 = new QVBoxLayout(layoutWidget6);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_26 = new QLabel(layoutWidget6);
        label_26->setObjectName(QStringLiteral("label_26"));

        horizontalLayout_12->addWidget(label_26);

        readINum = new QLabel(layoutWidget6);
        readINum->setObjectName(QStringLiteral("readINum"));

        horizontalLayout_12->addWidget(readINum);

        label_25 = new QLabel(layoutWidget6);
        label_25->setObjectName(QStringLiteral("label_25"));

        horizontalLayout_12->addWidget(label_25);

        readIMissNum = new QLabel(layoutWidget6);
        readIMissNum->setObjectName(QStringLiteral("readIMissNum"));

        horizontalLayout_12->addWidget(readIMissNum);

        label_22 = new QLabel(layoutWidget6);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_12->addWidget(label_22);

        readIMissRate = new QLabel(layoutWidget6);
        readIMissRate->setObjectName(QStringLiteral("readIMissRate"));
        readIMissRate->setMinimumSize(QSize(54, 40));

        horizontalLayout_12->addWidget(readIMissRate);


        verticalLayout_4->addLayout(horizontalLayout_12);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_32 = new QLabel(layoutWidget6);
        label_32->setObjectName(QStringLiteral("label_32"));

        horizontalLayout_14->addWidget(label_32);

        readDNum = new QLabel(layoutWidget6);
        readDNum->setObjectName(QStringLiteral("readDNum"));

        horizontalLayout_14->addWidget(readDNum);

        label_31 = new QLabel(layoutWidget6);
        label_31->setObjectName(QStringLiteral("label_31"));

        horizontalLayout_14->addWidget(label_31);

        readDMissNum = new QLabel(layoutWidget6);
        readDMissNum->setObjectName(QStringLiteral("readDMissNum"));

        horizontalLayout_14->addWidget(readDMissNum);

        label_28 = new QLabel(layoutWidget6);
        label_28->setObjectName(QStringLiteral("label_28"));

        horizontalLayout_14->addWidget(label_28);

        readDMissRate = new QLabel(layoutWidget6);
        readDMissRate->setObjectName(QStringLiteral("readDMissRate"));
        readDMissRate->setMinimumSize(QSize(54, 41));

        horizontalLayout_14->addWidget(readDMissRate);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_38 = new QLabel(layoutWidget6);
        label_38->setObjectName(QStringLiteral("label_38"));

        horizontalLayout_13->addWidget(label_38);

        writeNum = new QLabel(layoutWidget6);
        writeNum->setObjectName(QStringLiteral("writeNum"));

        horizontalLayout_13->addWidget(writeNum);

        label_37 = new QLabel(layoutWidget6);
        label_37->setObjectName(QStringLiteral("label_37"));

        horizontalLayout_13->addWidget(label_37);

        writeMissNum = new QLabel(layoutWidget6);
        writeMissNum->setObjectName(QStringLiteral("writeMissNum"));

        horizontalLayout_13->addWidget(writeMissNum);

        label_34 = new QLabel(layoutWidget6);
        label_34->setObjectName(QStringLiteral("label_34"));

        horizontalLayout_13->addWidget(label_34);

        writeMissRate = new QLabel(layoutWidget6);
        writeMissRate->setObjectName(QStringLiteral("writeMissRate"));
        writeMissRate->setMinimumSize(QSize(54, 40));

        horizontalLayout_13->addWidget(writeMissRate);


        verticalLayout_4->addLayout(horizontalLayout_13);

        layoutWidget7 = new QWidget(centralWidget);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(80, 650, 211, 31));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        cmdKind = new QComboBox(layoutWidget7);
        cmdKind->setObjectName(QStringLiteral("cmdKind"));

        horizontalLayout_15->addWidget(cmdKind);

        address = new QLineEdit(layoutWidget7);
        address->setObjectName(QStringLiteral("address"));

        horizontalLayout_15->addWidget(address);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(570, 200, 131, 41));
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        run->raise();
        label_10->raise();
        addressStreamFile->raise();
        inputByHand->raise();
        stepByStep->raise();
        line->raise();
        label_11->raise();
        line_2->raise();
        label_12->raise();
        lookUp->raise();
        filePath->raise();
        label_13->raise();
        label_17->raise();
        label_15->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label_4->setBuddy(sizeBlock);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_10->setText(QApplication::translate("MainWindow", "\345\234\260\345\235\200\350\256\277\351\227\256\357\274\232", 0));
        addressStreamFile->setText(QApplication::translate("MainWindow", "\345\234\260\345\235\200\346\265\201\346\226\207\344\273\266\357\274\232", 0));
        inputByHand->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\350\276\223\345\205\245", 0));
        stepByStep->setText(QApplication::translate("MainWindow", "\346\255\245\350\277\233", 0));
        run->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214\345\210\260\345\272\225", 0));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:24pt; color:#0000ff;\">Cache\346\250\241\346\213\237\345\231\250</span></p></body></html>", 0));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; color:#ff0000;\">\346\211\247\350\241\214\346\216\247\345\210\266</span></p></body></html>", 0));
        uniCacheSelected->setText(QApplication::translate("MainWindow", "\347\273\237\344\270\200Cache\347\232\204\345\244\247\345\260\217\357\274\232", 0));
        sizeCache->clear();
        sizeCache->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "2K", 0)
         << QApplication::translate("MainWindow", "4K", 0)
         << QApplication::translate("MainWindow", "8K", 0)
         << QApplication::translate("MainWindow", "16K", 0)
         << QApplication::translate("MainWindow", "32K", 0)
         << QApplication::translate("MainWindow", "64K", 0)
         << QApplication::translate("MainWindow", "128K", 0)
         << QApplication::translate("MainWindow", "256K", 0)
         << QApplication::translate("MainWindow", "512K", 0)
         << QApplication::translate("MainWindow", "1M", 0)
        );
        sizeCache->setCurrentText(QApplication::translate("MainWindow", "2K", 0));
        idCacheSelected->setText(QApplication::translate("MainWindow", "\347\213\254\347\253\213Cache\357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256cache\347\232\204\345\244\247\345\260\217\357\274\232", 0));
        dCacheSize->clear();
        dCacheSize->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1K", 0)
         << QApplication::translate("MainWindow", "2K", 0)
         << QApplication::translate("MainWindow", "4K", 0)
         << QApplication::translate("MainWindow", "8K", 0)
         << QApplication::translate("MainWindow", "16K", 0)
         << QApplication::translate("MainWindow", "32K", 0)
         << QApplication::translate("MainWindow", "64K", 0)
         << QApplication::translate("MainWindow", "128K", 0)
         << QApplication::translate("MainWindow", "256K", 0)
         << QApplication::translate("MainWindow", "512K", 0)
        );
        label_2->setText(QApplication::translate("MainWindow", "\346\214\207\344\273\244cache\347\232\204\345\244\247\345\260\217\357\274\232", 0));
        iCacheSize->clear();
        iCacheSize->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1K", 0)
         << QApplication::translate("MainWindow", "2K", 0)
         << QApplication::translate("MainWindow", "4K", 0)
         << QApplication::translate("MainWindow", "8K", 0)
         << QApplication::translate("MainWindow", "16K", 0)
         << QApplication::translate("MainWindow", "32K", 0)
         << QApplication::translate("MainWindow", "64K", 0)
         << QApplication::translate("MainWindow", "128K", 0)
         << QApplication::translate("MainWindow", "256K", 0)
         << QApplication::translate("MainWindow", "512K", 0)
        );
        label_4->setText(QApplication::translate("MainWindow", "\345\235\227\345\244\247\345\260\217\357\274\232", 0));
        sizeBlock->clear();
        sizeBlock->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "32B", 0)
         << QApplication::translate("MainWindow", "64B", 0)
         << QApplication::translate("MainWindow", "128B", 0)
         << QApplication::translate("MainWindow", "256B", 0)
         << QApplication::translate("MainWindow", "512B", 0)
        );
        label_5->setText(QApplication::translate("MainWindow", "\347\233\270\350\277\236\345\272\246\357\274\232", 0));
        sizeWay->clear();
        sizeWay->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\233\264\346\216\245\346\230\240\345\260\204", 0)
         << QApplication::translate("MainWindow", "2\350\267\257", 0)
         << QApplication::translate("MainWindow", "4\350\267\257", 0)
         << QApplication::translate("MainWindow", "8\350\267\257", 0)
         << QApplication::translate("MainWindow", "16\350\267\257", 0)
         << QApplication::translate("MainWindow", "32\350\267\257", 0)
        );
        label_6->setText(QApplication::translate("MainWindow", "\346\233\277\346\215\242\347\255\226\347\225\245\357\274\232", 0));
        replaceMethod->clear();
        replaceMethod->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "LRU", 0)
         << QApplication::translate("MainWindow", "FIFO", 0)
         << QApplication::translate("MainWindow", "RAND", 0)
        );
        label_7->setText(QApplication::translate("MainWindow", "\351\242\204\345\217\226\347\255\226\347\225\245\357\274\232", 0));
        prefetchMethod->clear();
        prefetchMethod->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\215\351\242\204\345\217\226", 0)
         << QApplication::translate("MainWindow", "\344\270\215\345\221\275\344\270\255\351\242\204\345\217\226", 0)
        );
        label_8->setText(QApplication::translate("MainWindow", "\345\206\231\347\255\226\347\225\245\357\274\232", 0));
        writeMethod->clear();
        writeMethod->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\206\231\345\233\236\346\263\225", 0)
         << QApplication::translate("MainWindow", "\345\206\231\347\233\264\350\276\276\346\263\225", 0)
        );
        label_9->setText(QApplication::translate("MainWindow", "\345\206\231\344\270\215\345\221\275\344\270\255\347\232\204\350\260\203\345\235\227\347\255\226\347\225\245\357\274\232", 0));
        blockFetchMethod->clear();
        blockFetchMethod->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\214\211\345\206\231\345\210\206\351\205\215", 0)
         << QApplication::translate("MainWindow", "\344\270\215\346\214\211\345\206\231\345\210\206\351\205\215", 0)
        );
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; color:#ff0000;\">\350\256\276\347\275\256\345\217\202\346\225\260</span></p></body></html>", 0));
        reset->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215", 0));
        lookUp->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", 0));
        label_13->setText(QApplication::translate("MainWindow", "\346\250\241\346\213\237\347\273\223\346\236\234", 0));
        label_17->setText(QApplication::translate("MainWindow", "\345\205\266\344\270\255\357\274\232", 0));
        label_14->setText(QApplication::translate("MainWindow", "\346\200\273\350\256\277\351\227\256\346\254\241\346\225\260\357\274\232", 0));
        totalAccessNum->setText(QApplication::translate("MainWindow", "0", 0));
        label_16->setText(QApplication::translate("MainWindow", "\344\270\215\345\221\275\344\270\255\346\254\241\346\225\260\357\274\232", 0));
        totalMissNum->setText(QApplication::translate("MainWindow", "0", 0));
        label_19->setText(QApplication::translate("MainWindow", "\344\270\215\345\221\275\344\270\255\347\216\207\357\274\232", 0));
        totalMissRate->setText(QApplication::translate("MainWindow", "0.0%", 0));
        label_26->setText(QApplication::translate("MainWindow", "\350\257\273\346\214\207\344\273\244\346\254\241\346\225\260\357\274\232", 0));
        readINum->setText(QApplication::translate("MainWindow", "0", 0));
        label_25->setText(QApplication::translate("MainWindow", "\344\270\215\345\221\275\344\270\255\346\254\241\346\225\260\357\274\232", 0));
        readIMissNum->setText(QApplication::translate("MainWindow", "0", 0));
        label_22->setText(QApplication::translate("MainWindow", "\344\270\215\345\221\275\344\270\255\347\216\207\357\274\232", 0));
        readIMissRate->setText(QApplication::translate("MainWindow", "0.0%", 0));
        label_32->setText(QApplication::translate("MainWindow", "\350\257\273\346\225\260\346\215\256\346\254\241\346\225\260\357\274\232", 0));
        readDNum->setText(QApplication::translate("MainWindow", "0", 0));
        label_31->setText(QApplication::translate("MainWindow", "\344\270\215\345\221\275\344\270\255\346\254\241\346\225\260\357\274\232", 0));
        readDMissNum->setText(QApplication::translate("MainWindow", "0", 0));
        label_28->setText(QApplication::translate("MainWindow", "\344\270\215\345\221\275\344\270\255\347\216\207\357\274\232", 0));
        readDMissRate->setText(QApplication::translate("MainWindow", "0.0%", 0));
        label_38->setText(QApplication::translate("MainWindow", "\345\206\231\346\225\260\346\215\256\346\254\241\346\225\260\357\274\232", 0));
        writeNum->setText(QApplication::translate("MainWindow", "0", 0));
        label_37->setText(QApplication::translate("MainWindow", "\344\270\215\345\221\275\344\270\255\346\254\241\346\225\260\357\274\232", 0));
        writeMissNum->setText(QApplication::translate("MainWindow", "0", 0));
        label_34->setText(QApplication::translate("MainWindow", "\344\270\215\345\221\275\344\270\255\347\216\207\357\274\232", 0));
        writeMissRate->setText(QApplication::translate("MainWindow", "0.0%", 0));
        cmdKind->clear();
        cmdKind->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\350\257\273\346\225\260\346\215\256", 0)
         << QApplication::translate("MainWindow", "\345\206\231\346\225\260\346\215\256", 0)
         << QApplication::translate("MainWindow", "\350\257\273\346\214\207\344\273\244", 0)
        );
        label_15->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; color:#ff0000;\">\346\211\247\350\241\214\347\273\223\346\236\234</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
