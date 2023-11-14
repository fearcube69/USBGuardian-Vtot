#!/bin/bash

# Update and upgrade packages
#sudo apt update -y && sudo apt upgrade -y

# Change root password
read -s -p "Enter your root password: " ROOT_PASSWORD
(echo "root:$ROOT_PASSWORD" | sudo chpasswd) || {
  echo "Failed to set root password"
}

# Configure swap
sudo apt install -y vim &&
sudo dphys-swapfile swapoff &&
echo "CONF_SWAPSIZE=2000" | sudo tee /etc/dphys-swapfile &&
sudo dphys-swapfile setup &&
sudo dphys-swapfile swapon

# Create and configure 'securite' user
sudo useradd -m securite &&
read -s -p "Enter password for 'securite' user: " SECURITE_PASSWORD &&
echo "securite:$SECURITE_PASSWORD" | sudo chpasswd &&
echo "securite ALL=(ALL:ALL) ALL" | sudo tee -a /etc/sudoers &&
sudo usermod -a -G adm,dialout,cdrom,sudo,audio,video,plugdev,games,users,input,netdev,gpio,i2c,spi securite
su - securite
# Delete 'pi' account
sudo pkill -u pi
sudo deluser --remove-home pi
sudo sed -i 's/pi securite/pi/' /etc/sudoers.d/010_pi-nopasswd

# SSH configurations
mkdir -p ~/.ssh
ssh-keygen -t ed25519
ssh-keygen -t rsa
vim ~/.ssh/authorized_keys
sudo sed -i 's/#Port 22/Port 2222/' /etc/ssh/sshd_config
sudo sed -i 's/#PasswordAuthentication yes/PasswordAuthentication no/' /etc/ssh/sshd_config
sudo sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin no/' /etc/ssh/sshd_config
sudo sed -i 's/#Banner none/Banner \/etc\/issue.net/' /etc/ssh/sshd_config
sudo service ssh restart

# Hostname configurations
sudo sed -i 's/.*$/station01/' /etc/hostname
sudo sed -i 's/raspberry/station01/' /etc/hosts

# Install ClamAV and configure
sudo apt install clamav clamav-daemon -y
sudo systemctl enable clamav-daemon
sudo freshclam
sudo /etc/init.d/clamav-freshclam stop
sudo freshclam
sudo /etc/init.d/clamav-freshclam start
echo -e "[Service]\nExecStartPre=/bin/mkdir -p /run/clamav" | sudo tee /etc/systemd/system/clamav-daemon.service.d/extend.conf
sudo systemctl daemon-reload
sudo service clamav-daemon start
echo -e "#!/bin/sh\n/etc/init.d/clamav-freshclam stop\n/usr/bin/freshclam -v >> /var/log/clamav/freshclam.log\n/etc/init.d/clamav-freshclam start" | sudo tee /etc/cron.daily/freshclam
sudo chmod +x /etc/cron.daily/freshclam

# USB Guardian configurations
cd ~
git clone https://github.com/AlrikRr/USBGuardian.git
cd USBGuardian
sudo cp -r USBGuardian-core /opt/USBGuardian
sudo chmod +x -R /opt/USBGuardian/scripts

# QT5 GUI configurations
sudo apt install qt5-default qtcreator -y
cd ~/USBGuardian/USBGuardian-GUI
qmake USBGuardian.pro
make
./USBGuardian

# UDEV rule config
sudo cp ~/USBGuardian/udev/insertUSB.rules /etc/udev/rules.d/insertUSB.rules
sudo udevadm control --reload

# Insert USB service
sudo cp ~/USBGuardian/service/insertUSB.service /etc/systemd/system/insertUSB.service
sudo systemctl enable insertUSB.service

# Setting permissions
sudo chown clamav:clamav -R /media/securite
sudo chmod 760 -R /media/securite
sudo chown securite -R /opt/USBGuardian/logs
sudo chmod 760 -R /opt/USBGuardian/logs

# Enable auto-reload for ClamAV daemon
sudo sed -i 's/#AutomaticReload yes/AutomaticReload yes/' /etc/clamav/clamd.conf

# Check for filesystem expansion
if sudo raspi-config --expand-rootfs; then
  echo "Root partition expanded. Would you like to reboot now? [y/N]"
  read response
  if [[ $response =~ ^(yes|y)$ ]]; then
    sudo reboot
  fi
else
