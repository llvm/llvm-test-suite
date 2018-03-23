//
// See README-LCALS_license.txt for access and distribution restrictions
//

//
// Header file defining routines and structures to gather and report
// LCALS loop suite execution information.
//

#ifndef LCALSStats_HXX
#define LCALSStats_HXX

#include "LCALSParams.hxx"

#include <vector>
#include <map>
#include <string>
#include <iostream>

#if defined(LCALS_USE_CYCLE)
#include "cycle.h"
typedef ticks LoopTime;

#elif defined(LCALS_USE_CLOCK)
#include <time.h>
typedef clock_t LoopTime;

#else
#error LCALS_TIMER_TYPE is undefined!

#endif


class LoopStat;

//
// Loop timing should follow the implementation described here.
// (See files containing loop implementations for details.)
//
// 1) Execute loop (identified by integer variable "iloop"):
//
//    LoopTimer ltimer;
//
//    flushCache(); 
//
//    TIMER_START(ltimer);
//
//        ...CODE FOR LOOP "iloop" GOES HERE...
//
//    TIMER_STOP(ltimer);
//
// 2) At some point after loop is run, but before next loop in file is run, 
//    copy timing information to appropriate loop stat object:
//
//    copyTimers(loop_stat, ilength, ltimer);
//

struct LoopTimer
{
   LoopTime start;
   LoopTime stop;
   bool was_run;

   LoopTimer() : start(0), stop(0), was_run(false) { ; }
};

void flushCache();
void copyTimer(LoopStat& loop_stat, int ilength, 
               const LoopTimer& loop_timer);

#if defined(LCALS_USE_CYCLE)

#define TIMER_START(lt)  lt.start = getticks(); 
#define TIMER_STOP(lt)  lt.stop = getticks(); \

#elif defined(LCALS_USE_CLOCK)

#define TIMER_START(lt) lt.start = clock();
#define TIMER_STOP(lt)  lt.stop = clock(); \
                        lt.was_run = true;

#else
#error LCALS_TIMER_TYPE is undefined!

#endif



//////////////////////////////////////////////////////////////////
//
//  Routines to set up loop data, run loops, generate output, etc.
//
//////////////////////////////////////////////////////////////////

//
// Forward declarations for structs defined below.
//
struct LoopStat;
struct LoopSuiteRunInfo;

//
// Routines for accessing loop suite run info.
//
LoopSuiteRunInfo& getLoopSuiteRunInfo();


//
// Routine to allocate and setup basic structures used to run loop suite
// and free them when done.
//
void allocateLoopSuiteRunInfo(const std::string& host_name,
                              unsigned num_loops,
                              unsigned num_loop_lengths,
                              unsigned num_suite_passes,
                              bool run_loop_length[],
                              CacheIndex_type cache_size);
void freeLoopSuiteRunInfo();


//
// Routine to generate loop excution timing report.
// 
// Also write output files if non-empty directory name is given.
//
void generateTimingReport(const std::vector< std::string >& run_loop_variants,
                          const std::string& output_dirname);

//
// Routine to generate report about loop checksums.
// 
// Also write output files if non-empty directory name is given.
//
void generateChecksumReport(const std::vector< std::string >& run_loop_variants,
                            const std::string& output_dirname);

//
// Routine to generate FOM report.
// 
// Also write output files if non-empty directory name is given.
//
void generateFOMReport(const std::vector< std::string >& run_loop_variants,
                       const std::string& output_dirname);



//////////////////////////////////////////////////////////////////
//
//  Structures holding parameters defining execution of loop suite 
//  and loop timing statistic information.
//
//////////////////////////////////////////////////////////////////

class LoopStat
{
public:

   bool loop_is_run; 

   double loop_weight;

   //
   // The following vectors are indexed by loop length ID.
   //
   // The second vector index for loop_run_time
   // is number of suite pass.
   //

   std::vector< std::vector<long double> > loop_run_time;
   std::vector< unsigned long > loop_run_count;

   std::vector< long double > mean;
   std::vector< long double > std_dev;
   std::vector< long double > min;
   std::vector< long double > max;
   std::vector< long double > harm_mean;
   std::vector< long double > meanrel2ref;

   std::vector< int > loop_length;
   std::vector< int > samples_per_pass;

   std::vector< long double > loop_chksum;

   explicit LoopStat(unsigned num_loop_lengths)
   : loop_is_run(false),
     loop_weight(0.0),
     loop_run_time(num_loop_lengths),
     loop_run_count(num_loop_lengths, 0),
     mean(num_loop_lengths, 0.0),
     std_dev(num_loop_lengths, 0.0),
     min(num_loop_lengths, 0.0),
     max(num_loop_lengths, 0.0),
     harm_mean(num_loop_lengths, 0.0),
     meanrel2ref(num_loop_lengths, 0.0),
     loop_length(num_loop_lengths, 0),
     samples_per_pass(num_loop_lengths, 0),
     loop_chksum(num_loop_lengths, 0.0)
   { ; } 

   //
   // Print routine for debugging.
   //
   void print(std::ostream& os) const;

private:
   //
   // The following methods are not implemented.
   //
   LoopStat();
};

class LoopSuiteRunInfo
{
public:

   std::string host_name;

   //
   // The following vectors are indexed by loop ID.
   //
   unsigned num_loops;
   std::vector<std::string> loop_names;

   //
   // The following vectors are indexed by loop length ID.
   //
   unsigned num_loop_lengths;
   std::vector<bool> run_loop_length;
   std::vector<std::string> loop_length_names;

   unsigned num_suite_passes;
   double loop_samp_frac;

   LoopStat ref_loop_stat;
   //
   // The following vectors are indexed by loop WeightGroup
   //
   std::vector<double> loop_weights;

   //
   // The following vectors are indexed first by loop variant 
   // (according to order in LoopStatMap, which is the same as 
   // run_loop_variants vector in main.cxx) and then by loop length.  
   // So we have NUM_LENGTHS values for each variant.
   //
   std::vector< std::vector< int > > num_loops_run;
   std::vector< std::vector< long double > > tot_time;
   std::vector< std::vector< long double > > fom_rel;
   std::vector< std::vector< long double > > fom_rate;


   CacheIndex_type cache_flush_data_len;
   double* cache_flush_data;
   long double cache_flush_data_sum;

   LoopSuiteRunInfo()
   : ref_loop_stat(static_cast<unsigned>(0)),
     num_loops(0),
     num_loop_lengths(0),
     num_suite_passes(0),
     loop_samp_frac(0.0),
     cache_flush_data_len(0),
     cache_flush_data(0),
     cache_flush_data_sum(0.0)
   { ; }


   typedef std::map< std::string, std::vector<LoopStat>* > LoopStatMap;

   ~LoopSuiteRunInfo() 
   {
      LoopStatMap::iterator lsi = loop_test_stats.begin();
      for (  ; lsi != loop_test_stats.end(); ++ lsi ) {
         delete (*lsi).second; 
      }
   }

   //
   // Add vector of loop stats for loop test with given name.
   //
   void addLoopStats(const std::string& name)
   {
      std::vector<LoopStat>* stat_vec = new std::vector<LoopStat>();
      loop_test_stats.insert( LoopStatMap::value_type( name, stat_vec ) );
   }

   //
   // Return reference to vector of loop stats for loop test with given name.
   //
   std::vector<LoopStat>& getLoopStats( const std::string& name )
   {
      LoopStatMap::iterator lsi = loop_test_stats.find(name);
      return( *( (*lsi).second ) );
   }

private:
   //
   // The following methods are not implemented.
   //
   LoopSuiteRunInfo(const LoopSuiteRunInfo&);
   LoopSuiteRunInfo& operator=(const LoopStat&); 

   LoopStatMap loop_test_stats;
};


#endif  // closing endif for header file include guard
