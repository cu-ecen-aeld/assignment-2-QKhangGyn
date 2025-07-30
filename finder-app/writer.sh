#!/bin/bash
NUMARGS=2
num_args=$#
writefile=$1
writestr=$2
#Check number of args
if [ $num_args -ne $NUMARGS ]
then
        echo "ERROR: Invalid number of arguments:
        The number of arguments should be 2.
        The order of the arguments should be:
        1) The absolute directory to the file you want to write
        2) The content you want to write to the file"
        exit 1
else #create a file from the writefile
        touch "$writefile"
        exit_status=$?
        #Check whether "touch" is successfully
        if [ $exit_status -ne '0' ]
        then
                echo "ERROR: cannot create the file you want"
                exit 1
        else
                echo "$writestr" > "$writefile"
                exit 0
        fi
fi