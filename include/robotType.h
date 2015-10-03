///\file
#ifndef __ROBOTTYPE_H
#define __ROBOTTYPE_H
#include<string>

///Robot type interface for the strategy pattern used to pick robots
class robotTypeInterface {
  public:
   ///returns the charge of the robot type chosen
   virtual int getChg() = 0;
   ///returns the load of the robot type chosen
   virtual int getLoad() = 0;
   ///returns the capacity of the robot type chosen
   virtual int getCap() = 0;
   ///returns the defending cap of the robot chosen
   virtual int getDefCap() = 0;
   ///returns the defending use of the robot chosen
   virtual int getDefUse() = 0;
   ///returns the range of the robot chosen
   virtual int getRng() = 0;
   ///returns the fuel capacity of the robot chosen
   virtual int getFuel() = 0;
   ///returns the health points of the robot chosen
   virtual int getHp() = 0;
   ///returns the speed of the robot chosen
   virtual int getSpd() = 0;
   ///returns the defense of the robot chosen
   virtual int getDef() = 0;
   ///returns the attack of the robot chosen
   virtual int getAtk() = 0;
   ///returns the description of the robot type chosen
   virtual std::string getDescription() = 0;
   ///destructor for the robotTypeInterface
   virtual ~robotTypeInterface() { }

};

typedef robotTypeInterface * robotType;
 #endif
