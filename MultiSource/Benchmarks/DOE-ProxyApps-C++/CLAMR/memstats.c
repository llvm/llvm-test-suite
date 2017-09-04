/*
 *  Copyright (c) 2011-2012, Los Alamos National Security, LLC.
 *  All rights Reserved.
 *
 *  Copyright 2011-2012. Los Alamos National Security, LLC. This software was produced 
 *  under U.S. Government contract DE-AC52-06NA25396 for Los Alamos National 
 *  Laboratory (LANL), which is operated by Los Alamos National Security, LLC 
 *  for the U.S. Department of Energy. The U.S. Government has rights to use, 
 *  reproduce, and distribute this software.  NEITHER THE GOVERNMENT NOR LOS 
 *  ALAMOS NATIONAL SECURITY, LLC MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR 
 *  ASSUMES ANY LIABILITY FOR THE USE OF THIS SOFTWARE.  If software is modified
 *  to produce derivative works, such modified software should be clearly marked,
 *  so as not to confuse it with the version available from LANL.
 *
 *  Additionally, redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Los Alamos National Security, LLC, Los Alamos 
 *       National Laboratory, LANL, the U.S. Government, nor the names of its 
 *       contributors may be used to endorse or promote products derived from 
 *       this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE LOS ALAMOS NATIONAL SECURITY, LLC AND 
 *  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT 
 *  NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL LOS ALAMOS NATIONAL
 *  SECURITY, LLC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *  
 *  CLAMR -- LA-CC-11-094
 *  This research code is being developed as part of the 
 *  2011 X Division Summer Workshop for the express purpose
 *  of a collaborative code for development of ideas in
 *  the implementation of AMR codes for Exascale platforms
 *  
 *  AMR implementation of the Wave code previously developed
 *  as a demonstration code for regular grids on Exascale platforms
 *  as part of the Supercomputing Challenge and Los Alamos 
 *  National Laboratory
 *  
 *  Authors: Bob Robey       XCP-2   brobey@lanl.gov
 *           Neal Davis              davis68@lanl.gov, davis68@illinois.edu
 *           David Nicholaeff        dnic@lanl.gov, mtrxknight@aol.com
 *           Dennis Trujillo         dptrujillo@lanl.gov, dptru10@gmail.com
 * 
 */
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <unistd.h>
#include <string.h>

#ifdef __APPLE_CC__
#include <mach/mach_host.h>
#include <mach/task.h>
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "memstats.h"

pid_t pid;
FILE *stat_fp = NULL, *meminfo_fp = NULL;

long long memstats_memused(){
   long long mem_current=0;
#ifdef __APPLE_CC__
/* This is all memory used and we want the memory for only our process -- do alternate
   vm_size_t page_size;
   mach_port_t mach_port;
   mach_msg_type_number_t count = HOST_VM_INFO_COUNT;

   host_page_size(mach_port, &page_size);
   vm_statistics_data_t vmstat;
   host_statistics (mach_host_self (), HOST_VM_INFO, (host_info_t) &vmstat, &count);

   mem_current = (vmstat.wire_count + vmstat.active_count + vmstat.inactive_count)*page_size/1024;
*/

   struct task_basic_info t_info;
   mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;
   task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&t_info, &t_info_count);

   mem_current = t_info.resident_size;
#else
   char proc_stat_file[50];
   char *p;
   int err;
   int memdebug = 0;
   //long long page_size = 1; //4096

   if (!stat_fp){
      pid = getpid();
      sprintf(proc_stat_file, "/proc/%d/status", pid);
      stat_fp = fopen(proc_stat_file, "r");
      if (!stat_fp){
         //printf("fopen %s failed: \n", proc_stat_file);
         return(-1);
      }
   }

   err = fflush(stat_fp);
   if (err) {
      printf("fflush %s failed: %s\n", proc_stat_file, strerror(err));
      return(-1);
   }
   err = fseek(stat_fp, 0L, 0);
   if (err) {
      printf("fseek %s failed: %s\n", proc_stat_file, strerror(err));
      return(-1);
   }

   char *str = (char *)malloc(140*sizeof(char));
   while (!feof(stat_fp)){
      str = fgets(str, 132, stat_fp);
      if (str == NULL){
         printf("Warning: Error in reading %s for memory stats\n",proc_stat_file);
      }
      p = strtok(str,":");
      //printf("p is |%s|\n",p);
      if (!strcmp(p, "VmRSS")) {
         p = strtok('\0'," ");
         p = strtok('\0'," ");
         //mem_current = atoll(p)*1024; // Size is in kB 
         mem_current = atoll(p); // Size is in kB 
         if (memdebug) {
            printf("VmRSS %lld\n",mem_current);
         }
         break;
      }
   }
   free(str);

   fclose(stat_fp);
   stat_fp = NULL;
#endif

   return(mem_current);
}

long long memstats_mempeak(){
   char proc_stat_file[50];
   char *p;
   int err;
   int memdebug = 0;
   long long mem_current=0;
   //long long page_size = 1; //4096

   if (!stat_fp){
      pid = getpid();
      sprintf(proc_stat_file, "/proc/%d/status", pid);
      stat_fp = fopen(proc_stat_file, "r");
      if (!stat_fp){
         //printf("fopen %s failed: \n", proc_stat_file);
         return(-1);
      }
   }

   err = fflush(stat_fp);
   if (err) {
      printf("fflush %s failed: %s\n", proc_stat_file, strerror(err));
      return(-1);
   }
   err = fseek(stat_fp, 0L, 0);
   if (err) {
      printf("fseek %s failed: %s\n", proc_stat_file, strerror(err));
      return(-1);
   }

   char *str = (char *)malloc(140*sizeof(char));
   while (!feof(stat_fp)){
      str = fgets(str, 132, stat_fp);
      if (str == NULL){
         printf("Warning: Error in reading %s for memory stats\n",proc_stat_file);
      }
      p = strtok(str,":");
      //printf("p is |%s|\n",p);
      if (!strcmp(p, "VmHWM")) {
         p = strtok('\0'," ");
         p = strtok('\0'," ");
         //mem_current = atoll(p)*1024; // Size is in kB 
         mem_current = atoll(p); // Size is in kB 
         if (memdebug) {
            printf("VmRSS %lld\n",mem_current);
         }
         break;
      }
   }

   fclose(stat_fp);
   stat_fp = NULL;
   free(str);

   return(mem_current);
}

#define TIMER_ONEK 1024
long long memstats_memfree(){
   long long freemem;
#ifdef __APPLE_CC__
   vm_size_t page_size;
   mach_port_t mach_port;
   mach_msg_type_number_t count = HOST_VM_INFO_COUNT;

   mach_port = mach_host_self();
   host_page_size(mach_port, &page_size);
   vm_statistics64_data_t vmstat;
   host_statistics64 (mach_port, HOST_VM_INFO, (host_info_t) &vmstat, &count);

   freemem = vmstat.free_count*page_size/1024;
#else
   int err;
   int memdebug = 0;
   char buf[260];
   char *p;

   freemem = -1;

   if (!meminfo_fp){
      meminfo_fp = fopen("/proc/meminfo", "r");
      if (!meminfo_fp){
         printf("fopen failed: \n");
         return(-1);
      }
   }

   err = fflush(meminfo_fp);
   if (err) {
      printf("fflush failed: %s\n", strerror(err));
      return(-1);
   }
   err = fseek(meminfo_fp, 0L, 0);
   if (err) {
      printf("fseek failed: %s\n", strerror(err));
      return(-1);
   }

   while (!feof(meminfo_fp)) {
      if (fgets(buf, 255, meminfo_fp)) { /* read header */
         //printf("buf is %s\n",buf);
         p = strtok(buf, ":");
         if (memdebug){
            printf("p: |%s|\n",p);
         }
         if (!strcmp(p, "MemFree")) {
            p = strtok('\0', " ");
            //printf("p is %s\n",p);
            freemem = atoll(p); // in kB
            break;
         }
      }
   }

   //return(freemem+cachedmem);

   fclose(meminfo_fp);
   meminfo_fp = NULL;
#endif

   return(freemem);
}

long long memstats_memtotal(){
   long long totalmem;
#ifdef __APPLE_CC__
/*
   vm_size_t page_size;
   mach_port_t mach_port;
   mach_msg_type_number_t count = HOST_VM_INFO_COUNT;

   host_page_size(mach_port, &page_size);
   vm_statistics_data_t vmstat;
   host_statistics (mach_host_self (), HOST_VM_INFO, (host_info_t) &vmstat, &count);

   totalmem = (vmstat.wire_count + vmstat.active_count + vmstat.inactive_count + vmstat.free_count)
              *page_size/1024;
*/
// alternate
   int mib[2];
   mib[0] = CTL_HW;
   mib[1] = HW_MEMSIZE;
   size_t length = sizeof(long long);
   sysctl(mib, 2, &totalmem, &length, NULL, 0);
   totalmem /= 1024;
#else
   int err;
   int memdebug = 0;
   char buf[260];
   char *p;

   totalmem = -1;

   if (!meminfo_fp){
      meminfo_fp = fopen("/proc/meminfo", "r");
      if (!meminfo_fp){
         printf("fopen failed: \n");
         return(-1);
      }
   }

   err = fflush(meminfo_fp);
   if (err) {
      printf("fflush failed: %s\n", strerror(err));
      return(-1);
   }
   err = fseek(meminfo_fp, 0L, 0);
   if (err) {
      printf("fseek failed: %s\n", strerror(err));
      return(-1);
   }

   while (!feof(meminfo_fp)) {
      if (fgets(buf, 255, meminfo_fp)) { /* read header */
         //printf("buf is %s\n",buf);
         p = strtok(buf, ":");
         if (memdebug){
            printf("p: |%s|\n",p);
         }
         if (!strcmp(p, "MemTotal")) {
            p = strtok('\0', " ");
            //printf("p is %s\n",p);
            totalmem = atoll(p); // in kB
            break;
         }
      }
   }

   fclose(meminfo_fp);
   meminfo_fp = NULL;
#endif

   return(totalmem);
}

