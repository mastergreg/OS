#!/bin/bash

machines=(evia
kefalonia
kerkyra
kythnos
lemnos
lesvos
leykada
naxos
patmos
paxoi
poros
serifos
skopelos
skyros
zakynthos
)
nr=${#machines[@]}
for i in `seq 0 128 4064`
do
    let j=i+128
    let mindex=i%nr
    for k in $(seq $mindex $nr)
    do
        m=${machines[$(($k))]}
        ping -W 1 -q $m -c 1 > /dev/null
        if [ "$?" == "0" ]; then
            break
        fi
    done
    (ssh $m /home/oslab/oslabb03/Repos/OS/ask_3/stage_1.2_bitmap/mandel $i $j && echo $m DONE) &
done

