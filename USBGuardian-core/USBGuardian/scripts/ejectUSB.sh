#!/bin/bash

#Unmount the USB stick
sudo umount -f /media/pi/*
#Kill any clamscan running (if USB stick is removed before the end of analysis
#Empty the report of the current USB stick
sudo echo "" > /opt/USBGuardian/logs/report.log
