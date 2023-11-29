#!/bin/bash

# Install & Config ClamAV
sudo apt install clamav clamav-daemon
sudo systemctl enable clamav-daemon
sudo ls -l /var/log/clamav

# Create freshclam.log file if not exists
sudo touch /var/log/clamav/freshclam.log
sudo chmod 600 /var/log/clamav/freshclam.log
sudo chown clamav /var/log/clamav/freshclam.log

# Run first update of the virus database
sudo freshclam

# If encountering an error, execute the following commands
sudo /etc/init.d/clamav-freshclam stop
sudo freshclam
sudo /etc/init.d/clamav-freshclam start

# Modify clamav-daemon conf
sudo vim /etc/systemctl/system/clamav-daemon.service.d/extend.conf
# Edit: ExecStartPre=/bin/mkdir -p /run/clamav
sudo systemctl daemon-reload
sudo service clamav-daemon start

# Automatic update of the virus database
sudo vim /etc/cron.daily/freshclam
# Edit:
#  #!/bin/sh
#  /etc/init.d/clamav-freshclam stop
#  /usr/bin/freshclam -v >> /var/log/clamav/freshclam.log
#  /etc/init.d/clamav-freshclam start

# Install USBGuardian
cd
git clone https://github.com/AlrikRr.USGBuardian.git
cd USBGuardian
sudo cp -r USBGuardian-core /opt/USBGuardian
sudo chmod +x -R /opt/USBGuardian/scripts

# Install QT5
sudo apt install qt5-default qtcreator
cd USBGuardian-GUI
qmake USBGUardian.pro
make