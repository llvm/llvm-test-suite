#!/usr/dcs/software/supported/bin/perl -w

# htmlcoldiff - Diff two files (specified on the command line) laid out in
# columns.  Output a copy of the second file with differences from the first
# hi-lighted in bold (with HTML tags).  This assumes that the first column of
# the file is an identifier that keys two rows of the files together.
#

$Input1 = $ARGV[0];
$Input2 = $ARGV[1];

open(INPUT1, $Input1) or die "Couldn't open '$Input1'!";
open(INPUT2, $Input2) or die "Couldn't open '$Input2'!";

# Read all of the lines of both files into arrays:
my @File1 = <INPUT1>;
my @File2 = <INPUT2>;

# Convert the first file from an array of lines to a hash from the key to the
# whole line.

foreach $Line (@File1) {
  my $Key = (split /\s+/, $Line, 2)[0];
  $File1Map{$Key} = $Line;
  #print "Map '$Key' => '$Line'\n";
}

# Loop over the second file, outputting it, surrounding field with <B> tags if
# they differ from the first file.

foreach $Line (@File2) {
  my @Fields = split /(\s+)/, $Line;  # Keep the seperators as well...
  my $Key = $Fields[0];
  my $CompareLine = $File1Map{$Key};
  my @FieldsCompare = split /\s+/, $CompareLine;  # Do not keep seperators

  # Loop over all of the Fields, outputting them with an optional tag...
  my $FieldNo = 0;
  foreach $Field (@Fields) {
    if ($Field =~ /\s+/) {    # If it's a seperator, just output it
      print $Field;
    } else {                  # If it's not a seperator, diff it...
      my $Hilight = 0;

      if (@FieldsCompare > $FieldNo) {
        my $FieldComp = $FieldsCompare[$FieldNo];
        if ($Field =~ /[0-9]+\.[0-9]+/ && $FieldComp =~ /[0-9]+\.[0-9]+/ &&
            $Field != 0) {              # Handle floating point numbers special
          # They are only highlighted if they change by 20% or more...
          my $Change = $FieldComp/$Field;
          $Hilight = 1 if ($Change > 1.3333 || $Change < 0.666);
          
        } elsif ($Field ne $FieldComp) {
          $Hilight = 1;
        }
      }

      print "<b>" if $Hilight;
      print $Field;
      print "</b>" if $Hilight;
      $FieldNo++;
    }
  }
}
