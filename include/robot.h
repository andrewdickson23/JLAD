///\file

#ifndef ROBOT_H
#define ROBOT_H

#include "robotInterface.h"
#include "robotType.h"
#include "Attachment.h"
#include <cstdlib>
#include <vector>
#include <string>

///Robot class for the robot battle arena game
class Robot : public RobotInterface{
  private:
   int strtHp;///<The default value for hp
   int strtDef;///<The default value for def
   int strtChg;///<The default value for chg
   int strtX;///<The default value for cordx
   int strtY;///<The default value for cordy
   int strtFuel;///<The default value for fuel
   int strtDefUse;///<The default value for defUse
   int hp; ///<Stores the robot's health points
   int spd; ///<Store the robot's speed stat
   int def; ///<Stores the robot's defence stat
   int atk; ///<Stores the robot's attack stat
   int chg; ///<Stores the robot's current charge level
   int load; ///<Stores the robot's current load of attachments
   int cap; ///<Stores the robot's weight capacity for attachments
   int rng; ///<Stores the distance away that this robot can attack
   int cordx; ///<Stores the x coordinate of the robot's location on the grid
   int cordy; ///<Stores the y coordinate of the robot's location on the grid
   robotType rtype;///<The type of robot to be selected
   bool type; ///<Stores whether or not robot is human (1) or AI (0)
   int defCap; ///<controls the cap for whether you can defend or not
   int defUse; ///<holds the number of times the player has defended
   int numMove; ///<holds the number of times the player can move in a turn
   std::string robName; ///<controls the name of the robot
   int fuel; ///<amount of fuel (how many total spaces it can move in a match)
   std::string description;///<description of the robot

   
  public:
   std::vector<attachment> resetArr;
   ///Robot
   ///\param[in] x (the desired x coordinate of the Robot)
   ///\param[in] y (the desired y coordinate of the Robot)
   ///\param[in] player (the type of player; human or AI)
   ///Constructor for robot class
   Robot(int x, int y, bool player, const std::string &nameConstruct, robotType rType);
   //mutators
   ///attack
   ///\param[in] R2 (the second robot object in the game; the attackee)
   ///\param[in] tester (1 if test AKA pseudo-random, 0 if production random)
   ///Attacks an enemy robot within range; uses one turn
   int attack(RobotInterface* R2, randstub* tester);
   ///defend
   ///Raises def stat of the robot by 1 point; uses one turn
   void defend();
   ///charge
   ///Adds one charge level to the robot's current charge; uses one turn
   void charge();
   ///takeDamage
   ///\param[in] amount (value of the damage to be taken by robot)
   ///Decrements HP by the value passed to it
   void takeDamage(int amount);
   ///changeX
   ///\param[in] shift (new x value for the robot's location)
   ///Changes the robot's x coordinate to the input value
   void changeX(int shift);
   ///changeY
   ///\param[in] shift (new y value for the robot's location)
   ///Changes the robot's y coordinate to the input value
   void changeY(int shift);
   ///attach
   ///\param[in] x (the attachment to be added to the robot)
   ///Adds an attachment to the robot to alter stats
   bool attach(attachment x);
   ///decMove
   ///After the player moves, this function is used to decrement the amount of 
   ///moves left for the player.
   void decMove();
   ///setMove
   ///Resets move variable to the maximum moves per turn for a specific robot
   void setMove();
   ///setDefault
   ///Resets stats that change in the course of the game to the default
   void setDefault();
   //accessors
   ///getAttack
   ///\Returns the integer variable atk (Robot's attack stat)
   int getAttack();
   ///getDefence
   ///\Returns the integer variable def (Robot's defence stat)
   int getDefence();
   ///getCharge
   ///\Returns the integer variable chg (Robot's charge count)
   int getCharge();
   ///getEvade
   ///\param[in] test (1 if test AKA pseudo-random, 0 if production random)
   ///\Returns a boolean value of whether or not the Robot will evade based on
   ///\speed stat and chance. 1 for evade, 0 for failure to evade.
   bool getEvade(randstub* test);
   ///getHP
   ///\Returns the integer variable hp (Robot's health point count)
   int getHP();
   ///getType
   ///\Returns the boolean variable type (1 for player, 0 for AI)
   bool getType();
   ///getRange
   ///\Returns the integer variable rng (Robot's attacking range)
   int getRange();
   ///getX
   ///\Returns the integer variable cordx (Robot's x coordinate)
   int getX();
   ///getY
   ///\Returns the integer variable cordy (Robot's y coordinate)
   int getY();
   ///getDefCap
   ///\Returns the integer variable defCap (Robot's cap on defence powerups)
   int getDefCap();
   ///getSpeed
   ///\Returns the integer variable spd (Robot's speed stat)
   int getSpeed();
   ///getLoad
   ///\Returns the current robot's load level
   int getLoad();
   ///getName
   ///\Returns the string stored for the name of the robot
   std::string getName();   
   ///getMove
   ///Returns the number of spaces remaining to move in a turn
   int getMove();
   ///getDefUse
   ///Returns the number of times the player has defended
   int getDefUse();
   ///getFuel
   ///Returns the amount of fuel left in the robot
   int getFuel();
   ///describe
   ///returns the description of the robot
   std::string describe();
   ///getCap
   ///Returns the carrying capacity of the robot
   int getCap();
   ///getResetArr
   ///return the array of attachments
   std::vector<attachment> getResetArr();
};

#endif
