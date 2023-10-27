#pac update

sudo apt update
sudo apt upgrade
sudo raspi-config

# grab pwd

pi $> sudo -i
root> passwd

#swap

root>apt install vim
root> dphys-swapfile swapoff
root> vim /etc/dphys-swapfile
	Ø Edit : CONF_SWAPSIZE=2000
root> dphys-swapfile setup
root> dphys-swapfile swapon

#create user

root > useradd -m securite
root > passwd securite 
root > vim /etc/sudoers
	Ø Edit : securite ALL=(ALL:ALL) ALL
root > su securite
securite $> sudo usermod -a -G adm,dialout,cdrom,sudo,audio,video,plugdev,games,users,input,netdev,gpio,i2c,spi securite
securite $> groups securite

#account security

#securite $> sudo pkill -u pi
securite $> sudo deluser -remove-home pi
securite $> sudo vim /etc/sudoers.d/010_pi-nopasswd
	Ø Edit : pi --> securite

#ssh cnfg

#securite $> mkdir ~/.ssh
securite $> ssh-keygen -t ed25519
securite $> ssh-keygen -t rsa
securite $> vim ~/.ssh/autorized_keys 
	Ø Edit : Add your public keys in the file
securite $> sudo vim /etc/ssh/sshd_config
	Ø Edit:
		○ Port 2222 # Change default port to 2222
		○ PasswordAuthentication no # Disable password connection, only keys are allowed
		○ PermitRootLogin no # Remove root connection with ssh.
		○ Banner /etc/issue.net # Add a beautiful banner before auth.
securite $> sudo service ssh restart

#hostname cfg

securite $> sudo vim /etc/hostname
	Ø Edit : station01
securite $> sudo vim /etc/hosts
	Ø Edit : remove raspberry and add station01

#zsh terminal

sudo apt install zsh

sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

#Clam AV

securite $> sudo apt install clamav clamav-daemon
securite $> sudo systemctl enable clamav-daemon
securite $> ls -l /var/log/clamav
securite $> sudo touch /var/log/clamav/freshclam.log
securite $> chmod 600 /var/log/clamav/freshclam.log
securite $> chown clamav /var/log/clamav/freshclam.log

#virusdb update

sudo freshclam

#internal logger erro condition

securite $> sudo /etc/init.d/clamav-freshclam stop
securite $> sudo freshclam
securite $> sudo /etc/init.d/clamav-freshclam start

#clamav daemon

securite $> sudo vim /etc/systemctl/system/clamav-daemon.service.d/extend.conf
	Ø Edit : ExecStartPre=/bin/mkdir -p /run/clamav
securite $> sudo systemctl daemon-reload
securite $> sudo service clamav-daemin start

#virusdb auto update

#usb gurdian install---
#change link later

securite $> cd 
securite $> git clone https://github.com/AlrikRr.USGBuardian.git
securite $> cd USBGuardian
securite $> sudo cp -r USBGuardian-core /opt/USBGuardian
securite $> sudo chmod +x -R /opt/USBGuardian/scripts


#QT5 gui

securite $> sudo apt install qt5-default qtcreator
securite $> cd USBGuardian-GUI
#compile
securite $> cd USBGuardian-GUI
securite $> qmake USBGUardian.pro
securite $> make

#udev rule usb
securite $> sudo cp ~/USBGuardian/udev/insertUSB.rules /etc/udev/rules.d/insertUSB.rules
securite $> sudo udevadm control --reload

securite $> sudo cp ~/USBGuardian/service/insertUSB.service /etc/systemd/system/insertUSB.service
securite $> sudo systemctl enable insertUSB.service


#automount


#permision general

securite $> sudo chown clamav:clamav -R /media/securite
securite $> sudo chmod 760 -R /media/securite

#file permission
securite $> sudo chown securite -R /opt/USBGuardian/logs
securite $> sudo chmod 760 -R /opt/USBGuardian/logs

