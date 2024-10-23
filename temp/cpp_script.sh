#!/bin/bash
nn=$1
un=$(echo -n $1 | tr '[a-z]' '[A-Z]')
sed -e "s/Interface/$nn/g" -e "s/INTERFACE/$un/g" '/Users/ehammoud/Desktop/Templates/Interface.cpp' > "$nn.cpp"
sed -e "s/Interface/$nn/g" -e "s/INTERFACE/$un/g" '/Users/ehammoud/Desktop/Templates/Interface.hpp' > "$nn.hpp"
