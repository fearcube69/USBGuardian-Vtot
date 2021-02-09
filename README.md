# USBGuardian

:warning: Le projet est actuellement en développment, il se peut qu'il y ait quelques problèmes, n'hésitez pas à contribuer ou à me contacter en cas de problème ! 

## Mise à jour importante :mage:

- Fonctionne avec une Raspberry Pi 4.
- Fonctionne avec le daemon clamAV pour une analyse plus rapide.
- Changement de l'utilisateur **pi** en **securite**.
- Changement du répertoire de scan par défaut en `/media/securite`.
- La clé USB est automatiquement montée par le système et plus par USBGuardian.
- Changement des rèlges Udev pour fonctionner avec Raspbian Buster.
- Traduction partiel en français de l'interface.
- Supporte les clés au format NTFS


# Comment ça fonctionne ? :sassy_man: 
Vous pouvez consulter la documentation sur le site officiel :[Documentation](https://usbguardian.wordpress.com/documentation/)

Pour l'utilisation de la StationBlanche voici la documentation : [usbguardian-user-manual.pdf](https://usbguardian.files.wordpress.com/2018/02/usbguardian-user-manual.pdf)

# Prérequis :mag_right:
- Raspberry Pi 4 (2GB ou plus)
- Carte SD (16GB ou plus)
- img Raspbian Buster Desktop (déjà flashé sur la carte)
- Clavier / Souris
- Connexion internet

# Installation - Raspberry :strawberry:

Pour le moment, aucun script d'installation n'est disponible, ce sera surement ma prochaine mission !  
Dans la partie installation, je vais aborder la configuration de la Raspberry et ensuite l'installation et la configuration de USBGUardian.

*La partie Flash de la carte SD ne sera pas expliqué ici*

## ----- Mise à jour
```bash
pi> sudo apt update
pi> sudo apt upgrade
pi> sudo raspi-config
```
Dans **raspi-config** selectionnez :
- Advanced Options --> A1 Expand Filesystem
Cette option permet de vérifier si Raspbian utilise bien 100% de l'espace disponible.

## ----- Root passwd
```bash
pi $> sudo -i
root> passwd
```
## ----- Configuration du SWAP
Nous allons ajouter 2GB en SWAP.
```bash
root>apt install vim
root> dphys-swapfile swapoff
root> vim /etc/dphys-swapfile
	Ø Edit : CONF_SWAPSIZE=2000
root> dphys-swapfile setup
root> dphys-swapfile swapon
```
## ----- Création d'un nouvel utilisateur
L'utilisateur **securite** va remplacer le compte pi.
```bash
root > useradd -m securite
root > passwd securite 
root > vim /etc/sudoers
	Ø Edit : securite ALL=(ALL:ALL) ALL
root > su securite
securite $> sudo usermod -a -G adm,dialout,cdrom,sudo,audio,video,plugdev,games,users,input,netdev,gpio,i2c,spi securite
securite $> groups securite
```
## ----- Securisation du compte pi
Dans cette partie on va supprimer le compte pi. Si la suppression ne fonctionne pas (Utilisation d'un processus par pi),
repoussez la suppression au prochain reboot de la machine.
```bash
securite $> sudo pkill -u pi
securite $> sudo deluser -remove-home pi
securite $> sudo vim /etc/sudoers.d/010_pi-nopasswd
	Ø Edit : pi --> securite
```
## ----- Configuration du SSH
Permet une connexion SSH sécurisé en utilisant des clés publique / privées.
Si vous n'avez pas de clés à disposition pour une connexion SSH, changez l'option PasswordAuthentication no en yes
```bash
securite $> mkdir ~/.ssh
securite $> ssh-keygen -t ed25519
securite $> ssh-keygen -t rsa
securite $> vim ~/.ssh/autorized_keys 
	Ø Edit : Ajouter ses clés PUBLIC ssh dans le fichier
securite $> sudo vim /etc/ssh/sshd_config
	Ø Edit:
		○ Port 2222 # Change le port par défaut en 2222
		○ PasswordAuthentication no # Désactive la connexion par mot de passe, uniquement par clés
		○ PermitRootLogin no # Désactive la connexion du compte root en ssh
		○ Banner /etc/issue.net # Ajoute une belle bannière (voir exemple en haut à droite de la procédure)
securite $> sudo service ssh restart
```

## ----- Hostname
Modification du nom de la machine, ici le nom sera station01. Si station01 est déjà utilisé, incrémentez en conséquence.
```bash
securite $> sudo vim /etc/hostname
	Ø Edit : station01
securite $> sudo vim /etc/hosts
	Ø Edit : changer raspberry en station01
```
## ----- (Optionnel : ZSH)
Permet d'installer un terminal zsh avec un plugin pour une meilleure expérience CLI.
```bash
securite $> sudo apt install zsh
securite $> sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
```

## ----- Reboot
```bash
securite $> sudo reboot
```

# Installation & Configuration - USBGuardian :shield:

## ----- Installation & Configuration ClamAV
```bash
securite $> sudo apt install clamav clamav-daemon
securite $> sudo systemctl enable clamav-daemon
securite $> ls -l /var/log/clamav
```
Après l'installation de clamav, il doit y avoir un fichier `freshclam.log` dans `/var/log/clamav` .
Si le fichier n'existe pas, créez le avec les commandes suivantes :
```bash
securite $> sudo touch /var/log/clamav/freshclam.log
securite $> chmod 600 /var/log/clamav/freshclam.log
securite $> chown clamav /var/log/clamav/freshclam.log
```
Lancez une première update de la base virale.
```bash
securite $> sudo freshclam
```

Si vous rencontrez l'erreur suivante : `ERROR : Problem with internal logger …`
Exécutez les commandes dans cette ordre :
```bash
securite $> sudo /etc/init.d/clamav-freshclam stop
securite $> sudo freshclam
securite $> sudo /etc/init.d/clamav-freshclam start
```

Modification de la conf clamav-daemon
```bash
securite $> sudo vim /etc/systemctl/system/clamav-daemon.service.d/extend.conf
	Ø Edit : ExecStartPre=/bin/mkdir -p /run/clamav
securite $> sudo systemctl daemon-reload
securite $> sudo service clamav-daemin start
```

Mise à jour automatique de la base virale.
```bash
securite $> sudo vim /etc/cron.daily/freshclam
	Ø Edit :
		#!/bin/sh
		/etc/init.d/clamav-freshclam stop
		/usr/bin/freshclam -v >> /var/log/clamav/freshclam.log
		/etc/init.d/clamav-freshclam start
```

## ----- Install USBGuardian 
```bash
securite $> cd 
securite $> git clone https://github.com/AlrikRr.USGBuardian.git
securite $> cd USBGuardian
securite $> sudo cp -r USBGuardian-core /opt/USBGuardian
securite $> sudo chmod +x -R /opt/USBGuardian/scripts
```

## ----- QT5
Qt5 va vous être utile pour compiler l'interface graphique. SI vous voulez modifier l'interface graphique, je vous recommande d'installer le paquet `qtcreator`.
```bash
securite $> sudo apt install qt5-default
securite $> cd USBGuardian-GUI
```
Ensuite, il faut compiler l'application pour avoir un binaire exécutable.
```bash
securite $> cd USBGuardian-GUI
securite $> qmake USBGUardian.pro
securite $> make
```

Exécutez ensuite le binaire USBGuardian pour exécuter l'interface graphique.
```bash
securite $> cd USBGuardian-GUI
securite $> ./USBGuardian
```

**En cas de modification de l'interface graphique, vous devez re-compiler l'application.**

## ----- Détection USB
Ajout d'un règle UDEV qui va détecter si une clé USB est branchée.
A la détection d'un clé USB "block" la règle udev insertUSB.rules va exécuter le service insertUSB.service.
```bash
securite $> sudo cp ~/USBGuardian/udev/insertUSB.rules /etc/udev/rules.d/insertUSB.rules
```
On reload les règles udev avec la commande :
```bash
securite $> sudo udevadm control --reload
```

## ----- insertUSB.service
Création du service qui va exécuter notre analyse.

```bash
securite $> sudo cp ~/USBGuardian/service/insertUSB.service /etc/systemd/system/insertUSB.service
securite $> sudo systemctl enable insertUSB.service
```
## ----- Montage automatique

Allez dans l'explorateur de fichier Raspbian.
	- Edition --> Préférences --> Gestion des supports amovibles --> Décochez "Afficher les options disponibles …"

## ----- :boom:  Modification temporaire :boom: 

Problèmes de droits pour /media/securite et /opt/USBGuardian/logs
Pour régler le problème temporairement j'ai ajouté les droits 777 sur les deux dossier **(ATTENTION CE N'EST PAS RECOMMANDEZ)**
```bash
securite $> sudo chmod 777 -R /opt/USBGuardian/logs
securite $> sudo chmod 777 -R /media/securite
```

# To-do :mechanical_arm:

- [ ] Debugger problème de droit pour `/logs/` et `/media/securite`
- [ ] Faie un script d'installation.
- [ ] Fournir une image fontionnelle.
- [ ] Debugger la fonction "Formater une clé USB"
- [ ] Problème de doublons sur l'affichage des virus trouvés
