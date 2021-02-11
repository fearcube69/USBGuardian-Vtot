#!/bin/bash

#Unmount usb stick in case there is an old one
sudo umount -f /mnt/securite/*
#Change directory
cd /opt/USBGuardian/logs

sleep 3

#Create the report file and write the date and the time in it
sudo touch report.log
sudo printf "Report created:  $(date)\n" >> ./report.log

#Check if the USB stick is partitioned
partitioned=1

while read x
do
	if [[ "$x" =~ ^sd[a-z][0-9] ]]; then
		partitioned="0"
	fi;
done << EOF
$(ls /dev)
EOF

if [ "$partitioned" = "0" ]; then
	#sudo mount /dev/sd[a-z][1-9] /mnt/usb
	sudo printf "Partitioned: yes\n" >> ./report.log
else
	#sudo mount /dev/sd[a-z] /mnt/usb
	sudo printf "Partitioned: no\n" >> ./report.log
fi;

#Create a file to store format info

sudo touch /opt/USBGuardian/scripts/checkFormat
sudo echo "NONE" > /opt/USBGuardian/scripts/checkFormat
#sudo chown pi /home/pi/Documents/checkFormat
#sudo chmod 777 /home/pi/Documents/checkFormat

#Store format info about the key
sudo mount | grep /media/securite/ > /opt/USBGuardian/scripts/checkFormat
#bash /opt/USBGuardian/scripts/test.sh
#Launch python script
python3 /opt/USBGuardian/scripts/checkFormat.py

#If the format is supported start the scan
#if [ "$partitioned" = "0" ]; then
#	sudo python3 /opt/USBGuardian/scripts/scan.py
#fi
