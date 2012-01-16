#!/bin/bash

for i in `seq 0 32 992`
do
    rm mandel_parallel.ppm
    cp ~/$i ./
    cat $i >> mandel_parallel.ppm
done

