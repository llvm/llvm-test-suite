/**********************************************************************
Copyright ©2013 Advanced Micro Devices, Inc. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

•	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
•	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or
 other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
********************************************************************/


#pragma OPENCL EXTENSION cl_khr_local_int32_base_atomics : enable

__kernel void read_kernel ( __global uint4 *in,
                            __global uint  *out,
                                     uint   ni,
                                     uint   val,
                                     uint   nk )
{
   if( nk == 0 ) return;
   
           uint pcount = 0;
   __local uint lcount;
           uint i, idx;

   if( get_local_id(0) == 0)
       lcount=0;

   barrier( CLK_LOCAL_MEM_FENCE );

   for(int n=0; n<nk; n++)
      for( i=0, idx=get_global_id(0); i<ni; i++, idx+=get_global_size(0) )
      {
         if(in[idx].x == val) pcount++;
         if(in[idx].y == val) pcount++;
         if(in[idx].z == val) pcount++;
         if(in[idx].w == val) pcount++;
      }
      
     (void) atomic_add( &lcount, pcount );

     barrier( CLK_LOCAL_MEM_FENCE );

     if( get_local_id(0) == 0 )
        out[get_group_id(0)] = lcount/nk;
}

__kernel void write_kernel ( __global uint  *in,
                             __global uint4 *out,
                                      uint  ni,
                                      uint  val,
                                      uint  nk )
{
   if( nk == 0 ) return;
   
   uint i, idx;
   uint4 pval = (uint4) (val, val, val, val);

   for(int n=0; n<nk; n++)
      for( i=0, idx=get_global_id(0); i<ni; i++, idx+=get_global_size(0) )
      {
         out[idx] = pval;
      }
}

                                  

