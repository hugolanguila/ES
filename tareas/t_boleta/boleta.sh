#!/bin/bash

GPIOS=( 14 15 18 23 24 25 8 )
SEG=(	1 1 0 1 1 0 1
		0 0 0 0 0 0 0  
		0 1 1 0 0 0 0  
		1 0 1 1 1 1 1  
		1 1 1 1 0 0 1 
		0 1 1 0 0 0 0 
		0 0 0 0 0 0 0 
		1 1 1 1 0 0 1 
		1 1 1 1 0 0 1 
		1 0 1 1 0 1 1 )

function habilitaGPIOS(){
	for i in ${GPIOS[*]}
	do
		if [ ! -d /sys/class/gpio/gpio$i ]
		then
			echo $i # > /sys/class/gpio/export
		fi	
	done
	sleep 1
}

function desabilitaGPIOS(){
	for i in ${GPIOS[*]}
	do
		if [ -d /sys/class/gpio/gpio$i ]
		then
			echo $i # > /sys/class/gpio/unexport
		fi	
	done
	sleep 1
}

function configuraGPIOS(){
	for i in ${GPIOS[*]}
	do
		echo "out" #>/sys/class/gpio/gpio$i/direction
	done
} 

habilitaGPIOS
configuraGPIOS

while [ 1 ]
do
	for (( i=0; $i<10; i=$i+1)) 
	do	
		let k=0
		for (( j=($i*7); $j<($i*7+7); j=$j+1 ))
		do
			echo ${SEG[$j]} > /sys/class/gpio/gpio${GPIOS[$k]}/value
			let "k=$k+1"
		done
		sleep 2
	done
	break
done

desabilitaGPIOS
