///\file
#ifndef RANDNORM_H
#define RANDNORM_H

#include "Rand.h"

///Random stub used to initialize real random in production code
class randnorm : public randstub {
  public:
   ///Function used to return a 0 to tell the code that it's not a test
   virtual bool randvar();
};
#endif
