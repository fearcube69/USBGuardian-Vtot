import virustotal_python
import os.path

def upload_file(files):
   with virustotal_python.Virustotal("<VirusTotal API Key>") as vtotal:
       resp = vtotal.request("files", files=files, method="POST")
       return resp.json()["data"]["id"]

def get_report(file_id):
   with virustotal_python.Virustotal("<VirusTotal API Key>") as vtotal:
       resp = vtotal.request(f"files/{file_id}")
       return resp.data
