! { dg-do compile }
module m
contains
   subroutine s
      print *, (erfc) ! { dg-error "not a floating constant" "" { target i?86-*-* x86_64-*-* sparc*-*-* cris-*-* hppa*-*-* } }
   end ! { dg-error "not a floating constant" "" { target { ! "i?86-*-* x86_64-*-* sparc*-*-* cris-*-* hppa*-*-*" } } }
   function erfc()
   end
end
