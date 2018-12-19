#!/bin/bash


for file in *.*.*;
do
#	echo $file
#	echo `printf %03d.%s ${file%%.*} ${file##*.}`
	mv $file `printf %03d.%s ${file%%.*} ${file##*.}`;
done