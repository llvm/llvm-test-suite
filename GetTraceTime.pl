#!/usr/bin/perl
($llc, $trace, $out) = @ARGV;
$prog = $llc; $prog =~ s/\.out.*$//;

open LLC, $llc;
foreach $line (<LLC>){
  if($line =~ /(user[\s]+)([0-9\.]+)/){
    $time_t  = $2;
  } elsif ($line =~ /(user[\s]+)([0-9]*)(:)([0-9\.]+)/){
    $time_t = $2*60+$4;
  } elsif($line =~ /(sys[\s]+)([0-9\.]+)/){
    $sys1=$2;
  } elsif($line =~ /(sys[\s]+)([0-9]*)(:)([0-9\.]+)/){
    $sys1 = $2*60+$4;
  }
}
close LLC;

open TRACE, $trace;
foreach $line (<TRACE>){
  if($line =~ /(user[\s]+)([0-9\.]+)/){
    $time_t2 = $2; 
  } elsif($line =~ /(user[\s]+)([0-9]*)(:)([0-9\.]+)/){
    $time_t2 = $2*60+$4;
  } elsif($line =~ /(sys[\s]+)([0-9\.]+)/){
    $sys2=$2;
  } elsif($line =~ /(sys[\s]+)([0-9]*)(:)([0-9\.]+)/){
    $sys2 = $2*60+$4;
  }
}
close TRACE;

$time_t = $sys1+$time_t;
$time_t2 = $sys2 + $time_t2;

$pct = "n/a";
$pct = sprintf("%.2f", ($time_t2/$time_t)*100.0) if ($time_t != 0);
$report = "$prog  percentage: $pct; time: $time_t2\n";
if (open(OUTPUT, ">>$out")) {
	print OUTPUT $report;
	close OUTPUT;
}
print $report;
exit 0;
