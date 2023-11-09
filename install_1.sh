#!/bin/bash

# issue
# 1. Reboot
# 2. Change to zshell stopped operation

# Update packages
sudo apt update && sudo apt upgrade -y

p2_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
fpth2_dir="$p2_dir/install_2.sh"

# Check for filesystem expansion
if sudo raspi-config --expand-rootfs; then
    echo "Root partition expanded. System will reboot now."

    # Set up the post-reboot script to run on reboot
    echo "@reboot $USER $fpth2_dir" | sudo crontab -
    sudo reboot
else
    echo "Root partition is already expanded or there was an issue expanding."
    $fpth2_dir
fi
