reset
set title 'hash function by division (M=256)'
set xlabel 'bucket address'
set ylabel 'slots number'
set term png enhanced font 'Verdana,10'
set output 'hash_slots.png'

plot 'hash_slots.txt'
