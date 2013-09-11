set terminal png
set xlabel "time[s]"
set ylabel "Magnetic field [-]"
#set yrange [-1:1]
set autoscale y

set output "thorsmork.png" 
plot "GeoMet01_2013-09-06.log" using ($5) title "X", "" using ($6) title "Y", "" using ($7) title "Z"
#pause 1
#reread
