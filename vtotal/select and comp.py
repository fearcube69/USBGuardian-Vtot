#function will select and compress file
# will limit to 640mb
# check file size, if <640mb comp, else, too large
# if file < 640mb
#     {
#         compress the file 
#     }
#     else
#     print "file is too large"


# https://maps.app.goo.gl/Q7N7JN97VJ5RkuP2A


import os
from PyQt5.QtWidgets import QApplication, QMainWindow, QFileDialog, QMessageBox
import zipfile

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

    def openFileDialog(self):
        options = QFileDialog.Options()
        options |= QFileDialog.DontUseNativeDialog
        files, _ = QFileDialog.getOpenFileNames(self, 'Select Files', '', 'All Files (*);;Text Files (*.txt)', options=options)

        if files:
            print(files)

            # Zip the selected files if size is less than 650MB
            with zipfile.ZipFile('selected_files.zip', 'w') as zipf:
                for file in files:
                    file_size = os.path.getsize(file) / (1024 * 1024)  # Get file size in MB
                    if file_size < 650:
                        zipf.write(file, arcname=os.path.basename(file))  # Use os.path.basename to get only the filename
                    else:
                        QMessageBox.warning(self, 'File Size Exceeded', f'{os.path.basename(file)} exceeds 650MB and cannot be zipped.')

            print('Selected files zipped successfully')
        else:
            print('No files selected')

app = QApplication([])
window = MainWindow()
window.openFileDialog()
