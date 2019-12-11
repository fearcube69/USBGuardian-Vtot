
# How to use
Please download the following user manual explaining how to use the station:

https://usbguardian.wordpress.com/documentation/

# Where to download
## Pre-build image
You can download the pre-built image here:

https://usbguardian.wordpress.com/documentation/

You will need to use an image writing tool to install the image you have downloaded on your SD card.

Etcher is a graphical SD card writing tool that works on Mac OS, Linux and Windows, and is the easiest option for most users. Etcher also supports writing images directly from the zip file, without any unzipping required. To write your image with Etcher:

Download Etcher and install it.
Connect an SD card reader with the SD card inside.
Open Etcher and select from your hard drive the Raspberry Pi .img file you wish to write to the SD card.
Select the SD card you wish to write your image to.
Review your selections and click ‘Flash!’ to begin writing data to the SD card.

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

# To-do

- Translation of the GUI
- Format USB option

