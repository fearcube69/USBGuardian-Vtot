#!/bin/bash

lxtermminal -e 

# Remove the temporary cron job
(sudo crontab -l | grep -v '/path/to/post-reboot-script.sh' | sudo crontab -) || {
  echo "Failed to remove the temporary cron job" | tee -a installation_errors.txt
}

# Set root password - Remember, setting a hardcoded root password in a script is not secure
(echo "root:YOUR_ROOT_PASSWORD" | sudo chpasswd) || {
  echo "Failed to set root password" | tee -a installation_errors.txt
}

# Configure swap
{
  sudo apt install -y vim &&
  sudo dphys-swapfile swapoff &&
  echo "CONF_SWAPSIZE=2000" | sudo tee /etc/dphys-swapfile &&
  sudo dphys-swapfile setup &&
  sudo dphys-swapfile swapon
} || {
  echo "Swap configuration failed" | tee -a installation_errors.txt
}

# Create and configure 'securite' user
{
  sudo useradd -m securite &&
  echo "securite:YOUR_USER_PASSWORD" | sudo chpasswd &&
  echo "securite ALL=(ALL:ALL) ALL" | sudo tee -a /etc/sudoers &&
  sudo usermod -a -G adm,dialout,cdrom,sudo,audio,video,plugdev,games,users,input,netdev,gpio,i2c,spi securite
} || {
  echo "Failed to create and configure 'securite' user" | tee -a installation_errors.txt
}

# Account security configurations
{
  sudo deluser --remove-home pi &&
  sudo sed -i 's/pi/securite/' /etc/sudoers.d/010_pi-nopasswd
} || {
  echo "Account security configurations failed" | tee -a installation_errors.txt
}

# SSH configurations
{
  ssh-keygen -t ed25519 -f ~/.ssh/id_ed25519 -N "" &&
  ssh-keygen -t rsa -f ~/.ssh/id_rsa -N "" &&
  sudo sed -i -e 's/Port [0-9]*/Port 2222/' -e 's/PasswordAuthentication yes/PasswordAuthentication no/' -e 's/PermitRootLogin yes/PermitRootLogin no/' /etc/ssh/sshd_config &&
  echo "Banner /etc/issue.net" | sudo tee -a /etc/ssh/sshd_config &&
  sudo service ssh restart
} || {
  echo "SSH configurations failed" | tee -a installation_errors.txt
}

# Hostname configurations
{
  echo "station01" | sudo tee /etc/hostname &&
  sudo sed -i 's/raspberry/station01/' /etc/hosts
} || {
  echo "Hostname configurations failed" | tee -a installation_errors.txt
}

# Install zsh without launching a new shell immediately
{
  sudo apt install -y zsh &&
  sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" "" --unattended
} || {
  echo "ZSH installation failed" | tee -a installation_errors.txt
}

# ClamAV configurations
{
  sudo apt install -y clamav clamav-daemon &&
  sudo systemctl enable clamav-daemon &&
  sudo touch /var/log/clamav/freshclam.log &&
  sudo chmod 600 /var/log/clamav/freshclam.log &&
  sudo chown clamav /var/log/clamav/freshclam.log &&
  sudo freshclam &&
  sudo /etc/init.d/clamav-freshclam stop &&
  sudo freshclam &&
  sudo /etc/init.d/clamav-freshclam start &&
  echo "ExecStartPre=/bin/mkdir -p /run/clamav" | sudo tee /etc/systemctl/system/clamav-daemon.service.d/extend.conf &&
  sudo systemctl daemon-reload &&
  sudo service clamav-daemon start
} || {
  echo "ClamAV configurations failed" | tee -a installation_errors.txt
}

# USB Guardian configurations
{
  git clone https://github.com/AlrikRr.USGBuardian.git &&
  sudo cp -r USBGuardian/USBGuardian-core /opt/USBGuardian &&
  sudo chmod +x -R /opt/USBGuardian/scripts
} ||

 {
  echo "USB Guardian configurations failed" | tee -a installation_errors.txt
}

# QT5 GUI configurations
{
  sudo apt install -y qt5-default qtcreator &&
  cd USBGuardian/USBGuardian-GUI &&
  qmake USBGuardian.pro &&
  make &&
  sudo cp ~/USBGuardian/udev/insertUSB.rules /etc/udev/rules.d/ &&
  sudo udevadm control --reload &&
  sudo cp ~/USBGuardian/service/insertUSB.service /etc/systemd/system/ &&
  sudo systemctl enable insertUSB.service
} || {
  echo "QT5 GUI configurations failed" | tee -a installation_errors.txt
}

# Setting permissions
{
  sudo chown clamav:clamav -R /media/securite &&
  sudo chmod 760 -R /media/securite &&
  sudo chown securite -R /opt/USBGuardian/logs &&
  sudo chmod 760 -R /opt/USBGuardian/logs
} || {
  echo "Setting permissions failed" | tee -a installation_errors.txt
}

