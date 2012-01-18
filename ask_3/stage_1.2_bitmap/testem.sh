#!/bin/bash
for i in `seq 0 32 992`
do 
    while( true )
    do 
        if [ -e $i ]; then
            break 
        fi
    done 
done
