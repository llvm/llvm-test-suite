//
// See README-LCALS_license.txt for access and distribution restrictions
//

//
// Header file containing LCALS traversal method templates used with
// "forall" loop variants.
//
// Tag structs for traversal types are located in LCALSParams.hxx. 
//

#ifndef LCALSTraversalMethods_HXX
#define LCALSTraversalMethods_HXX

#include "LCALSParams.hxx"

#include <vector>


/*!
 ******************************************************************************
 *
 * \brief  Traverse contiguous range of indices using sequential execution.
 *
 ******************************************************************************
 */
template <typename LOOP_BODY>
LCALS_INLINE
void forall(seq_exec,
            Index_type begin, Index_type end, LOOP_BODY loop_body)
{
#pragma novector
   for ( Index_type ii = begin ; ii < end ; ++ii ) {
      loop_body( ii );
   }
}

/// with stride
template <typename LOOP_BODY>
LCALS_INLINE
void forall(seq_exec,
            Index_type begin, Index_type end, Index_type stride,
            LOOP_BODY loop_body)
{
#pragma novector
   for ( Index_type ii = begin ; ii < end ; ii += stride ) {
      loop_body( ii );
   }
}


/*!
 ******************************************************************************
 *
 * \brief  Traverse contiguous range of indices using SIMD vectorization.
 *         No assumption made on data alignment.
 *
 ******************************************************************************
 */
template <typename LOOP_BODY>
LCALS_INLINE
void forall(simd_exec,
            Index_type begin, Index_type end, LOOP_BODY loop_body)
{
   for ( Index_type ii = begin ; ii < end ; ++ii ) {
      loop_body( ii );
   }
}

/// with stride
template <typename LOOP_BODY>
LCALS_INLINE
void forall(simd_exec,
            Index_type begin, Index_type end, Index_type stride,
            LOOP_BODY loop_body)
{
   for ( Index_type ii = begin ; ii < end ; ii += stride ) {
      loop_body( ii );
   }
}


/*!
 ******************************************************************************
 *
 * \brief  Traverse contiguous range of indices using OpenMP parallel for.
 *
 ******************************************************************************
 */
template <typename LOOP_BODY>
LCALS_INLINE
void forall(omp_parallel_for_exec,
            Index_type begin, Index_type end, LOOP_BODY loop_body)
{
//#pragma omp parallel for schedule(static)
#pragma omp parallel for
   for ( Index_type ii = begin ; ii < end ; ++ii ) {
      loop_body( ii );
   }
}

/// with stride
template <typename LOOP_BODY>
LCALS_INLINE
void forall(omp_parallel_for_exec,
            Index_type begin, Index_type end, Index_type stride,
            LOOP_BODY loop_body)
{
//#pragma omp parallel for schedule(static)
#pragma omp parallel for
   for ( Index_type ii = begin ; ii < end ; ii += stride ) {
      loop_body( ii );
   }
}


/*!
 ******************************************************************************
 *
 * \brief  Traverse contiguous range of indices using OpenMP for with
 *         nowait clause.
 *
 ******************************************************************************
 */
template <typename LOOP_BODY>
LCALS_INLINE
void forall(omp_for_nowait_exec,
            Index_type begin, Index_type end, LOOP_BODY loop_body)
{
//#pragma omp for nowait schedule(static)
#pragma omp for nowait
   for ( Index_type ii = begin ; ii < end ; ++ii ) {
      loop_body( ii );
   }
}

/// with stride
template <typename LOOP_BODY>
LCALS_INLINE
void forall(omp_for_nowait_exec,
            Index_type begin, Index_type end, Index_type stride,
            LOOP_BODY loop_body)
{
//#pragma omp for nowait schedule(static)
#pragma omp for nowait
   for ( Index_type ii = begin ; ii < end ; ii += stride ) {
      loop_body( ii );
   }
}


/*!
 ******************************************************************************
 *
 * \brief  Class representing a contiguous range of indices.
 *
 *         Range is specified by begin and end values.
 *         Traversal executes as:
 *            for (i = m_begin; i < m_end; ++i) {
 *               expression using i as array index.
 *            }
 *
 ******************************************************************************
 */
class RangeIndexSet
{
public:

   RangeIndexSet(Index_type begin, Index_type end)
     : m_begin(begin), m_end(end) { ; }

   Index_type getBegin() const { return m_begin; }
   Index_type getEnd() const { return m_end; }

   Index_type getLength() const { return (m_end-m_begin); }

   void print(std::ostream& os) const;

private:
   //
   // The default ctor is not implemented.
   //
   RangeIndexSet();

   Index_type m_begin;
   Index_type m_end;
};


/*!
 ******************************************************************************
 *
 * \brief  Class representing a contiguous range of indices with stride.
 *
 *         Range is specified by begin and end values.
 *         Traversal executes as:
 *            for (i = m_begin; i < m_end; i = i + m_stride) {
 *               expression using i as array index.
 *            }
 *
 ******************************************************************************
 */
class RangeStrideIndexSet
{
public:

   RangeStrideIndexSet(Index_type begin, Index_type end, Index_type stride)
     : m_begin(begin), m_end(end), m_stride(stride) { ; }

   Index_type getBegin() const { return m_begin; }
   Index_type getEnd() const { return m_end; }
   Index_type getStride() const { return m_stride; }

   Index_type getLength() const { return (m_end-m_begin); }

   void print(std::ostream& os) const;

private:
   //
   // The default ctor is not implemented.
   //
   RangeStrideIndexSet();

   Index_type m_begin;
   Index_type m_end;
   Index_type m_stride;
};


/*!
 ******************************************************************************
 *
 * \brief  Traversal methods for index set objects passed as arguments.
 *
 ******************************************************************************
 */
/// RangeIndexSet object
template <typename EXEC_T, typename LOOP_BODY>
LCALS_INLINE
void forall(EXEC_T exec,
            const RangeIndexSet& is, LOOP_BODY loop_body)
{
   forall( exec,
           is.getBegin(), is.getEnd(), loop_body );
}

/// RangeStrideIndexSet object
template <typename EXEC_T, typename LOOP_BODY>
LCALS_INLINE
void forall(EXEC_T exec,
            const RangeStrideIndexSet& is, LOOP_BODY loop_body)
{
   forall( exec,
           is.getBegin(), is.getEnd(), is.getStride(), loop_body );
}


/*!
 ******************************************************************************
 *
 * \brief  Class representing a hybrid index set which is a collection
 *         of index set objects defined above.  Within a hybrid, the
 *         individual index sets are referred to as segments.
 *
 *  NOTE: This class is an abreviated version of the actual RAJA class.
 *
 ******************************************************************************
 */
class HybridIndexSet
{
public:

   ///
   /// Enum describing types of segments in hybrid index set.
   ///
   enum SegmentType { _Range_, _RangeStride_, _Unknown_ };

   ///
   /// Class holding segment and segment type.
   ///
   class Segment
   {
   public:

      Segment()
         : m_type(_Unknown_), m_segment(0) { ; }

      Segment(SegmentType type,  const void* segment)
         : m_type(type), m_segment(segment) { ; }

      SegmentType m_type;
      const void* m_segment;

   };

   ///
   /// Construct empty hybrid index set
   ///
   HybridIndexSet() 
   : m_len(0) { ; }  

   //
   // Copy-constructor for hybrid index set
   //
   HybridIndexSet(const HybridIndexSet& other)
   : m_len(0)
   {
      copySegments(other);
   } 

   //
   // Copy-assignment for hybrid index set
   //
   HybridIndexSet& operator=(const HybridIndexSet& rhs)
   {
      if (this != &rhs) {
      copySegments(rhs);
      }
      return *this;
   }

   ///
   /// Hybrid index set destructor destroys all index set segments.
   ///
   ~HybridIndexSet();

   ///
   /// Create copy of given RangeIndexSet and add to hybrid index set.
   ///
   void addIndexSet(const RangeIndexSet& index_set);

   ///
   /// Add contiguous range of indices to hybrid index set as a RangeIndexSet.
   ///
   void addRangeIndices(Index_type begin, Index_type end);

   ///
   /// Create copy of given RangeStrideIndexSet and add to hybrid index set.
   ///
   void addIndexSet(const RangeStrideIndexSet& index_set);

   ///
   /// Add contiguous range of indices with stride to hybrid index set
   /// as a RangeStrideIndexSet.
   ///
   void addRangeStrideIndices(Index_type begin, Index_type end, Index_type stride);

   ///
   /// Return total length of hybrid index set; i.e., sum of lengths
   /// over all segments.
   ///
   Index_type getLength() const { return m_len; }

   ///
   /// Return total number of segments in hybrid index set.
   ///
   int getNumSegments() const { return m_segments.size(); }

   ///
   /// Return total number of segments in hybrid index set.
   ///
   const Segment* getSegments() const { return &m_segments[0]; }

private:
   //
   // Copy segments (deep copy) from given HybridIndexSet object.
   //
   void copySegments(const HybridIndexSet& other);

   Index_type  m_len;
   std::vector<Segment> m_segments;

};


/*!
 ******************************************************************************
 *
 * \brief  Iterate over segments sequentially, and use exec policy
 *         specified by template parameter for individual segments.
 *
 ******************************************************************************
 */
template <typename EXEC_T, typename LOOP_BODY>
LCALS_INLINE
void forall(EXEC_T exec,
            const HybridIndexSet& is, LOOP_BODY loop_body)
{
   const int num_seg = is.getNumSegments();
   const HybridIndexSet::Segment* seg = is.getSegments();
   for ( int isi = 0; isi < num_seg; ++isi ) {

      switch ( seg[isi].m_type ) {

         case HybridIndexSet::_Range_ : {
            forall(exec,
               *(static_cast<const RangeIndexSet*>(seg[isi].m_segment)),
               loop_body
            );
            break;
         }

         case HybridIndexSet::_RangeStride_ : {
            forall(exec,
               *(static_cast<const RangeStrideIndexSet*>(seg[isi].m_segment)),
               loop_body
            );
            break;
         }

         default : {
         }

      }  // switch on segment type

   } // iterate over segments of hybrid index set
}



/*!
 ******************************************************************************
 *
 * \brief Generic methods with exec policy specified by template 
 *        parameter.
 *
 ******************************************************************************
 */
template <typename EXEC_T, typename LOOP_BODY>
LCALS_INLINE
void forall(Index_type begin, Index_type end, LOOP_BODY loop_body)
{
   forall( EXEC_T(), begin, end, loop_body );
}

/// with stride
template <typename EXEC_T, typename LOOP_BODY>
LCALS_INLINE
void forall(Index_type begin, Index_type end, Index_type stride,
            LOOP_BODY loop_body)
{
   forall( EXEC_T(), begin, end, stride, loop_body );
}

/// passing index set object
template <typename EXEC_T,
          typename INDEXSET_T, typename LOOP_BODY>
LCALS_INLINE
void forall(const INDEXSET_T& is, LOOP_BODY loop_body)
{
   forall(EXEC_T(), is, loop_body);
}


#endif  // closing endif for header file include guard
