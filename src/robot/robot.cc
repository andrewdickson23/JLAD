/// \file
#include "../../include/robot.h"
#include <cstdlib>
#include <vector>
#include <ctime>
#include <string>
#include <iostream>

Robot::Robot(int x,int y,bool player, const std::string &nameConstruct, robotType rType){
   robName = nameConstruct;
   cordx = strtX = x;
   cordy = strtY = y;
   chg = rType->getChg();
   load = rType->getLoad();
   cap = rType->getCap();
   defCap = rType->getDefCap();
   defUse = rType->getDefUse();
   rng = rType->getRng();
   rtype = rType;
   type = player;
   fuel = rType->getFuel();
   
   hp = rType->getHp();
   spd = rType->getSpd();
   def = rType->getDef();
   atk = rType->getAtk();

   description = rType->getDescription();
   setMove();
}

int Robot::attack(RobotInterface* R2, randstub* tester){
   int damage;
   int a;
   int d;
   int basePower = 2;
   int minimalDamage = 1;
   
      if (R2->getEvade(tester))
      {
	 chg--;
	 return 0;
      }
      
      else {
	 a = (this->getAttack() * basePower);
	 d = R2->getDefence();
	 damage = a - d;
	 chg--;
	 
	 if (damage <= 0)
	 {
	    R2->takeDamage(minimalDamage);
	    return minimalDamage;
	 }
	 else
	 {
	    R2->takeDamage(damage);
	    return damage;
	 }
      }
}

void Robot::defend(){
   def += 1;
   defUse += 1;
}

void Robot::charge(){
   chg += 5;
}

int Robot::getLoad() {
   return load;
} 

void Robot::takeDamage(int amount){
   hp -= amount;
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

bool Robot::getEvade(randstub* test){
   if (test->randvar() == false)
      srand(time(NULL));
   else
      srand(1); //rand() generates the value 1804289383 if srand(1)
   
   int chance = (spd+2)/2;

   if (chance > 20)
      chance = 20;
   
   int num;
   
   num = rand() % 100;

   if (num <= chance)
      return 1;
   else
      return 0;
}

int Robot::getHP(){
   if (hp >= 0)
      return hp;
   else
      return 0;
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

int Robot::getDefCap(){
   return defCap;
}

int Robot::getSpeed(){
   return spd;
}

std::string Robot::getName(){
   return robName;
}

bool Robot::attach(attachment x){
   int spdReduce = 2;
  
   if ((load + x.weight) <= cap)
   {
      atk += x.atkm;
      hp += x.hpm;
      spd += x.spdm;
      def += x.defm;
      load += x.weight;
      fuel += x.fuelm;
      
      if (x.rngm > rng)
	 rng = x.rngm;
      
       spd -= (x.weight * spdReduce);

      if (spd <= 0)
       spd = 1;

      resetArr.push_back(x);

      setMove();
      
      return 1;
   }
   
   else{
      return 0;
   }
}

void Robot::decMove(){
   numMove--;
   fuel--;
}

void Robot::setMove(){
   int base = 2;
   numMove = ((spd)/base);
}

int Robot::getMove(){
   return numMove;
}

void Robot::changeX(int shift){
   cordx = shift;
}

void Robot::changeY(int shift){
   cordy = shift;
}

int Robot::getDefUse(){
   return defUse;
}

int Robot::getFuel(){
   return fuel;
}

std::string Robot::describe(){
   return description;
}

int Robot::getCap(){
   return cap;
}

void Robot::setDefault(){
   cordx = strtX;
   cordy = strtY;
   chg = rtype->getChg();
   load = rtype->getLoad();
   cap = rtype->getCap();
   defCap = rtype->getDefCap();
   defUse = rtype->getDefUse();
   rng = rtype->getRng();
   fuel = rtype->getFuel();
   
   hp = rtype->getHp();
   spd = rtype->getSpd();
   def = rtype->getDef();
   atk = rtype->getAtk();

   description = rtype->getDescription();
}

std::vector<attachment> Robot::getResetArr(){
   return resetArr;
}
   
