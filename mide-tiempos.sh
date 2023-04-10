#!/bin/bash 
#echo "" >> $1.dat
i=10000
while [ "$i" -le 200000 ]
do
    #./especifico VacasGeneradas/Vacasgeolocalizadas$i.txt >> Datos/especifico.dat
    #./dyv 4 VacasGeneradas/Vacasgeolocalizadas$i.txt >> Datos/dyv.dat
    #./generador $i
      i=$(( $i + 10000 ))
done
      
