#!/usr/bin/perl
# $HeadURL$
# $Revision$
# $Date$
# $Author$

=head1 NAME

Octopussy_Data_Report.t - Octopussy Source Code Checker for Octopussy::Data_Report

=cut

use strict;
use warnings;
use Readonly;

use File::Path;
use Test::More tests => 5;

use Octopussy::Data_Report;

Readonly my $DIR_DATA_REPORTS => Octopussy::Directory('data_reports');
Readonly my $PREFIX           => 'Octo_TEST_';
Readonly my $DATA_REPORT      => "${PREFIX}Data_Report";

# create fake Data Reports
my $dir = "$DIR_DATA_REPORTS$DATA_REPORT/";
rmtree($dir);

my @list1 = Octopussy::Data_Report::Type_List();

mkpath($dir);
system "touch $dir${DATA_REPORT}-20100120-2000.html";
system "touch $dir${DATA_REPORT}-20100130-2000.html";
system "touch $dir${DATA_REPORT}-20100210-2000.html";

my @list2 = Octopussy::Data_Report::Type_List();
ok(scalar @list1 + 1 == scalar @list2, 'Octopussy::Data_Report::Type_List()');

my $reports1    = Octopussy::Data_Report::List($DATA_REPORT);
my $nb_reports1 = scalar keys %{$reports1};
ok($nb_reports1 == 3, 'Octopussy::Data_Report::List()');

my $deleted_file =
  Octopussy::Data_Report::Remove($DATA_REPORT, "${DATA_REPORT}-20100120-2000");
my $reports2    = Octopussy::Data_Report::List($DATA_REPORT);
my $nb_reports2 = scalar keys %{$reports2};
ok(
  $deleted_file eq "$dir${DATA_REPORT}-20100120-2000.*"
    && $nb_reports2 == $nb_reports1 - 1,
  'Octopussy::Data_Report::Remove()'
);

my $pattern = Octopussy::Data_Report::Remove_Month($DATA_REPORT, '2010', '01');
my $reports3 = Octopussy::Data_Report::List($DATA_REPORT);
my $nb_reports3 = scalar keys %{$reports3};
ok($pattern eq "$dir${DATA_REPORT}-201001*" && $nb_reports3 == $nb_reports1 - 2,
  'Octopussy::Data_Report::Remove_Month()');

$pattern = Octopussy::Data_Report::Remove_All($DATA_REPORT);
ok($pattern eq $dir && !-f "$dir${DATA_REPORT}-20100210-2000.html",
  'Octopussy::Data_Report::Remove_All()');

# Make sure we destroy all the stuff we created with these tests
rmtree($dir);

1;

=head1 AUTHOR

Sebastien Thebert <octo.devel@gmail.com>

=cut