//
// See README-LCALS_license.txt for access and distribution restrictions
//

//
// Source file containing routines used to gather and report
// performance data for LCALS suite
//

#include "LCALSStats.hxx"

#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<limits>
#include<cstdlib>
#include<cmath>

using namespace std;

//
// LoopStat print routine for debugging.
//
void LoopStat::print(ostream& os) const
{
   os << "\nLoopStat::print..." << endl;
   os << "\tloop_is_run = " <<  loop_is_run << endl;
   os << "\tnum loop lengths = " <<  loop_length.size() << endl;
   for (unsigned i = 0; i < loop_length.size(); ++i) {
      os << "\t\t ilength = " <<  i << " --> " << endl;  
      os << "\t\t\t loop_length = " <<  loop_length[i] << endl;
      os << "\t\t\t samples_per_pass = " <<  samples_per_pass[i] << endl;
      os << "\t\t\t loop_run_count = " <<  loop_run_count[i] << endl;
      if ( loop_run_count[i] > 0 ) {
         for (unsigned j = 0; j < loop_run_time[i].size(); ++j) {
            os << "\t\t\t\t sample time = " <<  loop_run_time[i][j] << endl;
         }
         os << "\t\t\t\t mean = "            <<  mean[i] << endl; 
         os << "\t\t\t\t std_dev = "         <<  std_dev[i] << endl; 
         os << "\t\t\t\t min = "             <<  min[i] << endl; 
         os << "\t\t\t\t max = "             <<  max[i] << endl; 
         os << "\t\t\t\t harm_mean = "       <<  harm_mean[i] << endl; 
         os << "\t\t\t\t meanrel2ref = "     <<  meanrel2ref[i] << endl; 
         os << endl;
         for (unsigned j = 0; j < loop_run_time[i].size(); ++j) {
            os << "\t\t\t\t sample time = " <<  loop_run_time[i][j] << endl;
         }
      }    
   }
   os << endl;
}


//
// File scope data holding structures needed to execute and time loops.
//
static LoopSuiteRunInfo* s_loop_suite_run_info = 0;

//
// Accessor routine for suite run info.
//
LoopSuiteRunInfo& getLoopSuiteRunInfo() { return *s_loop_suite_run_info; }


//
// Define how suite will run and initialize timing structures for loops.
//
void allocateLoopSuiteRunInfo(const string& host_name,
                              unsigned num_loops,
                              unsigned num_loop_lengths,
                              unsigned num_suite_passes,
                              bool run_loop_length[],
                              CacheIndex_type cache_size)
{
#ifdef TESTSUITE
   cout << "\n allocateLoopSuiteRunInfo..." << endl;
#endif
   if ( s_loop_suite_run_info == 0 ) { 
      s_loop_suite_run_info = new LoopSuiteRunInfo(); 
   }

   s_loop_suite_run_info->host_name = host_name;

   s_loop_suite_run_info->num_loops = num_loops;
   s_loop_suite_run_info->num_loop_lengths = num_loop_lengths;
   s_loop_suite_run_info->num_suite_passes = num_suite_passes;
   for (unsigned ilen = 0; ilen < num_loop_lengths; ++ilen) {
      s_loop_suite_run_info->run_loop_length.push_back(
                                             run_loop_length[ilen]);
   }

   //
   // To make sure all data cache levels are flushed completely, we
   // define a data buffer with length equal to twice given cache size.
   //
   s_loop_suite_run_info->cache_flush_data_len = 
                          (cache_size*2)/sizeof(Real_type);
   s_loop_suite_run_info->cache_flush_data = 
      new double[s_loop_suite_run_info->cache_flush_data_len];
   for (CacheIndex_type i = 0; 
        i < s_loop_suite_run_info->cache_flush_data_len; ++i) {
      s_loop_suite_run_info->cache_flush_data[i] = drand48() + 0.1;
   }

}

//
// Free data structures defining loop suite execution.
//
void freeLoopSuiteRunInfo()
{
   if ( s_loop_suite_run_info ) { 
      if ( s_loop_suite_run_info->cache_flush_data ) {
         delete [] s_loop_suite_run_info->cache_flush_data;
      }
      delete s_loop_suite_run_info; 
      s_loop_suite_run_info = 0;
   }
}

//////////////////////////////////////////////////////////////////
//
//  Routines used for loop timing...
//
//////////////////////////////////////////////////////////////////

//
// Flush cache before each loop is run to minimize impact of one
// loop on another's execution.
//
void flushCache()
{
   for (CacheIndex_type i = 0; 
        i < s_loop_suite_run_info->cache_flush_data_len; ++i) {
      s_loop_suite_run_info->cache_flush_data_sum +=
         s_loop_suite_run_info->cache_flush_data[i];
   }
   s_loop_suite_run_info->cache_flush_data_sum /=
      s_loop_suite_run_info->cache_flush_data_len; 
}


//
// Copy loop run time to LoopStat.
//
void copyTimer(LoopStat& loop_stat, int ilength,
               const LoopTimer& loop_timer)
{
   if ( loop_timer.was_run ) {
#if defined(LCALS_USE_CYCLE)
      long double run_time = elapsed(loop_timer.stop,
                                     loop_timer.start);
#elif defined(LCALS_USE_CLOCK)
      long double run_time =
         static_cast<long double>(loop_timer.stop -
                                  loop_timer.start) / CLOCKS_PER_SEC;
#else
#error LCALS_TIMER_TYPE is undefined! 

#endif
      loop_stat.loop_run_time[ilength].push_back( run_time );
   }
}



//
// Compute statistics for loop run for variant with given index.
//
void computeStats( unsigned ilv, vector<LoopStat>& loop_stats,
                   bool do_fom )
{

   // compute stats for each loop...
   for ( unsigned iloop = 0; iloop < loop_stats.size(); ++iloop ) {

      LoopStat& stat = loop_stats[iloop];

      if ( stat.loop_is_run ) {

         // compute stats for each length loop is run...
         for ( unsigned ilen = 0; ilen < stat.loop_length.size(); ++ilen )  {
   
            if ( stat.loop_run_count[ilen] > 0 ) { 

               vector<long double>& time_sample = 
                                         stat.loop_run_time[ilen]; 
               unsigned sample_size = time_sample.size();
    
               long double mean = 0.0;
               long double sdev = 0.0;
               long double max = -std::numeric_limits<long double>::max();
               long double min = std::numeric_limits<long double>::max();
               long double harm = 0.0;

               for (unsigned is = 0; is < sample_size; ++is) {
                  mean += time_sample[is];
                  max = std::max(max, time_sample[is]);
                  min = std::min(min, time_sample[is]);
                  if ( time_sample[is] > 0.0 ) {
                     harm += 1.0/time_sample[is];
                  }
               }

               mean /= sample_size;
   
               if ( harm > 0.0 ) { harm = sample_size/harm; }

               for (unsigned is = 0; is < sample_size; ++is) {
                  sdev += (time_sample[is] - mean)*(time_sample[is] - mean);
               }

               sdev /= sample_size;

               stat.mean[ilen]      = mean;
               stat.std_dev[ilen]   = sdev;
               stat.min[ilen]       = min;
               stat.max[ilen]       = max;
               stat.harm_mean[ilen] = harm;

            }  // if loop length was run  

         }  // iterate over loop lengths

      }  // if loop is run

   }  // iterate over loops

   //
   // FOM calculations (done separately for simplicity)
   //
   if ( do_fom ) {

      LoopSuiteRunInfo& suite_info = getLoopSuiteRunInfo();
      LoopStat& ref_loop_stat = suite_info.ref_loop_stat;

      std::vector<int> num_loops_run(suite_info.num_loop_lengths, 0);
      std::vector< long double > tot_weight(suite_info.num_loop_lengths, 0.0);
      std::vector< long double > tot_time(suite_info.num_loop_lengths, 0.0);
      std::vector< long double > fom_rel(suite_info.num_loop_lengths, 0.0);
      std::vector< long double > fom_rate(suite_info.num_loop_lengths, 0.0);

      for ( unsigned iloop = 0; iloop < loop_stats.size(); ++iloop ) {

         LoopStat& stat = loop_stats[iloop];

         if ( stat.loop_is_run ) {

            for ( unsigned ilen = 0; ilen < stat.loop_length.size(); ++ilen )  {

               if ( stat.loop_run_count[ilen] > 0 ) {

                  num_loops_run[ilen]++;
                  tot_weight[ilen]   += stat.loop_weight; 
                  tot_time[ilen]     += stat.mean[ilen]; 
   
                  //
                  // sum weighted loop time 
                  //
                  fom_rel[ilen] += stat.loop_weight * stat.mean[ilen];

                  //
                  // sum weighted loop iteration rate
                  //
                  fom_rate[ilen] += (stat.loop_weight * stat.mean[ilen]) /
                      (stat.loop_length[ilen] * stat.samples_per_pass[ilen]);
   
               }  // if loop length was run
   
            }  // iterate over loop lengths
   
         }  // if loop is run
   
      }  // iterate over loops

      for (unsigned ilen = 0; ilen < suite_info.num_loop_lengths; ++ilen) {
         suite_info.num_loops_run[ilv][ilen] = num_loops_run[ilen];
         suite_info.tot_time[ilv][ilen] = tot_time[ilen];

         long double ref_time = ref_loop_stat.loop_run_time[ilen][0];
   
         if ( num_loops_run[ilen] > 0 ) {
#if 0  // this makes 0 <= fom_rel <= 1/tot_time
            suite_info.fom_rel[ilv][ilen] = 
               ref_time * tot_weight[ilen] / ( tot_time[ilen] * fom_rel[ilen] );
#else  // this makes 0 <= fom_rel <= 1
            suite_info.fom_rel[ilv][ilen] = 
               ref_time * tot_weight[ilen] / fom_rel[ilen] ;
#endif
            suite_info.fom_rate[ilv][ilen] = 1.0 / fom_rate[ilen];
         }
      }

   }

}


//
// Forward declarations for routines that write loop reports.
//
namespace {

   void writeTimingSummaryReport(
        const vector< string >& run_loop_variants,
        ostream& os);

   void writeChecksumReport(
        const vector< string >& run_loop_variants,
        ostream& os);

   void writeFOMReport(
        const vector< string >& run_loop_variants,
        ostream& os);

   void writeMeanTimeReport(const string& variant_name, 
                            const string& output_dirname);

   void writeRelativeTimeReport(const string& variant_name, 
                                const string& output_dirname);

   std::string buildVersionInfo();

};  // unnamed namespace


//
// Routine called from main() to generate timing report(s).
//
void generateTimingReport(const vector< string >& run_loop_variants,
                          const string& output_dirname)
{
   if ( run_loop_variants.size() == 0 ) return;

   bool do_fom = true;

   std::string ver_info = buildVersionInfo(); 

   //
   // Compute statistics for all loops.
   //
   LoopSuiteRunInfo& suite_run_info = getLoopSuiteRunInfo();
   const unsigned nvariants = run_loop_variants.size();
   for (unsigned ilv = 0; ilv < nvariants; ++ilv) {
      computeStats( ilv, suite_run_info.getLoopStats(run_loop_variants[ilv]),
                    do_fom );
   }

   //
   // If output directory name is given, write files in that directory.
   // Else, write only summary to standard output.  
   //
   if (!output_dirname.empty()) {

      string timing_fname(output_dirname + "/" + "timing.txt");
      ofstream file(timing_fname.c_str(), ios::out | ios::trunc);
      if ( !file ) {
         cout << " ERROR: Can't open output file " 
                   << timing_fname << endl;
      }
      cout << "\n writeTimingSummaryReport...   " << timing_fname << endl;
      writeTimingSummaryReport(run_loop_variants, file);

      //
      // Write mean run time file for each loop variant.
      //
      for (unsigned ilv = 0; ilv < nvariants; ++ilv) {
         writeMeanTimeReport( run_loop_variants[ilv], output_dirname );
      }

      //
      // Write relative run time file for each loop variant.
      //
      // NOTE: We assume variant "zero" is reference.
      //
      for (unsigned ilv = 1; ilv < nvariants; ++ilv) {
         writeRelativeTimeReport( run_loop_variants[ilv], output_dirname );
      }

   } else {

      writeTimingSummaryReport(run_loop_variants, cout);

   }
}

//
// Routine called from main() to generate checksum report.
//
void generateChecksumReport(
   const vector< string >& run_loop_variants,
   const string& output_dirname)
{
#if defined(LCALS_VERIFY_CHECKSUM)
   if ( run_loop_variants.size() == 0 ) return;

   //
   // If output directory name is given, write file in that directory.
   // Else, write summary to standard output.
   //
   if (!output_dirname.empty()) {
      string checksum_fname(output_dirname + "/" + "checksum.txt");
      ofstream file(checksum_fname.c_str(), ios::out | ios::trunc);
      if ( !file ) {
         cout << " ERROR: Can't open output file "                   
                   << checksum_fname << endl;
      }
      cout << "\n writeChecksumReport...    " << checksum_fname << endl;
      writeChecksumReport(run_loop_variants, file);   
   } else {
      writeChecksumReport(run_loop_variants, cout);
   }
#endif
}

//
// Routine called from main() to generate FOM report.
//
void generateFOMReport(
   const vector< string >& run_loop_variants,
   const string& output_dirname)
{
   if ( run_loop_variants.size() == 0 ) return;

   //
   // If output directory name is given, write file in that directory.
   // Else, write only summary to standard output.
   //
   if (!output_dirname.empty()) {
      string fom_fname(output_dirname + "/" + "fom.txt");
      ofstream file(fom_fname.c_str(), ios::out | ios::trunc);
      if ( !file ) {
         cout << " ERROR: Can't open output file "
                   << fom_fname << endl;
      }
      cout << "\n writeFOMReport... " << fom_fname << endl;
      writeFOMReport(run_loop_variants, file);   
   } else {
      writeFOMReport(run_loop_variants, cout);
   }
}
 

//
// Implementation of file-scope routines that write loop reports.
//
namespace {

//
// Write report about loop execution timings to given output stream.
//
void writeTimingSummaryReport(const vector< string >& run_loop_variants,
                              ostream& os)
{
   LoopSuiteRunInfo& suite_run_info = getLoopSuiteRunInfo();
   const unsigned nvariants = run_loop_variants.size();

   const string& ref_variant = run_loop_variants[0];
   vector<string>& loop_names = suite_run_info.loop_names;

   //
   //  Define some strings used to print summary table.
   //
   string equal_line("===========================================================================================================\n");
   string dash_line("------------------------------------------------------------------------------------------------------------\n");
   string dash_line_part("-------------------------------------------------------\n");
   string dot_line_part("............................................\n");
   vector<string> len_id(suite_run_info.loop_length_names.size());
   for (unsigned ilen = 0; ilen < len_id.size(); ++ilen) {
      len_id[ilen] = suite_run_info.loop_length_names[ilen][0];
   }

   std::string ver_info = buildVersionInfo();

   //
   //  Print compilation summary information.
   //
   os << "\n\n\n";
   os << equal_line;
   os << equal_line;

   os << "LCALS compilation summary: " << endl;
   os << ver_info << endl;

   //
   //  Print basic run summary information.
   //
   os << "\n\n";
   os << equal_line;
   os << equal_line;

   os << "LCALS run summary: " << endl;
   os << "sizeof(Real_type) = " << sizeof(Real_type) << endl;
   os << "     num suite passes = " << suite_run_info.num_suite_passes << endl;
   os << "     loop sample fraction = " << suite_run_info.loop_samp_frac << endl;
   os << "     loop variants run : ";
   for (unsigned ilv = 0; ilv < nvariants; ++ilv) {
      string last_char;
      if ( ilv+1 < run_loop_variants.size() ) last_char = string(" , ");
      os << run_loop_variants[ilv] << last_char;
   }
   os << "\n     reference variant : " << ref_variant << endl;
   os << equal_line;
   os << equal_line;

   //
   // Set basic table formatting.
   //
   size_t max_name_len = 0;
   for (size_t iloop = 0; iloop < loop_names.size(); ++iloop) {
      max_name_len = max(max_name_len, loop_names[iloop].size()); 
   }

   size_t max_var_name_len = 0;
   for (size_t ilv = 0; ilv < nvariants; ++ilv) {
      max_var_name_len = 
         max(max_var_name_len, run_loop_variants[ilv].size()); 
   }

   string var_field("Variant(length id)");
   size_t var_field_len = var_field.size(); 
   unsigned prec = 10;
   unsigned prec_buf = prec + 8;
   unsigned reldiff_prec = 6;

   //
   // Print table column headers.
   //
   os << "Loop name(Loop ID) -->   <length id>:(length, samples/pass), etc." 
      << endl;
   os <<left<< setw(var_field_len+1) << var_field;
   os <<right<< setw(prec_buf) << "   Mean Time ";
   os <<left<< setw(prec_buf) << "        Min Time";
   os <<left<< setw(prec_buf) << "      Max Time";
   os <<left<< setw(prec_buf) << "    Std. Dev.";
   os <<left<< setw(prec_buf) << "Mean time rel to ref variant" << endl;
   os << dash_line;


   //
   // Print timing results for all loops in a table.
   //
   for (unsigned iloop = 0; iloop < loop_names.size(); ++iloop) {

      LoopStat& ref_variant_stat = suite_run_info.
                                   getLoopStats(run_loop_variants[0])[iloop]; 
      vector<long double> ref_mean(ref_variant_stat.mean); 

      if ( !loop_names[iloop].empty() && ref_variant_stat.loop_is_run ) {

         if ( iloop > 1 ) {  // magic numbers are bad!!
            os << endl << dash_line_part;
         }
         os <<left << loop_names[iloop] << " (" << iloop << ") --> ";

         for (unsigned ilv = 0; ilv < nvariants; ++ilv) {

            LoopStat& stat = suite_run_info.
                             getLoopStats(run_loop_variants[ilv])[iloop];

            if ( stat.loop_is_run ) {

               //
               // Print separator line for new loop or new variant.
               //
               if ( ilv == 0 ) {

                  for (unsigned ilen = 0; ilen < stat.loop_length.size(); ++ilen) {
                     os << "   " << len_id[ilen] << ":(" 
                        << stat.loop_length[ilen] << ", "
                        << stat.samples_per_pass[ilen] << ")";
                  }
                  os << endl; 

               } else {

                  os << dot_line_part;

               }

               //
               // Print statistics for each length of loop run.
               //
               for (unsigned ilen = 0; ilen < stat.loop_length.size(); ++ilen) {

                  if ( stat.loop_run_count[ilen] > 0 ) {

                     string var_string(run_loop_variants[ilv] + 
                                         "(" + len_id[ilen] + ")");
                  
                     os << showpoint << setprecision(prec)
                          <<left<< setw(var_field_len+1) << var_string;

                     os <<right<< setw(prec_buf) << stat.mean[ilen];
                     os <<right<< setw(prec_buf) << stat.min[ilen];
                     os <<right<< setw(prec_buf) << stat.max[ilen];
                     os <<right<< setw(prec_buf) << stat.std_dev[ilen];

                     if ( ilv > 0 ) {
                        // compare mean run time to reference variant 

                        long double rel_mean_diff = 0;
                        if ( ref_mean[ilen] != 0.0 ) {
                           rel_mean_diff = 1.0 + 
                              (stat.mean[ilen]-ref_mean[ilen])/ref_mean[ilen];
                        }
                        os <<right<< setprecision(reldiff_prec) << setw(prec_buf) 
                             << rel_mean_diff << endl;
                        stat.meanrel2ref[ilen] = rel_mean_diff;
                     } else {
                        os << endl;
                     }

                  }  // if loop length was run

               } // iterate over loop lengths

            } // if loop is run

         }  // iterate over variants of loop run

      }  // if loop name is not empty
      
   }  // iterate over loops


   os << dash_line;
   os << "\n\n\n"; 

   os.flush();
}


//
// Write report about loop chksums to given output stream.
//
void writeChecksumReport(const vector< string >& run_loop_variants,
                         ostream& os)
{
   LoopSuiteRunInfo& suite_run_info = getLoopSuiteRunInfo();
   const unsigned nvariants = run_loop_variants.size();
   const string& ref_variant = run_loop_variants[0];
   vector<string>& loop_names = suite_run_info.loop_names;

   //
   //  Define some strings used to print summary table.
   //
   string equal_line("===========================================================================================================\n");
   string dash_line("------------------------------------------------------------------------------------------------------------\n");
   string dash_line_part("-------------------------------------------------------\n");
   string dot_line_part("............................................\n");
   vector<string> len_id(suite_run_info.loop_length_names.size());
   for (unsigned ilen = 0; ilen < len_id.size(); ++ilen) {
      len_id[ilen] = suite_run_info.loop_length_names[ilen][0];
   }

   std::string ver_info = buildVersionInfo();

   //
   //  Print compilation summary information.
   //
   os << "\n\n\n";
   os << equal_line;
   os << equal_line;

   os << "LCALS compilation summary: " << endl;
   os << ver_info << endl;

   //
   //  Print checksum information.
   //
   os << "\n\n";
   os << equal_line;
   os << equal_line;

   //
   // Set basic table formatting.
   //
   size_t max_name_len = 0;
   for (size_t iloop = 0; iloop < loop_names.size(); ++iloop) {
      max_name_len = max(max_name_len, loop_names[iloop].size());
   }

   size_t max_var_name_len = 0;
   for (size_t ilv = 0; ilv < nvariants; ++ilv) {
      max_var_name_len =
         max(max_var_name_len, run_loop_variants[ilv].size());
   }

   string var_field("Variant(length #)");
   size_t var_field_len = var_field.size();
   unsigned prec = 32;
   unsigned prec_buf = prec + 8;

   //
   // Print table column headers.
   //
   os << "Loop name -->" << endl;
   os <<left<< setw(var_field_len+1) << var_field;
   os <<right<< setw(prec_buf) << "Check Sum    ";
   os <<left<< setw(prec_buf) << "        Delta from reference" << endl;
   os << dash_line;

   //
   // Print check sums for all loops in a table.
   //
   for (unsigned iloop = 0; iloop < loop_names.size(); ++iloop) {

      LoopStat& ref_variant_stat = suite_run_info.
                                   getLoopStats(run_loop_variants[0])[iloop];
      vector<long double> ref_chksum(ref_variant_stat.loop_chksum);

      if ( !loop_names[iloop].empty() && ref_variant_stat.loop_is_run ) {

         if ( iloop > 1 ) {  // magic numbers are bad!!
            os << endl << dash_line_part;
         }
         os <<left << loop_names[iloop] << " (" << iloop << ") --> ";

         for (unsigned ilv = 0; ilv < nvariants; ++ilv) {

            LoopStat& stat = suite_run_info.
                             getLoopStats(run_loop_variants[ilv])[iloop];

            if ( stat.loop_is_run ) {

               //
               // Print separator line for new loop or new variant.
               //
               if ( ilv == 0 ) {
                  os << endl;
               } else {
                  os << dot_line_part;
               }

               //
               // Print checksum for each length of loop run.
               //
               for (unsigned ilen = 0; ilen < stat.loop_length.size(); ++ilen) {

                  if ( stat.loop_run_count[ilen] > 0 ) {

                     string var_string(run_loop_variants[ilv] +
                                         "(" + len_id[ilen] + ")");

                     os << showpoint << setprecision(prec)
                          <<left<< setw(var_field_len+1) << var_string;

                     os <<right<< setw(prec_buf) << stat.loop_chksum[ilen];

                     if ( ilv > 0 ) {
                        // compare checksum to reference variant
                        long double chksum_diff = fabs(
                           stat.loop_chksum[ilen]-ref_chksum[ilen] );
                        os <<right<< setw(prec_buf)
                             << chksum_diff << endl;
                     } else {
                        os << endl;
                     }

                  }  // if loop length was run

               } // iterate over loop lengths

            } // if loop is run

         }  // iterate over variants of loop run

      }  // if loop name is not empty

   }  // iterate over loops


   os << dash_line;
   os << "\n\n\n";

   os.flush();
}

//
// Generate FOM report file to given output stream.
//
void writeFOMReport(const vector< string >& run_loop_variants,
                    ostream& os)
{
   LoopSuiteRunInfo& suite_run_info = getLoopSuiteRunInfo();
   const unsigned nvariants = run_loop_variants.size();

   //
   //  Define some strings used to print FOM summary table.
   //
   string equal_line("===========================================================================================================\n");
   string dash_line_part("-------------------------------------------------------\n");
   string dot_line_part("............................................\n");

   std::string ver_info = buildVersionInfo();

   //
   //  Print compilation summary information.
   //
   os << "\n\n\n";
   os << equal_line;
   os << equal_line;

   os << "LCALS compilation summary: " << endl;
   os << ver_info << endl;

   //
   //  Print checksum information.
   //
   os << "\n\n";
   os << equal_line;
   os << equal_line;

   os << "LCALS FOM results: " << endl;
   os << equal_line;

   vector<string>& len_name = suite_run_info.loop_length_names;

   unsigned prec = 32;
   //
   // Output FOM for each loop variant (and loop lengths)
   //
   for (unsigned ilv = 0; ilv < nvariants; ++ilv) {

      vector< int >& num_loops_run    = suite_run_info.num_loops_run[ilv];
      vector< long double >& tot_time = suite_run_info.tot_time[ilv];
      vector< long double >& fom_rel  = suite_run_info.fom_rel[ilv];
      vector< long double >& fom_rate = suite_run_info.fom_rate[ilv];

      os <<left << "Loop variant -- " << run_loop_variants[ilv] << endl;

      for (unsigned ilen = 0; ilen < len_name.size(); ++ilen) {
         os << "\t" << len_name[ilen]
                    << " :   # loops run = " << num_loops_run[ilen];
         os << showpoint << setprecision(prec)
                    << " ,   total exec time = " << tot_time[ilen] << endl;
         os << "\t\tFOM_relative = " << fom_rel[ilen] << endl;
#if 0  // It's not clear what this FOM rate means...
         os << "\t\tFOM_rate     = " << fom_rate[ilen] << endl;
#endif

         if ( ilen < len_name.size() - 1 ) {
            os << dot_line_part;
         }
      }

      if ( ilv < nvariants - 1 ) {
         os << endl << dash_line_part;
      }

   }

   os << equal_line;
   os << "\n\n\n";

   os.flush();
}

//
// Write mean run time report file.
//
void writeMeanTimeReport(const string& variant_name, 
                         const string& output_dirname)
{
   string rept_fname(output_dirname + "/");
   rept_fname += variant_name;
   rept_fname += string("-meantime.txt");

   ofstream file(rept_fname.c_str(), ios::out | ios::trunc);
   if ( !file ) {
      cout << " ERROR: Can't open output file " << rept_fname << endl;
   }
   cout << "\n writeMeanTimeReport...   " << rept_fname << endl;

   LoopSuiteRunInfo& suite_run_info = getLoopSuiteRunInfo();

   vector<string>& loop_names = suite_run_info.loop_names;
   vector<string>& len_names = suite_run_info.loop_length_names;

   const string sepchr(" , ");
   unsigned prec = 8;

   //
   // Print title line.
   // 
   file << variant_name << " Mean Run Times ";
   for (unsigned i = 0; i < len_names.size(); ++i) {
      file << sepchr;
   } 
   file << endl;
   
   //
   // Print column header line.
   // 
   for (unsigned i = 0; i < len_names.size(); ++i) {
      file << sepchr << len_names[i];
   } 
   file << endl;

   //
   // Print row of times for each loop.
   //
   for (unsigned iloop = 0; iloop < loop_names.size(); ++iloop) {

      LoopStat& stat = suite_run_info.
                       getLoopStats(variant_name)[iloop]; 

      if ( !loop_names[iloop].empty() && stat.loop_is_run ) {

         file << loop_names[iloop];
         for (unsigned ilen = 0; ilen < stat.loop_length.size(); ++ilen) {
            file << sepchr << setprecision(prec) << stat.mean[ilen];
         }
         file << endl;

      }

   }

   file.flush();
}

//
// Write relative run time report file.
//
void writeRelativeTimeReport(const string& variant_name, 
                             const string& output_dirname)
{
   string rept_fname(output_dirname + "/");
   rept_fname += variant_name;
   rept_fname += string("-reltime.txt");

   ofstream file(rept_fname.c_str(), ios::out | ios::trunc);
   if ( !file ) {
      cout << " ERROR: Can't open output file " << rept_fname << endl;
   }
   cout << "\n writeRelativeTimeReport...   " << rept_fname << endl;

   LoopSuiteRunInfo& suite_run_info = getLoopSuiteRunInfo();

   vector<string>& loop_names = suite_run_info.loop_names;
   vector<string>& len_names = suite_run_info.loop_length_names;

   const string sepchr(" , ");
   unsigned prec = 6;

   //
   // Print title line.
   // 
   file << variant_name << " Relative Run Times ";
   for (unsigned i = 0; i < len_names.size(); ++i) {
      file << sepchr;
   } 
   file << endl;
   
   //
   // Print column header line.
   // 
   for (unsigned i = 0; i < len_names.size(); ++i) {
      file << sepchr << len_names[i];
   } 
   file << endl;

   //
   // Print row of times for each loop.
   //
   for (unsigned iloop = 0; iloop < loop_names.size(); ++iloop) {

      LoopStat& stat = suite_run_info.
                       getLoopStats(variant_name)[iloop]; 

      if ( !loop_names[iloop].empty() && stat.loop_is_run ) {

         file << loop_names[iloop];
         for (unsigned ilen = 0; ilen < stat.loop_length.size(); ++ilen) {
            file << sepchr << setprecision(prec) << stat.meanrel2ref[ilen];
         }
         file << endl;

      }

   }

   file.flush();
}

//
// Build string containing LCALS compilation information from
// file created when make is invoked.
//
std::string buildVersionInfo()
{
   std::ifstream infile("lcalsversioninfo.txt", std::ios::in);
  
   std::string ver_info;

   infile.seekg(0, std::ios::end);
   ver_info.reserve(infile.tellg());
   infile.seekg(0, std::ios::beg);
   
   ver_info.assign((std::istreambuf_iterator<char>(infile)),
                    std::istreambuf_iterator<char>());
   infile.close(); 
   
#if 0
   std::string ver_info = "LCALS compilation info: \n" 
              << "\tUser = " << VER_PERSON << "\n"
              << "\tDate, Time = " << VER_DATE << " , " << VER_TIME << "\n"
              << "\tMachine = " << VER_MACHINE << "\n"
              << "\tOS = " << VER_OS << "\n"
              << "\t-----------------------------------------------" << "\n"
              << "\tCompiler + options = " << lcals_ver_info_values[0] << "\n"
              << "\tLCALS rules (defines) = " << lcals_ver_info_values[1] << "\n";
#endif
   return ver_info;
}

};  // unnamed namespace



