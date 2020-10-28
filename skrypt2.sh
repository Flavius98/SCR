!bin/bash

sudp pat update && sudo apt get upgrade -y && sudo apt install -y mutt

path=$(pwd)/lab_files

for mail in $(cat $path/adresy.txt)

do
    cat $path/tresc.txt 
done