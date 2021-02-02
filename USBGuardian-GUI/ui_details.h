/********************************************************************************
** Form generated from reading UI file 'details.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILS_H
#define UI_DETAILS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_Details
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listDetails;

    void setupUi(QDialog *Details)
    {
        if (Details->objectName().isEmpty())
            Details->setObjectName(QStringLiteral("Details"));
        Details->setWindowModality(Qt::NonModal);
        Details->setEnabled(true);
        Details->resize(400, 300);
        Details->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        Details->setSizeGripEnabled(false);
        Details->setModal(false);
        buttonBox = new QDialogButtonBox(Details);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 260, 381, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listDetails = new QListWidget(Details);
        listDetails->setObjectName(QStringLiteral("listDetails"));
        listDetails->setGeometry(QRect(5, 11, 391, 241));

        retranslateUi(Details);
        QObject::connect(buttonBox, SIGNAL(accepted()), Details, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Details, SLOT(reject()));

        QMetaObject::connectSlotsByName(Details);
    } // setupUi

    void retranslateUi(QDialog *Details)
    {
        Details->setWindowTitle(QApplication::translate("Details", "Details", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Details: public Ui_Details {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILS_H
