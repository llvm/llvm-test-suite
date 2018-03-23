//
// See README-LCALS_license.txt for access and distribution restrictions
//

//
// Source file containing LCALS traversal method implementations 
// used in forall-hybrid loop variants.
//

#include "LCALSTraversalMethods.hxx"

#include <iostream>


/*
*************************************************************************
*
* HybridIndexSet class dtor.
*
*************************************************************************
*/
HybridIndexSet::~HybridIndexSet()
{
   const int num_segs = m_segments.size();
   for ( int isi = 0; isi < num_segs; ++isi ) {
      Segment& seg = m_segments[isi];

      switch ( seg.m_type ) {

         case _Range_ : {
            if ( seg.m_segment ) {
               RangeIndexSet* is =
                  const_cast<RangeIndexSet*>(
                     static_cast<const RangeIndexSet*>(seg.m_segment)
                  );
               delete is;
            }
            break;
         }

         case _RangeStride_ : {
            if ( seg.m_segment ) {
               RangeStrideIndexSet* is =
                  const_cast<RangeStrideIndexSet*>(
                     static_cast<const RangeStrideIndexSet*>(seg.m_segment)
                  );
               delete is;
            }
            break;
         }

         default : {
            std::cout << "\t HybridIndexSet dtor: case not implemented!!\n";
         }

      } // iterate over segments of hybrid index set
   }
}


/*
*************************************************************************
*
* Private helper function to copy hybrid index set segments.
*
*************************************************************************
*/
void HybridIndexSet::copySegments(const HybridIndexSet& other)
{
   const int num_segs = m_segments.size();
   for ( int isi = 0; isi < num_segs; ++isi ) {
      const Segment& seg = m_segments[isi];

      switch ( seg.m_type ) {

         case _Range_ : {
            addIndexSet(*static_cast<const RangeIndexSet*>(seg.m_segment));
            break;
         }

         case _RangeStride_ : {
            addIndexSet(*static_cast<const RangeStrideIndexSet*>(seg.m_segment));
            break;
         }

         default : {
            std::cout << "\t HybridIndexSet copySegments: case not implemented!!\n";
         }

      } // iterate over segments of hybrid index set
   }
}


/*
*************************************************************************
*
* Methods to add indices to hybrid index set.
*
*************************************************************************
*/

void HybridIndexSet::addIndexSet(const RangeIndexSet& index_set)
{
   RangeIndexSet* new_is =
      new RangeIndexSet(index_set.getBegin(), index_set.getEnd());
   m_segments.push_back( Segment( _Range_, new_is ) );

   m_len += new_is->getLength();
}

void HybridIndexSet::addRangeIndices(Index_type begin, Index_type end)
{
   RangeIndexSet* new_is = new RangeIndexSet(begin, end);
   m_segments.push_back( Segment( _Range_, new_is ) );

   m_len += new_is->getLength();
}

void HybridIndexSet::addIndexSet(const RangeStrideIndexSet& index_set)
{
   RangeStrideIndexSet* new_is =
      new RangeStrideIndexSet(index_set.getBegin(), index_set.getEnd(),
                              index_set.getStride());
   m_segments.push_back( Segment( _RangeStride_, new_is ) );

   m_len += new_is->getLength() / new_is->getStride();
}

void HybridIndexSet::addRangeStrideIndices(Index_type begin, Index_type end,
                                           Index_type stride)
{
   RangeStrideIndexSet* new_is = new RangeStrideIndexSet(begin, end, stride);
   m_segments.push_back( Segment( _RangeStride_, new_is ) );

   m_len += new_is->getLength() / new_is->getStride();
}
