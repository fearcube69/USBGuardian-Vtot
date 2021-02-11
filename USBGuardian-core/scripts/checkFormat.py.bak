#!/usr/bin/python3.5
#-*- coding: utf-8 -*-

import subprocess

#Open the file in which format info is stored
#checkFormat = open('/opt/USBGuardian/scripts/checkFormat',"r")
formatOK=0
formated="NONE"
i = 1
with open('/opt/USBGuardian/scripts/checkFormat',"r") as checkFormat, open('/opt/USBGuardian/logs/report.log',"a") as report:
    #Read the file to search the format and write it on report.log
    for lignes in checkFormat:
        if "vfat" in lignes:
            formated = "VFAT"
            report.write("Partition "+str(i)+" format: "+ formated + "\n")
        elif "fat32" in lignes:
            formated = "FAT32"
            report.write("Partition "+str(i)+" format: "+ formated + "\n")
        elif "fat16" in lignes:
            formated = "FAT16"
            report.write("Partition "+str(i)+" format: "+ formated + "\n")
        elif "fuseblk" in lignes:
            formated = "NTFS"
            report.write("Partition "+str(i)+" format: "+ formated + "\n")
        else:
            formated = "Unsupported format"
            formatOK=1
            report.write("USB stick format:"+ formated + "\n")
        i = i+1


#Delete the checkFormat file
#rmBashCommand = "sudo rm -f /opt/USBGuardian/scripts/checkFormat"
#subprocess.call(rmBashCommand.split())

#Execute the scan
if formatOK==0:
    scanBashCommand = "sudo python3 /opt/USBGuardian/scripts/scan.py"
    subprocess.call(scanBashCommand.split())
