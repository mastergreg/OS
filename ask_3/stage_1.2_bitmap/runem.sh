#!/bin/bash

machines=(anafi
evia
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
for i in `seq 0 32 992`
do
    let j=i+32
    m=${machines[$(($i % $nr))]}
    ssh $m  /home/oslab/oslabb03/Repos/OS/ask_3/stage_1.2_bitmap/mandel $i $j
done

