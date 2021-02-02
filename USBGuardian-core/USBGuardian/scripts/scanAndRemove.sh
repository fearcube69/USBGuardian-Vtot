#!/bin/bash

#Empty the log file
sudo truncate -s 0 /opt/USBGuardian/logs/lastAnalysis.log

#Scan the USB device
sudo clamdscan --remove --verbose /mnt/usb/ >> /opt/USBGuardian/logs/lastAnalysis.log


