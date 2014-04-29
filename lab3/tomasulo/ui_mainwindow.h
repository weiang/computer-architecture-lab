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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QCommandLinkButton *reset;
    QCommandLinkButton *execute;
    QTableWidget *exeCycle;
    QGroupBox *groupBox_8;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QComboBox *i[10][4];
    QWidget *page_2;
    QGroupBox *groupBox_2;
    QTableWidget *is;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QCommandLinkButton *stepOneBack;
    QCommandLinkButton *stepOneFront;
    QCommandLinkButton *stepFiveFront;
    QCommandLinkButton *stepFiveBack;
    QCommandLinkButton *allToOne;
    QCommandLinkButton *exit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *currentTime;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *jumpTo;
    QCommandLinkButton *go;
    QGroupBox *groupBox_4;
    QTableWidget *rs;
    QGroupBox *groupBox_5;
    QTableWidget *lb;
    QGroupBox *groupBox_6;
    QTableWidget *sb;
    QGroupBox *groupBox_7;
    QTableWidget *r;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1057, 868);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 931, 341));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(610, 30, 291, 291));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 210, 251, 41));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        reset = new QCommandLinkButton(layoutWidget);
        reset->setObjectName(QStringLiteral("reset"));

        horizontalLayout_4->addWidget(reset);

        execute = new QCommandLinkButton(layoutWidget);
        execute->setObjectName(QStringLiteral("execute"));

        horizontalLayout_4->addWidget(execute);

        exeCycle = new QTableWidget(groupBox);
        if (exeCycle->columnCount() < 1)
            exeCycle->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        exeCycle->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (exeCycle->rowCount() < 6)
            exeCycle->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        exeCycle->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        exeCycle->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        exeCycle->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        exeCycle->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        exeCycle->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        exeCycle->setVerticalHeaderItem(5, __qtablewidgetitem6);
        exeCycle->setObjectName(QStringLiteral("exeCycle"));
        exeCycle->setGeometry(QRect(70, 20, 141, 171));
        exeCycle->verticalHeader()->setDefaultSectionSize(24);
        groupBox_8 = new QGroupBox(page);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 20, 591, 291));
        layoutWidget_2 = new QWidget(groupBox_8);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 20, 481, 271));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        i[0][0] = new QComboBox(layoutWidget_2);
        i[0][0]->setObjectName(QStringLiteral("i00"));

        verticalLayout_7->addWidget(i[0][0]);

        i[1][0] = new QComboBox(layoutWidget_2);
        i[1][0]->setObjectName(QStringLiteral("i10"));

        verticalLayout_7->addWidget(i[1][0]);

        i[2][0] = new QComboBox(layoutWidget_2);
        i[2][0]->setObjectName(QStringLiteral("i20"));

        verticalLayout_7->addWidget(i[2][0]);

        i[3][0] = new QComboBox(layoutWidget_2);
        i[3][0]->setObjectName(QStringLiteral("i30"));

        verticalLayout_7->addWidget(i[3][0]);

        i[4][0] = new QComboBox(layoutWidget_2);
        i[4][0]->setObjectName(QStringLiteral("i40"));

        verticalLayout_7->addWidget(i[4][0]);

        i[5][0] = new QComboBox(layoutWidget_2);
        i[5][0]->setObjectName(QStringLiteral("i50"));

        verticalLayout_7->addWidget(i[5][0]);

        i[6][0] = new QComboBox(layoutWidget_2);
        i[6][0]->setObjectName(QStringLiteral("i60"));

        verticalLayout_7->addWidget(i[6][0]);

        i[7][0] = new QComboBox(layoutWidget_2);
        i[7][0]->setObjectName(QStringLiteral("i70"));

        verticalLayout_7->addWidget(i[7][0]);

        i[8][0] = new QComboBox(layoutWidget_2);
        i[8][0]->setObjectName(QStringLiteral("i80"));

        verticalLayout_7->addWidget(i[8][0]);

        i[9][0] = new QComboBox(layoutWidget_2);
        i[9][0]->setObjectName(QStringLiteral("i90"));

        verticalLayout_7->addWidget(i[9][0]);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        i[0][1] = new QComboBox(layoutWidget_2);
        i[0][1]->setObjectName(QStringLiteral("i[0][1]"));

        verticalLayout_8->addWidget(i[0][1]);

        i[1][1] = new QComboBox(layoutWidget_2);
        i[1][1]->setObjectName(QStringLiteral("i[1][1]"));

        verticalLayout_8->addWidget(i[1][1]);

        i[2][1] = new QComboBox(layoutWidget_2);
        i[2][1]->setObjectName(QStringLiteral("i[2][1]"));

        verticalLayout_8->addWidget(i[2][1]);

        i[3][1] = new QComboBox(layoutWidget_2);
        i[3][1]->setObjectName(QStringLiteral("i[3][1]"));

        verticalLayout_8->addWidget(i[3][1]);

        i[4][1] = new QComboBox(layoutWidget_2);
        i[4][1]->setObjectName(QStringLiteral("i[4][1]"));

        verticalLayout_8->addWidget(i[4][1]);

        i[5][1] = new QComboBox(layoutWidget_2);
        i[5][1]->setObjectName(QStringLiteral("i[5][1]"));

        verticalLayout_8->addWidget(i[5][1]);

        i[6][1] = new QComboBox(layoutWidget_2);
        i[6][1]->setObjectName(QStringLiteral("i[6][1]"));

        verticalLayout_8->addWidget(i[6][1]);

        i[7][1] = new QComboBox(layoutWidget_2);
        i[7][1]->setObjectName(QStringLiteral("i[7][1]"));

        verticalLayout_8->addWidget(i[7][1]);

        i[8][1] = new QComboBox(layoutWidget_2);
        i[8][1]->setObjectName(QStringLiteral("i[8][1]"));

        verticalLayout_8->addWidget(i[8][1]);

        i[9][1] = new QComboBox(layoutWidget_2);
        i[9][1]->setObjectName(QStringLiteral("i[9][1]"));

        verticalLayout_8->addWidget(i[9][1]);


        horizontalLayout_2->addLayout(verticalLayout_8);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        i[0][2] = new QComboBox(layoutWidget_2);
        i[0][2]->setObjectName(QStringLiteral("i[0][2]"));

        verticalLayout_6->addWidget(i[0][2]);

        i[1][2] = new QComboBox(layoutWidget_2);
        i[1][2]->setObjectName(QStringLiteral("i[1][2]"));

        verticalLayout_6->addWidget(i[1][2]);

        i[2][2] = new QComboBox(layoutWidget_2);
        i[2][2]->setObjectName(QStringLiteral("i[2][2]"));

        verticalLayout_6->addWidget(i[2][2]);

        i[3][2] = new QComboBox(layoutWidget_2);
        i[3][2]->setObjectName(QStringLiteral("i[3][2]"));

        verticalLayout_6->addWidget(i[3][2]);

        i[4][2] = new QComboBox(layoutWidget_2);
        i[4][2]->setObjectName(QStringLiteral("i[4][2]"));

        verticalLayout_6->addWidget(i[4][2]);

        i[5][2] = new QComboBox(layoutWidget_2);
        i[5][2]->setObjectName(QStringLiteral("i[5][2]"));

        verticalLayout_6->addWidget(i[5][2]);

        i[6][2] = new QComboBox(layoutWidget_2);
        i[6][2]->setObjectName(QStringLiteral("i[6][2]"));

        verticalLayout_6->addWidget(i[6][2]);

        i[7][2] = new QComboBox(layoutWidget_2);
        i[7][2]->setObjectName(QStringLiteral("i[7][2]"));

        verticalLayout_6->addWidget(i[7][2]);

        i[8][2] = new QComboBox(layoutWidget_2);
        i[8][2]->setObjectName(QStringLiteral("i[8][2]"));

        verticalLayout_6->addWidget(i[8][2]);

        i[9][2] = new QComboBox(layoutWidget_2);
        i[9][2]->setObjectName(QStringLiteral("i[9][2]"));

        verticalLayout_6->addWidget(i[9][2]);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        i[0][3] = new QComboBox(layoutWidget_2);
        i[0][3]->setObjectName(QStringLiteral("i[0][3]"));

        verticalLayout_5->addWidget(i[0][3]);

        i[1][3] = new QComboBox(layoutWidget_2);
        i[1][3]->setObjectName(QStringLiteral("i[1][3]"));

        verticalLayout_5->addWidget(i[1][3]);

        i[2][3] = new QComboBox(layoutWidget_2);
        i[2][3]->setObjectName(QStringLiteral("i[2][3]"));

        verticalLayout_5->addWidget(i[2][3]);

        i[3][3] = new QComboBox(layoutWidget_2);
        i[3][3]->setObjectName(QStringLiteral("i[3][3]"));

        verticalLayout_5->addWidget(i[3][3]);

        i[4][3] = new QComboBox(layoutWidget_2);
        i[4][3]->setObjectName(QStringLiteral("i[4][3]"));

        verticalLayout_5->addWidget(i[4][3]);

        i[5][3] = new QComboBox(layoutWidget_2);
        i[5][3]->setObjectName(QStringLiteral("i[5][3]"));

        verticalLayout_5->addWidget(i[5][3]);

        i[6][3] = new QComboBox(layoutWidget_2);
        i[6][3]->setObjectName(QStringLiteral("i[6][3]"));

        verticalLayout_5->addWidget(i[6][3]);

        i[7][3] = new QComboBox(layoutWidget_2);
        i[7][3]->setObjectName(QStringLiteral("i[7][3]"));

        verticalLayout_5->addWidget(i[7][3]);

        i[8][3] = new QComboBox(layoutWidget_2);
        i[8][3]->setObjectName(QStringLiteral("i[8][3]"));

        verticalLayout_5->addWidget(i[8][3]);

        i[9][3] = new QComboBox(layoutWidget_2);
        i[9][3]->setObjectName(QStringLiteral("i[9][3]"));

        verticalLayout_5->addWidget(i[9][3]);


        for (int ijkl = 0; ijkl != 10; ijkl ++) {
            for (int ijklm = 0; ijklm != 4; ijklm ++) {
                i[ijkl][ijklm] -> insertItems(0, QStringList()
                 << QApplication::translate("MainWindow", "Null", 0));
            }
        }

        horizontalLayout_2->addLayout(verticalLayout_5);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 0, 531, 331));
        is = new QTableWidget(groupBox_2);
        if (is->columnCount() < 4)
            is->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setText(QStringLiteral("Instrcution"));
        is->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        is->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        is->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        is->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        if (is->rowCount() < 10)
            is->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        is->setVerticalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        is->setVerticalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        is->setVerticalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        is->setVerticalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        is->setVerticalHeaderItem(4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        is->setVerticalHeaderItem(5, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        is->setVerticalHeaderItem(6, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        is->setVerticalHeaderItem(7, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        is->setVerticalHeaderItem(8, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        is->setVerticalHeaderItem(9, __qtablewidgetitem20);
        is->setObjectName(QStringLiteral("is"));
        is->setEnabled(true);
        is->setGeometry(QRect(50, 30, 451, 291));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(is->sizePolicy().hasHeightForWidth());
        is->setSizePolicy(sizePolicy1);
        is->setMaximumSize(QSize(481, 311));
        is->setBaseSize(QSize(0, 0));
        is->setLineWidth(-5);
        is->setMidLineWidth(2);
        is->verticalHeader()->setDefaultSectionSize(26);
        groupBox_3 = new QGroupBox(page_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(570, 20, 331, 301));
        gridLayoutWidget = new QWidget(groupBox_3);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 40, 221, 151));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stepOneBack = new QCommandLinkButton(gridLayoutWidget);
        stepOneBack->setObjectName(QStringLiteral("stepOneBack"));

        gridLayout->addWidget(stepOneBack, 0, 1, 1, 1);

        stepOneFront = new QCommandLinkButton(gridLayoutWidget);
        stepOneFront->setObjectName(QStringLiteral("stepOneFront"));

        gridLayout->addWidget(stepOneFront, 0, 0, 1, 1);

        stepFiveFront = new QCommandLinkButton(gridLayoutWidget);
        stepFiveFront->setObjectName(QStringLiteral("stepFiveFront"));

        gridLayout->addWidget(stepFiveFront, 1, 0, 1, 1);

        stepFiveBack = new QCommandLinkButton(gridLayoutWidget);
        stepFiveBack->setObjectName(QStringLiteral("stepFiveBack"));

        gridLayout->addWidget(stepFiveBack, 1, 1, 1, 1);

        allToOne = new QCommandLinkButton(gridLayoutWidget);
        allToOne->setObjectName(QStringLiteral("allToOne"));

        gridLayout->addWidget(allToOne, 2, 0, 1, 1);

        exit = new QCommandLinkButton(gridLayoutWidget);
        exit->setObjectName(QStringLiteral("exit"));

        gridLayout->addWidget(exit, 2, 1, 1, 1);

        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 200, 162, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        currentTime = new QLabel(layoutWidget1);
        currentTime->setObjectName(QStringLiteral("currentTime"));

        horizontalLayout->addWidget(currentTime);

        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 240, 189, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        jumpTo = new QLineEdit(layoutWidget2);
        jumpTo->setObjectName(QStringLiteral("jumpTo"));

        horizontalLayout_3->addWidget(jumpTo);

        go = new QCommandLinkButton(groupBox_3);
        go->setObjectName(QStringLiteral("go"));
        go->setGeometry(QRect(210, 240, 61, 31));
        stackedWidget->addWidget(page_2);
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 340, 551, 231));
        rs = new QTableWidget(groupBox_4);
        if (rs->columnCount() < 8)
            rs->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        rs->setHorizontalHeaderItem(0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        rs->setHorizontalHeaderItem(1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        rs->setHorizontalHeaderItem(2, __qtablewidgetitem23);
        QFont font;
        font.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font);
        rs->setHorizontalHeaderItem(3, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        rs->setHorizontalHeaderItem(4, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        rs->setHorizontalHeaderItem(5, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        rs->setHorizontalHeaderItem(6, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        rs->setHorizontalHeaderItem(7, __qtablewidgetitem28);
        if (rs->rowCount() < 5)
            rs->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        rs->setVerticalHeaderItem(0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        rs->setVerticalHeaderItem(1, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        rs->setVerticalHeaderItem(2, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        rs->setVerticalHeaderItem(3, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        rs->setVerticalHeaderItem(4, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        rs->setItem(0, 1, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        rs->setItem(0, 2, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        rs->setItem(0, 3, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        rs->setItem(1, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        rs->setItem(1, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        rs->setItem(2, 1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        rs->setItem(2, 2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        rs->setItem(3, 1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        rs->setItem(3, 2, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        rs->setItem(4, 1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        rs->setItem(4, 2, __qtablewidgetitem44);
        rs->setObjectName(QStringLiteral("rs"));
        rs->setGeometry(QRect(20, 30, 511, 191));
        rs->setBaseSize(QSize(2, 2));
        rs->setFrameShape(QFrame::VLine);
        rs->setFrameShadow(QFrame::Raised);
        rs->setProperty("showDropIndicator", QVariant(false));
        rs->setShowGrid(true);
        rs->setSortingEnabled(false);
        rs->setWordWrap(true);
        rs->horizontalHeader()->setVisible(true);
        rs->horizontalHeader()->setDefaultSectionSize(63);
        rs->horizontalHeader()->setHighlightSections(false);
        rs->horizontalHeader()->setMinimumSectionSize(19);
        rs->verticalHeader()->setVisible(false);
        rs->verticalHeader()->setDefaultSectionSize(27);
        rs->verticalHeader()->setMinimumSectionSize(20);
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(580, 340, 371, 111));
        lb = new QTableWidget(groupBox_5);
        if (lb->columnCount() < 6)
            lb->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        lb->setHorizontalHeaderItem(0, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        lb->setHorizontalHeaderItem(1, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        lb->setHorizontalHeaderItem(2, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        lb->setHorizontalHeaderItem(3, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        lb->setHorizontalHeaderItem(4, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        lb->setHorizontalHeaderItem(5, __qtablewidgetitem50);
        if (lb->rowCount() < 3)
            lb->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        lb->setVerticalHeaderItem(0, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        lb->setVerticalHeaderItem(1, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        lb->setVerticalHeaderItem(2, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        lb->setItem(0, 0, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        lb->setItem(0, 1, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        lb->setItem(1, 0, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        lb->setItem(1, 1, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        lb->setItem(2, 0, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        lb->setItem(2, 1, __qtablewidgetitem59);
        lb->setObjectName(QStringLiteral("lb"));
        lb->setGeometry(QRect(20, 20, 331, 81));
        lb->horizontalHeader()->setDefaultSectionSize(54);
        lb->verticalHeader()->setVisible(false);
        lb->verticalHeader()->setDefaultSectionSize(18);
        lb->verticalHeader()->setHighlightSections(true);
        lb->verticalHeader()->setMinimumSectionSize(20);
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(580, 460, 371, 111));
        sb = new QTableWidget(groupBox_6);
        if (sb->columnCount() < 7)
            sb->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        sb->setHorizontalHeaderItem(0, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        sb->setHorizontalHeaderItem(1, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        sb->setHorizontalHeaderItem(2, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        sb->setHorizontalHeaderItem(3, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        sb->setHorizontalHeaderItem(4, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        sb->setHorizontalHeaderItem(5, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        sb->setHorizontalHeaderItem(6, __qtablewidgetitem66);
        if (sb->rowCount() < 3)
            sb->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        sb->setVerticalHeaderItem(0, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        sb->setVerticalHeaderItem(1, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        sb->setVerticalHeaderItem(2, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        sb->setItem(0, 0, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        sb->setItem(0, 1, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        sb->setItem(1, 0, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        sb->setItem(1, 1, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        sb->setItem(1, 2, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        sb->setItem(2, 0, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        sb->setItem(2, 1, __qtablewidgetitem76);
        sb->setObjectName(QStringLiteral("sb"));
        sb->setGeometry(QRect(20, 20, 331, 81));
        sb->horizontalHeader()->setDefaultSectionSize(47);
        sb->horizontalHeader()->setMinimumSectionSize(57);
        sb->verticalHeader()->setVisible(false);
        sb->verticalHeader()->setDefaultSectionSize(17);
        sb->verticalHeader()->setHighlightSections(true);
        sb->verticalHeader()->setMinimumSectionSize(25);
        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 580, 941, 101));
        r = new QTableWidget(groupBox_7);
        if (r->columnCount() < 17)
            r->setColumnCount(17);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(0, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(1, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(2, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(3, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(4, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(5, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(6, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(7, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(8, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(9, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(10, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(11, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(12, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(13, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(14, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(15, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(16, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        r->setHorizontalHeaderItem(17, __qtablewidgetitem94);
        if (r->rowCount() < 2)
            r->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        r->setVerticalHeaderItem(0, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        r->setVerticalHeaderItem(1, __qtablewidgetitem96);
        r->setObjectName(QStringLiteral("r"));
        r->setGeometry(QRect(20, 20, 901, 71));
        r->horizontalHeader()->setDefaultSectionSize(47);
        r->verticalHeader()->setDefaultSectionSize(22);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Setting", 0));
        reset->setText(QApplication::translate("MainWindow", "Reset", 0));
        execute->setText(QApplication::translate("MainWindow", "Execute", 0));
        QTableWidgetItem *___qtablewidgetitem = exeCycle->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Cycles", 0));
        QTableWidgetItem *___qtablewidgetitem1 = exeCycle->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Add", 0));
        QTableWidgetItem *___qtablewidgetitem2 = exeCycle->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Sub", 0));
        QTableWidgetItem *___qtablewidgetitem3 = exeCycle->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Mul", 0));
        QTableWidgetItem *___qtablewidgetitem4 = exeCycle->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Div", 0));
        QTableWidgetItem *___qtablewidgetitem5 = exeCycle->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Load", 0));
        QTableWidgetItem *___qtablewidgetitem6 = exeCycle->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Store", 0));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Instruction Queue", 0));
        i[0][0]->clear();
        i[0][0]->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NOP", 0)
         << QApplication::translate("MainWindow", "ADD.D", 0)
         << QApplication::translate("MainWindow", "SUB.D", 0)
         << QApplication::translate("MainWindow", "MUL.D", 0)
         << QApplication::translate("MainWindow", "DIV.D", 0)
         << QApplication::translate("MainWindow", "L.D", 0)
         << QApplication::translate("MainWindow", "S.D", 0)
        );
        i[1][0]->clear();
        i[1][0]->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NOP", 0)
         << QApplication::translate("MainWindow", "ADD.D", 0)
         << QApplication::translate("MainWindow", "SUB.D", 0)
         << QApplication::translate("MainWindow", "MUL.D", 0)
         << QApplication::translate("MainWindow", "DIV.D", 0)
         << QApplication::translate("MainWindow", "L.D", 0)
         << QApplication::translate("MainWindow", "S.D", 0)
        );
        i[2][0]->clear();
        i[2][0]->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NOP", 0)
         << QApplication::translate("MainWindow", "ADD.D", 0)
         << QApplication::translate("MainWindow", "SUB.D", 0)
         << QApplication::translate("MainWindow", "MUL.D", 0)
         << QApplication::translate("MainWindow", "DIV.D", 0)
         << QApplication::translate("MainWindow", "L.D", 0)
         << QApplication::translate("MainWindow", "S.D", 0)
        );
        i[3][0]->clear();
        i[3][0]->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NOP", 0)
         << QApplication::translate("MainWindow", "ADD.D", 0)
         << QApplication::translate("MainWindow", "SUB.D", 0)
         << QApplication::translate("MainWindow", "MUL.D", 0)
         << QApplication::translate("MainWindow", "DIV.D", 0)
         << QApplication::translate("MainWindow", "L.D", 0)
         << QApplication::translate("MainWindow", "S.D", 0)
        );
        i[4][0]->clear();
        i[4][0]->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NOP", 0)
         << QApplication::translate("MainWindow", "ADD.D", 0)
         << QApplication::translate("MainWindow", "SUB.D", 0)
         << QApplication::translate("MainWindow", "MUL.D", 0)
         << QApplication::translate("MainWindow", "DIV.D", 0)
         << QApplication::translate("MainWindow", "L.D", 0)
         << QApplication::translate("MainWindow", "S.D", 0)
        );
        i[5][0]->clear();
        i[5][0]->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NOP", 0)
         << QApplication::translate("MainWindow", "ADD.D", 0)
         << QApplication::translate("MainWindow", "SUB.D", 0)
         << QApplication::translate("MainWindow", "MUL.D", 0)
         << QApplication::translate("MainWindow", "DIV.D", 0)
         << QApplication::translate("MainWindow", "L.D", 0)
         << QApplication::translate("MainWindow", "S.D", 0)
        );
        i[6][0]->clear();
        i[6][0]->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NOP", 0)
         << QApplication::translate("MainWindow", "ADD.D", 0)
         << QApplication::translate("MainWindow", "SUB.D", 0)
         << QApplication::translate("MainWindow", "MUL.D", 0)
         << QApplication::translate("MainWindow", "DIV.D", 0)
         << QApplication::translate("MainWindow", "L.D", 0)
         << QApplication::translate("MainWindow", "S.D", 0)
        );
        i[7][0]->clear();
        i[7][0]->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NOP", 0)
         << QApplication::translate("MainWindow", "ADD.D", 0)
         << QApplication::translate("MainWindow", "SUB.D", 0)
         << QApplication::translate("MainWindow", "MUL.D", 0)
         << QApplication::translate("MainWindow", "DIV.D", 0)
         << QApplication::translate("MainWindow", "L.D", 0)
         << QApplication::translate("MainWindow", "S.D", 0)
        );
        i[8][0]->clear();
        i[8][0]->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NOP", 0)
         << QApplication::translate("MainWindow", "ADD.D", 0)
         << QApplication::translate("MainWindow", "SUB.D", 0)
         << QApplication::translate("MainWindow", "MUL.D", 0)
         << QApplication::translate("MainWindow", "DIV.D", 0)
         << QApplication::translate("MainWindow", "L.D", 0)
         << QApplication::translate("MainWindow", "S.D", 0)
        );
        i[9][0]->clear();
        i[9][0]->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NOP", 0)
         << QApplication::translate("MainWindow", "ADD.D", 0)
         << QApplication::translate("MainWindow", "SUB.D", 0)
         << QApplication::translate("MainWindow", "MUL.D", 0)
         << QApplication::translate("MainWindow", "DIV.D", 0)
         << QApplication::translate("MainWindow", "L.D", 0)
         << QApplication::translate("MainWindow", "S.D", 0)
        );
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Instruction Status", 0));
        QTableWidgetItem *___qtablewidgetitem7 = is->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Issue", 0));
        QTableWidgetItem *___qtablewidgetitem8 = is->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Execute", 0));
        QTableWidgetItem *___qtablewidgetitem9 = is->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Write Result", 0));
        QTableWidgetItem *___qtablewidgetitem10 = is->verticalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Ins1", 0));
        QTableWidgetItem *___qtablewidgetitem11 = is->verticalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Ins2", 0));
        QTableWidgetItem *___qtablewidgetitem12 = is->verticalHeaderItem(2);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Ins3", 0));
        QTableWidgetItem *___qtablewidgetitem13 = is->verticalHeaderItem(3);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Ins4", 0));
        QTableWidgetItem *___qtablewidgetitem14 = is->verticalHeaderItem(4);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Ins5", 0));
        QTableWidgetItem *___qtablewidgetitem15 = is->verticalHeaderItem(5);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "Ins6", 0));
        QTableWidgetItem *___qtablewidgetitem16 = is->verticalHeaderItem(6);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Ins7", 0));
        QTableWidgetItem *___qtablewidgetitem17 = is->verticalHeaderItem(7);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Ins8", 0));
        QTableWidgetItem *___qtablewidgetitem18 = is->verticalHeaderItem(8);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "Ins9", 0));
        QTableWidgetItem *___qtablewidgetitem19 = is->verticalHeaderItem(9);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Ins10", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Control", 0));
        stepOneBack->setText(QApplication::translate("MainWindow", "One Back", 0));
        stepOneFront->setText(QApplication::translate("MainWindow", "One Front", 0));
        stepFiveFront->setText(QApplication::translate("MainWindow", "Five Front", 0));
        stepFiveBack->setText(QApplication::translate("MainWindow", "Five Back", 0));
        allToOne->setText(QApplication::translate("MainWindow", "Continue", 0));
        exit->setText(QApplication::translate("MainWindow", "Exit", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Current Cycle\357\274\232</span></p></body></html>", 0));
        currentTime->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Go to\357\274\232", 0));
        go->setText(QApplication::translate("MainWindow", "Go", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Reservation Station", 0));
        QTableWidgetItem *___qtablewidgetitem20 = rs->horizontalHeaderItem(0);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "Time", 0));
        QTableWidgetItem *___qtablewidgetitem21 = rs->horizontalHeaderItem(1);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem22 = rs->horizontalHeaderItem(2);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "Busy", 0));
        QTableWidgetItem *___qtablewidgetitem23 = rs->horizontalHeaderItem(3);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "Op", 0));
        QTableWidgetItem *___qtablewidgetitem24 = rs->horizontalHeaderItem(4);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "Vj", 0));
        QTableWidgetItem *___qtablewidgetitem25 = rs->horizontalHeaderItem(5);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "Vk", 0));
        QTableWidgetItem *___qtablewidgetitem26 = rs->horizontalHeaderItem(6);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "Qj", 0));
        QTableWidgetItem *___qtablewidgetitem27 = rs->horizontalHeaderItem(7);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "Qk", 0));
        QTableWidgetItem *___qtablewidgetitem28 = rs->verticalHeaderItem(0);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem29 = rs->verticalHeaderItem(1);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem30 = rs->verticalHeaderItem(2);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem31 = rs->verticalHeaderItem(3);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem32 = rs->verticalHeaderItem(4);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", 0));

        const bool __sortingEnabled = rs->isSortingEnabled();
        rs->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem33 = rs->item(0, 1);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "Add1", 0));
        QTableWidgetItem *___qtablewidgetitem34 = rs->item(0, 2);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "No", 0));
        QTableWidgetItem *___qtablewidgetitem35 = rs->item(1, 1);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "Add2", 0));
        QTableWidgetItem *___qtablewidgetitem36 = rs->item(1, 2);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "No", 0));
        QTableWidgetItem *___qtablewidgetitem37 = rs->item(2, 1);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "Add3", 0));
        QTableWidgetItem *___qtablewidgetitem38 = rs->item(2, 2);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "No", 0));
        QTableWidgetItem *___qtablewidgetitem39 = rs->item(3, 1);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "Mul1", 0));
        QTableWidgetItem *___qtablewidgetitem40 = rs->item(3, 2);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "No", 0));
        QTableWidgetItem *___qtablewidgetitem41 = rs->item(4, 1);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "Mul2", 0));
        QTableWidgetItem *___qtablewidgetitem42 = rs->item(4, 2);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "No", 0));
        rs->setSortingEnabled(__sortingEnabled);

        groupBox_5->setTitle(QApplication::translate("MainWindow", "Load Buffer", 0));
        QTableWidgetItem *___qtablewidgetitem43 = lb->horizontalHeaderItem(0);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem44 = lb->horizontalHeaderItem(1);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWindow", "Busy", 0));
        QTableWidgetItem *___qtablewidgetitem45 = lb->horizontalHeaderItem(2);
        ___qtablewidgetitem45->setText(QApplication::translate("MainWindow", "A", 0));
        QTableWidgetItem *___qtablewidgetitem46 = lb->horizontalHeaderItem(3);
        ___qtablewidgetitem46->setText(QApplication::translate("MainWindow", "Value", 0));
        QTableWidgetItem *___qtablewidgetitem47 = lb->horizontalHeaderItem(4);
        ___qtablewidgetitem47->setText(QApplication::translate("MainWindow", "Vj", 0));
        QTableWidgetItem *___qtablewidgetitem48 = lb->horizontalHeaderItem(5);
        ___qtablewidgetitem48->setText(QApplication::translate("MainWindow", "Qj", 0));
        QTableWidgetItem *___qtablewidgetitem49 = lb->verticalHeaderItem(0);
        ___qtablewidgetitem49->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem50 = lb->verticalHeaderItem(1);
        ___qtablewidgetitem50->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem51 = lb->verticalHeaderItem(2);
        ___qtablewidgetitem51->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", 0));

        const bool __sortingEnabled1 = lb->isSortingEnabled();
        lb->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem52 = lb->item(0, 0);
        ___qtablewidgetitem52->setText(QApplication::translate("MainWindow", "Load1", 0));
        QTableWidgetItem *___qtablewidgetitem53 = lb->item(0, 1);
        ___qtablewidgetitem53->setText(QApplication::translate("MainWindow", "No", 0));
        QTableWidgetItem *___qtablewidgetitem54 = lb->item(1, 0);
        ___qtablewidgetitem54->setText(QApplication::translate("MainWindow", "Load2", 0));
        QTableWidgetItem *___qtablewidgetitem55 = lb->item(1, 1);
        ___qtablewidgetitem55->setText(QApplication::translate("MainWindow", "No", 0));
        QTableWidgetItem *___qtablewidgetitem56 = lb->item(2, 0);
        ___qtablewidgetitem56->setText(QApplication::translate("MainWindow", "Load3", 0));
        QTableWidgetItem *___qtablewidgetitem57 = lb->item(2, 1);
        ___qtablewidgetitem57->setText(QApplication::translate("MainWindow", "No", 0));
        lb->setSortingEnabled(__sortingEnabled1);

        groupBox_6->setTitle(QApplication::translate("MainWindow", "Store Buffer", 0));
        QTableWidgetItem *___qtablewidgetitem58 = sb->horizontalHeaderItem(0);
        ___qtablewidgetitem58->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem59 = sb->horizontalHeaderItem(1);
        ___qtablewidgetitem59->setText(QApplication::translate("MainWindow", "Busy", 0));
        QTableWidgetItem *___qtablewidgetitem60 = sb->horizontalHeaderItem(2);
        ___qtablewidgetitem60->setText(QApplication::translate("MainWindow", "A", 0));
        QTableWidgetItem *___qtablewidgetitem61 = sb->horizontalHeaderItem(3);
        ___qtablewidgetitem61->setText(QApplication::translate("MainWindow", "Vj", 0));
        QTableWidgetItem *___qtablewidgetitem62 = sb->horizontalHeaderItem(4);
        ___qtablewidgetitem62->setText(QApplication::translate("MainWindow", "Vk", 0));
        QTableWidgetItem *___qtablewidgetitem63 = sb->horizontalHeaderItem(5);
        ___qtablewidgetitem63->setText(QApplication::translate("MainWindow", "Qj", 0));
        QTableWidgetItem *___qtablewidgetitem64 = sb->horizontalHeaderItem(6);
        ___qtablewidgetitem64->setText(QApplication::translate("MainWindow", "Qk", 0));
        QTableWidgetItem *___qtablewidgetitem65 = sb->verticalHeaderItem(0);
        ___qtablewidgetitem65->setText(QApplication::translate("MainWindow", "ST1", 0));
        QTableWidgetItem *___qtablewidgetitem66 = sb->verticalHeaderItem(1);
        ___qtablewidgetitem66->setText(QApplication::translate("MainWindow", "ST2", 0));
        QTableWidgetItem *___qtablewidgetitem67 = sb->verticalHeaderItem(2);
        ___qtablewidgetitem67->setText(QApplication::translate("MainWindow", "ST3", 0));

        const bool __sortingEnabled2 = sb->isSortingEnabled();
        sb->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem68 = sb->item(0, 0);
        ___qtablewidgetitem68->setText(QApplication::translate("MainWindow", "ST1", 0));
        QTableWidgetItem *___qtablewidgetitem69 = sb->item(0, 1);
        ___qtablewidgetitem69->setText(QApplication::translate("MainWindow", "No", 0));
        QTableWidgetItem *___qtablewidgetitem70 = sb->item(1, 0);
        ___qtablewidgetitem70->setText(QApplication::translate("MainWindow", "ST2", 0));
        QTableWidgetItem *___qtablewidgetitem71 = sb->item(1, 1);
        ___qtablewidgetitem71->setText(QApplication::translate("MainWindow", "No", 0));
        QTableWidgetItem *___qtablewidgetitem72 = sb->item(2, 0);
        ___qtablewidgetitem72->setText(QApplication::translate("MainWindow", "ST3", 0));
        QTableWidgetItem *___qtablewidgetitem73 = sb->item(2, 1);
        ___qtablewidgetitem73->setText(QApplication::translate("MainWindow", "No", 0));
        sb->setSortingEnabled(__sortingEnabled2);

        groupBox_7->setTitle(QApplication::translate("MainWindow", "Register", 0));
        QTableWidgetItem *___qtablewidgetitem74 = r->horizontalHeaderItem(0);
        ___qtablewidgetitem74->setText(QApplication::translate("MainWindow", "F0", 0));
        QTableWidgetItem *___qtablewidgetitem75 = r->horizontalHeaderItem(1);
        ___qtablewidgetitem75->setText(QApplication::translate("MainWindow", "F2", 0));
        QTableWidgetItem *___qtablewidgetitem76 = r->horizontalHeaderItem(2);
        ___qtablewidgetitem76->setText(QApplication::translate("MainWindow", "F4", 0));
        QTableWidgetItem *___qtablewidgetitem77 = r->horizontalHeaderItem(3);
        ___qtablewidgetitem77->setText(QApplication::translate("MainWindow", "F6", 0));
        QTableWidgetItem *___qtablewidgetitem78 = r->horizontalHeaderItem(4);
        ___qtablewidgetitem78->setText(QApplication::translate("MainWindow", "F8", 0));
        QTableWidgetItem *___qtablewidgetitem79 = r->horizontalHeaderItem(5);
        ___qtablewidgetitem79->setText(QApplication::translate("MainWindow", "F10", 0));
        QTableWidgetItem *___qtablewidgetitem80 = r->horizontalHeaderItem(6);
        ___qtablewidgetitem80->setText(QApplication::translate("MainWindow", "F12", 0));
        QTableWidgetItem *___qtablewidgetitem81 = r->horizontalHeaderItem(7);
        ___qtablewidgetitem81->setText(QApplication::translate("MainWindow", "F14", 0));
        QTableWidgetItem *___qtablewidgetitem82 = r->horizontalHeaderItem(8);
        ___qtablewidgetitem82->setText(QApplication::translate("MainWindow", "F16", 0));
 //       QTableWidgetItem *___qtablewidgetitem83 = r->horizontalHeaderItem(9);
 //       ___qtablewidgetitem83->setText(QApplication::translate("MainWindow", "F16", 0));
        QTableWidgetItem *___qtablewidgetitem84 = r->horizontalHeaderItem(9);
        ___qtablewidgetitem84->setText(QApplication::translate("MainWindow", "F18", 0));
        QTableWidgetItem *___qtablewidgetitem85 = r->horizontalHeaderItem(10);
        ___qtablewidgetitem85->setText(QApplication::translate("MainWindow", "F20", 0));
        QTableWidgetItem *___qtablewidgetitem86 = r->horizontalHeaderItem(11);
        ___qtablewidgetitem86->setText(QApplication::translate("MainWindow", "F22", 0));
        QTableWidgetItem *___qtablewidgetitem87 = r->horizontalHeaderItem(12);
        ___qtablewidgetitem87->setText(QApplication::translate("MainWindow", "F24", 0));
        QTableWidgetItem *___qtablewidgetitem88 = r->horizontalHeaderItem(13);
        ___qtablewidgetitem88->setText(QApplication::translate("MainWindow", "F26", 0));
        QTableWidgetItem *___qtablewidgetitem89 = r->horizontalHeaderItem(14);
        ___qtablewidgetitem89->setText(QApplication::translate("MainWindow", "F28", 0));
        QTableWidgetItem *___qtablewidgetitem90 = r->horizontalHeaderItem(15);
        ___qtablewidgetitem90->setText(QApplication::translate("MainWindow", "F30", 0));
        QTableWidgetItem *___qtablewidgetitem91 = r->horizontalHeaderItem(16);
        ___qtablewidgetitem91->setText(QApplication::translate("MainWindow", "F32", 0));
        QTableWidgetItem *___qtablewidgetitem92 = r->verticalHeaderItem(0);
        ___qtablewidgetitem92->setText(QApplication::translate("MainWindow", "Qi", 0));
        QTableWidgetItem *___qtablewidgetitem93 = r->verticalHeaderItem(1);
        ___qtablewidgetitem93->setText(QApplication::translate("MainWindow", "Value", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
