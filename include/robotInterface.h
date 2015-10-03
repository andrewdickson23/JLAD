///\file
#ifndef ROBOT_INTERFACE_H
#define ROBOT_INTERFACE_H
#include "RandNorm.h"
#include <string>
#include <vector>
#include "ConcreteTile.h"
#include "Attachment.h"

///Robot interface for the robot battle arena game
class RobotInterface{

  public:
   virtual ~RobotInterface() { }
//mutators
   ///attack
   ///\param[in] R2 (the second robot object in the game; the attackee)
   ///\param[in] tester (1 if test AKA pseudo-random, 0 if production random)
   ///Attacks an enemy robot within range; uses one turn
   virtual int attack(RobotInterface* R2, randstub* tester) = 0;
   ///defend
   ///Raises def stat of the robot by 1 point; uses one turn
   virtual void defend() = 0;
   ///charge
   ///Adds one charge level to the robot's current charge; uses one turn
   virtual void charge() = 0;
   ///takeDamage
   ///\param[in] amount (value of the damage to be taken by robot)
   ///Decrements HP by the value passed to it
   virtual void takeDamage(int amount) = 0;
   ///changeX
   ///\param[in] shift (new x value for the robot's location)
   ///Changes the robot's x coordinate to the input value
   virtual void changeX(int shift) = 0;
   ///changeY
   ///\param[in] shift (new y value for the robot's location)
   ///Changes the robot's y coordinate to the input value
   virtual void changeY(int shift) = 0;
   ///attach
   ///\param[in] x (the attachment to be added to the robot)
   ///Adds an attachment to the robot to alter stats
   virtual bool attach(attachment x) = 0;
   ///decMove
   ///After the player moves, this function is used to decrement the amount of 
   ///moves left for the player.
   virtual void decMove() = 0;
   ///setMove
   ///Resets move variable to the maximum moves per turn for a specific robot
   virtual void setMove() = 0;
   ///setDefault
   ///Resets stats that change in the course of the game to the default
   virtual void setDefault() = 0;
//accessors
   ///getAttack
   ///\Returns the integer variable atk (Robot's attack stat)
   virtual int getAttack() = 0;
   ///getDefence
   ///\Returns the integer variable def (Robot's defence stat)
   virtual int getDefence() = 0;
   ///getCharge
   ///\Returns the integer variable chg (Robot's charge count)
   virtual int getCharge() = 0;
   ///getEvade
   ///\param[in] test (1 if test AKA pseudo-random, 0 if production random)
   ///\Returns a boolean value of whether or not the Robot will evade based on
   ///\speed stat and chance. 1 for evade, 0 for failure to evade.
   virtual bool getEvade(randstub* test) = 0;
   ///getHP
   ///\Returns the integer variable hp (Robot's health point count)
   virtual int getHP() = 0;
   ///getType
   ///\Returns the boolean variable type (1 for player, 0 for AI)
   virtual bool getType() = 0;
   ///getRange
   ///\Returns the integer variable rng (Robot's attacking range)
   virtual int getRange() = 0;
   ///getX
   ///\Returns the integer variable cordx (Robot's x coordinate)
   virtual int getX() = 0;
   ///getY
   ///\Returns the integer variable cordy (Robot's y coordinate)
   virtual int getY() = 0;
   ///getDefCap
   ///\Returns the integer variable defCap (Robot's cap on defence powerups)
   virtual int getDefCap() = 0;
   ///getLoad
   ///\Returns the current load capacatiy
   virtual int getLoad() = 0;
   ///getSpeed
   ///\Returns the integer variable spd (Robot's speed stat)
   virtual int getSpeed() = 0;
   ///getName
   ///\Returns the string stored for the name of the robot
   virtual std::string getName() = 0;   
   ///getMove
   ///Returns the number of spaces remaining to move in a turn
   virtual int getMove() = 0;
   ///getDefUse
   ///Returns the number of times the player has defended
   virtual int getDefUse() = 0;
   ///getFuel
   ///Returns the amount of fuel left in the robot
   virtual int getFuel() = 0;
   ///describe
   ///returns the description of the robot
   virtual std::string describe() = 0;
   ///getCap
   ///Returns the carrying capacity of the robot
   virtual int getCap() = 0;
   ///getResetArr
   ///return the array of attachments
   virtual std::vector<attachment> getResetArr() = 0;
};
#endif
