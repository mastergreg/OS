#!/bin/bash
machines=(evia kefalonia kerkyra kythnos lemnos lesvos leykada naxos patmos paxoi poros serifos skopelos skyros zakynthos)
for i in "${machines[@]}"
do
    ping -c 1 -W 2 $i.cslab.ece.ntua.gr &> /dev/null
    echo "ping -c 1 -W 2 $i.cslab.ece.ntua.gr [$?]"
done

