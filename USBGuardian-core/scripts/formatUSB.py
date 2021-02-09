#!/usr/bin/python3.5
#-*- coding:utf-8 -*-

import subprocess


#var
i = 0
temp_array = [] #used to store usb path /dev/
temp_fs = [] # used to store filesystem of /dev/sd[a-z][0-9]



# Exec : lsblk | grep /media/
cmd = ['lsblk','-f']
ps = subprocess.Popen(cmd, stdout=subprocess.PIPE)
cmd = ['grep', '/media/']
grep = subprocess.Popen(cmd, stdin=ps.stdout, stdout=subprocess.PIPE,
                        encoding='utf-8')
ps.stdout.close()
output, _ = grep.communicate()
output_array = output.split('\n')
# remove last line of array because it's empty
output_array = output_array[:-1]

# output_array looks like :
# sda vfat 1826F87DS87868 3,7G 1% /media/securite/USB
# OR if it's partitioned :
# └─sda1 ntfs 1826F87DS87868 3,7G 1% /media/securite/USB
# └─sda2 ntfs 1826F87D77DD6S 3,7G 1% /media/securite/USB
# We only need index 0 ; 1 ; 5(or -1)


## -- Umount part -- #

# is Partitioned ?
if len(output_array) > 1: #YES
    partitioned = 1
    for i in range(len(output_array)):
        usb_name = output_array[i].split()
        temp_usb = usb_name[0] #get sd[a-z][0-9]
        temp_fs.append(usb_name[1]) #store filesystem for format part
        usb_full_name = "/dev/"+str(temp_usb[2:])# add /dev/ and remove └─
        usb_full_path = usb_name[-1] # get mount point
        temp_array.append(usb_full_name) #store usbname sd[a-z][0-9] for format part
        #print("Partition "+str(i+1)+" : "+usb_full_name+" at "+usb_full_path+"\n")
        
        # Exec : sudo umount /media/securite/[name]
        bashCommand = "sudo umount "+usb_full_path
        subprocess.call(bashCommand.split())

else: #NO
    partitioned = 0

    # get /dev/sd[a-z] 
    usb_name = output_array[0].split()
    tp_usb = usb_name[0]
    
    # Remove the └─ because ntfs is always partitioned with sd[a-z]1
    if tp_usb[0] != "s":
        usb_full_name = "/dev/"+tp_usb[2:]
    else:
        usb_full_name = "/dev/"+usb_name[0]
    
    temp_array.append(usb_full_name) #get /dev/sd[a-z][0-9]
    temp_fs.append(usb_name[1]) # get filesystem
    usb_full_path = usb_name[-1] # get mount point

    # Exec : sudo umount /media/securite/[name]
    bashCommand = "sudo umount "+usb_full_path
    subprocess.call(bashCommand.split())

## -- Format part -- #
i = 0
for i in range(len(temp_array)):
    #print(temp_fs)
    #print(temp_array)
    #print("Formatage de "+temp_array[i]+" en "+temp_fs[i])

    # VFAT
    if temp_fs[i] == "vfat":
        if partitioned == 0:
            #Exec: echo ',,7;' | sudo  sfdisk temp_array[i]
            cmd = ["echo","',,7;'"]
            ps = subprocess.Popen(cmd, stdout=subprocess.PIPE)
            cmd = ['sudo', 'sfdisk', temp_array[i]]
            grep = subprocess.Popen(cmd, stdin=ps.stdout, stdout=subprocess.PIPE,
                        encoding='utf-8')
            ps.stdout.close()
            output, _ = grep.communicate()
        
        #Exec : sudo mkfs.vfat -I temp_array[i]
        mkfsCommand = "sudo mkfs.vfat -I "+temp_array[i]
        subprocess.call(mkfsCommand.split())
    
    # FAT32
    elif temp_fs[i] == "fat":
        if partitioned == 0:
            #Exec: echo ',,7;' | sudo  sfdisk temp_array[i]
            cmd = ["echo","',,7;'"]
            ps = subprocess.Popen(cmd, stdout=subprocess.PIPE)
            cmd = ['sudo', 'sfdisk', temp_array[i]]
            grep = subprocess.Popen(cmd, stdin=ps.stdout, stdout=subprocess.PIPE,
                        encoding='utf-8')
            ps.stdout.close()
            output, _ = grep.communicate()
        
        #Exec : sudo mkfs.fat -F 32 -I temp_array[i]
        mkfsCommand = "sudo mkfs.fat -F 32 -I "+temp_array[i]
        subprocess.call(mkfsCommand.split())

    # NTFS
    elif temp_fs[i] == "ntfs":
        if partitioned == 0:
            #Exec: echo ',,7;' | sudo  sfdisk temp_array[i]
            cmd = ["echo","',,7;'"]
            ps = subprocess.Popen(cmd, stdout=subprocess.PIPE)
            cmd = ['sudo', 'sfdisk', '--force', temp_array[i]]
            grep = subprocess.Popen(cmd, stdin=ps.stdout, stdout=subprocess.PIPE,
                        encoding='utf-8')
            ps.stdout.close()
            output, _ = grep.communicate()
        
        #Exec : sudo mkfs.ntfs temp_array[i]
        mkfsCommand = "sudo mkfs.ntfs -f "+temp_array[i]
        subprocess.call(mkfsCommand.split())

    else:
        print("Error")
        break
