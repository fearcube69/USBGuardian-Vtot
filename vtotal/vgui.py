from PyQt5.QtWidgets import QPushButton, QLabel

def upload_file():
   FILE_PATH = "/path/to/file/to/scan.zip" # Replace with actual file path
   files = {"file": (os.path.basename(FILE_PATH), open(os.path.abspath(FILE_PATH), "rb"))}
   file_id = virustotal.upload_file(files)
   report = virustotal.get_report(file_id)
   report_label.setText(str(report))
