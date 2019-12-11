# How it works
We also created a document explaining how to recreate this software step by step:
https://usbguardian.wordpress.com/documentation/

# Edit

- `/scripts/scan.py` : Using **clamdscan** rather **clamscan** . D'ont to forghet to initialize the clamav daemon before the scan. From a Raspberry Pi B The scan time is greatly improved( clamscan : 8Minutes / clamdscan : 10 secondes)

- `/scripts/scanAndRemove.py` : Same as scan.py. Using clamdscan instead of clamscan.

- `/etc/clamav/clamd.conf`: Replace the clamav user and add root user instead.

- `/etc/udev/rules.d/insertUSB.rule`: Edit the udev rules, working with Raspbian Buster

- `/etc/systemd/system/insertUSB.service`: Add *User* option on *Service* unit

- Now USBGuardian is working on **NTFS**

- Few edit on the GUI, need a few adjustment.

- I remove the manual mount on /mnt/usb and leave the system doing it by itself (that correct a lot of problem about the ntfs format)

- Scan directory is now **/media/pi/**

- When you turn on the raspberry, you need to wait a few minutes util the clamav-daemon is loading.


# To-do

- Translation of the GUI
- Format USB option
- If the clamav-daemon is starting, print a message on the mainwindow
- Add Option Unit on insertUSB.service so it will wait clamav-daemon is loaded
