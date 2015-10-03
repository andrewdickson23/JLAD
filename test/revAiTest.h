/// \file
#ifndef __REVAITEST_H
#define __REVAITEST_H

#include <iostream>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../include/robot.h"
#include "../include/ai.h"
#include "../include/RandTest.h"
#include "../include/lightRobotType.h"

///class containing the test cases for the robot class
class revAiTest : public CppUnit::TestFixture {
   
   CPPUNIT_TEST_SUITE(revAiTest);
   CPPUNIT_TEST(testplay);
   CPPUNIT_TEST_SUITE_END();
   
  private:
   /// different robots used to test interaction
   Ai* test;
   randstub* testing;
   Robot* R1;
   Robot* R2;
   robotType light;
  public:
   /// initialization for the test robots
   void setUp() {
      test = new Ai();
      testing = new randtest();
      light = new lightRobotType;
      R1 = new Robot(0,0,1, "Player 1", light);
      R2 = new Robot(0,1,1, "Player 2", light);
   }
   
   /// frees memory for the robots
   void tearDown() {
      delete test;
      delete testing;
      delete R1;
      delete R2;
      delete light;
   }

   /// tests the play function to make sure that charge and defence
   /// will not be called as well as robot1 attacks robot2
   /// when using the srand(1) in the test stub
   void testplay(){
      ///test that play(R1,R2) calls play on R1 and damages R2
      test->play(R1, R2, testing);
      
      CPPUNIT_ASSERT(R1->getCharge() == 4);
      CPPUNIT_ASSERT(R1->getDefence() == 10);
      CPPUNIT_ASSERT(R2->getHP() < 100);

      ///test that play(R2,R1) calls play on R2 and damages R1
      test->play(R2, R1, testing);
	 
      CPPUNIT_ASSERT(R2->getCharge() == 4);
      CPPUNIT_ASSERT(R2->getDefence() == 10);
      CPPUNIT_ASSERT(R1->getHP() < 100);
   }
};
#endif
