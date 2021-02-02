#!/usr/bin/python3.5
#-*- coding: utf-8 -*-

import os


#Open the file in which format info is stored
checkFormat = open('/opt/USBGuardian/scripts/checkFormat',"r")
formatOK=0
formated="NONE"

#Read the file to search the format
for lignes in checkFormat:

	if "vfat" in lignes:
		formated = "VFAT"

	elif "fat32" in lignes:
		formated = "FAT32"

	elif "fat16" in lignes:
		formated = "FAT16"

	elif "fuseblk" in lignes:
		formated = "NTFS"

	else:
		formated = "Unsupported format"
		formatOK=1

#Write the format in the report
with open('/opt/USBGuardian/logs/report.log',"a") as report:
	report.write("USB stick format: " + formated + "\n")

#Delete the checkFormat file
#os.system("sudo rm -f /home/pi/Documents/checkFormat")

#Execute the scan
if formatOK==0:
	os.system("sudo python3 /opt/USBGuardian/scripts/scan.py")
