///\file
#ifndef __RANDTEST_H
#define __RANDTEST_H

#include "Rand.h"
///Random stub used to initialize pseudo random in the test code
class randtest : public randstub {
  public:
   ///Function used to return a 1 to tell the code that it's a test
   virtual bool randvar();
};
#endif
