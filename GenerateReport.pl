#!/usr/dcs/software/supported/bin/perl -w
#
# Program:  GenerateReport.pl
#
# Synopsis: Summarize a big log file into a table of values, commonly used for
#           testing.  This can generate either a plaintext table or HTML table
#           depending on whether the -html option is specified.
#
#           This script reads a report description file to specify the fields
#           and descriptions for the columns of interest.  In reads the raw log
#           input from stdin and writes the table to stdout.
#
# Syntax:   GenerateReport.pl [-html] <ReportDesc> < Input > Output
#

# Default values for arguments
$HTML = 0;

# Parse arguments...
while ($_ = $ARGV[0], /^[-+]/) {
  shift;
  last if /^--$/;  # Stop processing arguments on --

  # List command line options here...
  if (/^-html$/) { $HTML = 1; next; }

  print "Unknown option: $_ : ignoring!\n";
}

#
# Parameters which may be overriden by the report description file.
#

# The column to sort by, to be overridden as neccesary by the report description
my $SortCol = 0;
my $SortReverse = 0;

# Helper functions which may be called by the report description files...
sub SumCols {
  my ($Cols, $Col, $NumRows) = @_;
  $Val = 0;
  while ($NumRows) {
    $Col--; $NumRows--;
    $Val += $Cols->[$Col] if ($Cols->[$Col] ne "*");
  }
  return $Val;
}

# Check command line arguments...
die "Must specify a report description option" if (scalar(@ARGV) < 1);

# Read file input in one big gulp...
undef $/;

# Read raw data file and split it up into records.  Each benchmarks starts with
# a line with a >>> prefix
#
my @Records = split />>> ========= /, <STDIN>;

# Delete the first "entry" which is really stuff printed prior to starting the
# first test.
shift @Records;

# Read and eval the report description file now.  This defines the Fields array
# and may potentially modify some of our global settings like the sort key.
#
my $ReportFN = $ARGV[0];
#print "Reading report description from $ReportFN\n";
open(REPORTDESC, $ReportFN) or
  die "Couldn't open report description '$ReportFN'!";

my @Fields = eval <REPORTDESC>;


#
# Read data into the table of values...
#
my @Values;
foreach $Record (@Records) {
  my @RowValues;
  my $Col = 0;
  for $Row (@Fields) {
    if (scalar(@$Row)) {            # An actual value to read?
      if (ref ($Row->[1])) {          # Code to be executed?
        push @RowValues, &{$Row->[1]}(\@RowValues, $Col);
      } else {                      # Field to be read...
        $Record =~ m/$Row->[1]/;
        if (!defined($1)) {
          push @RowValues, "*";
        } else {
          push @RowValues, $1;
        }
      }
    } else {                        # Just add a seperator...
      push @RowValues, "|";
    }
    $Col++;
  }

  my $Assert = "";
  if ($Record =~ m/Assertion/) {
    # If an assertion failure occured, print it out.
    $Assert = sprintf "\n\t\t\t%s", (grep /Assertion/, (split "\n", $Record));
  }
  push @RowValues, $Assert if (!$HTML);
  push @Values, [@RowValues];
}

#
# Sort table now...
#
@Values = sort { $a->[$SortCol] cmp $b->[$SortCol] } @Values;
@Values = reverse @Values if ($SortReverse);

#
# Condense the header into an easier to access array...
#
my @Header;
for $Row (@Fields) {
  if (scalar(@$Row)) {   # Non-empty row?
    push @Header, $Row->[0];
  } else {               # Empty row, just add seperator
    push @Header, "|";
  }
}

if ($HTML) {
  sub printCell {
    my $Str = shift;
    if ($Str eq '|') {
      print "<td bgcolor='black' width='1'></td>";
    } else {
      print "<td><table border='0' cellspacing='0' cellpadding='3'><tr><td>$Str</td></tr></table></td>\n";
    }; "";
  }
  sub printLine {
    print "<td bgcolor='" . ($_[0] ? "#DDDDDD" : "#AAAAAA") . "' width=1>\n";
  }

  print "<table border='0' cellspacing='0' cellpadding='0'>\n";
  print "<tr bgcolor=#FFCC99>\n";
  map {
    print "<td bgcolor='#DDAA77' width='1'></td>";
    $_ = "<b><a href=\"#$_\">$_</a></b>"
      if $_ ne "|"; printCell $_
  } @Header;
  print "<td bgcolor='#DDAA77' width='1'></td>";
  print "\n</tr><tr bgcolor='black'>";
  print "<td height=1></td>" x (2*@Header+1);
  print "</tr>\n";
  my $RowCount = 0;
  foreach $Row (@Values) {
    my $IsWhite;
    $IsWhite = ++$RowCount <= 2;
    print "<tr bgcolor='" . ($IsWhite ? "white" : "#CCCCCC") . "'>\n";
    $RowCount = 0 if ($RowCount > 3);
    map { printLine($IsWhite); printCell $_ } @$Row;
    printLine($IsWhite);
    print "\n</tr>\n";
  }
  print "\n</table>\n";
} else {
  # Add the header for the report to the table after sorting...
  unshift @Values, [@Header];

  #
  # Figure out how wide each field should be...
  #
  my @FieldWidths = (0) x scalar(@Fields);
  foreach $Value (@Values) {
    for ($i = 0; $i < @$Value-1; $i++) {
      if (length($$Value[$i]) > $FieldWidths[$i]) {
        $FieldWidths[$i] = length($$Value[$i])
      }
    }
  }

  #
  # Print out the table now...
  #
  foreach $Value (@Values) {
    for ($i = 0; $i < @$Value-1; $i++) {
      printf "%-$FieldWidths[$i]s ", $$Value[$i];
    }

    # Print the assertion message if existant...
    print "$$Value[@$Value-1]\n";
  }
}
