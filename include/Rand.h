///\file
#ifndef __RAND_H
#define __RAND_H

///Base interface for the random stub used in robot and AI classes
class randstub {
  public:
   ///In child classes, function returns 0 or 1 depending on test or production
   virtual bool randvar() = 0;
};
#endif
