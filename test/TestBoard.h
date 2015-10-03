/// \file

#ifndef __TESTBOARD_H
#define __TESTBOARD_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../include/robot.h"
#include "../include/ConcreteBoard.h"
#include "../include/lightRobotType.h"


/// Class containing the test cases for ConcreteBoard. The ConcreteBoard
/// is exercised through its interface Board.
class TestBoard : public CppUnit::TestFixture {
   CPPUNIT_TEST_SUITE(TestBoard);
   CPPUNIT_TEST(testGetTile);
   CPPUNIT_TEST(test4LinesOfDraw);
   CPPUNIT_TEST(testBoardOutputOfDraw);
   CPPUNIT_TEST(testBottomOutputOfDraw);
   CPPUNIT_TEST(testMoveNorth);
   CPPUNIT_TEST(testMoveEastWithWall);
   CPPUNIT_TEST(testMoveWestWithOpponant);
   CPPUNIT_TEST(testDisplayRange);
   CPPUNIT_TEST_SUITE_END();
   
  private:
   
   /// Creates two robot pointers and the game board pointer
   RobotInterface* P1;
   RobotInterface* P2;
   Board gameBoard;
   robotType lightType;
   
   int boardX;
   int boardY;
   
  public:
   /// initialization for the board
   void setUp() {
      lightType = new lightRobotType;
      boardX = 30;
      boardY = 24;
      P1 = new Robot(14,12,true, "Player 1", lightType);
      P2 = new Robot(15,12,true, "Player 2", lightType);
      gameBoard = new ConcreteBoard(boardX, boardY, P1, P2);
            
   }
   
   /// frees memory from the players
   void tearDown() {
      delete P1;
      delete P2;
      delete lightType;
   }
   
   /// test that the getTile function can return several different tile states
   /// including an invalid tile
   void testGetTile() {

      ostringstream sstr;
      Tile tile0x0 = gameBoard->getTile(0,0,sstr);
      Tile tile6x6 = gameBoard->getTile(6,6,sstr);
      Tile tile6x17 = gameBoard->getTile(6,17,sstr);
      Tile tile23x6 = gameBoard->getTile(23,6,sstr);
      Tile tile23x17 = gameBoard->getTile(23,17,sstr);
      Tile tileP1 = gameBoard->getTile(14,12,sstr);
      Tile tileP2 = gameBoard->getTile(15,12, sstr);

      Tile tileneg1xneg1 = gameBoard->getTile(-1,-1,sstr);
      string s = sstr.str();

      size_t line1 = s.find('\n');
      size_t line2 = s.find('\n',line1+1);
      size_t line3 = s.find('\n',line2+1);
      size_t line4 = s.find('\n',line3+1);
      
      size_t line5 = s.find('\n',line4+1);
      size_t line6 = s.find('\n',line5+1);
      size_t line7 = s.find('\n',line6+1);
      size_t line8 = s.find('\n',line7+1);
      size_t line9 = s.find('\n',line8+1);
      size_t line10 = s.find('\n',line9+1);
      size_t line11 = s.find('\n',line10+1);
      size_t line12 = s.find('\n',line11+1);
      size_t line13 = s.find('\n',line12+1);
      size_t line14 = s.find('\n',line13+1);
      size_t line15 = s.find('\n',line14+1);
      size_t line16 = s.find('\n',line15+1);
      size_t line17 = s.find('\n',line16+1);
      size_t line18 = s.find('\n',line17+1);
      size_t line19 = s.find('\n',line18+1);
      size_t line20 = s.find('\n',line19+1);
      size_t line21 = s.find('\n',line20+1);
      size_t line22 = s.find('\n',line21+1);
      size_t line23 = s.find('\n',line22+1);
      size_t line24 = s.find('\n',line23+1);
      size_t line25 = s.find('\n',line24+1);
      size_t line26 = s.find('\n',line25+1);
      size_t line27 = s.find('\n',line26+1);
      size_t line28 = s.find('\n',line27+1);
      size_t line29 = s.find('\n',line28+1);

      size_t line30 = s.find('\n',line29+1);
      size_t line31 = s.find('\n',line30+1);
      size_t line32 = s.find('\n',line31+1);
      
      CPPUNIT_ASSERT(tileneg1xneg1 == tile0x0);
      CPPUNIT_ASSERT(tileneg1xneg1->getState() == ".");
      CPPUNIT_ASSERT(s.substr(line31+1, line32-line31-1) == "You chose a tile that does not exist. Error occured");
            
      CPPUNIT_ASSERT(tile0x0 != NULL);
      CPPUNIT_ASSERT(tile0x0->getState() == ".");
      CPPUNIT_ASSERT(tile6x6 != NULL);
      CPPUNIT_ASSERT(tile6x6->getState() == "X");
      CPPUNIT_ASSERT(tile6x17 != NULL);
      CPPUNIT_ASSERT(tile6x17->getState() == "X");
      CPPUNIT_ASSERT(tile23x6 != NULL);
      CPPUNIT_ASSERT(tile23x6->getState() == "X");
      CPPUNIT_ASSERT(tile23x17 != NULL);
      CPPUNIT_ASSERT(tile23x17->getState() == "X");
      CPPUNIT_ASSERT(tileP1 != NULL);
      CPPUNIT_ASSERT(tileP1->getState() == "R");
      CPPUNIT_ASSERT(tileP2 != NULL);
      CPPUNIT_ASSERT(tileP2->getState() == "R");
   }

   /// This will test that the first 4 lines of the draw function output the
   /// expected words and colours, including player designation, the base
   /// health of the robots and what type of robot they are 
   void test4LinesOfDraw() {
      
      ostringstream sstr;
      gameBoard->draw("This is a test message", sstr);
      string s = sstr.str();
      
      /// These lines are for the first test
      size_t line1 = s.find('\n');         
      size_t line2 = s.find('\n',line1+1);
      size_t line3 = s.find('\n',line2+1);
      size_t line4 = s.find('\n',line3+1);
      
      CPPUNIT_ASSERT(s.substr(0, line1) == "\033[0;31mPlayer 1\033[0;0m                     Simulation In Progress                     \033[0;34mPlayer 2\033[0;0m");
      CPPUNIT_ASSERT(s.substr(line1+1, line2-line1-1) == "AI                                                                            AI");
      CPPUNIT_ASSERT(s.substr(line2+1, line3-line2-1) == "HP: 100  Range: 1   Move: 10 Fuel: 250 || HP: 100  Range:  1  Move: 10 Fuel: 250");
      CPPUNIT_ASSERT(s.substr(line3+1, line4-line3-1) == "\033[4mChrg:  5   Attk:  10   Def: 10         ||         Chrg:  5   Attk:  10   Def: 10\033[0m");
      
   }
   
   /// This test tests that the actual grid part of the board has appropriately
   /// been drawn including 4 obstacles and 2 coloured robots.
   void testBoardOutputOfDraw() {
      ostringstream sstr;
      gameBoard->draw("This is a test message", sstr);
      string s = sstr.str();  

      /// These lines are for the first test
      size_t line1 = s.find('\n');          
      size_t line2 = s.find('\n',line1+1);
      size_t line3 = s.find('\n',line2+1);
      size_t line4 = s.find('\n',line3+1);

      /// These lines are for the second and third test
      size_t line5 = s.find('\n',line4+1); 
      size_t line6 = s.find('\n',line5+1);
      size_t line7 = s.find('\n',line6+1);
      size_t line8 = s.find('\n',line7+1);
      size_t line9 = s.find('\n',line8+1);
      size_t line10 = s.find('\n',line9+1);
      size_t line11 = s.find('\n',line10+1);
      size_t line12 = s.find('\n',line11+1);
      size_t line13 = s.find('\n',line12+1);
      size_t line14 = s.find('\n',line13+1);
      size_t line15 = s.find('\n',line14+1);
      size_t line16 = s.find('\n',line15+1);
      size_t line17 = s.find('\n',line16+1);
      size_t line18 = s.find('\n',line17+1);
      size_t line19 = s.find('\n',line18+1);
      size_t line20 = s.find('\n',line19+1);
      size_t line21 = s.find('\n',line20+1);
      size_t line22 = s.find('\n',line21+1);
      size_t line23 = s.find('\n',line22+1);
      size_t line24 = s.find('\n',line23+1);
      size_t line25 = s.find('\n',line24+1);
      size_t line26 = s.find('\n',line25+1);
      size_t line27 = s.find('\n',line26+1);
      size_t line28 = s.find('\n',line27+1);
      size_t line29 = s.find('\n',line28+1);
      size_t line30 = s.find('\n',line29+1);


      CPPUNIT_ASSERT(s.substr(line4+1, line5-line4-1) == "         -------------------------------------------------------------"  );
      CPPUNIT_ASSERT(s.substr(line5+1, line6-line5-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line6+1, line7-line6-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line7+1, line8-line7-1) == "        | . . . . . . . . . . . X . . . . . . X . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line8+1, line9-line8-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line9+1, line10-line9-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line10+1, line11-line10-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line11+1, line12-line11-1) == "        | . . . . . . X . . . . . . . . . . . . . . . . X . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line12+1, line13-line12-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line13+1, line14-line13-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line14+1, line15-line14-1) == "        | . . . . . . . . . X . . . . . . . . . . X . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line15+1, line16-line15-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line16+1, line17-line16-1) == "        | . . . . X . . . . . . . . . \033[31mR\033[0m \033[34mR\033[0m . . . . . . . . . X . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line17+1, line18-line17-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"   );
      CPPUNIT_ASSERT(s.substr(line18+1, line19-line18-1) == "        | . . . . . . . . . X . . . . . . . . . . X . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line19+1, line20-line19-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line20+1, line21-line20-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line21+1, line22-line21-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line22+1, line23-line22-1) == "        | . . . . . . X . . . . . . . . . . . . . . . . X . . . . . . \033[0;0m|" );
      CPPUNIT_ASSERT(s.substr(line23+1, line24-line23-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line24+1, line25-line24-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line25+1, line26-line25-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line26+1, line27-line26-1) == "        | . . . . . . . . . . . X . . . . . . X . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line27+1, line28-line27-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line28+1, line29-line28-1) == "        | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . \033[0;0m|"  );
      CPPUNIT_ASSERT(s.substr(line29+1, line30-line29-1) == "         -------------------------------------------------------------");

   }

   /// This will test that the bottom lines of draw are ouput propperly
   /// including the line dividing the status message from the board and
   /// the status message itself 
   void testBottomOutputOfDraw(){
      ostringstream sstr;
      gameBoard->draw("This is a test message", sstr);
      string s = sstr.str();  // get the output as string
      size_t line1 = s.find('\n');
      size_t line2 = s.find('\n',line1+1);
      size_t line3 = s.find('\n',line2+1);
      size_t line4 = s.find('\n',line3+1);
      
      size_t line5 = s.find('\n',line4+1);
      size_t line6 = s.find('\n',line5+1);
      size_t line7 = s.find('\n',line6+1);
      size_t line8 = s.find('\n',line7+1);
      size_t line9 = s.find('\n',line8+1);
      size_t line10 = s.find('\n',line9+1);
      size_t line11 = s.find('\n',line10+1);
      size_t line12 = s.find('\n',line11+1);
      size_t line13 = s.find('\n',line12+1);
      size_t line14 = s.find('\n',line13+1);
      size_t line15 = s.find('\n',line14+1);
      size_t line16 = s.find('\n',line15+1);
      size_t line17 = s.find('\n',line16+1);
      size_t line18 = s.find('\n',line17+1);
      size_t line19 = s.find('\n',line18+1);
      size_t line20 = s.find('\n',line19+1);
      size_t line21 = s.find('\n',line20+1);
      size_t line22 = s.find('\n',line21+1);
      size_t line23 = s.find('\n',line22+1);
      size_t line24 = s.find('\n',line23+1);
      size_t line25 = s.find('\n',line24+1);
      size_t line26 = s.find('\n',line25+1);
      size_t line27 = s.find('\n',line26+1);
      size_t line28 = s.find('\n',line27+1);
      size_t line29 = s.find('\n',line28+1);
      size_t line30 = s.find('\n',line29+1);

      size_t line31 = s.find('\n',line30+1);
      size_t line32 = s.find('\n',line31+1);

      CPPUNIT_ASSERT(s.substr(line30+1, line31-line30-1) == "\033[4mCommands: Move:[w][a][s][d]   Attack:[j]    Defend:[k]   Charge:[l]   Range:[r] \033[0m");
      CPPUNIT_ASSERT(s.substr(line31+1, line32-line31-1) == "This is a test message");
      
   }

   /// This test is the inital test of the move function, where a robot attempts
   /// to move to an open square. This test, by inclusion, also tests the
   /// helper functions used by move (which are P1ChangeLoc and P1Location)
   /// but they are too simple to warrent individual testing
   void testMoveNorth(){
      ostringstream sstr;
            
      int p1CordX = P1->getX();
      int p1CordY = P1->getY();
      Tile p1Locat = gameBoard->P1Location();
      
      gameBoard->move('w', P1, P2, sstr);
      string s = sstr.str();
            
      size_t line1 = s.find('\n');
      size_t line2 = s.find('\n',line1+1);
      size_t line3 = s.find('\n',line2+1);
      size_t line4 = s.find('\n',line3+1);
      
      size_t line5 = s.find('\n',line4+1);
      size_t line6 = s.find('\n',line5+1);
      size_t line7 = s.find('\n',line6+1);
      size_t line8 = s.find('\n',line7+1);
      size_t line9 = s.find('\n',line8+1);
      size_t line10 = s.find('\n',line9+1);
      size_t line11 = s.find('\n',line10+1);
      size_t line12 = s.find('\n',line11+1);
      size_t line13 = s.find('\n',line12+1);
      size_t line14 = s.find('\n',line13+1);
      size_t line15 = s.find('\n',line14+1);
      size_t line16 = s.find('\n',line15+1);
      size_t line17 = s.find('\n',line16+1);
      size_t line18 = s.find('\n',line17+1);
      size_t line19 = s.find('\n',line18+1);
      size_t line20 = s.find('\n',line19+1);
      size_t line21 = s.find('\n',line20+1);
      size_t line22 = s.find('\n',line21+1);
      size_t line23 = s.find('\n',line22+1);
      size_t line24 = s.find('\n',line23+1);
      size_t line25 = s.find('\n',line24+1);
      size_t line26 = s.find('\n',line25+1);
      size_t line27 = s.find('\n',line26+1);
      size_t line28 = s.find('\n',line27+1);
      size_t line29 = s.find('\n',line28+1);

      size_t line30 = s.find('\n',line29+1);
      size_t line31 = s.find('\n',line30+1);
      size_t line32 = s.find('\n',line31+1);

      CPPUNIT_ASSERT(P1->getX() == p1CordX);
      CPPUNIT_ASSERT(P1->getY() == p1CordY+1);
      CPPUNIT_ASSERT(p1Locat != gameBoard->P1Location());
      CPPUNIT_ASSERT(s.substr(line31+1, line32-line31-1) == "Player 1 moved.");
      
   }

   /// This test moves the robot to beside a wall and attempts to move the robot
   /// off the board
   void testMoveEastWithWall(){

      ostringstream sstr;

      gameBoard->P1ChangeLoc(29,14,sstr);
      int p1CordX = P1->getX();
      int p1CordY = P1->getY();
      Tile p1Locat = gameBoard->P1Location();

      gameBoard->move('d', P1, P2, sstr);
      string s = sstr.str();

      size_t line1 = s.find('\n');
      size_t line2 = s.find('\n',line1+1);
      size_t line3 = s.find('\n',line2+1);
      size_t line4 = s.find('\n',line3+1);
      
      size_t line5 = s.find('\n',line4+1);
      size_t line6 = s.find('\n',line5+1);
      size_t line7 = s.find('\n',line6+1);
      size_t line8 = s.find('\n',line7+1);
      size_t line9 = s.find('\n',line8+1);
      size_t line10 = s.find('\n',line9+1);
      size_t line11 = s.find('\n',line10+1);
      size_t line12 = s.find('\n',line11+1);
      size_t line13 = s.find('\n',line12+1);
      size_t line14 = s.find('\n',line13+1);
      size_t line15 = s.find('\n',line14+1);
      size_t line16 = s.find('\n',line15+1);
      size_t line17 = s.find('\n',line16+1);
      size_t line18 = s.find('\n',line17+1);
      size_t line19 = s.find('\n',line18+1);
      size_t line20 = s.find('\n',line19+1);
      size_t line21 = s.find('\n',line20+1);
      size_t line22 = s.find('\n',line21+1);
      size_t line23 = s.find('\n',line22+1);
      size_t line24 = s.find('\n',line23+1);
      size_t line25 = s.find('\n',line24+1);
      size_t line26 = s.find('\n',line25+1);
      size_t line27 = s.find('\n',line26+1);
      size_t line28 = s.find('\n',line27+1);
      size_t line29 = s.find('\n',line28+1);

      size_t line30 = s.find('\n',line29+1);
      size_t line31 = s.find('\n',line30+1);
      size_t line32 = s.find('\n',line31+1);
      
      CPPUNIT_ASSERT(P1->getX() == p1CordX);
      CPPUNIT_ASSERT(P1->getY() == p1CordY);
      CPPUNIT_ASSERT(p1Locat == gameBoard->P1Location());
      CPPUNIT_ASSERT(s.substr(line31+1, line32-line31-1) == "You can't go there.");
   }

   /// This tests that a robot can't move onto the same square as another robot
   void testMoveWestWithOpponant(){
      ostringstream sstr;
            
      int p1CordX = P1->getX();
      int p1CordY = P1->getY();
      Tile p1Locat = gameBoard->P1Location();
      
      gameBoard->P1ChangeLoc(14,12,sstr);
      gameBoard->move('d', P1, P2, sstr);
      
      string s = sstr.str();
            
      size_t line1 = s.find('\n');
      size_t line2 = s.find('\n',line1+1);
      size_t line3 = s.find('\n',line2+1);
      size_t line4 = s.find('\n',line3+1);
      
      size_t line5 = s.find('\n',line4+1);
      size_t line6 = s.find('\n',line5+1);
      size_t line7 = s.find('\n',line6+1);
      size_t line8 = s.find('\n',line7+1);
      size_t line9 = s.find('\n',line8+1);
      size_t line10 = s.find('\n',line9+1);
      size_t line11 = s.find('\n',line10+1);
      size_t line12 = s.find('\n',line11+1);
      size_t line13 = s.find('\n',line12+1);
      size_t line14 = s.find('\n',line13+1);
      size_t line15 = s.find('\n',line14+1);
      size_t line16 = s.find('\n',line15+1);
      size_t line17 = s.find('\n',line16+1);
      size_t line18 = s.find('\n',line17+1);
      size_t line19 = s.find('\n',line18+1);
      size_t line20 = s.find('\n',line19+1);
      size_t line21 = s.find('\n',line20+1);
      size_t line22 = s.find('\n',line21+1);
      size_t line23 = s.find('\n',line22+1);
      size_t line24 = s.find('\n',line23+1);
      size_t line25 = s.find('\n',line24+1);
      size_t line26 = s.find('\n',line25+1);
      size_t line27 = s.find('\n',line26+1);
      size_t line28 = s.find('\n',line27+1);
      size_t line29 = s.find('\n',line28+1);

      size_t line30 = s.find('\n',line29+1);
      size_t line31 = s.find('\n',line30+1);
      size_t line32 = s.find('\n',line31+1);

      CPPUNIT_ASSERT(P1->getX() == p1CordX);
      CPPUNIT_ASSERT(P1->getY() == p1CordY);
      CPPUNIT_ASSERT(p1Locat == gameBoard->P1Location());
      CPPUNIT_ASSERT(s.substr(line31+1, line32-line31-1) == "You can't go there.");
   }


   /// This tests the range display function, which highlights all of the tiles
   /// within the robot's range green
   void testDisplayRange(){
      ostringstream sstr;

      gameBoard->displayRange(P1, sstr);

      string s = sstr.str();
            
      size_t line1 = s.find('\n');
      size_t line2 = s.find('\n',line1+1);
      size_t line3 = s.find('\n',line2+1);
      size_t line4 = s.find('\n',line3+1);
      
      size_t line5 = s.find('\n',line4+1);
      size_t line6 = s.find('\n',line5+1);
      size_t line7 = s.find('\n',line6+1);
      size_t line8 = s.find('\n',line7+1);
      size_t line9 = s.find('\n',line8+1);
      size_t line10 = s.find('\n',line9+1);
      size_t line11 = s.find('\n',line10+1);
      size_t line12 = s.find('\n',line11+1);
      size_t line13 = s.find('\n',line12+1);
      size_t line14 = s.find('\n',line13+1);
      size_t line15 = s.find('\n',line14+1);
      size_t line16 = s.find('\n',line15+1);
      size_t line17 = s.find('\n',line16+1);
      size_t line18 = s.find('\n',line17+1);
      size_t line19 = s.find('\n',line18+1);
      size_t line20 = s.find('\n',line19+1);
      size_t line21 = s.find('\n',line20+1);
      size_t line22 = s.find('\n',line21+1);
      size_t line23 = s.find('\n',line22+1);
      size_t line24 = s.find('\n',line23+1);
      size_t line25 = s.find('\n',line24+1);
      size_t line26 = s.find('\n',line25+1);
      size_t line27 = s.find('\n',line26+1);
      size_t line28 = s.find('\n',line27+1);
      size_t line29 = s.find('\n',line28+1);
      size_t line30 = s.find('\n',line29+1);
      
      size_t line31 = s.find('\n',line30+1);
      size_t line32 = s.find('\n',line31+1);
      
      CPPUNIT_ASSERT(s.substr(line15+1, line16-line15-1) == "        | . . . . . . . . . . . . . . \033[42m.\033[0m . . . . . . . . . . . . . . . \033[0;0m|");
      CPPUNIT_ASSERT(s.substr(line16+1, line17-line16-1) == "        | . . . . X . . . . . . . . \033[42m.\033[0m \033[42;31mR\033[0m \033[42;34mR\033[0m . . . . . . . . . X . . . . \033[0;0m|");
      CPPUNIT_ASSERT(s.substr(line17+1, line18-line17-1) == "        | . . . . . . . . . . . . . . \033[42m.\033[0m . . . . . . . . . . . . . . . \033[0;0m|");
      CPPUNIT_ASSERT(s.substr(line31+1, line32-line31-1) == "Player 1's range displayed.");

   }
   
};



#endif
