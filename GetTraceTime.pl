#!/usr/bin/perl
$prog = $ARGV[0];
$llc = $ARGV[1];
$trace = $ARGV[2];
open(LLC,"< $llc");
open(TRACE, "< $trace");

$time_t;
$sys1;
$cycles;
$instrCnt;
foreach $line (<LLC>){
  if($line =~ /(user[\s]+)([0-9\.]+)/){
    #  if($line =~ /([0-9\.]*)([\s]*[0-9]*[\s]*exit[\s]*)([0-9]*)([\s]+)([0-9]*)/){
    #$time_t = $1;
    $time_t  = $2;
    $cycles = $3;
    $instrCnt = $5;
    #print "Time: $time_t \tCycles: $cycles \tInstrCnt: $instrCnt\n";
    end;
  }
  if($line =~ /(user[\s]+)([0-9]*)(:)([0-9\.]+)/){
    $time_t = $2*60+$4;
  }
  if($line =~ /(sys[\s]+)([0-9\.]+)/){
    $sys1=$2;
  }
  if($line =~ /(sys[\s]+)([0-9]*)(:)([0-9\.]+)/){
    $sys1 = $2*60+$4;
  }
  

}

$time_t2;
$sys2;
$cycles2;
$instrCnt2;
foreach $line (<TRACE>){
 
  if($line =~ /(user[\s]+)([0-9\.]+)/){
    #if($line =~ /([0-9\.]*)([\s]*[0-9]*[\s]*exit[\s]*)([0-9]*)([\s]+)([0-9]*)/){
    #$time_t2 = $1;
    $time_t2 = $2; 
    $cycles2 = $3;
    $instrCnt2 = $5;
    #print "Time: $time_t \tCycles: $cycles \tInstrCnt: $instrCnt\n";
    end;
  }
  if($line =~ /(user[\s]+)([0-9]*)(:)([0-9\.]+)/){
    $time_t2 = $2*60+$4;
  }
  
  if($line =~ /(sys[\s]+)([0-9\.]+)/){
    $sys2=$2;
  }
  if($line =~ /(sys[\s]+)([0-9]*)(:)([0-9\.]+)/){
    $sys2 = $2*60+$4;
  }
}

$time_t = $sys1+$time_t;
$time_t2 = $sys2 + $time_t2;

open(OUTPUT, ">> /home/vadve/ashukla/runs");
$dt = `date`;
print OUTPUT $dt."\n";
print $prog.":\n---------------------\n";
printf ("%0.2f\t",(($time_t2/$time_t)*100));
#printf ("instrCnt: %0.2f\t",(($instrCnt2/$instrCnt)*100));
printf ("time: %0.2f\n---------------------\n",$time_t2);


print OUTPUT $prog.":\n---------------------\n";
printf OUTPUT "%0.2f\t", (($time_t2/$time_t)*100);
#printf OUTPUT "instrCnt: %0.2f\t",(($instrCnt2/$instrCnt)*100);
printf OUTPUT "time: %0.2f\n---------------------\n",$time_t2;
close(LLC);
close(TRACE);
close(OUTPUT);



