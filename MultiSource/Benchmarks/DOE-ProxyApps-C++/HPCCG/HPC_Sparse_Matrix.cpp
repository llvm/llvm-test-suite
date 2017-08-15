#include "HPC_Sparse_Matrix.hpp"

#ifdef USING_MPI
#include <mpi.h>
#endif

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void destroyMatrix(HPC_Sparse_Matrix * &A)
{
  if(A->title)
  {
    delete [] A->title;
  }
  if(A->nnz_in_row)
  {
    delete [] A->nnz_in_row;
  }
  if(A->list_of_vals)
  {
    delete [] A->list_of_vals;
  }
  if(A->ptr_to_vals_in_row !=0)
  {
    delete [] A->ptr_to_vals_in_row;
  }
  if(A->list_of_inds)
  {
    delete [] A->list_of_inds;
  }
  if(A->ptr_to_inds_in_row !=0)
  {
    delete [] A->ptr_to_inds_in_row;
  }
  if(A->ptr_to_diags)
  {
    delete [] A->ptr_to_diags;
  }

#ifdef USING_MPI
  if(A->external_index)
  {
    delete [] A->external_index;
  }
  if(A->external_local_index)
  {
    delete [] A->external_local_index;
  }
  if(A->elements_to_send)
  {
    delete [] A->elements_to_send;
  }
  if(A->neighbors)
  {
    delete [] A->neighbors;
  }
  if(A->recv_length)
  {
    delete [] A->recv_length;
  }
  if(A->send_length)
  {
    delete [] A->send_length;
  }
  if(A->send_buffer)
  {
    delete [] A->send_buffer;
  }
#endif

  delete A;
  A = 0;
}
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#ifdef USING_SHAREDMEM_MPI
#ifndef SHAREDMEM_ALTERNATIVE
void destroySharedMemMatrix(HPC_Sparse_Matrix * &A)
{
  if(A==0)
  {
    return; //noop
  }

  if(A->title)
  {
    delete [] A->title;
  }

  if(A->nnz_in_row)
  {
    MPI_Comm_free_mem(MPI_COMM_NODE,A->nnz_in_row);
  }
  if(A->list_of_vals)
  {
    MPI_Comm_free_mem(MPI_COMM_NODE,A->list_of_vals);
  }
  if(A->ptr_to_vals_in_row !=0)
  {
    MPI_Comm_free_mem(MPI_COMM_NODE,A->ptr_to_vals_in_row);
  }
  if(A->list_of_inds)
  {
    MPI_Comm_free_mem(MPI_COMM_NODE,A->list_of_inds);
  }
  if(A->ptr_to_inds_in_row !=0)
  {
    MPI_Comm_free_mem(MPI_COMM_NODE,A->ptr_to_inds_in_row);
  }

  // currently not allocated with shared memory
  if(A->ptr_to_diags)
  {
    delete [] A->ptr_to_diags;
  }


#ifdef USING_MPI
  if(A->external_index)
  {
    delete [] A->external_index;
  }
  if(A->external_local_index)
  {
    delete [] A->external_local_index;
  }
  if(A->elements_to_send)
  {
    delete [] A->elements_to_send;
  }
  if(A->neighbors)
  {
    delete [] A->neighbors;
  }
  if(A->recv_length)
  {
    delete [] A->recv_length;
  }
  if(A->send_length)
  {
    delete [] A->send_length;
  }
  if(A->send_buffer)
  {
    delete [] A->send_buffer;
  }
#endif

  MPI_Comm_free_mem(MPI_COMM_NODE,A); A=0;

}
#endif
#endif
////////////////////////////////////////////////////////////////////////////////

