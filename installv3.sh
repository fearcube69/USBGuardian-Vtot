#!/bin/bash
sudo apt update -y && sudo apt upgrade -y

# Change root pwd
read -s -p "Enter your root password: " ROOT_PASSWORD
(echo "root:$ROOT_PASSWORD" | sudo chpasswd) || {
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

  sudo useradd -m securite &&
  echo "securite:YOUR_USER_PASSWORD" | sudo chpasswd &&
{
  sudo useradd -m securite &&
  read -s -p "Enter password for 'securite' user: " SECURITE_PASSWORD &&
  echo "securite:$SECURITE_PASSWORD" | sudo chpasswd &&
  echo "securite ALL=(ALL:ALL) ALL" | sudo tee -a /etc/sudoers &&
  sudo usermod -a -G adm,dialout,cdrom,sudo,audio,video,plugdev,games,users,input,netdev,gpio,i2c,spi securite
} || {
  echo "Failed to create and configure 'securite' user" | tee -a installation_errors.txt
}

# Account pi delete
{
  # Kill processes owned by the "pi" user
sudo pkill -u pi

# Delete the "pi" user and remove its home directory
sudo deluser --remove-home pi

# Modify the sudoers file to replace "pi" with "securite"
sudo sed -i 's/pi securite/pi/' /etc/sudoers.d/010_pi-nopasswd

echo "pi account deleted and sudoers file updated."

# Check if the "pi" user is still logged in
if who | grep -q pi; then
  echo "Reboot required to complete the deletion of the pi account."
  sudo touch /var/run/reboot-required
fi
} || {
  echo "Account security configurations failed" | tee -a installation_errors.txt
}

# SSH configurations
{
  #!/bin/bash

# Create the .ssh directory if it doesn't exist
mkdir -p ~/.ssh

# Generate ed25519 key pair
ssh-keygen -t ed25519

# Generate RSA key pair
ssh-keygen -t rsa

# Open the authorized_keys file for editing
vim ~/.ssh/authorized_keys

# Modify the SSH server configuration file
sudo sed -i 's/#Port 22/Port 2222/' /etc/ssh/sshd_config
sudo sed -i 's/#PasswordAuthentication yes/PasswordAuthentication no/' /etc/ssh/sshd_config
sudo sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin no/' /etc/ssh/sshd_config
sudo sed -i 's/#Banner none/Banner \/etc\/issue.net/' /etc/ssh/sshd_config

# Restart the SSH service
sudo service ssh restart

echo "SSH connection configured securely."

} || {
  echo "SSH configurations failed" | tee -a installation_errors.txt
}

# Hostname configurations
{
  # Modify the /etc/hostname file
sudo sed -i 's/.*$/station01/' /etc/hostname

# Modify the /etc/hosts file
sudo sed -i 's/raspberry/station01/' /etc/hosts

echo "Machine name modified to station01."
} || {
  echo "Hostname configurations failed" | tee -a installation_errors.txt
}

# # Install zsh without launching a new shell immediately
# {
#   sudo apt install -y zsh &&
#   sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" "" --unattended
# } || {
#   echo "ZSH installation failed" | tee -a installation_errors.txt
# }



# ClamAV install and configurations
{
#!/bin/bash

# Install ClamAV and ClamAV-daemon
sudo apt install clamav clamav-daemon -y

# Enable ClamAV-daemon
sudo systemctl enable clamav-daemon

# Check if freshclam.log exists
if [ ! -f /var/log/clamav/freshclam.log ]; then
    # Create freshclam.log if it doesn't exist
    sudo touch /var/log/clamav/freshclam.log
    sudo chmod 600 /var/log/clamav/freshclam.log
    sudo chown clamav /var/log/clamav/freshclam.log
fi

# Update the virus database
sudo freshclam

# If there's a problem with the internal logger, stop the service, update, and then start the service again
if [ $? -ne 0 ]; then
    sudo /etc/init.d/clamav-freshclam stop
    sudo freshclam
    sudo /etc/init.d/clamav-freshclam start
fi

# Modify clamav-daemon configuration
echo -e "[Service]\nExecStartPre=/bin/mkdir -p /run/clamav" | sudo tee /etc/systemd/system/clamav-daemon.service.d/extend.conf
sudo systemctl daemon-reload
sudo service clamav-daemon start

# Set up automatic update of the virus database
echo -e "#!/bin/sh\n/etc/init.d/clamav-freshclam stop\n/usr/bin/freshclam -v >> /var/log/clamav/freshclam.log\n/etc/init.d/clamav-freshclam start" | sudo tee /etc/cron.daily/freshclam
sudo chmod +x /etc/cron.daily/freshclam

echo "ClamAV installation and configuration completed."

} || {
  echo "ClamAV configurations failed" | tee -a installation_errors.txt
}

# USB Guardian configurations
{
  

# Navigate to home directory
cd ~

# Clone the USBGuardian repository
git clone https://github.com/AlrikRr/USBGuardian.git

# Navigate to the USBGuardian directory
cd USBGuardian

# Copy the USBGuardian-core directory to /opt/USBGuardian
sudo cp -r USBGuardian-core /opt/USBGuardian

# Make the scripts in /opt/USBGuardian/scripts executable
sudo chmod +x -R /opt/USBGuardian/scripts

echo "USBGuardian installation completed."

} ||

 {
  echo "USB Guardian configurations failed" | tee -a installation_errors.txt
}

# QT5 GUI configurations
{
{
  #!/bin/bash

# Install Qt5 and Qt Creator
sudo apt install qt5-default qtcreator -y

# Navigate to the USBGuardian-GUI directory
cd ~/USBGuardian/USBGuardian-GUI

# Compile the application
qmake USBGuardian.pro
make

# Run the USBGuardian binary
./USBGuardian

echo "USBGuardian GUI compiled and run successfully."

} || {
  echo "QT5 GUI configurations and dependency installation failed" | tee -a installation_errors.txt
}
}



#UDEV rule config

# Copy the insertUSB.rules file to /etc/udev/rules.d/
sudo cp ~/USBGuardian/udev/insertUSB.rules /etc/udev/rules.d/insertUSB.rules

# Reload the UDEV rules
sudo udevadm control --reload

echo "UDEV rule for USB detection added and UDEV rules reloaded."


#Insert USB service

 sudo cp ~/USBGuardian/service/insertUSB.service /etc/systemd/system/insertUSB.service
 sudo systemctl enable insertUSB.service

# Open the Raspbian file explorer preferences
pcmanfm --preferences

# Wait for the preferences window to open
sleep 2

# Activate the "Removable media" tab
xdotool key Tab

# Uncheck the "Display options for removable media when inserted" checkbox
xdotool key space

# Close the preferences window
xdotool key Alt+F4

echo "Automount configuration completed."











# Setting permissions
{
  # Set ownership and permissions for /media/securite/
sudo chown clamav:clamav -R /media/securite
sudo chmod 760 -R /media/securite

# Set ownership and permissions for /opt/USBGuardian/logs
sudo chown securite -R /opt/USBGuardian/logs
sudo chmod 760 -R /opt/USBGuardian/logs

echo "Permissions set successfully."
} || {
  echo "Setting permissions failed" | tee -a installation_errors.txt
}

#autoreload clamAV
sudo sed -i 's/#AutomaticReload yes/AutomaticReload yes/' /etc/clamav/clamd.conf

 Check for filesystem expansion
if sudo raspi-config --expand-rootfs; then
if sudo raspi-config --expand-rootfs; then
    echo "Root partition expanded. Would you like to reboot now? [y/N]"
    read response
    if [[ $response =~ ^(yes|y)$ ]]
    then
        # Set up the post-reboot script to run on reboot
        echo "@reboot $USER $fpth2_dir" | sudo crontab -
        sudo reboot
    fi
else
    echo "Root partition is already expanded or there was an issue expanding."
    $fpth2_dir
fi