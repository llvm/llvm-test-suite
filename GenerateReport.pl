#!/usr/dcs/software/supported/bin/perl -w

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
  push @RowValues, $Assert;
  push @Values, [@RowValues];
}

#
# Sort table now...
#
@Values = sort { $a->[$SortCol] cmp $b->[$SortCol] } @Values;
@Values = reverse @Values if ($SortReverse);

#
# Add the header for the report to the table after sorting...
#
my @Header;
for $Row (@Fields) {
  if (scalar(@$Row)) {   # Non-empty row?
    push @Header, $Row->[0];
  } else {               # Empty row, just add seperator
    push @Header, "|";
  }
}
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
