///\file

#ifndef __ROBOTTEST_H
#define __ROBOTTEST_H

#include <iostream>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../include/robot.h"
#include "../include/RandTest.h"
#include "../include/lightRobotType.h"
#include "../include/Attachment.h"

///Class containing the test cases for the robot class
class robotTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(robotTest);
	CPPUNIT_TEST(testConstructor);
	CPPUNIT_TEST(testattack);
	CPPUNIT_TEST(testdefend);
	CPPUNIT_TEST(testcharge);
	CPPUNIT_TEST(testtakeDamage);
	CPPUNIT_TEST(testchangeX);
	CPPUNIT_TEST(testchangeY);
	CPPUNIT_TEST(testattach);
	CPPUNIT_TEST(testdecMove);
	CPPUNIT_TEST(testsetMove);
	CPPUNIT_TEST(testsetDefault);
	CPPUNIT_TEST(testgetAttack);
	CPPUNIT_TEST(testgetDefence);
	CPPUNIT_TEST(testgetCharge);
	CPPUNIT_TEST(testgetEvade);
	CPPUNIT_TEST(testgetHP);
	CPPUNIT_TEST(testgetType);
	CPPUNIT_TEST(testgetRange);
	CPPUNIT_TEST(testgetX);
	CPPUNIT_TEST(testgetY);
	CPPUNIT_TEST(testgetDefCap);
	CPPUNIT_TEST(testgetName);
	CPPUNIT_TEST_SUITE_END();
        
private:
	///Different robots used to test interaction
	randstub* testing;
	robotType lightType;
	Robot* R1;
	Robot* R2;
	int x,y,charge,defencecap,range,type,health,defence,attack,speed,rand1, fuel,move;
	attachment attachtest;
	attachment attachtest2;
public:
	///Initialization for the test robots
	void setUp() {
	   lightType = new lightRobotType;
	   testing = new randtest();
	   R1 = new Robot(0,0,1, "Player 1", lightType);
	   R2 = new Robot(0,1,1, "Player 2", lightType);

	   x = 0;
	   y = 0;
	   charge = 5;
	   defencecap = 5;
	   range = 1;
	   type = 1;
	   health = 100;
	   defence = 10;
	   attack = 10;
	   speed = 20;
	   rand1 = 1804289383;
	   fuel = 250;
	   move = (20/2);


	   attachtest.name = "test";
	   attachtest.description = "sfgjhsgfjh";
	   attachtest.atkm = 3;
	   attachtest.hpm = 10;
	   attachtest.spdm = 3;
	   attachtest.defm = 3;
	   attachtest.rngm = 3;
	   attachtest.weight = 2;
	   attachtest.fuelm = 10;

	   attachtest2 = attachtest;
	   attachtest2.weight = 6;
	}

	///Frees memory for the robots
	void tearDown() {
	   delete testing;
	   delete R1;
	   delete R2;
	}

	///Tests that the constructor allocates values correctly
	void testConstructor(){
	   CPPUNIT_ASSERT(R1->getX() == x);
	   CPPUNIT_ASSERT(R1->getY() == y);
	   CPPUNIT_ASSERT(R1->getCharge() == charge);
	   CPPUNIT_ASSERT(R1->getDefCap() == defencecap);
	   CPPUNIT_ASSERT(R1->getRange() == range);
	   CPPUNIT_ASSERT(R1->getType() == type);
	   CPPUNIT_ASSERT(R1->getHP() == health);
	   CPPUNIT_ASSERT(R1->getDefence() == defence);
	   CPPUNIT_ASSERT(R1->getAttack() == attack);
	   CPPUNIT_ASSERT(R1->getSpeed() == speed);
	}

	///Tests that attack results in the correct changes to variables
	void testattack(){
	   R1->attack(R2, testing);
	   
	   int damage, a, d;
	   a = (R1->getAttack() * 2);
	   d = R2->getDefence();
	   damage = a - d;

	   charge--;
	   
	   CPPUNIT_ASSERT(R1->getCharge() == charge);
	   CPPUNIT_ASSERT(R2->getHP() <= health);
	   
	   if (R2->getHP() < health-1)
	   {
	      CPPUNIT_ASSERT(R2->getHP() == (health-damage));
	   }
	}

	///Tests that defend causes the correct change to the def variable
	void testdefend(){
	   R1->defend();

	   defence++;

	   CPPUNIT_ASSERT(R1->getDefence() == defence);
	}

	///Tests that charge adds the correct amount to chg variable
	void testcharge(){
	   R1->charge();

	   charge+=5;

	   CPPUNIT_ASSERT(R1->getCharge() == charge);	
	}

	///Tests that takeDamage causes the right change to hp
	void testtakeDamage(){
	   R1->takeDamage(25);

	   health-=25;

	   CPPUNIT_ASSERT(R1->getHP() == health);
	}

	///Tests that changeX correctly changes cordx to the input value
	void testchangeX(){
	   R1->changeX(5);

	   CPPUNIT_ASSERT(R1->getX() == 5);
	}

	///Tests that changeY correctly changes cordy to the input value
	void testchangeY(){
	   R1->changeY(5);

	   CPPUNIT_ASSERT(R1->getY() == 5);
	}

	///Tests to see if attach changes all of the values specified
	void testattach(){
	   R1->attach(attachtest);

	   CPPUNIT_ASSERT(R1->getAttack() == attack+3);
	   CPPUNIT_ASSERT(R1->getHP() == health+10);
	   CPPUNIT_ASSERT(R1->getDefence() == defence+3);
	   CPPUNIT_ASSERT(R1->getRange() == 3);
	   CPPUNIT_ASSERT(R1->getFuel() == fuel+10);
	   CPPUNIT_ASSERT(R1->getSpeed() == speed+3-4);

	   R2->attach(attachtest2);

	   CPPUNIT_ASSERT(R2->getAttack() == attack);
	   CPPUNIT_ASSERT(R2->getHP() == health);
	   CPPUNIT_ASSERT(R2->getDefence() == defence);
	   CPPUNIT_ASSERT(R2->getRange() == range);
	   CPPUNIT_ASSERT(R2->getFuel() == fuel);
	   CPPUNIT_ASSERT(R2->getSpeed() == speed);
	}

	///Tests that decMove changes numMove correctly
	void testdecMove(){
	   R1->decMove();

	   CPPUNIT_ASSERT(R1->getMove() == move-1);
	}

	///Tests that set move resets numMove correctly
	void testsetMove(){
	   R1->decMove();

	   CPPUNIT_ASSERT(R1->getMove() == move-1);

	   R1->setMove();

	   CPPUNIT_ASSERT(R1->getMove() == move);
	}

	///Tests that setDefault resets stats correctly
	void testsetDefault(){
	   R1->defend();
	   R1->takeDamage(10);
	   R1->changeX(5);
	   R1->changeY(5);
	   R1->decMove();

	   R1->setDefault();

	   CPPUNIT_ASSERT(R1->getAttack() == attack);
	   CPPUNIT_ASSERT(R1->getHP() == health);
	   CPPUNIT_ASSERT(R1->getDefence() == defence);
	   CPPUNIT_ASSERT(R1->getRange() == range);
	   CPPUNIT_ASSERT(R1->getFuel() == fuel);
	   CPPUNIT_ASSERT(R1->getSpeed() == speed);
	}

	///Tests the return of atk
	void testgetAttack(){
	   CPPUNIT_ASSERT(R1->getAttack() == attack);
	}

	///Tests the return of def
	void testgetDefence(){
	   CPPUNIT_ASSERT(R1->getDefence() == defence);
	}

	///Tests the return of chg
	void testgetCharge(){
	   CPPUNIT_ASSERT(R1->getCharge() == charge);
	}

	///Tests that evade instance is calculated correctly based on chance
	void testgetEvade(){	   
	   int num = (rand1 % 100);
	   bool dodge = 0;
	   int chance = (R1->getSpeed()+2);

	   if (num <= chance)
	      dodge = 1;

	   CPPUNIT_ASSERT(R1->getEvade(testing) == dodge);
	}

	///Tests the return of hp
	void testgetHP(){
	   CPPUNIT_ASSERT(R1->getHP() == health);
	}

	///Tests the return of type
	void testgetType(){
	   CPPUNIT_ASSERT(R1->getType() == type);
	}

	///Tests the return of rng
	void testgetRange(){
	   CPPUNIT_ASSERT(R1->getRange() == range);
	}

	///Tests the return of cordx
	void testgetX(){
	   CPPUNIT_ASSERT(R1->getX() == x);
	}

	///Tests the return of cordy
	void testgetY(){
	   CPPUNIT_ASSERT(R1->getY() == y);
	}

	///Tests the return of defCap
	void testgetDefCap(){
	   CPPUNIT_ASSERT(R1->getDefCap() == defencecap);
	}

	///Tests the return of the player name
	void testgetName(){
	   CPPUNIT_ASSERT(R1->getName() == "Player 1");
	}
};
#endif
