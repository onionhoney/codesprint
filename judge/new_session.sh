#!/bin/bash

if [[ "$2" == "" ]] || [[ "$2" =~ ^.*\ .*$ ]] ; then
    echo "Usage: new_session.sh full_name dir_name(no whitespace)"
    exit 1
fi

wwwown () {
    sudo chown -R www-data:www-data $1
    sudo chmod -R 755 $1
}

echo "$1;$2" >> sessions.txt
sudo cp -a sessions/template sessions/$2
mkdir "../problems/$2"
wwwown "../problems/$2"
cd sessions/$2
sudo ./session_setup.sh
