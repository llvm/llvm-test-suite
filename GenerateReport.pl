#!/usr/dcs/software/supported/bin/perl -w

# Default values for arguments
$SHOW_TIMES = 1;

# Parse arguments...
while ($_ = $ARGV[0], /^[-+]/) {
  shift;
  last if /^--$/;  # Stop processing arguments on --

  # List command line options here...
  if (/^-no-times$/) { $SHOW_TIMES = 0; next; }

  print "Unknown option: $_ : ignoring!\n";
}

my $InputFN = $ARGV[0];
#print "Reading input from $InputFN\n";

open(INPUT, $InputFN) or die "Couldn't open '$InputFN'!";

# Read all input...
my @Lines = <INPUT>;

# Turn it into one big string...
my $FILE = join "\n", @Lines;

# Now split it up into records.  Each benchmarks starts with a line with a >>>
# prefix

my @Records = split />>> ========= /, $FILE;

# Delete the first "entry" which is really stuff printed prior to starting the
# first test.
shift @Records;

# The column to sort by, to be overridden as neccesary by the report description
my $SortCol = 2;
my $SortReverse = 1;

sub SumCols {
  my ($Cols, $Col, $NumRows) = @_;
  $Val = 0;
  while ($NumRows) {
    $Col--; $NumRows--;
    $Val += $Cols->[$Col] if ($Cols->[$Col] ne "*");
  }
  return $Val;
}

sub Ratio {
  my ($Cols, $Col) = @_;
  if ($Cols->[$Col-2] ne "*" and
      $Cols->[$Col-2] != "0") {
    return $Cols->[$Col-1]/$Cols->[$Col-2];
  } else {
    return "n/a";
  }
}

my @Fields = (
# Name
            ["Name:" , '\'([^\']+)\' Program'],
            [],
# Times
            ["Anlyz:", '([0-9.]+) \([^)]+\)[ 0-9]+TOTAL'],
            ["LocTm:", '([0-9.]+) \([^)]+\)[ 0-9]+Local'],
            ["BUTim:", '([0-9.]+) \([^)]+\)[ 0-9]+Bottom'],
            ["TDTim:", '([0-9.]+) \([^)]+\)[ 0-9]+Top'],
            ["SumTm:", sub { return SumCols(@_, 3); }],
            [],
# Sizes
            ["LocSize:", '([0-9]+)  Local'],
            ["BUSize:" , '([0-9]+)  Bottom-up'],
            ["TDSize:" , '([0-9]+)  Top-down'],
            ["BU+TDSz:", sub { return SumCols(@_, 3); }],
            [],
# Misc stuff
            ["NumFold" , '([0-9]+).*Number of folded nodes '],
            ["NumNodes", 'Graphs contain \\[([0-9+]+)\\] nodes total'],
            ["MaxSz"   , '([0-9]+).*Maximum graph size'],
            ["GlobGr"  , '\\.GlobalsGraph\\.dot\'... \\[([0-9+]+)\\]'],
            ["MaxSCC"  , '([0-9]+).*Maximum SCC Size in Call Graph'],
            [],
            ["Loads"   , '([0-9]+).*Number of Load insts'],
            ["Store"   , '([0-9]+).*Number of Store insts'],
            ["Calls"   , '([0-9]+).*Number of Call insts'],
            ["Allca"   , '([0-9]+).*Number of Alloca insts'],
            ["Mallc"   , '([0-9]+).*Number of Malloc insts'],
            [" Sum "   , sub { return SumCols(@_, 5); }],
            #[" Sum "   , sub { return $_[0]->[$_[1]-1]; }],
            [],
            ["num/ind" , '([0-9]+).*number of indirect call sites'],
            ["indcallee",'([0-9]+).*number of callee functions at'],
            ["ratio"   , \&Ratio],  # B / A if A != 0 else "n/a"
            []
           );

my @Values;

#
# Read data into the table of values...
#
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
