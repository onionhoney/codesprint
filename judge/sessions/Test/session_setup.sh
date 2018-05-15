#!/bin/bash

# set up permissions for files and directories
chmod 755 data/
chmod 744 ./grade_standalone.pl
chmod 744 submissions.txt
chmod 744 judgements.txt
chmod 744 solved.txt
chmod 744 config.txt
chmod 744 crequests.txt
chmod 774 teams.txt

sudo chown www-data:www-data judgements.txt
sudo chown www-data:www-data submissions.txt
sudo chown www-data:www-data solved.txt
sudo chown www-data:www-data config.txt
sudo chown www-data:www-data crequests.txt
sudo chown www-data:www-data teams.txt
sudo chown www-data:www-data grade_standalone.pl
sudo chown -R www-data:www-data data

# compile the autojudge
g++ -std=c++11 -Wall -O2 -o judge judge.cc

