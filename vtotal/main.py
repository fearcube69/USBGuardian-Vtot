from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QLabel
import sys
import vgui
import virustotal

def main():

    app = QApplication(sys.argv)
    w = QWidget()
    w.resize(300,300)
    w.setWindowTitle("Virus Total Scan Mode")

    btn = QPushButton('Upload FIle', w)
    btn.move(110,150)
    btn.clicked.connect(gui.upload_file)

    report_label = QLabel(w)
    report_label.move(100,130)

    w.show()
    sys.exit(app.exec())


if __name__ == "__main__":
   main()
