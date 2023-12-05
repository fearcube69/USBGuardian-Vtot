// Include the necessary header files
#include "details.h"
#include "ui_details.h"
#include <QDebug>

// Constructor for the Details class
Details::Details(const QString &report, QWidget *parent) :
   QDialog(parent), // Inherit from QDialog
   ui(new Ui::Details) // Initialize the UI
{
   // Set up the UI
   ui->setupUi(this);

   // Set the window flags
   setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);

   // Clear the button box and add a close button
   ui->buttonBox->clear();
   ui->buttonBox->addButton(QDialogButtonBox::Close);

   // Split the report into a list of viruses
   QStringList virusesList = report.split('\n', QString::SkipEmptyParts);

   // For each virus in the list, if the virus is found or removed, add it to the list widget
   foreach (QString virus, virusesList) {
       if (virus.contains("FOUND") || virus.contains("Removed")) {
           QListWidgetItem *item = new QListWidgetItem(virus.replace("FOUND", "INFECTED"));
           ui->listDetails->addItem(item);
       }
   }
}

// Destructor for the Details class
Details::~Details()
{
   // Delete the UI object to free the memory
   delete ui;
}
