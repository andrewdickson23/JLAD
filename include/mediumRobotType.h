/// \file
#ifndef __MEDIUMROBOTTYPE_H
#define __MEDIUMROBOTTYPE_H
#include<string>
#include "robotType.h"

///Medium robot type strategy pattern
class mediumRobotType : public robotTypeInterface {
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

   ///Constructor used to initialize the medium robot stat values
   mediumRobotType() {
      chg = 7;
      load = 0;
      cap = 7;
      defCap = 5;
      defUse = 0;
      rng = 1;
      fuel = 200;
      
      hp = 150;
      spd = 10;
      def = 15;
      atk = 15;

      std::string a = "";
      description = a+
	  " A jack of all trades, this robot has standard specifications \n"+
	 " with mid range speed, defence capabilities, attack power, \n"+
	 " carrying capacity, fuel capacity, and health points. \n \n"+
	 " HP = 150 \n"+
	 " Speed = 10 \n"+
	 " Defence = 15 \n"+
	 " Attack = 15 \n"+
	 " Carrying Capacity = 7 \n"+
	 " Fuel Capacity = 200 \n";
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
