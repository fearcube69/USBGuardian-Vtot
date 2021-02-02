#!/bin/bash

#Unmount usb stick in case there is an old one
sudo umount -f /mnt/securite
#Change directory
cd /opt/USBGuardian/logs

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


#Store format info about the key
sudo mount | grep /media/securite/ > /opt/USBGuardian/scripts/checkFormat

#Launch python script
python3 /opt/USBGuardian/scripts/checkFormat.py

