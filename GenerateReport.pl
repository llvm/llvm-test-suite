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

my @Records = split />>> =========  /, $FILE;

# Delete the first "entry" which is really stuff printed prior to starting the
# first test.
shift @Records;


# Output the headers for the report....
printf("%-20s ", "Name:");
if ($SHOW_TIMES) {
  printf("%6s %-6s %-6s %-6s %-8s %-8s     ",
         "Anlyz:", "LocTm:", "BUTim:", "TDTim:", "TimeSum:", "BCTime:");
}

printf("%-8s %-8s %-8s %-8s %-8s   ",
       "LocSize:", "BUSize:", "TDSize:", "BUTDSz:", "BCSize:");
printf("%-8s %-10s %-6s %-6s %-6s " . "| %-5s %-5s %-5s %-5s %-5s %-5s" .
       " | %7s %9s %5s\n",
       "NumFold", "NumNodes", "MaxSz", "GlobGr", "MaxSCC",
       "Loads", "Store", "Calls", "Allca", "Mallc", "Sum",
       "num/ind", "indcallee", "ratio");

foreach $Record (@Records) {
  # Print BM name
  printField('======= ([-a-zA-Z0-9.]+) Program', $Record, -20);

  if ($Record =~ m/Assertion/) {
    # If an assertion failure occured, print it out.
    print (grep /Assertion/, (split "\n", $Record));
  } else {
    if ($SHOW_TIMES) {
      # Print Times
      my $B = printField('([0-9.]+) \([^)]+\)[ 0-9]+Bottom', $Record, -6);
      my $L = printField('([0-9.]+) \([^)]+\)[ 0-9]+Local' , $Record, -6);
      printField('([0-9.]+) \([^)]+\)[ 0-9]+Bottom', $Record, -6);
      my $T = printField('([0-9.]+) \([^)]+\)[ 0-9]+Top'   , $Record, -6);
      printf("%-8s ", $L+$B+$T);
      printField('([0-9.]+) \([^)]+\)[ ]*[0-9]+  Bytecode', $Record, -8);
      print "|   ";
    }

    # Print Sizes
    printField("([0-9]+)  Local", $Record, -8);
    my $B = printField("([0-9]+)  Bottom-up", $Record, -8);
    my $T = printField("([0-9]+)  Top-down", $Record, -8);
    printf("%-8s ", $B+$T);
    printField("([0-9]+)  Bytecode", $Record, -8);

    print "|    ";
    printField("([0-9]+).*Number of folded nodes ", $Record, -5);
    printField("Graphs contain \\[([0-9+]+)\\] nodes total", $Record, -10);
    printField("([0-9]+).*Maximum graph size", $Record, -6);
    printField("\\.GlobalsGraph\\.dot'... \\[([0-9+]+)\\]", $Record, -6);
    printField("([0-9]+).*Maximum SCC Size in Call Graph", $Record, -6);

    print "| ";
    my $I = printField("([0-9]+).*Number of LoadInsts", $Record, -5);
    $I += printField("([0-9]+).*Number of StoreInsts", $Record, -5);
    $I += printField("([0-9]+).*Number of CallInsts", $Record, -5);
    $I += printField("([0-9]+).*Number of AllocaInsts", $Record, -5);
    $I += printField("([0-9]+).*Number of MallocInsts", $Record, -5);
    printf("%-5s ", $I);

    print "| ";
    my $NI = printField("([0-9]+).*number of indirect call sites", $Record, -7);
    my $NC = printField("([0-9]+).*number of callee functions at", $Record, -9);
    if ($NI != 0) {
      printf("%-5s ", $NC/$NI);
    } else {
      printf("%-5s ", "n/a");
    }

  }
  print "\n";
}

sub printField {
  ($Regex, $Record, $FieldWidth) = @_;
  #print "Args: '$Regex' '$Record'\n";
  $Record =~ m/$Regex/;
  if (!defined($1)) {
    printf("%${FieldWidth}s ", "*");
    return "0";
  } else {
    printf("%${FieldWidth}s ", $1);
  }
  return $1;
}
