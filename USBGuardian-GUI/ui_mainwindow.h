/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *homeView;
    QStackedWidget *stackedWidget;
    QWidget *welcome_view;
    QLabel *label_welcome;
    QLabel *logo_welcomeView;
    QPushButton *btn_information;
    QPushButton *btn_restart_welcomeView;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView_3;
    QLabel *label_welcome_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *analyze_view;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QProgressBar *progressBar;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_11;
    QPushButton *btn_restart_analyzeView;
    QLabel *label_analyze_view_title;
    QPushButton *btn_cancel_analyze;
    QGraphicsView *graphicsView_imgSlider;
    QWidget *eject_view;
    QLabel *img_info;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_recommendations;
    QLabel *label_recommendations_1;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_8;
    QPushButton *btn_restart_ejectView;
    QWidget *report_view;
    QLabel *img_report_state;
    QLabel *label_report_title_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_report_state_title;
    QLabel *label_report_time;
    QLabel *label_report_files;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_report_information;
    QLabel *label_report_information_details;
    QLabel *logo_reportView;
    QPushButton *btn_restart_reportView;
    QPushButton *btnEject;
    QPushButton *btnRemove;
    QPushButton *btnFormat;
    QPushButton *btnShowInfectedFiles;
    QWidget *exception_view;
    QLabel *img_exception;
    QLabel *label_7;
    QPushButton *btn_restart_exceptionView;
    QPushButton *btn_close_exceptionView;
    QLabel *label_exception_title;
    QWidget *information_view;
    QLabel *label_information_title;
    QPushButton *btn_close_statisticsView;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_nbDevicesScanned_title;
    QLabel *label_nbMalwaresDetected_title;
    QLabel *label_nbFilesScanned_title;
    QLabel *label_percentInfectedDevices_title;
    QLabel *label_averageTimeScan_title;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_nbDevicesScanned_value;
    QLabel *label_nbMalwaresDetected_value;
    QLabel *label_nbFilesScanned_value;
    QLabel *label_percentInfectedDevices_value;
    QLabel *label_averageTimeScan_value;
    QLabel *label_general_title;
    QLabel *label_statistics_title;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_databaseVersion_title;
    QLabel *label_softwareVersion_title;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_softwareVersion_value;
    QLabel *label_databaseVersion_value;
    QLabel *label_10;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        MainWindow->setStyleSheet(QStringLiteral(""));
        homeView = new QWidget(MainWindow);
        homeView->setObjectName(QStringLiteral("homeView"));
        homeView->setStyleSheet(QLatin1String("QPushButton:focus {\n"
"	outline: none;\n"
"}\n"
"QPushButton {\n"
"	border: none;\n"
"	background-color: #607d8b;\n"
"	color: white;\n"
"}"));
        stackedWidget = new QStackedWidget(homeView);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(9, 9, 784, 491));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setStyleSheet(QStringLiteral(""));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        welcome_view = new QWidget();
        welcome_view->setObjectName(QStringLiteral("welcome_view"));
        welcome_view->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: transparent;\n"
"}"));
        label_welcome = new QLabel(welcome_view);
        label_welcome->setObjectName(QStringLiteral("label_welcome"));
        label_welcome->setGeometry(QRect(0, 110, 781, 61));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        label_welcome->setFont(font);
        label_welcome->setMouseTracking(false);
        label_welcome->setStyleSheet(QStringLiteral("color: rgb(21, 101, 192);"));
        label_welcome->setAlignment(Qt::AlignCenter);
        logo_welcomeView = new QLabel(welcome_view);
        logo_welcomeView->setObjectName(QStringLiteral("logo_welcomeView"));
        logo_welcomeView->setGeometry(QRect(0, 0, 150, 150));
        logo_welcomeView->setStyleSheet(QStringLiteral("image: url(:/resources/assets/USBGuardian.png);"));
        logo_welcomeView->setAlignment(Qt::AlignCenter);
        btn_information = new QPushButton(welcome_view);
        btn_information->setObjectName(QStringLiteral("btn_information"));
        btn_information->setGeometry(QRect(650, 20, 50, 50));
        btn_information->setMaximumSize(QSize(50, 50));
        btn_information->setLayoutDirection(Qt::RightToLeft);
        btn_information->setStyleSheet(QStringLiteral("border-image: url(:/resources/assets/icons/info.png);"));
        btn_information->setFlat(true);
        btn_restart_welcomeView = new QPushButton(welcome_view);
        btn_restart_welcomeView->setObjectName(QStringLiteral("btn_restart_welcomeView"));
        btn_restart_welcomeView->setGeometry(QRect(720, 20, 50, 50));
        btn_restart_welcomeView->setMaximumSize(QSize(50, 50));
        btn_restart_welcomeView->setStyleSheet(QStringLiteral("border-image: url(:/resources/assets/icons/power.png);"));
        btn_restart_welcomeView->setFlat(true);
        graphicsView = new QGraphicsView(welcome_view);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(125, 250, 100, 100));
        graphicsView->setStyleSheet(QStringLiteral("border-image: url(:/resources/assets/step1.png);"));
        graphicsView_2 = new QGraphicsView(welcome_view);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(340, 250, 100, 100));
        graphicsView_2->setStyleSheet(QStringLiteral("border-image: url(:/resources/assets/step2.png);"));
        graphicsView_3 = new QGraphicsView(welcome_view);
        graphicsView_3->setObjectName(QStringLiteral("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(550, 250, 100, 100));
        graphicsView_3->setStyleSheet(QStringLiteral("border-image: url(:/resources/assets/step3.png);"));
        label_welcome_2 = new QLabel(welcome_view);
        label_welcome_2->setObjectName(QStringLiteral("label_welcome_2"));
        label_welcome_2->setGeometry(QRect(0, 140, 781, 61));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label_welcome_2->setFont(font1);
        label_welcome_2->setMouseTracking(false);
        label_welcome_2->setStyleSheet(QStringLiteral("color: rgb(21, 101, 192);"));
        label_welcome_2->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label = new QLabel(welcome_view);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 370, 161, 51));
        QFont font2;
        font2.setPointSize(14);
        label->setFont(font2);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label->setWordWrap(true);
        label_3 = new QLabel(welcome_view);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 370, 161, 71));
        QFont font3;
        font3.setFamily(QStringLiteral("Piboto Light"));
        font3.setPointSize(14);
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_3->setWordWrap(true);
        label_12 = new QLabel(welcome_view);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(540, 370, 161, 71));
        label_12->setFont(font2);
        label_12->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_12->setWordWrap(true);
        label_13 = new QLabel(welcome_view);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(90, 370, 31, 21));
        QFont font4;
        font4.setFamily(QStringLiteral("Piboto"));
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setWeight(75);
        label_13->setFont(font4);
        label_13->setStyleSheet(QStringLiteral("color: rgb(52, 101, 164);"));
        label_14 = new QLabel(welcome_view);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(300, 370, 31, 21));
        label_14->setFont(font4);
        label_14->setStyleSheet(QStringLiteral("color: rgb(52, 101, 164);"));
        label_15 = new QLabel(welcome_view);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(530, 370, 31, 21));
        label_15->setFont(font4);
        label_15->setStyleSheet(QStringLiteral("color: rgb(52, 101, 164);"));
        stackedWidget->addWidget(welcome_view);
        analyze_view = new QWidget();
        analyze_view->setObjectName(QStringLiteral("analyze_view"));
        analyze_view->setStyleSheet(QLatin1String("#btn_restart_analyzeView {\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"#btn_cancel_analyze {\n"
"	background-color: transparent;\n"
"	color: rgb(55, 71, 79);\n"
"}"));
        horizontalLayoutWidget = new QWidget(analyze_view);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 400, 711, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        label_2->setFont(font5);

        horizontalLayout->addWidget(label_2);

        progressBar = new QProgressBar(horizontalLayoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);

        label_6 = new QLabel(analyze_view);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 370, 781, 21));
        QFont font6;
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setWeight(75);
        label_6->setFont(font6);
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 56, 56);"));
        label_6->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(analyze_view);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 10, 60, 60));
        label_11 = new QLabel(analyze_view);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 0, 80, 80));
        label_11->setStyleSheet(QStringLiteral("image: url(:/resources/assets/USBGuardian.png);"));
        label_11->setAlignment(Qt::AlignCenter);
        btn_restart_analyzeView = new QPushButton(analyze_view);
        btn_restart_analyzeView->setObjectName(QStringLiteral("btn_restart_analyzeView"));
        btn_restart_analyzeView->setGeometry(QRect(740, 10, 32, 32));
        btn_restart_analyzeView->setMaximumSize(QSize(32, 32));
        btn_restart_analyzeView->setStyleSheet(QStringLiteral("border-image: url(:/resources/assets/icons/power.png);"));
        btn_restart_analyzeView->setFlat(true);
        label_analyze_view_title = new QLabel(analyze_view);
        label_analyze_view_title->setObjectName(QStringLiteral("label_analyze_view_title"));
        label_analyze_view_title->setGeometry(QRect(120, 20, 611, 51));
        QFont font7;
        font7.setPointSize(24);
        font7.setBold(true);
        font7.setWeight(75);
        label_analyze_view_title->setFont(font7);
        label_analyze_view_title->setStyleSheet(QStringLiteral("color: rgb(21, 101, 192);"));
        btn_cancel_analyze = new QPushButton(analyze_view);
        btn_cancel_analyze->setObjectName(QStringLiteral("btn_cancel_analyze"));
        btn_cancel_analyze->setGeometry(QRect(720, 400, 50, 50));
        QFont font8;
        font8.setPointSize(18);
        font8.setBold(false);
        font8.setWeight(50);
        btn_cancel_analyze->setFont(font8);
        btn_cancel_analyze->setStyleSheet(QStringLiteral("border-image: url(:/resources/assets/icons/cancel.png);"));
        btn_cancel_analyze->setFlat(true);
        graphicsView_imgSlider = new QGraphicsView(analyze_view);
        graphicsView_imgSlider->setObjectName(QStringLiteral("graphicsView_imgSlider"));
        graphicsView_imgSlider->setGeometry(QRect(0, 100, 781, 241));
        graphicsView_imgSlider->setStyleSheet(QStringLiteral("border-image: url(:/resources/assets/sensi-3.png);"));
        stackedWidget->addWidget(analyze_view);
        eject_view = new QWidget();
        eject_view->setObjectName(QStringLiteral("eject_view"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(eject_view->sizePolicy().hasHeightForWidth());
        eject_view->setSizePolicy(sizePolicy1);
        eject_view->setStyleSheet(QLatin1String("#btn_restart_ejectView {\n"
"	background-color: transparent;\n"
"}"));
        img_info = new QLabel(eject_view);
        img_info->setObjectName(QStringLiteral("img_info"));
        img_info->setEnabled(true);
        img_info->setGeometry(QRect(80, 120, 100, 100));
        img_info->setStyleSheet(QStringLiteral("border-image: url(:/resources/assets/icons/info.png);"));
        img_info->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(eject_view);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(200, 270, 581, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_recommendations = new QLabel(verticalLayoutWidget);
        label_recommendations->setObjectName(QStringLiteral("label_recommendations"));
        QFont font9;
        font9.setPointSize(18);
        font9.setBold(true);
        font9.setUnderline(false);
        font9.setWeight(75);
        font9.setStrikeOut(false);
        font9.setKerning(true);
        label_recommendations->setFont(font9);
        label_recommendations->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_2->addWidget(label_recommendations);

        label_recommendations_1 = new QLabel(verticalLayoutWidget);
        label_recommendations_1->setObjectName(QStringLiteral("label_recommendations_1"));
        label_recommendations_1->setFont(font2);
        label_recommendations_1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(label_recommendations_1);

        verticalLayoutWidget_2 = new QWidget(eject_view);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(200, 130, 581, 86));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font7);
        label_4->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        verticalLayout_3->addWidget(label_5);

        label_8 = new QLabel(eject_view);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 0, 80, 80));
        label_8->setStyleSheet(QStringLiteral("image: url(:/resources/assets/USBGuardian.png);"));
        label_8->setAlignment(Qt::AlignCenter);
        btn_restart_ejectView = new QPushButton(eject_view);
        btn_restart_ejectView->setObjectName(QStringLiteral("btn_restart_ejectView"));
        btn_restart_ejectView->setGeometry(QRect(740, 10, 32, 32));
        btn_restart_ejectView->setMaximumSize(QSize(32, 32));
        btn_restart_ejectView->setStyleSheet(QStringLiteral("border-image: url(:/resources/assets/icons/power.png);"));
        btn_restart_ejectView->setFlat(true);
        stackedWidget->addWidget(eject_view);
        report_view = new QWidget();
        report_view->setObjectName(QStringLiteral("report_view"));
        report_view->setStyleSheet(QLatin1String("#btn_restart_reportView {\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"#btnShowInfectedFiles { \n"
"	background-color: transparent;\n"
"	border: 1px solid #607d8b;\n"
"	color: rgb(55, 71, 79);\n"
"}"));
        img_report_state = new QLabel(report_view);
        img_report_state->setObjectName(QStringLiteral("img_report_state"));
        img_report_state->setGeometry(QRect(0, 120, 100, 100));
        img_report_state->setStyleSheet(QStringLiteral(""));
        img_report_state->setAlignment(Qt::AlignCenter);
        label_report_title_2 = new QLabel(report_view);
        label_report_title_2->setObjectName(QStringLiteral("label_report_title_2"));
        label_report_title_2->setGeometry(QRect(90, 20, 701, 51));
        label_report_title_2->setFont(font7);
        label_report_title_2->setStyleSheet(QStringLiteral("color: rgb(21, 101, 192);"));
        verticalLayoutWidget_3 = new QWidget(report_view);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(140, 120, 641, 99));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_report_state_title = new QLabel(verticalLayoutWidget_3);
        label_report_state_title->setObjectName(QStringLiteral("label_report_state_title"));
        label_report_state_title->setFont(font1);
        label_report_state_title->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_4->addWidget(label_report_state_title);

        label_report_time = new QLabel(verticalLayoutWidget_3);
        label_report_time->setObjectName(QStringLiteral("label_report_time"));
        label_report_time->setFont(font2);

        verticalLayout_4->addWidget(label_report_time);

        label_report_files = new QLabel(verticalLayoutWidget_3);
        label_report_files->setObjectName(QStringLiteral("label_report_files"));
        label_report_files->setFont(font2);

        verticalLayout_4->addWidget(label_report_files);

        verticalLayoutWidget_4 = new QWidget(report_view);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(148, 280, 631, 101));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_report_information = new QLabel(verticalLayoutWidget_4);
        label_report_information->setObjectName(QStringLiteral("label_report_information"));
        label_report_information->setFont(font6);
        label_report_information->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_5->addWidget(label_report_information);

        label_report_information_details = new QLabel(verticalLayoutWidget_4);
        label_report_information_details->setObjectName(QStringLiteral("label_report_information_details"));
        label_report_information_details->setFont(font2);
        label_report_information_details->setScaledContents(true);
        label_report_information_details->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_report_information_details->setWordWrap(true);

        verticalLayout_5->addWidget(label_report_information_details);

        logo_reportView = new QLabel(report_view);
        logo_reportView->setObjectName(QStringLiteral("logo_reportView"));
        logo_reportView->setGeometry(QRect(0, 0, 80, 80));
        logo_reportView->setStyleSheet(QStringLiteral("image: url(:/resources/assets/USBGuardian.png);"));
        logo_reportView->setAlignment(Qt::AlignCenter);
        btn_restart_reportView = new QPushButton(report_view);
        btn_restart_reportView->setObjectName(QStringLiteral("btn_restart_reportView"));
        btn_restart_reportView->setGeometry(QRect(740, 10, 32, 32));
        btn_restart_reportView->setMaximumSize(QSize(32, 32));
        btn_restart_reportView->setStyleSheet(QStringLiteral("border-image: url(:/resources/assets/icons/power.png);"));
        btn_restart_reportView->setFlat(true);
        btnEject = new QPushButton(report_view);
        btnEject->setObjectName(QStringLiteral("btnEject"));
        btnEject->setGeometry(QRect(650, 410, 131, 51));
        QFont font10;
        font10.setPointSize(18);
        btnEject->setFont(font10);
        btnRemove = new QPushButton(report_view);
        btnRemove->setObjectName(QStringLiteral("btnRemove"));
        btnRemove->setGeometry(QRect(400, 410, 211, 51));
        btnRemove->setFont(font10);
        btnFormat = new QPushButton(report_view);
        btnFormat->setObjectName(QStringLiteral("btnFormat"));
        btnFormat->setGeometry(QRect(190, 410, 201, 51));
        btnFormat->setFont(font10);
        btnShowInfectedFiles = new QPushButton(report_view);
        btnShowInfectedFiles->setObjectName(QStringLiteral("btnShowInfectedFiles"));
        btnShowInfectedFiles->setGeometry(QRect(140, 220, 101, 31));
        btnShowInfectedFiles->setFont(font5);
        btnShowInfectedFiles->setStyleSheet(QStringLiteral(""));
        btnShowInfectedFiles->setFlat(false);
        stackedWidget->addWidget(report_view);
        exception_view = new QWidget();
        exception_view->setObjectName(QStringLiteral("exception_view"));
        exception_view->setStyleSheet(QLatin1String("#btn_restart_exceptionView {\n"
"	background-color: transparent;\n"
"}"));
        img_exception = new QLabel(exception_view);
        img_exception->setObjectName(QStringLiteral("img_exception"));
        img_exception->setGeometry(QRect(90, 200, 100, 100));
        img_exception->setStyleSheet(QStringLiteral("border-image: url(:/resources/assets/icons/warning.png);"));
        img_exception->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(exception_view);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 0, 80, 80));
        label_7->setStyleSheet(QStringLiteral("image: url(:/resources/assets/USBGuardian.png);"));
        label_7->setAlignment(Qt::AlignCenter);
        btn_restart_exceptionView = new QPushButton(exception_view);
        btn_restart_exceptionView->setObjectName(QStringLiteral("btn_restart_exceptionView"));
        btn_restart_exceptionView->setGeometry(QRect(740, 10, 32, 32));
        btn_restart_exceptionView->setMaximumSize(QSize(32, 32));
        btn_restart_exceptionView->setStyleSheet(QStringLiteral("border-image: url(:/resources/assets/icons/power.png);"));
        btn_restart_exceptionView->setFlat(true);
        btn_close_exceptionView = new QPushButton(exception_view);
        btn_close_exceptionView->setObjectName(QStringLiteral("btn_close_exceptionView"));
        btn_close_exceptionView->setGeometry(QRect(650, 410, 131, 51));
        btn_close_exceptionView->setFont(font10);
        btn_close_exceptionView->setAutoFillBackground(false);
        btn_close_exceptionView->setCheckable(false);
        btn_close_exceptionView->setFlat(false);
        label_exception_title = new QLabel(exception_view);
        label_exception_title->setObjectName(QStringLiteral("label_exception_title"));
        label_exception_title->setGeometry(QRect(200, 210, 571, 78));
        QFont font11;
        font11.setPointSize(20);
        font11.setBold(true);
        font11.setWeight(75);
        label_exception_title->setFont(font11);
        label_exception_title->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));
        label_exception_title->setAlignment(Qt::AlignCenter);
        label_exception_title->setWordWrap(true);
        stackedWidget->addWidget(exception_view);
        information_view = new QWidget();
        information_view->setObjectName(QStringLiteral("information_view"));
        label_information_title = new QLabel(information_view);
        label_information_title->setObjectName(QStringLiteral("label_information_title"));
        label_information_title->setGeometry(QRect(90, 20, 611, 51));
        label_information_title->setFont(font7);
        label_information_title->setStyleSheet(QStringLiteral("color: rgb(21, 101, 192);"));
        btn_close_statisticsView = new QPushButton(information_view);
        btn_close_statisticsView->setObjectName(QStringLiteral("btn_close_statisticsView"));
        btn_close_statisticsView->setGeometry(QRect(650, 410, 131, 51));
        btn_close_statisticsView->setFont(font10);
        btn_close_statisticsView->setFlat(false);
        horizontalLayoutWidget_6 = new QWidget(information_view);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(30, 270, 751, 138));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_nbDevicesScanned_title = new QLabel(horizontalLayoutWidget_6);
        label_nbDevicesScanned_title->setObjectName(QStringLiteral("label_nbDevicesScanned_title"));
        QFont font12;
        font12.setPointSize(12);
        font12.setBold(true);
        font12.setWeight(75);
        label_nbDevicesScanned_title->setFont(font12);
        label_nbDevicesScanned_title->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_12->addWidget(label_nbDevicesScanned_title);

        label_nbMalwaresDetected_title = new QLabel(horizontalLayoutWidget_6);
        label_nbMalwaresDetected_title->setObjectName(QStringLiteral("label_nbMalwaresDetected_title"));
        label_nbMalwaresDetected_title->setFont(font12);
        label_nbMalwaresDetected_title->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_12->addWidget(label_nbMalwaresDetected_title);

        label_nbFilesScanned_title = new QLabel(horizontalLayoutWidget_6);
        label_nbFilesScanned_title->setObjectName(QStringLiteral("label_nbFilesScanned_title"));
        label_nbFilesScanned_title->setFont(font12);
        label_nbFilesScanned_title->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_12->addWidget(label_nbFilesScanned_title);

        label_percentInfectedDevices_title = new QLabel(horizontalLayoutWidget_6);
        label_percentInfectedDevices_title->setObjectName(QStringLiteral("label_percentInfectedDevices_title"));
        label_percentInfectedDevices_title->setFont(font12);
        label_percentInfectedDevices_title->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_12->addWidget(label_percentInfectedDevices_title);

        label_averageTimeScan_title = new QLabel(horizontalLayoutWidget_6);
        label_averageTimeScan_title->setObjectName(QStringLiteral("label_averageTimeScan_title"));
        label_averageTimeScan_title->setFont(font12);
        label_averageTimeScan_title->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_12->addWidget(label_averageTimeScan_title);


        horizontalLayout_9->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        label_nbDevicesScanned_value = new QLabel(horizontalLayoutWidget_6);
        label_nbDevicesScanned_value->setObjectName(QStringLiteral("label_nbDevicesScanned_value"));
        label_nbDevicesScanned_value->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_13->addWidget(label_nbDevicesScanned_value);

        label_nbMalwaresDetected_value = new QLabel(horizontalLayoutWidget_6);
        label_nbMalwaresDetected_value->setObjectName(QStringLiteral("label_nbMalwaresDetected_value"));
        label_nbMalwaresDetected_value->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_13->addWidget(label_nbMalwaresDetected_value);

        label_nbFilesScanned_value = new QLabel(horizontalLayoutWidget_6);
        label_nbFilesScanned_value->setObjectName(QStringLiteral("label_nbFilesScanned_value"));
        label_nbFilesScanned_value->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_13->addWidget(label_nbFilesScanned_value);

        label_percentInfectedDevices_value = new QLabel(horizontalLayoutWidget_6);
        label_percentInfectedDevices_value->setObjectName(QStringLiteral("label_percentInfectedDevices_value"));
        label_percentInfectedDevices_value->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_13->addWidget(label_percentInfectedDevices_value);

        label_averageTimeScan_value = new QLabel(horizontalLayoutWidget_6);
        label_averageTimeScan_value->setObjectName(QStringLiteral("label_averageTimeScan_value"));
        label_averageTimeScan_value->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_13->addWidget(label_averageTimeScan_value);


        horizontalLayout_9->addLayout(verticalLayout_13);

        label_general_title = new QLabel(information_view);
        label_general_title->setObjectName(QStringLiteral("label_general_title"));
        label_general_title->setGeometry(QRect(20, 90, 761, 51));
        label_general_title->setFont(font11);
        label_general_title->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));
        label_statistics_title = new QLabel(information_view);
        label_statistics_title->setObjectName(QStringLiteral("label_statistics_title"));
        label_statistics_title->setGeometry(QRect(20, 220, 761, 51));
        label_statistics_title->setFont(font11);
        label_statistics_title->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));
        horizontalLayoutWidget_7 = new QWidget(information_view);
        horizontalLayoutWidget_7->setObjectName(QStringLiteral("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(30, 140, 751, 61));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_databaseVersion_title = new QLabel(horizontalLayoutWidget_7);
        label_databaseVersion_title->setObjectName(QStringLiteral("label_databaseVersion_title"));
        label_databaseVersion_title->setFont(font12);
        label_databaseVersion_title->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_14->addWidget(label_databaseVersion_title);

        label_softwareVersion_title = new QLabel(horizontalLayoutWidget_7);
        label_softwareVersion_title->setObjectName(QStringLiteral("label_softwareVersion_title"));
        label_softwareVersion_title->setFont(font12);
        label_softwareVersion_title->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_14->addWidget(label_softwareVersion_title);


        horizontalLayout_10->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_softwareVersion_value = new QLabel(horizontalLayoutWidget_7);
        label_softwareVersion_value->setObjectName(QStringLiteral("label_softwareVersion_value"));
        label_softwareVersion_value->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));

        verticalLayout_15->addWidget(label_softwareVersion_value);

        label_databaseVersion_value = new QLabel(horizontalLayoutWidget_7);
        label_databaseVersion_value->setObjectName(QStringLiteral("label_databaseVersion_value"));
        label_databaseVersion_value->setStyleSheet(QStringLiteral("color: rgb(55, 71, 79);"));
        label_databaseVersion_value->setScaledContents(false);
        label_databaseVersion_value->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_15->addWidget(label_databaseVersion_value);


        horizontalLayout_10->addLayout(verticalLayout_15);

        label_10 = new QLabel(information_view);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 0, 80, 80));
        label_10->setStyleSheet(QStringLiteral("image: url(:/resources/assets/USBGuardian.png);"));
        label_10->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(information_view);
        MainWindow->setCentralWidget(homeView);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        btn_cancel_analyze->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "USBGuardian", nullptr));
        label_welcome->setText(QApplication::translate("MainWindow", "Analyze your USB key", nullptr));
        logo_welcomeView->setText(QString());
        btn_information->setText(QString());
        btn_restart_welcomeView->setText(QString());
        label_welcome_2->setText(QApplication::translate("MainWindow", "with USBGuardian", nullptr));
        label->setText(QApplication::translate("MainWindow", "Insert your USB key", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "USBGuardian takes care of the rest!", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Clean viruses easily!", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "1.", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "2.", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "3.", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Analysis", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Do not remove your USB key!", nullptr));
        label_9->setText(QString());
        label_11->setText(QString());
        btn_restart_analyzeView->setText(QString());
        label_analyze_view_title->setText(QApplication::translate("MainWindow", "Analysis of your USB key in progress...", nullptr));
        btn_cancel_analyze->setText(QString());
        img_info->setText(QString());
        label_recommendations->setText(QApplication::translate("MainWindow", "Recommendations", nullptr));
        label_recommendations_1->setText(QApplication::translate("MainWindow", "In case of doubt: security@example.com", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "You can remove your USB key", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "The key can be safely removed.", nullptr));
        label_8->setText(QString());
        btn_restart_ejectView->setText(QString());
        img_report_state->setText(QString());
        label_report_title_2->setText(QApplication::translate("MainWindow", "Analysis Report", nullptr));
        label_report_state_title->setText(QApplication::translate("MainWindow", "No issues detected", nullptr));
        label_report_time->setText(QApplication::translate("MainWindow", "Total time: 9 minutes 30 seconds", nullptr));
        label_report_files->setText(QApplication::translate("MainWindow", "Files analyzed: 90/100", nullptr));
        label_report_information->setText(QApplication::translate("MainWindow", "Information", nullptr));
        label_report_information_details->setText(QApplication::translate("MainWindow", "A new file with analysis signature has been created at the root of the USB drive", nullptr));
        logo_reportView->setText(QString());
        btn_restart_reportView->setText(QString());
        btnEject->setText(QApplication::translate("MainWindow", "Eject", nullptr));
        btnRemove->setText(QApplication::translate("MainWindow", "Remove viruses", nullptr));
        btnFormat->setText(QApplication::translate("MainWindow", "Format the key", nullptr));
        btnShowInfectedFiles->setText(QApplication::translate("MainWindow", "Details", nullptr));
        img_exception->setText(QString());
        label_7->setText(QString());
        btn_restart_exceptionView->setText(QString());
        btn_close_exceptionView->setText(QApplication::translate("MainWindow", "Close", nullptr));
        label_exception_title->setText(QApplication::translate("MainWindow", "Your USB key format is not supported!", nullptr));
        label_information_title->setText(QApplication::translate("MainWindow", "Information", nullptr));
        btn_close_statisticsView->setText(QApplication::translate("MainWindow", "Close", nullptr));
        label_nbDevicesScanned_title->setText(QApplication::translate("MainWindow", "Number of keys analyzed", nullptr));
        label_nbMalwaresDetected_title->setText(QApplication::translate("MainWindow", "Number of detected viruses", nullptr));
        label_nbFilesScanned_title->setText(QApplication::translate("MainWindow", "Number of files analyzed", nullptr));
        label_percentInfectedDevices_title->setText(QApplication::translate("MainWindow", "% of infected keys", nullptr));
        label_averageTimeScan_title->setText(QApplication::translate("MainWindow", "Average analysis time", nullptr));
        label_nbDevicesScanned_value->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_nbMalwaresDetected_value->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_nbFilesScanned_value->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_percentInfectedDevices_value->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_averageTimeScan_value->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_general_title->setText(QApplication::translate("MainWindow", "Versions", nullptr));
        label_statistics_title->setText(QApplication::translate("MainWindow", "Some figures", nullptr));
        label_databaseVersion_title->setText(QApplication::translate("MainWindow", "Software version", nullptr));
        label_softwareVersion_title->setText(QApplication::translate("MainWindow", "Database version", nullptr));
        label_softwareVersion_value->setText(QApplication::translate("MainWindow", "1.0.0", nullptr));
        label_databaseVersion_value->setText(QApplication::translate("MainWindow", "0.0.0", nullptr));
        label_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
