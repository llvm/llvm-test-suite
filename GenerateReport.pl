#!/usr/dcs/software/supported/bin/perl -w
#
# Program:  GenerateReport.pl
#
# Synopsis: Summarize a big log file into a table of values, commonly used for
#           testing.  This can generate either a plaintext table, HTML table,
#           or Latex table, depending on whether the -html or -latex options are
#           specified.
#
#           This script reads a report description file to specify the fields
#           and descriptions for the columns of interest.  In reads the raw log
#           input from stdin and writes the table to stdout.
#
# Syntax:   GenerateReport.pl [-html] [-latex] [-graphs] <ReportDesc>
#                    < Input > Output
#

# Default values for arguments
my $HTML = 0;
my $LATEX = 0;
my $GRAPHS = 0;

# Parse arguments...
while ($_ = $ARGV[0], /^[-+]/) {
  shift;
  last if /^--$/;  # Stop processing arguments on --

  # List command line options here...
  if (/^-html$/)   { $HTML = 1; next; }
  if (/^-latex$/)  { $LATEX = 1; next; }
  if (/^-graphs$/) { $GRAPHS = 1; next; }

  print "Unknown option: $_ : ignoring!\n";
}

#
# Parameters which may be overriden by the report description file.
#

# The column to sort by, to be overridden as necessary by the report description
my $SortCol = 0;
my $SortReverse = 0;
my $SortNumeric = 0;   # Sort numerically or textually?

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

my @LatexColumns;  # Filled in by report if it supports Latex mode
my %LatexColumnFormat;  # Filled in by report if supports latex mode
my @Graphs;        # Filled in by the report if supports graph mode

# Fill in all of the fields from the report description
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
      if (ref ($Row->[1])) {        # Code to be executed?
        push @RowValues, &{$Row->[1]}(\@RowValues, $Col);
      } else {                      # Field to be read...
        $Record =~ m/$Row->[1]/;
        if (!defined($1)) {
          push @RowValues, "*";
        } else {
          # If there is a formatting function, run it now...
          my $Val = $1;
          if (scalar(@$Row) > 2) {
            $Val = &{$Row->[2]}($Val);
          }

          push @RowValues, $Val;
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
if ($SortNumeric) {
  @Values = sort { $a->[$SortCol] <=> $b->[$SortCol] } @Values;
} else {
  @Values = sort { $a->[$SortCol] cmp $b->[$SortCol] } @Values;
}
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
    $_ = "<center><b><a href=\"#$_\">$_</a></b></center>"
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
} elsif ($GRAPHS) {      # Graph output...
  print "Generating gnuplot data files:\n";
  my $GraphNo = 0;
  foreach $Graph (@Graphs) {
    my @Graph = @$Graph;
    my $Type = shift @Graph;
    die "Only scatter graphs supported right now, not '$Type'!"
      if ($Type ne "scatter");

    my $Filename = shift @Graph;

    print "Writing '$Filename'...\n";
    open (FILE, ">$Filename") or die ("Could not open file '$Filename'!");

    my ($XCol, $YCol) = @Graph;
    foreach $Row (@Values) {
      print FILE $$Row[$XCol] . "\t" . $$Row[$YCol] . "\n";
    }
    close FILE;
    ++$GraphNo;
  }

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

  if ($LATEX) {
    #
    # Print out the latexified table...
    #
    shift @Values;  # Don't print the header...

    # Make sure the benchmark name field is wide enough for any aliases.
    foreach $Name (@LatexRowMapOrder) {
      $FieldWidths[0] = length $Name if (length($Name) > $FieldWidths[0]);
    }

    # Print out benchmarks listed in the LatexRowMapOrder
    for ($i = 0; $i < @LatexRowMapOrder; $i += 2) {
      my $Name = $LatexRowMapOrder[$i];
      if ($Name eq '-') {
        print "\\hline\n";
      } else {
        # Output benchmark name...
        printf "%-$FieldWidths[0]s", $LatexRowMapOrder[$i+1];

        # Find the row that this benchmark name corresponds to...
        foreach $Row (@Values) {
          if ($Row->[0] eq $Name) {
            for $ColNum (@LatexColumns) {
              # Print a seperator...
              my $Val = $Row->[$ColNum];
              if (exists $LatexColumnFormat{$ColNum}) {
                # If a column format routine has been specified, run it now...
                $Val = &{$LatexColumnFormat{$ColNum}}($Val);
              }

              # Escape illegal latex characters
              $Val =~ s/([%#])/\\$1/g;

              printf " & %-$FieldWidths[$ColNum]s", $Val;
            }
            goto Done;
          }
        }
        print "UNKNOWN Benchmark name: " . $Name;
      Done:
        print "\\\\\n";
      }
    }
  } else {
    #
    # Print out the table in plaintext format now...
    #
    foreach $Value (@Values) {
      for ($i = 0; $i < @$Value-1; $i++) {
        printf "%-$FieldWidths[$i]s ", $$Value[$i];
      }
      
      # Print the assertion message if existant...
      print "$$Value[@$Value-1]\n";
    }
  }
}
