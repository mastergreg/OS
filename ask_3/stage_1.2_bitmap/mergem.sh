#!/bin/bash

rm mandel_parallel.ppm
for i in `seq 0 32 992`
do
    cat ~/$i >> mandel_parallel.ppm
    #rm ~/$i
done
convert mandel_parallel.ppm mandel_parallel.png

