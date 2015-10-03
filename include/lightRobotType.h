/// \file
#ifndef __LIGHTROBOTTYPE_H
#define __LIGHTROBOTTYPE_H
#include<string>
#include "robotType.h"

///Light robot type strategy pattern
class lightRobotType : public robotTypeInterface {
  public:
   int chg;///<Stores the robot's current charge level
   int load;///<Stores the robot's current load of attachments
   int cap;///<Stores the robot's weight capacity for attachments
   int defCap;///<controls the cap for whether you can defend or not
   int defUse;///<holds the number of times the player has defended
   int fuel;///<amount of fuel (how many total spaces it can move in a match)
   int hp;///<Stores the robot's health points
   int spd;///<Store the robot's speed stat
   int def;///<Stores the robot's defence stat
   int atk;///<Stores the robot's attack stat
   int rng;///<Stores the distance away that this robot can attack
   std::string description;///<description of the robot

   ///Constructor used to initialize light robot stat values
   lightRobotType() {
      chg = 5;
      load = 0;
      cap = 5;
      defCap = 5;
      defUse = 0;
      rng = 1;
      fuel = 250;
      
      hp = 100;
      spd = 20;
      def = 10;
      atk = 10;

      std::string a = "";
      description = a+
	 " Modeled after Slenderman, this robot has long spindly legs that \n"+
	 " give it a longer stride and the ability to surprise even the \n"+
	 " largest of foes with it's high speed and evasive ability. \n"+
	 " With it's enhanced movement, it was also designed to hold more \n"+
	 " fuel. With all those perks, the slim build of this robot makes \n"+
	 " it have a harder time defending against attacks and lower health \n"+
	 " in addition to low attack power and low carrying capacity. \n \n"+
	 " HP = 100 \n"+
	 " Speed = 20 \n"+
	 " Defence = 10 \n"+
	 " Attack = 10 \n"+
	 " Carrying Capacity = 5 \n"+
	 " Fuel Capacity = 250 \n";
   }

   ///returns the charge of the robot type chosen
   int getChg() {return chg;}
   ///returns the load of the robot type chosen
   int getLoad() {return load;}
   ///returns the capacity of the robot type chosen
   int getCap() {return cap;}
   ///returns the defending cap of the robot chosen
   int getDefCap() {return defCap;}
   ///returns the defending use of the robot chosen
   int getDefUse() {return defUse;}
   ///returns the range of the robot chosen
   int getRng() {return rng;}
   ///returns the fuel capacity of the robot chosen
   int getFuel() {return fuel;}
   ///returns the health points of the robot chosen
   int getHp() {return hp;}
   ///returns the speed of the robot chosen
   int getSpd() {return spd;}
   ///returns the defense of the robot chosen
   int getDef() {return def;}
   ///returns the attack of the robot chosen
   int getAtk() {return atk;}
   ///returns the description of the robot type chosen
   std::string getDescription() {return description;}
   
};

#endif
