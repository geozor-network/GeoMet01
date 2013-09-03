set terminal png
set xlabel "time[s]"
set ylabel "Magnetic field [-]"
#set yrange [-1:1]
set autoscale y


#plot data transformed to G units. (3,3V/1024 * 0.8V/G)
k=3.3/1024.0*0.8 # sensitivity constant
zero_gravity=512.0

set output "mereni.png" 
plot "tabor.txt" using ($1) title "X", "" using ($2) title "Y", "" using ($3) title "Z"
pause 1
reread
