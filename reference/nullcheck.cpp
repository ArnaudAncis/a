#ifndef NDEBUG
#define NULLCHECK(p) \
  if ( !p ) abort( #p " should not be zero" )
#else
#define NULLCHECK(p)
#endif
