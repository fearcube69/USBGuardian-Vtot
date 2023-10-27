#!/bin/bash

# Update packages
sudo apt update && sudo apt upgrade -y

#expanding partitions
if sudo raspi-config --expand-rootfs; then
    echo "Root partition expanded. System will reboot now."
    sudo reboot
else
    echo "Root partition is already expanded or there was an issue expanding."
fi

# Set root password - Remember, setting a hardcoded root password in a script is not secure
echo "root:YOUR_ROOT_PASSWORD" | sudo chpasswd

# Configure swap
sudo apt install -y vim
sudo dphys-swapfile swapoff
echo "CONF_SWAPSIZE=2000" | sudo tee /etc/dphys-swapfile
sudo dphys-swapfile setup
sudo dphys-swapfile swapon

# Create and configure 'securite' user
sudo useradd -m securite
echo "securite:YOUR_USER_PASSWORD" | sudo chpasswd
echo "securite ALL=(ALL:ALL) ALL" | sudo tee -a /etc/sudoers
sudo usermod -a -G adm,dialout,cdrom,sudo,audio,video,plugdev,games,users,input,netdev,gpio,i2c,spi securite

# Account security configurations
sudo deluser --remove-home pi
sudo sed -i 's/pi/securite/' /etc/sudoers.d/010_pi-nopasswd

# SSH configurations
ssh-keygen -t ed25519 -f ~/.ssh/id_ed25519 -N ""
ssh-keygen -t rsa -f ~/.ssh/id_rsa -N ""
# Note: You would ideally append public keys to authorized_keys here
sudo sed -i -e 's/Port [0-9]*/Port 2222/' -e 's/PasswordAuthentication yes/PasswordAuthentication no/' -e 's/PermitRootLogin yes/PermitRootLogin no/' /etc/ssh/sshd_config
echo "Banner /etc/issue.net" | sudo tee -a /etc/ssh/sshd_config
sudo service ssh restart

# Hostname configurations
echo "station01" | sudo tee /etc/hostname
sudo sed -i 's/raspberry/station01/' /etc/hosts

# Install zsh and configure
sudo apt install -y zsh
sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

# ClamAV configurations
sudo apt install -y clamav clamav-daemon
sudo systemctl enable clamav-daemon

sudo touch /var/log/clamav/freshclam.log
sudo chmod 600 /var/log/clamav/freshclam.log
sudo chown clamav /var/log/clamav/freshclam.log
sudo freshclam

sudo /etc/init.d/clamav-freshclam stop
sudo freshclam
sudo /etc/init.d/clamav-freshclam start

echo "ExecStartPre=/bin/mkdir -p /run/clamav" | sudo tee /etc/systemctl/system/clamav-daemon.service.d/extend.conf
sudo systemctl daemon-reload
sudo service clamav-daemon start

# USB Guardian configurations
git clone https://github.com/AlrikRr.USGBuardian.git
sudo cp -r USBGuardian/USBGuardian-core /opt/USBGuardian
sudo chmod +x -R /opt/USBGuardian/scripts

# QT5 GUI configurations
sudo apt install -y qt5-default qtcreator
cd USBGuardian/USBGuardian-GUI
qmake USBGuardian.pro
make

sudo cp ~/USBGuardian/udev/insertUSB.rules /etc/udev/rules.d/
sudo udevadm control --reload
sudo cp ~/USBGuardian/service/insertUSB.service /etc/systemd/system/
sudo systemctl enable insertUSB.service

# Setting permissions
sudo chown clamav:clamav -R /media/securite
sudo chmod 760 -R /media/securite
sudo chown securite -R /opt/USBGuardian/logs
sudo chmod 760 -R /opt/USBGuardian/logs
