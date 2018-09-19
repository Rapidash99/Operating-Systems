#!/bin/bash 
                                                                      
if test ! -f file; then                                                   
    echo 0 > file
fi

for i in `seq 1 199`;
do
    last=`tail -1 file`
    last=$((last+1))

    echo $last >> file
done