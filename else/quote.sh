#!/bin/bash
file="INSERT FILE PATH"
quote="$(shuf -n 1 $file --random-source=/dev/urandom)"
printf "\n$quote\n\n" | fmt -w 60
