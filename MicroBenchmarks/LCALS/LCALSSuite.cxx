//
// See README-LCALS_license.txt for access and distribution restrictions
//

//
// Source file with routines to allocate data for LCALS suite
// and define parameters controlling execution of each loop.
//

#include "LCALSSuite.hxx"
#include "LCALSStats.hxx"

#include "SubsetDataA.hxx"

#include<cstdlib>
#include<string>
#include<iostream>

#include<sys/types.h>
#include<sys/stat.h>

//#define LCALS_OMP_MEM_INIT
#undef LCALS_OMP_MEM_INIT

//
// File scope data holding structures used in loop suite
//
static LoopData* s_loop_data = 0;


//
// Default value for static ADomain member;
//
double ADomain::loop_length_factor = 1.0;

//
// Prototypes for file scope routines used in to manage loop data and checksums
//

namespace {

Real_ptr allocAndInitData(LoopData::RealArray& ra, Index_type len);
Index_type* allocAndInitData(LoopData::IndxArray& ia, Index_type len);
Complex_ptr allocAndInitData(LoopData::ComplexArray& ca, Index_type len);
void initData(LoopData::RealArray& ra);
void initData(LoopData::IndxArray& ia);
void initData(LoopData::ComplexArray& ca);

void initChksum(LoopStat& stat, LoopLength ilength);
void updateChksum(LoopStat& stat, LoopLength ilength,
                  const LoopData::RealArray& ra, Real_type scale_factor = 1.0);
void updateChksum(LoopStat& stat, LoopLength ilength,
                  Real_type val);
void updateChksum(LoopStat& stat, LoopLength ilength,
                  const LoopData::ComplexArray& ca, Real_type scale_factor = 1.0);

}  // closing brace for unnamed namespace




//
// Accessor routine for suite kernel data.
//
LoopData& getLoopData() { return *s_loop_data; }


//
// Define how suite will run and initialize stat structures for loops.
//
// NOTE: Loop lengths, loop sample counts (and weights for optimization
//       evaluation) are defined here!
//
// These values should be set large enough to accurately generate 
// execution timings (i.e., not too small to be masked by CPU timing 
// resolution and overhead).  The values set here were manually determined 
// so that O(1) seconds of execution time is required to sample each loop 
// on some of our fastest Intel machines.
//
void defineLoopSuiteRunInfo(const std::vector<LoopVariantID>& run_variants,
                            bool run_loop[], 
                            double sample_frac,
                            double loop_length_factor)
{
#ifdef TESTSUITE
   std::cout << "\n defineLoopSuiteRunInfo..." << std::endl;
#endif
   std::vector<std::string> run_variant_names = getVariantNames(run_variants);

   if ( s_loop_data == 0 ) { 
      s_loop_data = new LoopData(); 
   }

   //
   //
   // Enumeration defining loop groups for relative weighting of
   // execution timing based on what we think is most important.
   //
   // In computation of figures of merit (FOM), loops with higher 
   // weights will reduce FOM value more for higher run-time than 
   // those with lower weights.
   //
   enum WeightGroup {

      DATA_PARALLEL = 0,
      ORDER_DEPENDENT,
      TRANSCENDENTAL,
      DATA_DEPENDENT,
      POINTER_NEST,
      COMPLEX,

      NUM_WEIGHT_GROUPS  // Keep this one last and NEVER comment out (!!)
   };


   //
   // Initialize structure holding loop suite execution data.
   //
   LoopSuiteRunInfo& suite_info = getLoopSuiteRunInfo();

   suite_info.loop_samp_frac = sample_frac;

   suite_info.loop_weights.resize(NUM_WEIGHT_GROUPS);
   suite_info.loop_weights[DATA_PARALLEL]   = 2.0;
   suite_info.loop_weights[ORDER_DEPENDENT] = 1.8;
   suite_info.loop_weights[TRANSCENDENTAL]  = 1.7;
   suite_info.loop_weights[DATA_DEPENDENT]  = 1.7;
   suite_info.loop_weights[POINTER_NEST]    = 1.4;
   suite_info.loop_weights[COMPLEX]         = 1.0;

   suite_info.loop_length_names.resize(NUM_LENGTHS);
   suite_info.loop_length_names[LONG] = std::string("LONG");
   suite_info.loop_length_names[MEDIUM] = std::string("MEDIUM");
   suite_info.loop_length_names[SHORT] = std::string("SHORT");

   suite_info.num_loops_run.resize( run_variant_names.size() );
   suite_info.tot_time.resize( run_variant_names.size() );
   suite_info.fom_rel.resize( run_variant_names.size() );
   suite_info.fom_rate.resize( run_variant_names.size() );

   for (unsigned ilv = 0; ilv < run_variant_names.size(); ++ilv) {
      suite_info.addLoopStats(run_variant_names[ilv]);

      suite_info.num_loops_run[ilv].resize(NUM_LENGTHS, 0);
      suite_info.tot_time[ilv].resize(NUM_LENGTHS, 0.0);
      suite_info.fom_rel[ilv].resize(NUM_LENGTHS, 0.0);
      suite_info.fom_rate[ilv].resize(NUM_LENGTHS, 0.0);
   }


   //
   // Define common loop lengths for LONG, MEDIUM, SHORT loops.
   //
   // The values assigned here are propagated across all kernels 
   // (with a few exceptions) to simplify suite configuration en masse.  
   // These can also be set per-kernel below. 
   //
   std::vector< int > shared_loop_length(NUM_LENGTHS);
   shared_loop_length[LONG]   = static_cast<int>(44217 * loop_length_factor);
   shared_loop_length[MEDIUM] = static_cast<int>(5001 * loop_length_factor);
   shared_loop_length[SHORT]  = static_cast<int>(171 * loop_length_factor);

   ADomain::loop_length_factor = loop_length_factor;


   std::vector<double>& weight = suite_info.loop_weights;

   Index_type max_loop_length = 0;

   for (unsigned iloop = 0 ; iloop < suite_info.num_loops; ++iloop) {

      std::string loop_name;
      LoopStat loop_stat(suite_info.num_loop_lengths);

      Index_type max_loop_indx = 0;

      if ( run_loop[iloop] ) {

         switch ( iloop ) {
   
            case REF_LOOP : {
               loop_name = std::string("REF_LOOP"); 
               //
               // Note: Reference loop stats are not used in
               //       in suite.  Parameters are defined in 
               //       defineReferenceLoopRunInfo( ) routine.
               //
               break;
            }


            //
            // Parameters defining how loops in Subset A are run...
            //
            case PRESSURE_CALC   :
            case PRESSURE_CALC_ALT   : {

               if ( static_cast<LoopKernelID>(iloop) == PRESSURE_CALC ) {
                  loop_name = std::string("PRESSURE_CALC");
               } else {
                  loop_name = std::string("PRESSURE_CALC_ALT");
               }

               loop_stat.loop_weight = weight[DATA_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 15000;
               loop_stat.samples_per_pass[MEDIUM] = 200000;
               loop_stat.samples_per_pass[SHORT]  = 10000000;

               break;
            }

            case ENERGY_CALC   :
            case ENERGY_CALC_ALT   : {

               if ( static_cast<LoopKernelID>(iloop) == ENERGY_CALC ) {
                  loop_name = std::string("ENERGY_CALC");
               } else {
                  loop_name = std::string("ENERGY_CALC_ALT");
               } 

               loop_stat.loop_weight = weight[DATA_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 3000;
               loop_stat.samples_per_pass[MEDIUM] = 30000;
               loop_stat.samples_per_pass[SHORT]  = 1000000;

               break;
            }

            case VOL3D_CALC   : {
               loop_name = std::string("VOL3D_CALC");

               loop_stat.loop_weight = weight[ORDER_DEPENDENT]; 

               Index_type ndims = 3;

               ADomain Ldomain(LONG, ndims);
               loop_stat.loop_length[LONG]   = Ldomain.lpz - Ldomain.fpz + 1;
               ADomain Mdomain(MEDIUM, ndims);
               loop_stat.loop_length[MEDIUM] = Mdomain.lpz - Mdomain.fpz + 1;
               ADomain Sdomain(SHORT, ndims);
               loop_stat.loop_length[SHORT]  = Sdomain.lpz - Sdomain.fpz + 1;

               max_loop_indx = Ldomain.lpn;

               loop_stat.samples_per_pass[LONG]   = 6500;
               loop_stat.samples_per_pass[MEDIUM] = 30000;
               loop_stat.samples_per_pass[SHORT]  = 800000;

               break;
            }

            case DEL_DOT_VEC_2D : {
               loop_name = std::string("DEL_DOT_VEC_2D");

               loop_stat.loop_weight = weight[DATA_PARALLEL]; 

               Index_type ndims = 2;

               ADomain Ldomain(LONG, ndims);
               loop_stat.loop_length[LONG]   = Ldomain.n_real_zones;
               ADomain Mdomain(MEDIUM, ndims);
               loop_stat.loop_length[MEDIUM] = Mdomain.n_real_zones;
               ADomain Sdomain(SHORT, ndims);
               loop_stat.loop_length[SHORT]  = Sdomain.n_real_zones;

               max_loop_indx = Ldomain.lrn;

               loop_stat.samples_per_pass[LONG]   = 4000;
               loop_stat.samples_per_pass[MEDIUM] = 25000;
               loop_stat.samples_per_pass[SHORT]  = 2000000;

               break;
            }

            case COUPLE   : {
               loop_name = std::string("COUPLE");

               loop_stat.loop_weight = weight[TRANSCENDENTAL]; 

               Index_type ndims = 3;

               ADomain Ldomain(LONG, ndims);
               loop_stat.loop_length[LONG]   = Ldomain.lpz - Ldomain.fpz + 1;
               ADomain Mdomain(MEDIUM, ndims);
               loop_stat.loop_length[MEDIUM] = Mdomain.lpz - Mdomain.fpz + 1;
               ADomain Sdomain(SHORT, ndims);
               loop_stat.loop_length[SHORT]  = Sdomain.lpz - Sdomain.fpz + 1;

               max_loop_indx = Ldomain.lrn;

               loop_stat.samples_per_pass[LONG]   = 2000;
               loop_stat.samples_per_pass[MEDIUM] = 10000;
               loop_stat.samples_per_pass[SHORT]  = 600000;

               break;
            }

            case FIR   : {
               loop_name = std::string("FIR");

               loop_stat.loop_weight = weight[ORDER_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 10000;
               loop_stat.samples_per_pass[MEDIUM] = 80000;
               loop_stat.samples_per_pass[SHORT]  = 3000000;

               break;
            }


            //
            // Parameters defining how loops in Subset B are run...
            //
            case INIT3 : {
               loop_name = std::string("INIT3");

               loop_stat.loop_weight = weight[DATA_PARALLEL]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 10000;
               loop_stat.samples_per_pass[MEDIUM] = 110000;
               loop_stat.samples_per_pass[SHORT]  = 12000000;

               break;
            }

            case MULADDSUB : { 
               loop_name = std::string("MULADDSUB"); 

               loop_stat.loop_weight = weight[DATA_PARALLEL]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 12000;
               loop_stat.samples_per_pass[MEDIUM] = 140000;
               loop_stat.samples_per_pass[SHORT]  = 15000000;

               break; 
            }

            case IF_QUAD : {
               loop_name = std::string("IF_QUAD");

               loop_stat.loop_weight = weight[DATA_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 3000;
               loop_stat.samples_per_pass[MEDIUM] = 30000;
               loop_stat.samples_per_pass[SHORT]  = 1000000;

               break;
            }

            case TRAP_INT : {
               loop_name = std::string("TRAP_INT");

               loop_stat.loop_weight = weight[ORDER_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 4000;
               loop_stat.samples_per_pass[MEDIUM] = 32000;
               loop_stat.samples_per_pass[SHORT]  = 1000000;

               break;
            }


            //
            // Parameters defining how loops in Subset C are run...
            //
            case HYDRO_1D : { 
               loop_name = std::string("HYDRO_1D"); 

               loop_stat.loop_weight = weight[DATA_PARALLEL]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 30000;
               loop_stat.samples_per_pass[MEDIUM] = 320000;
               loop_stat.samples_per_pass[SHORT]  = 15000000;

               break; 
            }

            case ICCG : {
               loop_name = std::string("ICCG"); 

               loop_stat.loop_weight = weight[COMPLEX]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 20000;
               loop_stat.samples_per_pass[MEDIUM] = 200000;
               loop_stat.samples_per_pass[SHORT]  = 6000000;

               break; 
            }

            case INNER_PROD : {
               loop_name = std::string("INNER_PROD"); 

               loop_stat.loop_weight = weight[ORDER_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 50000;
               loop_stat.samples_per_pass[MEDIUM] = 600000;
               loop_stat.samples_per_pass[SHORT]  = 30000000;

               break; 
            }

            case BAND_LIN_EQ : {
               loop_name = std::string("BAND_LIN_EQ"); 

               loop_stat.loop_weight = weight[COMPLEX]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 40000;
               loop_stat.samples_per_pass[MEDIUM] = 600000;
               loop_stat.samples_per_pass[SHORT]  = 20000000;

               break; 
            }

            case TRIDIAG_ELIM : {
               loop_name = std::string("TRIDIAG_ELIM"); 

               loop_stat.loop_weight = weight[ORDER_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 10000;
               loop_stat.samples_per_pass[MEDIUM] = 100000;
               loop_stat.samples_per_pass[SHORT]  = 3000000;

               break; 
            }

            case EOS   : { 
               loop_name = std::string("EOS");

               loop_stat.loop_weight = weight[DATA_PARALLEL]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 18000;
               loop_stat.samples_per_pass[MEDIUM] = 140000;
               loop_stat.samples_per_pass[SHORT]  = 5000000;
            
               break; 
            }

            case ADI   : {
               loop_name = std::string("ADI");

               loop_stat.loop_weight = weight[COMPLEX]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 1000;
               loop_stat.samples_per_pass[MEDIUM] = 9000;
               loop_stat.samples_per_pass[SHORT]  = 300000;
            
               break; 
            }

            case INT_PREDICT   : {
               loop_name = std::string("INT_PREDICT");

               loop_stat.loop_weight = weight[POINTER_NEST]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 3000;
               loop_stat.samples_per_pass[MEDIUM] = 30000;
               loop_stat.samples_per_pass[SHORT]  = 2000000;
            
               break; 
            }

            case DIFF_PREDICT   : {
               loop_name = std::string("DIFF_PREDICT");

               loop_stat.loop_weight = weight[POINTER_NEST]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 2000;
               loop_stat.samples_per_pass[MEDIUM] = 22000;
               loop_stat.samples_per_pass[SHORT]  = 1800000;
            
               break; 
            }

            case FIRST_SUM   : { 
               loop_name = std::string("FIRST_SUM");

               loop_stat.loop_weight = weight[ORDER_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 30000;
               loop_stat.samples_per_pass[MEDIUM] = 250000;
               loop_stat.samples_per_pass[SHORT]  = 8000000;

               break; 
            }

            case FIRST_DIFF   : { 
               loop_name = std::string("FIRST_DIFF");

               loop_stat.loop_weight = weight[DATA_PARALLEL]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 30000;
               loop_stat.samples_per_pass[MEDIUM] = 500000;
               loop_stat.samples_per_pass[SHORT]  = 30000000;

               break; 
            }

            case PIC_2D   : {
               loop_name = std::string("PIC_2D");

               loop_stat.loop_weight = weight[COMPLEX]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 2000;
               loop_stat.samples_per_pass[MEDIUM] = 18000;
               loop_stat.samples_per_pass[SHORT]  = 700000;

               break; 
            }

            case PIC_1D   : {
               loop_name = std::string("PIC_1D");

               loop_stat.loop_weight = weight[DATA_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 3000;
               loop_stat.samples_per_pass[MEDIUM] = 24000;
               loop_stat.samples_per_pass[SHORT]  = 1000000;

               break; 
            }

            case HYDRO_2D   : {   
               loop_name = std::string("HYDRO_2D");

               loop_stat.loop_weight = weight[ORDER_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 300;
               loop_stat.samples_per_pass[MEDIUM] = 2000;
               loop_stat.samples_per_pass[SHORT]  = 50000;

               break; 
            }

            case GEN_LIN_RECUR   : { 
               loop_name = std::string("GEN_LIN_RECUR");

               loop_stat.loop_weight = weight[ORDER_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 4000;
               loop_stat.samples_per_pass[MEDIUM] = 36000;
               loop_stat.samples_per_pass[SHORT]  = 1000000;

               break; 
            }

            case DISC_ORD   : { 
               loop_name = std::string("DISC_ORD");

               loop_stat.loop_weight = weight[ORDER_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 1000;
               loop_stat.samples_per_pass[MEDIUM] = 8000;
               loop_stat.samples_per_pass[SHORT]  = 200000;

               break; 
            }

            case MAT_X_MAT   : {   
               loop_name = std::string("MAT_X_MAT");

               loop_stat.loop_weight = weight[ORDER_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 8;
               loop_stat.samples_per_pass[MEDIUM] = 70;
               loop_stat.samples_per_pass[SHORT]  = 8000;

               break; 
            }

            case PLANCKIAN   : { 
               loop_name = std::string("PLANCKIAN");

               loop_stat.loop_weight = weight[TRANSCENDENTAL]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 4000;
               loop_stat.samples_per_pass[MEDIUM] = 30000;
               loop_stat.samples_per_pass[SHORT]  = 1000000;

               break; 
            }

            case IMP_HYDRO_2D   : {
               loop_name = std::string("IMP_HYDRO_2D");

               loop_stat.loop_weight = weight[ORDER_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 800;
               loop_stat.samples_per_pass[MEDIUM] = 6000;
               loop_stat.samples_per_pass[SHORT]  = 150000;

               break; 
            }

            case FIND_FIRST_MIN   : { 
               loop_name = std::string("FIND_FIRST_MIN");

               loop_stat.loop_weight = weight[DATA_DEPENDENT]; 

               for (int i = 0; i < NUM_LENGTHS; ++i) {
                  loop_stat.loop_length[i] = shared_loop_length[i];
               }
               max_loop_indx = loop_stat.loop_length[LONG];

               loop_stat.samples_per_pass[LONG]   = 50000;
               loop_stat.samples_per_pass[MEDIUM] = 330000;
               loop_stat.samples_per_pass[SHORT]  = 8000000;

               break; 
            }

            default : { 
               std::cout << "\n Unknown loop id = " << iloop << std::endl; 
            }

         }  // switch statement on loop id

      }  // if loop with id is to be run


      suite_info.loop_names.push_back(loop_name); 

      //
      // Set max loop length to be largest loop index used over all loops.
      // 
      max_loop_length = 
         std::max(max_loop_length, max_loop_indx);
            
      //
      // Set number of times each loop length will be run.
      // 
      for (unsigned i = 0; i < suite_info.num_loop_lengths; ++i) {

         loop_stat.samples_per_pass[i] = static_cast<int>(
            loop_stat.samples_per_pass[i] * suite_info.loop_samp_frac / 
            loop_length_factor); 

         if ( suite_info.run_loop_length[i] ) {
            loop_stat.loop_run_count[i] = 
               loop_stat.samples_per_pass[i] * suite_info.num_suite_passes;
         } else {
            loop_stat.loop_run_count[i] = 0;
         }

      }

      //
      // We add loop stat for each loop to maintain consistent array indexing.
      // However, only loops specified to be run will be executed.
      // 
      for (unsigned ilv = 0; ilv < run_variant_names.size(); ++ilv) {
         suite_info.getLoopStats(run_variant_names[ilv]).push_back(loop_stat);
      }

   }  // loop over loop IDs


   defineReferenceLoopRunInfo();

   s_loop_data->max_loop_length = 
      std::max(max_loop_length, suite_info.ref_loop_stat.loop_length[LONG]); 
}

//
// Generate vector of loop variant names string from vector of 
// LoopVariantID enum values.
//
std::vector<std::string> getVariantNames(
   const std::vector<LoopVariantID>& lvids)
{
   std::vector<std::string> run_variant_names;
   for (unsigned ilv = 0; ilv < lvids.size(); ++ilv) {
      std::string variant_name = getVariantName(lvids[ilv]);
      run_variant_names.push_back(variant_name);
   }
   return run_variant_names;
}

//
// Generate loop variant name string from LoopVariantID enum value.
//
std::string getVariantName(LoopVariantID lvid)
{
   std::string lvname;

   switch ( lvid ) {

// Bechmark variants
//
      case RAW: { 
         lvname = "Raw"; break; 
      }
      case RAW_OMP: { 
         lvname = "Raw_OMP"; break; 
      }
      case FORALL_LAMBDA: {
         lvname = "Forall_Lambda"; break;
      }
      case FORALL_LAMBDA_OMP: {
         lvname = "Forall_Lambda_OMP"; break;
      }

#if defined(LCALS_DO_MISC)

// Misc variants
//
      case FORALL_HYBRID_LAMBDA: {
         lvname = "Hybrid_Lambda"; break; 
      }
#if 0  // THESE ARE AVAILABLE YET!!!
      case FORALL_HYBRID_LAMBDA_OMP: {
         lvname = "Hybrid_Lambda_OMP"; break; 
      }
#endif
      case FORALL_FUNCTOR: {
         lvname = "Forall_Functor"; break;
      }
      case FORALL_FUNCTOR_OMP: {
         lvname = "Forall_Functor_OMP"; break;
      }
#if 0  // THESE ARE AVAILABLE YET!!!
      case FORALL_HYBRID_FUNCTOR: {
         lvname = "Hybrid_Functor"; break; 
      }
      case FORALL_HYBRID_FUNCTOR_OMP: { 
         lvname = "Hybrid_Functor_OMP"; break; 
      }
#endif
      case RAW_FUNC: {
         lvname = "Raw_Func"; break;
      }
      case FORALL_LAMBDA_TYPEFIX: {
         lvname = "Forall_Lambda_TYPEFIX"; break;
      }
      case FORALL_LAMBDA_OMP_TYPEFIX: {
         lvname = "Forall_Lambda_OMP_TYPEFIX"; break;
      }
      case FORALL_HYBRID_LAMBDA_TYPEFIX: {
         lvname = "Hybrid_Lambda_TYPEFIX"; break; 
      }

#endif // if LCALS_DO_MISC

      default: {
         std::cout << "\n Unknown loop variant id = " << lvid << std::endl; 
      }

   }

   return lvname;
}

#ifdef TEST_SUITE
//
// Execute loop variant identified by function args.
//
void runLoopVariant( LoopVariantID lvid,
                     bool run_loop[],
                     LoopLength ilength )
{
   LoopSuiteRunInfo& loop_suite_run_info = getLoopSuiteRunInfo();

   std::string loop_variant_name = getVariantName(lvid);
   std::vector<LoopStat>& loop_stats =
        loop_suite_run_info.getLoopStats(loop_variant_name);

   switch ( lvid ) {

// Bechmark variants
//
      case RAW: { 
         runARawLoops(loop_stats, run_loop, ilength);
         runBRawLoops(loop_stats, run_loop, ilength);
         runCRawLoops(loop_stats, run_loop, ilength);
         break; 
      }
      case FORALL_LAMBDA: {
         runAForallLambdaLoops(loop_stats, run_loop, ilength);
         runBForallLambdaLoops(loop_stats, run_loop, ilength);
         runCForallLambdaLoops(loop_stats, run_loop, ilength); 
         break;
      }
      case RAW_OMP: { 
         runOMPRawLoops(loop_stats, run_loop, ilength);
         break; 
      }
      case FORALL_LAMBDA_OMP: {
         runOMPForallLambdaLoops(loop_stats, run_loop, ilength);
         break;
      }

#if defined(LCALS_DO_MISC)

// Misc variants
//
      case FORALL_HYBRID_LAMBDA: {
         runAForallHybridLambdaLoops(loop_stats, run_loop, ilength);
         runBForallHybridLambdaLoops(loop_stats, run_loop, ilength);
         runCForallHybridLambdaLoops(loop_stats, run_loop, ilength);
         break; 
      }
#if 0  // THESE ARE NOT DEFINED YET!!!
      case FORALL_HYBRID_LAMBDA_OMP: {
         break; 
      }
#endif
      case FORALL_FUNCTOR: {
         runAForallFunctorLoops(loop_stats, run_loop, ilength);
         runBForallFunctorLoops(loop_stats, run_loop, ilength);
         runCForallFunctorLoops(loop_stats, run_loop, ilength);
         break;
      }
      case FORALL_FUNCTOR_OMP: {
         runOMPForallFunctorLoops(loop_stats, run_loop, ilength);
         break;
      }
#if 0  // THESE ARE NOT DEFINED YET!!!
      case FORALL_HYBRID_FUNCTOR: {
         break; 
      }
      case FORALL_HYBRID_FUNCTOR_OMP: { 
         break; 
      }
#endif
      case RAW_FUNC: {
         runARawFuncLoops(loop_stats, run_loop, ilength);
         runBRawFuncLoops(loop_stats, run_loop, ilength);
         runCRawFuncLoops(loop_stats, run_loop, ilength);
         break;
      }
      case FORALL_LAMBDA_TYPEFIX: {
         runAForallLambdaLoops_TYPEFIX(loop_stats, run_loop, ilength);
         runBForallLambdaLoops_TYPEFIX(loop_stats, run_loop, ilength);
         runCForallLambdaLoops_TYPEFIX(loop_stats, run_loop, ilength);
         break;
      }
      case FORALL_LAMBDA_OMP_TYPEFIX: {
         runOMPForallLambdaLoops_TYPEFIX(loop_stats, run_loop, ilength); 
         break;
      }
      case FORALL_HYBRID_LAMBDA_TYPEFIX: {
         runAForallHybridLambdaLoops_TYPEFIX(loop_stats, run_loop, ilength);
         runBForallHybridLambdaLoops_TYPEFIX(loop_stats, run_loop, ilength);
         runCForallHybridLambdaLoops_TYPEFIX(loop_stats, run_loop, ilength); 
         break; 
      }

#endif // if LCALS_DO_MISC

      default: {
         std::cout << "\n Unknown loop variant id = " << lvid << std::endl; 
      }

   }

}
#endif

//
// Initialize data to run loop with given ID.  Note that this routine 
// assumes that it is called before the loop with given ID is run and
// that data initialization calls in here are concistent with what is
// needed to execute loop.
//
// Loop data is initialized in this routine so all variants of loop
// tun the same way.  Note that data arrays are initialized for 
// each loop only under the circumstances that it is actually required.
//
//

void loopInit(unsigned iloop, LoopStat& stat)
{
   LoopData& loop_data = getLoopData();

   flushCache();

   stat.loop_is_run = true;


   switch ( iloop ) {
   
      case REF_LOOP : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);

         break;
      }

      case PRESSURE_CALC   :
      case PRESSURE_CALC_ALT   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);

         initData(loop_data.RealArray_scalars);

         break;
      }

      case ENERGY_CALC   :
      case ENERGY_CALC_ALT   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);
         initData(loop_data.RealArray_1D[5]);
         initData(loop_data.RealArray_1D[6]);
         initData(loop_data.RealArray_1D[7]);
         initData(loop_data.RealArray_1D[8]);
         initData(loop_data.RealArray_1D[9]);
         initData(loop_data.RealArray_1D[10]);
         initData(loop_data.RealArray_1D[11]);
         initData(loop_data.RealArray_1D[12]);
         initData(loop_data.RealArray_1D[13]);
         initData(loop_data.RealArray_1D[14]);

         initData(loop_data.RealArray_scalars);

         break;
      }

      case VOL3D_CALC   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);

         break;
      }

      case DEL_DOT_VEC_2D : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);

         break;
      }

      case COUPLE   : {

         initData(loop_data.ComplexArray_1D[0]);
         initData(loop_data.ComplexArray_1D[1]);
         initData(loop_data.ComplexArray_1D[2]);
         initData(loop_data.ComplexArray_1D[3]);
         initData(loop_data.ComplexArray_1D[4]);

         break;
      }

      case FIR   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);

         break;
      }

      case INIT3 : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);

         break;
      }

      case MULADDSUB : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);

         break;
      }

      case IF_QUAD : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);

         break;
      }

      case TRAP_INT : {

         initData(loop_data.IndxArray_1D[0]);

         initData(loop_data.RealArray_scalars);

         break;
      }


      case HYDRO_1D : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);

         initData(loop_data.RealArray_scalars);

         break;
      }

      case ICCG : {

         initData(loop_data.RealArray_1D_Nx4[0]);
         initData(loop_data.RealArray_1D_Nx4[1]);

         break;
      }

      case INNER_PROD : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);

         break;
      }

      case BAND_LIN_EQ : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);

         break;
      }

      case TRIDIAG_ELIM : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);

         break;
      }

      case EOS   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);

         initData(loop_data.RealArray_scalars);

         break;
      }

      case ADI   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);

         initData(loop_data.RealArray_3D_2xNx4[0]);
         initData(loop_data.RealArray_3D_2xNx4[1]);
         initData(loop_data.RealArray_3D_2xNx4[2]);

         initData(loop_data.RealArray_scalars);

         break;
      }

      case INT_PREDICT   : {

         initData(loop_data.RealArray_2D_Nx25[0]);

         initData(loop_data.RealArray_scalars);

         break;
      }

      case DIFF_PREDICT   : {

         initData(loop_data.RealArray_2D_Nx25[0]);
         initData(loop_data.RealArray_2D_Nx25[1]);

         break;
      }

      case FIRST_SUM   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);

         break;
      }

      case FIRST_DIFF   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);

         break;
      }

      case PIC_2D   : {

         initData(loop_data.RealArray_2D_Nx25[0]);
         initData(loop_data.RealArray_2D_Nx25[1]);
         initData(loop_data.RealArray_2D_Nx25[2]);

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);

         initData(loop_data.IndxArray_1D[0]);
         initData(loop_data.IndxArray_1D[1]);

         initData(loop_data.RealArray_2D_64x64[0]);

         break;
      }

      case PIC_1D   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);
         initData(loop_data.RealArray_1D[5]);
         initData(loop_data.RealArray_1D[6]);
         initData(loop_data.RealArray_1D[7]);
         initData(loop_data.RealArray_1D[8]);

         initData(loop_data.RealArray_scalars);

         initData(loop_data.IndxArray_1D[2]);
         initData(loop_data.IndxArray_1D[3]);
         initData(loop_data.IndxArray_1D[4]);

         break;
      }

      case HYDRO_2D   : {

         initData(loop_data.RealArray_2D_7xN[0]);
         initData(loop_data.RealArray_2D_7xN[1]);
         initData(loop_data.RealArray_2D_7xN[2]);
         initData(loop_data.RealArray_2D_7xN[3]);
         initData(loop_data.RealArray_2D_7xN[4]);
         initData(loop_data.RealArray_2D_7xN[5]);
         initData(loop_data.RealArray_2D_7xN[6]);
         initData(loop_data.RealArray_2D_7xN[7]);
         initData(loop_data.RealArray_2D_7xN[8]);
         initData(loop_data.RealArray_2D_7xN[9]);
         initData(loop_data.RealArray_2D_7xN[10]);

         break;
      }

      case GEN_LIN_RECUR   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);

         initData(loop_data.RealArray_scalars);

         break;
      }

      case DISC_ORD   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);
         initData(loop_data.RealArray_1D[5]);
         initData(loop_data.RealArray_1D[6]);
         initData(loop_data.RealArray_1D[7]);
         initData(loop_data.RealArray_1D[8]);

         initData(loop_data.RealArray_scalars);

         break;
      }

      case MAT_X_MAT   : {

         initData(loop_data.RealArray_2D_Nx25[0]);
         initData(loop_data.RealArray_2D_Nx25[1]);
         initData(loop_data.RealArray_2D_64x64[0]);

         break;
      }

      case PLANCKIAN   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);

         break;
      }

      case IMP_HYDRO_2D   : {

         initData(loop_data.RealArray_2D_7xN[0]);
         initData(loop_data.RealArray_2D_7xN[1]);
         initData(loop_data.RealArray_2D_7xN[2]);
         initData(loop_data.RealArray_2D_7xN[3]);
         initData(loop_data.RealArray_2D_7xN[4]);
         initData(loop_data.RealArray_2D_7xN[5]);

         break;
      }

      case FIND_FIRST_MIN   : {

         initData(loop_data.RealArray_1D[0]);

         break;
      }


      default : {
         std::cout << "\n Unknown loop id = " << iloop << std::endl;
      }
   }
}

/* *********** LLVM Test Suite ************* *
 *                                           *
 *   Overloaded for use in the test suite.   *
 *   Removes LoopStat argument and setting   *
 *   the loop as run.  Benchmark library     *
 *   replaces the stat object for timing     *
 *   statistics.                             *
 *                                           *
 * ***************************************** */

void loopInit(unsigned iloop) //, LoopStat& stat)
{
   LoopData& loop_data = getLoopData();

   flushCache();

//   stat.loop_is_run = true;


   switch ( iloop ) {
   
      case REF_LOOP : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);

         break;
      }


      //
      // Initialize data for Loop Subset A...
      //
      case PRESSURE_CALC   :
      case PRESSURE_CALC_ALT   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);

         initData(loop_data.RealArray_scalars); 

         break;
      }

      case ENERGY_CALC   :
      case ENERGY_CALC_ALT   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);
         initData(loop_data.RealArray_1D[5]);
         initData(loop_data.RealArray_1D[6]);
         initData(loop_data.RealArray_1D[7]);
         initData(loop_data.RealArray_1D[8]);
         initData(loop_data.RealArray_1D[9]);
         initData(loop_data.RealArray_1D[10]);
         initData(loop_data.RealArray_1D[11]);
         initData(loop_data.RealArray_1D[12]);
         initData(loop_data.RealArray_1D[13]);
         initData(loop_data.RealArray_1D[14]);

         initData(loop_data.RealArray_scalars);

         break;
      }

      case VOL3D_CALC   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);

         break;
      }

      case DEL_DOT_VEC_2D : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);

         break;
      }

      case COUPLE   : {

         initData(loop_data.ComplexArray_1D[0]);
         initData(loop_data.ComplexArray_1D[1]);
         initData(loop_data.ComplexArray_1D[2]);
         initData(loop_data.ComplexArray_1D[3]);
         initData(loop_data.ComplexArray_1D[4]);

         break;
      }

      case FIR   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);

         break;
      }


      //
      // Initialize data for Loop Subset B...
      //
      case INIT3 : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);

         break;
      }

      case MULADDSUB : { 

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);

         break; 
      }

      case IF_QUAD : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);

         break;
      }

      case TRAP_INT : {

         initData(loop_data.IndxArray_1D[0]);

         initData(loop_data.RealArray_scalars);

         break;
      }


      //
      // Initialize data for Loop Subset C...
      //
      case HYDRO_1D : { 

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);

         initData(loop_data.RealArray_scalars);

         break; 
      }

      case ICCG : {

         initData(loop_data.RealArray_1D_Nx4[0]);
         initData(loop_data.RealArray_1D_Nx4[1]);

         break; 
      }

      case INNER_PROD : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);

         break; 
      }

      case BAND_LIN_EQ : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);

         break; 
      }

      case TRIDIAG_ELIM : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);

         break; 
      }

      case EOS   : { 

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);

         initData(loop_data.RealArray_scalars);
      
         break; 
      }

      case ADI   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);

         initData(loop_data.RealArray_3D_2xNx4[0]);
         initData(loop_data.RealArray_3D_2xNx4[1]);
         initData(loop_data.RealArray_3D_2xNx4[2]);

         initData(loop_data.RealArray_scalars);
      
         break; 
      }

      case INT_PREDICT   : {

         initData(loop_data.RealArray_2D_Nx25[0]);

         initData(loop_data.RealArray_scalars);
      
         break; 
      }

      case DIFF_PREDICT   : {

         initData(loop_data.RealArray_2D_Nx25[0]);
         initData(loop_data.RealArray_2D_Nx25[1]);
      
         break; 
      }

      case FIRST_SUM   : { 

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);

         break; 
      }

      case FIRST_DIFF   : { 

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);

         break; 
      }

      case PIC_2D   : {

         initData(loop_data.RealArray_2D_Nx25[0]);
         initData(loop_data.RealArray_2D_Nx25[1]);
         initData(loop_data.RealArray_2D_Nx25[2]);

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);

         initData(loop_data.IndxArray_1D[0]);
         initData(loop_data.IndxArray_1D[1]);

         initData(loop_data.RealArray_2D_64x64[0]);

         break; 
      }

      case PIC_1D   : {

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);
         initData(loop_data.RealArray_1D[5]);
         initData(loop_data.RealArray_1D[6]);
         initData(loop_data.RealArray_1D[7]);
         initData(loop_data.RealArray_1D[8]);

         initData(loop_data.RealArray_scalars);

         initData(loop_data.IndxArray_1D[2]);
         initData(loop_data.IndxArray_1D[3]);
         initData(loop_data.IndxArray_1D[4]);

         break; 
      }

      case HYDRO_2D   : {   

         initData(loop_data.RealArray_2D_7xN[0]);
         initData(loop_data.RealArray_2D_7xN[1]);
         initData(loop_data.RealArray_2D_7xN[2]);
         initData(loop_data.RealArray_2D_7xN[3]);
         initData(loop_data.RealArray_2D_7xN[4]);
         initData(loop_data.RealArray_2D_7xN[5]);
         initData(loop_data.RealArray_2D_7xN[6]);
         initData(loop_data.RealArray_2D_7xN[7]);
         initData(loop_data.RealArray_2D_7xN[8]);
         initData(loop_data.RealArray_2D_7xN[9]);
         initData(loop_data.RealArray_2D_7xN[10]);

         break; 
      }

      case GEN_LIN_RECUR   : { 

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);

         initData(loop_data.RealArray_scalars);

         break; 
      }

      case DISC_ORD   : { 

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);
         initData(loop_data.RealArray_1D[5]);
         initData(loop_data.RealArray_1D[6]);
         initData(loop_data.RealArray_1D[7]);
         initData(loop_data.RealArray_1D[8]);

         initData(loop_data.RealArray_scalars);

         break; 
      }

      case MAT_X_MAT   : {   

         initData(loop_data.RealArray_2D_Nx25[0]);
         initData(loop_data.RealArray_2D_Nx25[1]);
         initData(loop_data.RealArray_2D_64x64[0]);

         break; 
      }

      case PLANCKIAN   : { 

         initData(loop_data.RealArray_1D[0]);
         initData(loop_data.RealArray_1D[1]);
         initData(loop_data.RealArray_1D[2]);
         initData(loop_data.RealArray_1D[3]);
         initData(loop_data.RealArray_1D[4]);

         break; 
      }

      case IMP_HYDRO_2D   : {

         initData(loop_data.RealArray_2D_7xN[0]);
         initData(loop_data.RealArray_2D_7xN[1]);
         initData(loop_data.RealArray_2D_7xN[2]);
         initData(loop_data.RealArray_2D_7xN[3]);
         initData(loop_data.RealArray_2D_7xN[4]);
         initData(loop_data.RealArray_2D_7xN[5]);

         break; 
      }

      case FIND_FIRST_MIN   : { 

         initData(loop_data.RealArray_1D[0]);

         break; 
      }


      default : { 
         std::cout << "\n Unknown loop id = " << iloop << std::endl; 
      }

   }  // switch statement on loop id

}


//
// Finalize data for loop with given ID.  Note that this routine assumes 
// that it is called after the loop with given ID is run and that checksum 
// calls in here are concistent with what is needed for loop.
//
void loopFinalize(unsigned iloop, LoopStat& stat, LoopLength ilength)
{
#if defined(LCALS_VERIFY_CHECKSUM)
   initChksum(stat, ilength);

   LoopData& loop_data = getLoopData();

   switch ( iloop ) {
   
      case REF_LOOP : {

         // Nothing to do for REF_LOOP case...

         break;
      }


      //
      // Update checksums for Loop Subset A...
      //
      case PRESSURE_CALC   :
      case PRESSURE_CALC_ALT   : {

         updateChksum(stat, ilength, loop_data.RealArray_1D[2]);

         break;
      }

      case ENERGY_CALC   :
      case ENERGY_CALC_ALT     : {

         updateChksum(stat, ilength, loop_data.RealArray_1D[0]);
         updateChksum(stat, ilength, loop_data.RealArray_1D[5]);

         break;
      }

      case VOL3D_CALC   : {

         updateChksum(stat, ilength, loop_data.RealArray_1D[3]);

         break;
      }

      case DEL_DOT_VEC_2D : {

         updateChksum(stat, ilength, loop_data.RealArray_1D[4]);

         break;
      }

      case COUPLE   : {

         updateChksum(stat, ilength, loop_data.ComplexArray_1D[0]);
         updateChksum(stat, ilength, loop_data.ComplexArray_1D[1]);
         updateChksum(stat, ilength, loop_data.ComplexArray_1D[2]);

         break;
      }

      case FIR   : {

         updateChksum(stat, ilength, loop_data.RealArray_1D[0]);

         break;
      }


      //
      // Update checksums for Loop Subset B...
      //
      case INIT3 : {

         updateChksum(stat, ilength, loop_data.RealArray_1D[0]);
         updateChksum(stat, ilength, loop_data.RealArray_1D[1]);
         updateChksum(stat, ilength, loop_data.RealArray_1D[2]);

         break;
      }

      case MULADDSUB : { 

         updateChksum(stat, ilength, loop_data.RealArray_1D[0]);
         updateChksum(stat, ilength, loop_data.RealArray_1D[1]);
         updateChksum(stat, ilength, loop_data.RealArray_1D[2]);

         break; 
      }

      case IF_QUAD : {

         updateChksum(stat, ilength, loop_data.RealArray_1D[3]);
         updateChksum(stat, ilength, loop_data.RealArray_1D[4]);

         break;
      }

      case TRAP_INT : {

         updateChksum(stat, ilength, loop_data.scalar_Real[0]);

         break;
      }


      //
      // Update checksums for Loop Subset C...
      //
      case HYDRO_1D : { 

         updateChksum(stat, ilength, loop_data.RealArray_1D[0]);

         break; 
      }

      case ICCG : {

         updateChksum(stat, ilength, loop_data.RealArray_1D_Nx4[0]);

         break; 
      }

      case INNER_PROD : {

         updateChksum(stat, ilength, loop_data.scalar_Real[0]);

         break; 
      }

      case BAND_LIN_EQ : {

         updateChksum(stat, ilength, loop_data.RealArray_1D[0]);

         break; 
      }

      case TRIDIAG_ELIM : {

         updateChksum(stat, ilength, loop_data.RealArray_1D[0]); 

         break; 
      }

      case EOS   : { 

         updateChksum(stat, ilength, loop_data.RealArray_1D[0]);

         break; 
      }

      case ADI   : {

         updateChksum(stat, ilength, loop_data.RealArray_3D_2xNx4[0]);
         updateChksum(stat, ilength, loop_data.RealArray_3D_2xNx4[1]);
         updateChksum(stat, ilength, loop_data.RealArray_3D_2xNx4[2]);

         break; 
      }

      case INT_PREDICT   : {

         updateChksum(stat, ilength, loop_data.RealArray_2D_Nx25[0]);

         break; 
      }

      case DIFF_PREDICT   : {

         updateChksum(stat, ilength, loop_data.RealArray_2D_Nx25[0]);

         break; 
      }

      case FIRST_SUM   : { 

         updateChksum(stat, ilength, loop_data.RealArray_1D[0]);

         break; 
      }

      case FIRST_DIFF   : { 

         updateChksum(stat, ilength, loop_data.RealArray_1D[0]);

         break; 
      }

      case PIC_2D   : {

         updateChksum(stat, ilength, loop_data.RealArray_2D_Nx25[0]);
         updateChksum(stat, ilength, loop_data.RealArray_2D_64x64[0]); 

         break; 
      }

      case PIC_1D   : {

         updateChksum(stat, ilength, loop_data.RealArray_1D[6]);
         updateChksum(stat, ilength, loop_data.RealArray_1D[1]);
         updateChksum(stat, ilength, loop_data.RealArray_1D[7]);

         break; 
      }

      case HYDRO_2D   : {   

         updateChksum(stat, ilength, loop_data.RealArray_2D_7xN[9]);
         updateChksum(stat, ilength, loop_data.RealArray_2D_7xN[10]);

         break; 
      }

      case GEN_LIN_RECUR   : { 

         updateChksum(stat, ilength, loop_data.RealArray_1D[0]);

         break; 
      }

      case DISC_ORD   : { 

         updateChksum(stat, ilength, loop_data.RealArray_1D[7]);

         break; 
      }

      case MAT_X_MAT   : {   

         updateChksum(stat, ilength, loop_data.RealArray_2D_Nx25[0]); 

         break; 
      }

      case PLANCKIAN   : { 

         updateChksum(stat, ilength, loop_data.RealArray_1D[4]);

         break; 
      }

      case IMP_HYDRO_2D   : {

         updateChksum(stat, ilength, loop_data.RealArray_2D_7xN[0]);

         break; 
      }

      case FIND_FIRST_MIN   : { 

         updateChksum(stat, ilength, loop_data.scalar_Real[0]); 

         break; 
      }


      default : { 
         std::cout << "\n Unknown loop id = " << iloop << std::endl; 
      }

   }  // switch statement on loop id

#endif  // if LCALS_VERIFY_CHECKSUM
}


//
// Allocate and initialize arrays (and scalars) used to execute loops in suite.
//
void allocateLoopData()
{
#ifdef TESTSUITE
   std::cout << "\n allocateLoopData..." << std::endl;
#endif
   unsigned num_aligned_segments = 
      (s_loop_data->max_loop_length + 20)/LCALS_DATA_ALIGN + 1;
   unsigned aligned_chunksize = num_aligned_segments * LCALS_DATA_ALIGN;

   //
   //  Allocate and initialize 1D loop length Real arrays.
   // 
   for (unsigned i = 0; i < s_loop_data->s_num_1D_Real_arrays; ++i) { 
      Index_type data_len = aligned_chunksize;

      LoopData::RealArray* rarray = s_loop_data->RealArray_1D;
      rarray[i].id = i+1;
      Real_ptr data = allocAndInitData(rarray[i], data_len); 

      s_loop_data->array_1D_Real[i] = data;
   }

   //
   //  Allocate and initialize 1D loop length X 4 Real arrays.
   //
   for (unsigned i = 0; i < s_loop_data->s_num_1D_Nx4_Real_arrays; ++i) {
      Index_type data_len = aligned_chunksize*4;

      LoopData::RealArray* rarray = s_loop_data->RealArray_1D_Nx4;
      rarray[i].id = i+1;
      Real_ptr data = allocAndInitData(rarray[i], data_len);

      s_loop_data->array_1D_Nx4_Real[i] = data;
   }

   //
   //  Allocate and initialize 1D loop length Indx arrays.
   // 
   for (unsigned i = 0; i < s_loop_data->s_num_1D_Indx_arrays; ++i) {
      Index_type data_len = aligned_chunksize;

      LoopData::IndxArray* iarray = s_loop_data->IndxArray_1D;
      iarray[i].id = i;
      Index_type* data = allocAndInitData(iarray[i], data_len);

      s_loop_data->array_1D_Indx[i] = data;
   }

   //
   //  Allocate and initialize 1D loop length Complex arrays.
   //
   for (unsigned i = 0; i < s_loop_data->s_num_1D_Complex_arrays; ++i) {
      Index_type data_len = aligned_chunksize;

      LoopData::ComplexArray* carray = s_loop_data->ComplexArray_1D;
      carray[i].id = i+1;
      Complex_ptr data = allocAndInitData(carray[i], data_len);

      s_loop_data->array_1D_Complex[i] = data;
   }

   //
   //  Allocate and initialize 2D loop length X 25 Real arrays.
   //
   for (unsigned i = 0; i < s_loop_data->s_num_2D_Nx25_Real_arrays; ++i) {
      Index_type data_len = aligned_chunksize*25;

      LoopData::RealArray* rarray = s_loop_data->RealArray_2D_Nx25;
      rarray[i].id = i+1;
      Real_ptr data = allocAndInitData(rarray[i], data_len);

      s_loop_data->array_2D_Nx25_Real[i] = new Real_ptr[aligned_chunksize];
      for (Index_type k = 0; k < aligned_chunksize; ++k) {
         s_loop_data->array_2D_Nx25_Real[i][k] = &data[k*25];
      }
   }

   //
   //  Allocate and initialize 2D 7 X loop length Real arrays.
   //
   for (unsigned i = 0; i < s_loop_data->s_num_2D_7xN_Real_arrays; ++i) {
      Index_type data_len = 7*aligned_chunksize;

      LoopData::RealArray* rarray = s_loop_data->RealArray_2D_7xN;
      rarray[i].id = i+1;
      Real_ptr data = allocAndInitData(rarray[i], data_len);

      s_loop_data->array_2D_7xN_Real[i] = new Real_ptr[7];
      for (Index_type k = 0; k < 7; ++k) {
         s_loop_data->array_2D_7xN_Real[i][k] = &data[k*aligned_chunksize];
      }
   }

   //
   //  Allocate and initialize 2D 64 X 64 Real arrays.
   //
   for (unsigned i = 0; i < s_loop_data->s_num_2D_64x64_Real_arrays; ++i) {
      Index_type data_len = 64*64;

      LoopData::RealArray* rarray = s_loop_data->RealArray_2D_64x64;
      rarray[i].id = i+1;
      Real_ptr data = allocAndInitData(rarray[i], data_len);

      s_loop_data->array_2D_64x64_Real[i] = new Real_ptr[64];
      for (Index_type k = 0; k < 64; ++k) {
         s_loop_data->array_2D_64x64_Real[i][k] = &data[k*64];
      }
   }

   //
   //  Allocate and initialize 3D 2 X loop length X 4 Real arrays.
   //
   for (unsigned i = 0; i < s_loop_data->s_num_3D_2xNx4_Real_arrays; ++i) {
      Index_type data_len = 2*aligned_chunksize*4;

      LoopData::RealArray* rarray = s_loop_data->RealArray_3D_2xNx4;
      rarray[i].id = i+1;
      Real_ptr data = allocAndInitData(rarray[i], data_len);

      s_loop_data->array_3D_2xNx4_Real[i] = new Real_ptr*[2];
      for (Index_type k = 0; k < 2; ++k) {
         s_loop_data->array_3D_2xNx4_Real[i][k] = new Real_ptr[aligned_chunksize];
      }

      for (Index_type k = 0; k < 2; ++k) {
         for (Index_type l = 0; l < aligned_chunksize; ++l) {
            s_loop_data->array_3D_2xNx4_Real[i][k][l] = &data[k*l*4];
         }
      }
   }


   //
   //  Initialize Real scalars.
   //
   s_loop_data->RealArray_scalars.id = 21;
   s_loop_data->RealArray_scalars.data = s_loop_data->scalar_Real;
   s_loop_data->RealArray_scalars.len = s_loop_data->s_num_Real_scalars;
   initData(s_loop_data->RealArray_scalars);

}

//
// Free arrays used in loop suite loop execution (allocated in routine above).
//
void freeLoopData()
{
   if ( s_loop_data != 0 )  return;
#ifdef TESTSUITE
   std::cout << "\n freeLoopData..." << std::endl;
#endif
   //
   //  De-allocate 1D loop length Real arrays.
   //
   for (unsigned i = 0; i < s_loop_data->s_num_1D_Real_arrays; ++i) {
#if defined(USE_PTR_CLASS)
      free( s_loop_data->array_1D_Real[i].get() );
#else
      free( s_loop_data->array_1D_Real[i] );
#endif
   }

   //
   //  De-allocate 1D loop length X 4 Real arrays.
   //
   for (unsigned i = 0; i < s_loop_data->s_num_1D_Nx4_Real_arrays; ++i) {
#if defined(USE_PTR_CLASS)
      free( s_loop_data->array_1D_Nx4_Real[i].get() );
#else
      free( s_loop_data->array_1D_Nx4_Real[i] );
#endif
   }

   //
   //  De-allocate 1D loop length Indx arrays.
   //
   for (unsigned i = 0; i < s_loop_data->s_num_1D_Indx_arrays; ++i) {
      free( s_loop_data->array_1D_Indx[i] );
   }

   //
   //  De-allocate 1D loop length Complex arrays.
   //
   for (unsigned i = 0; i < s_loop_data->s_num_1D_Complex_arrays; ++i) {
#if defined(USE_PTR_CLASS)
      free( s_loop_data->array_1D_Complex[i].get() );
#else
      free( s_loop_data->array_1D_Complex[i] );
#endif
   }

   //
   //  De-allocate 2D 7 X loop length Real arrays.
   //
   for (unsigned i = 0; i < s_loop_data->s_num_2D_7xN_Real_arrays; ++i) {
#if defined(USE_PTR_CLASS)
      free( s_loop_data->array_2D_7xN_Real[i][0].get() );
#else
      free( s_loop_data->array_2D_7xN_Real[i][0] );
#endif
      delete [] s_loop_data->array_2D_7xN_Real[i]; 
   }

   //
   //  De-allocate 2D 64 X 64 Real arrays.
   //
   for (unsigned i = 0; i < s_loop_data->s_num_2D_64x64_Real_arrays; ++i) {
#if defined(USE_PTR_CLASS)
      free( s_loop_data->array_2D_64x64_Real[i][0].get() );
#else
      free( s_loop_data->array_2D_64x64_Real[i][0] );
#endif
      delete [] s_loop_data->array_2D_64x64_Real[i]; 
   }

   //
   //  De-allocate and initialize 3D 2 X loop length X 4 Real arrays.
   //
   for (unsigned i = 0; i < s_loop_data->s_num_3D_2xNx4_Real_arrays; ++i) {
#if defined(USE_PTR_CLASS)
      free( s_loop_data->array_3D_2xNx4_Real[i][0][0].get() );
#else
      free( s_loop_data->array_3D_2xNx4_Real[i][0][0] );
#endif
      for (Index_type k = 0; k < 2; ++k) {
         delete [] s_loop_data->array_3D_2xNx4_Real[i][k]; 
      }
      delete [] s_loop_data->array_3D_2xNx4_Real[i]; 
   }

   delete s_loop_data;
   s_loop_data = 0;
}


//
// Implementations of file scope routines used to manage loop data 
// and checksums
//

namespace {


//
// Routines to allocate and initialize individual arrays consistently for 
// checking results.
//
Real_ptr allocAndInitData(LoopData::RealArray& ra, Index_type len)
{
   Real_ptr data = 0; 
   posix_memalign( (void **)&data, LCALS_DATA_ALIGN, len*sizeof(Real_type) );
   ra.data = data;
   ra.len = len; 

   initData(ra);

   return data;
}

Index_type* allocAndInitData(LoopData::IndxArray& ia, Index_type len)
{
   Index_type* data = 0;
   posix_memalign( (void **)&data, LCALS_DATA_ALIGN, len*sizeof(Index_type) );
   ia.data = data;
   ia.len = len;

   initData(ia);

   return data;
}

Complex_ptr allocAndInitData(LoopData::ComplexArray& ca, Index_type len)
{
   Complex_ptr data = new Complex_type[len];
   ca.data = data; 
   ca.len = len;

   initData(ca);

   return data;
}

void initData(LoopData::RealArray& ra)
{
   int id = ra.id;
   Real_type factor = ( id % 2 ? 0.1 : 0.2 );
   Real_ptr data = ra.data;
   Index_type totlen = ra.len;
#if defined(LCALS_OMP_MEM_INIT)
#pragma omp parallel for
   for (Index_type j = 0; j < totlen; ++j) {
      data[j] = factor*(j + 1.1)/(j + 1.12345);
   }
#else
   for (Index_type j = 0; j < totlen; ++j) {
      data[j] = factor*(j + 1.1)/(j + 1.12345);
   }
#endif
}

void initData(LoopData::IndxArray& ia)
{
   int id = ia.id;
   Index_type* data = ia.data;
   Index_type totlen = ia.len;
#if defined(LCALS_OMP_MEM_INIT)
#pragma omp parallel for
   for (Index_type j = 0; j < totlen; ++j) {
      data[j] = 0;
   }
#else
   for (Index_type j = 0; j < totlen; ++j) {
      data[j] = 0;
   }
#endif
}

void initData(LoopData::ComplexArray& ca)
{
   int id = ca.id;
   Complex_type factor = ( id % 2 ? Complex_type(0.1,0.2) : 
                                    Complex_type(0.2,0.3) );
   Complex_ptr data = ca.data;
   Index_type totlen = ca.len;
#if defined(LCALS_OMP_MEM_INIT)
#pragma omp parallel for
   for (Index_type j = 0; j < totlen; ++j) {
      data[j] = factor*(j + 1.1)/(j + 1.12345);
   }
#else
   for (Index_type j = 0; j < totlen; ++j) {
      data[j] = factor*(j + 1.1)/(j + 1.12345);
   }
#endif
}


//
// Routines to initialize loop check sum.
//
void initChksum(LoopStat& stat, LoopLength ilength)
{
   stat.loop_chksum[ilength] = 0.0;
}

//
// Routines to update loop check sum.
//
void updateChksum(LoopStat& stat, LoopLength ilength,
                  const LoopData::RealArray& ra,
                  Real_type scale_factor)
{
   Real_ptr data = ra.data;
   Index_type len = ra.len;
   long double tchk = stat.loop_chksum[ilength];
   for (Index_type j = 0; j < len; ++j) {
      tchk += (j+1)*data[j]*scale_factor;
   }
   stat.loop_chksum[ilength] = tchk;
}

void updateChksum(LoopStat& stat, LoopLength ilength,
                  Real_type val)
{
   stat.loop_chksum[ilength] += val;
}

void updateChksum(LoopStat& stat, LoopLength ilength,
                  const LoopData::ComplexArray& ca,
                  Real_type scale_factor)
{
   Complex_ptr data = ca.data;
   Index_type len = ca.len;
   long double tchk = stat.loop_chksum[ilength];
   for (Index_type j = 0; j < len; ++j) {
      tchk += (j+1)*(real(data[j])+imag(data[j]))*scale_factor;
   }
   stat.loop_chksum[ilength] = tchk;
}

}  // closing brace for unnamed namespace



//
// Recursively construct directories for given path name.
//
bool recursiveMkdir(const std::string& path)
{
   bool retval = true;

   mode_t mode = (S_IRUSR | S_IWUSR | S_IXUSR);
   const char separator = '/';

   int length = static_cast<int>(path.length());
   char* path_buf = new char[length + 1];
   sprintf(path_buf, "%s", path.c_str());
   struct stat status;
   int pos = length - 1;

   /* find part of path that has not yet been created */
   while ((stat(path_buf, &status) != 0) && (pos >= 0)) {

      /* slide backwards in string until next slash found */
      bool slash_found = false;
      while ((!slash_found) && (pos >= 0)) {
         if (path_buf[pos] == separator) {
            slash_found = true;
            if (pos >= 0) path_buf[pos] = '\0';
         } else pos--;
      }
   }

   /*
    * if there is a part of the path that already exists make sure
    * it is really a directory
    */
   if (pos >= 0) {
      if (!S_ISDIR(status.st_mode)) {
         std::cout << "Cannot create directories in path = " << path
                   << "\n    because some intermediate item in path exists and"
                   << "is NOT a directory" << std::endl;
         retval = false;
      }
   }

   /*
    * make all directories that do not already exist
    *
    * if (pos < 0), then there is no part of the path that
    * already exists.  Need to make the first part of the
    * path before sliding along path_buf.
    */
   if ( retval && pos < 0) {
      if (mkdir(path_buf, mode) != 0) {
         std::cout << "   Cannot create directory  = "
                   << path_buf << std::endl;
         retval = false;
      }
      pos = 0;
   }

   if ( retval ) {

      /* make remaining directories */
      do {

         /* slide forward in string until next '\0' found */
            bool null_found = false;
         while ((!null_found) && (pos < length)) {
            if (path_buf[pos] == '\0') {
               null_found = true;
            path_buf[pos] = separator;
            }
            pos++;
         }

         /* make directory if not at end of path */
         if (pos < length) {
            if (mkdir(path_buf, mode) != 0) {
              std::cout << "   Cannot create directory  = "
                        << path_buf << std::endl;
              retval = false;
            }
         }
      } while (pos < length && retval);

   }

   delete[] path_buf;

   return retval;
}
