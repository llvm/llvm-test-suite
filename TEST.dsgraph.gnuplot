## set size  square 0.5,0.5
## set key left top
set nokey
set pointsize 3

set terminal postscript


##------- log(Time) vs. log(MemOps) --------
set output "runtimes.timeVmem.ps"
set logscale xy
#set xrange [5:50000]
#set yrange [0.0005:5]
set xlabel "Total Memory Operations" "TimesRoman,24"
set ylabel "Execution time (sec)" "TimesRoman,24"
plot 'timeVmem.txt' title "Time vs. Memory Ops"
#replot 0.000002 * x * log10(x)

##------- log(Time) vs. log(LOC) --------
set output "runtimes.timeloc.ps"
set logscale xy
#set xrange [10:100000]
#set yrange [0.0005:5]
set xlabel "Lines of Code" "TimesRoman,24"
set ylabel "Execution time (sec)" "TimesRoman,24"
plot 'timeVloc.txt' title "Time vs. LOC"
replot 0.000002 * x * log10(x)

set terminal png

##------- log(Time) vs. log(MemOps) --------
set output "runtimes.timeVmem.png"
set logscale xy
#set xrange [5:50000]
#set yrange [0.0005:5]
set xlabel "Total Memory Operations" "TimesRoman,24"
set ylabel "Execution time (sec)" "TimesRoman,24"
plot 'timeVmem.txt' title "Time vs. Memory Ops"
#replot 0.000002 * x * log10(x)

##------- log(Time) vs. log(LOC) --------
set output "runtimes.timeloc.png"
set logscale xy
#set xrange [10:100000]
#set yrange [0.0005:5]
set xlabel "Lines of Code" "TimesRoman,24"
set ylabel "Execution time (sec)" "TimesRoman,24"
plot 'timeVloc.txt' title "Time vs. LOC"
replot 0.000002 * x * log10(x)




##------- log(Time/LOC) vs. log(LOC) --------
set nologscale y
set logscale x
set xrange [100:100000]
set yrange [2:20]
set xlabel "Lines of Code" "TimesRoman,24"
set ylabel "Time/Line (microsec/line)" "TimesRoman,24"
#set output "runtimes.timelocratio.ps"
#plot '< ./runtimes.awk -v PlotTimeLOCRatio=1 data.txt' title "Time vs. LOC"

##------- log(Memory) vs. log(LOC) --------
set logscale xy
set yrange [10:10000]
set xlabel "Lines of Code" "TimesRoman,24"
set ylabel "Total Memory (KB)" "TimesRoman,24"
#set output "runtimes.memloc.ps"
#plot '< ./runtimes.awk -v PlotMemLOC=1 data.txt' title "Time vs. LOC"
