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
sudo -i -u securite