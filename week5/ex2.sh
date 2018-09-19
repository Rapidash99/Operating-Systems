#!/bin/bash 
                                                                      
if test ! -f file; then                                                   
    echo 0 > file
fi

if in file file.lock; then
    for i in `seq 1 199`;
    do
	last=`tail -1 file`
	last=$((last+1))

	echo $last >> file
    done
fi
rm file.lock