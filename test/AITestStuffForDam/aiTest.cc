#ifndef ROBOT_INTERFACE_H
#define ROBOT_INTERFACE_H

class RobotInterface{
   //mutators
   virtual void attack(RobotInterface* R2) = 0;
   virtual void defend() = 0;
   virtual void charge() = 0;
   //accessors
   virtual int getAttack() = 0;
   virtual int getDefence() = 0;
   virtual int getCharge() = 0;
   virtual bool getEvade() = 0;
   virtual int getHP() = 0;
   virtual bool getType() = 0;
   virtual int getRange() = 0;
   virtual int getX() = 0;
   virtual int getY() = 0;
};
#endif

#ifndef ROBOT_H
#define ROBOT_H
#include "robotInterface.h"
#include <cstdlib>

class Robot : public RobotInterface{
  private:
   int hp; //<Stores the robot's health points
   int spd; //<Store the robot's speed stat
   int def; //<Stores the robot's defence stat
   int atk; //<Stores the robot's attack stat
   int chg; //<Stores the robot's current charge level
   int load; //<Stores the robot's current load of attachments
   int cap; //<Stores the robot's weight capacity for attachments
   int rng; //<Stores the distance away that this robot can attack
   int cordx; //<Stores the x coordinate of the robot's location on the grid
   int cordy; //<Stores the y coordinate of the robot's location on the grid
   bool type; //<Stores whether or not robot is player (1) or AI (0)
   
  public:
   ///Constructor for robot class
   Robot(int x, int y, bool player);
   //mutators
   ///Attacks an enemy robot within range; uses one turn
   void attack(Robot* R2);
   ///Defends against a possible enemy attack, eliminating damage; uses one turn
   void defend();
   ///Adds one charge level to the robot's current charge; uses one turn
   void charge();
   //accessors
   ///Returns the robot's attack stat
   int getAttack();
   ///Returns the robot's defence stat
   int getDefence();
   ///Returns the robot's current charge level
   int getCharge();
   ///Returns the robot's evasive chance
   bool getEvade();
   ///Returns the robot's health points
   int getHP();
   ///Returns the player type of the robot
   bool getType();
   ///Returns the robot's attack range
   int getRange();
   ///Returns the robot's x coordinate on the grid
   int getX();
   ///Returns the robot's y coordinate on the grid
   int getY();   
};
#endif

#include "robot.h"
#include <cstdlib>
#include <ctime>

Robot::Robot(int x, int y, bool player){
   cordx = x;
   cordy = y;
   chg = 5;
   load = 0;
   cap = 5;
   rng = 1;
   type = player;
   
   hp = 100;
   spd = 2;
   def = 2;
   atk = 2;   
}

void Robot::attack(Robot* R2){
   int damage;
   int a;
   int d;
   
      if (R2->getEvade())
      {
	 return;
      }
      
      else
      {
	 a = (this->getAttack() * 2);
      d = (R2->getDefence() * 1);
      damage = a - d;
      chg--;
      
      if (damage <= 0)
	 R2->hp -= 1;
      
      else
	 R2->hp -= damage;
      }
}

void Robot::defend(){
   def += 1;
}

void Robot::charge(){
   chg += 5;
}

int Robot::getAttack(){
   return atk;
}

int Robot::getDefence(){
   return def;
}

int Robot::getCharge(){
   return chg;
}

bool Robot::getEvade(){
   srand(time(NULL));
   int chance = spd+2;
   int num;
   
   num = rand() % 100;

   if (num <= chance)
      return 1;

   else
      return 0;
}

int Robot::getHP(){
   return hp;
}

bool Robot::getType(){
   return type;
}

int Robot::getRange(){
   return rng;
}

int Robot::getX(){
   return cordx;
}

int Robot::getY(){
   return cordy;
}

#ifndef __AI_H
#define __AI_H

#include <ctime>
#include <cstdlib>
#include "robot.h"

class Ai{
  public:
   void play(Robot* player1, Robot* player2);
};

#endif

#include "ai.h"

void Ai::play(Robot* player1, Robot* player2) {
   srand(time(NULL));

   if (player1->getCharge() == 0){
      if (rand()%5 <= 3)
	 player1->charge();
      else
	 player1->defend();
   }
   else{
      int temp = rand()%4;
      if (temp<=1)
	 player1->attack(player2);
      else if (temp = 2)
	 player1->defend();
      else
	 player1->charge();
   }

}

int main(){};
