#!/bin/bash

x_number=$(shuf -i 0-200 -n 1)
x_number=$((x_number-100)) 
TEST="$x_number,$x_number"
echo $TEST
