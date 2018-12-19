#!/bin/bash

for file in [0-9]*.java;
do
	echo $file
	reFile=`printf %03d.%s ${file%.*} ${file##*.}`;
	echo $reFile;
	mv $file $reFile;
done