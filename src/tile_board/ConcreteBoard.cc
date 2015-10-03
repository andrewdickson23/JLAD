/// \file

#include "ConcreteBoard.h"
#include "ConcreteTile.h"
#include "robot.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;


int ConcreteBoard::tilesNorth() {
   return yBound;
}


int ConcreteBoard::tilesEast() {
   return xBound;
}


void ConcreteBoard::draw(string statMess, ostream& out) {
/// Draws first line
   out << setw(42) << left << "\033[0;31mPlayer 1\033[0;0m"
       << setw(43) << "Simulation In Progress" << "\033[0;34mPlayer 2\033[0;0m"
       << endl;

   out << setw(5);
   
/// Checks if Players are human or AI
   if(player1->getType() == true)
      out << "AI";
   else
      out << "Human";

   out << setw(75) << right;


   if(player2->getType() == true)
      out << "AI";
   else
      out << "Human";

   out << endl;

/// outputs battle statistics
   out << left << "HP: " << setw(3) << player1->getHP() << "  Range: "
       << setw(2) << player1->getRange() << "  Move: " << setw(2)
       << player1->getMove() << " Fuel: " << right << setw(3)
       << player1->getFuel() << " |"
       << left << "| " << "HP: " << right << setw(3)
       << player2->getHP() << left << "  Range: " << right
       << setw(2) << player2->getRange() << left << "  Move: "
       << right << setw(2) << player2->getMove() << " Fuel: " << right
       << setw(3) << player2->getFuel() << endl;

   out << "\033[4mChrg: " << setw(2) << player1->getCharge() << "   Attk: "
       << setw(3) << player1->getAttack() << "   Def: " << setw(2)
       << player1->getDefence() << right << setw(10) << '|' << left << setw(10)
       << '|' << "Chrg: " << right << setw(2) << player2->getCharge() << left
       << "   Attk: " << right << setw(3) << player2->getAttack() << left
       << "   Def: " << right << setw(2) << player2->getDefence() << "\033[0m"
       << endl;

   out << "         -------------------------------------------------------------"     << endl << setfill(' ');

/// Draws the board 
   for (int y = tilesNorth()-1; y>=0; y--) {
      
      out << right << setw(10) << "| ";

      for (int x = 0; x < tilesEast(); x++) {
	 Tile tile = getTile(x,y,out);
	 if (tile->getState() == "R" && tile == robotA) /// checks for robot
	    out << left << "\033[31mR\033[0m" << ' ';
	 else if (tile->getState() == "\033[42mR\033[0m" && tile == robotA) 
	    out << left << "\033[42;31mR\033[0m" << ' ';
	 else if (tile->getState() == "R" && tile == robotB)
	    out << left << "\033[34mR\033[0m" << ' ';
	 else if (tile->getState() == "\033[42mR\033[0m" && tile == robotB)  
	    out << left << "\033[42;34mR\033[0m" << ' ';
	 else
	    out << left << tile->getState() << ' ';
      }
      out << "\033[0;0m" << '|' << endl;
      
   }
   out << "         -------------------------------------------------------------" << endl;
/// outputs command list
   out << "\033[4mCommands: Move:[w][a][s][d]   Attack:[j]    Defend:[k]   Charge:[l]   Range:[r] \033[0m" << endl; 
/// outputs the message
   out << statMess << endl;
}


ConcreteBoard::ConcreteBoard(int userX, int userY, RobotInterface* a,
			     RobotInterface* b) {
   ostream& out = cout;
   xBound = userX;
   yBound = userY;
   
   player1 = a;
   player2 = b;
   
   // reserve memory for rows
   tiles.reserve(tilesNorth());
   
   // insert empty rows
   for (int y = 0; y<tilesNorth(); y++) {
      tiles.push_back(std::vector <Tile>());  
      tiles[y].reserve(tilesEast());
      
      for (int x = 0; x < tilesEast(); x++) {
	 tiles[y].push_back(new ConcreteTile());
	 
      }
   }
/// Assign the robot's tiles to their players
   robotA = getTile(player1->getX(), player1->getY(), out);
   robotB = getTile(player2->getX(), player2->getY(), out);  
/// Makes the robots visible on the board
   robotA->robotArrive();
   robotB->robotArrive();

/// Places obstacles on the board
   obstA = getTile(6,6,out);
   obstB = getTile(6,17,out);
   obstC = getTile(23,6,out);
   obstD = getTile(23,17,out);
   obstE = getTile(11,2,out);
   obstF = getTile(18,2,out);
   obstG = getTile(11,21,out);
   obstH = getTile(18,21,out);
   obstI = getTile(9,10,out);
   obstJ = getTile(20,10,out);
   obstK = getTile(9,14,out);
   obstL = getTile(20,14,out);
   obstM = getTile(4,12,out);
   obstN = getTile(25,12,out);

   obstA->placeObstacle();
   obstB->placeObstacle();   
   obstC->placeObstacle();
   obstD->placeObstacle();
   obstE->placeObstacle();
   obstF->placeObstacle();   
   obstG->placeObstacle();
   obstH->placeObstacle();
   obstI->placeObstacle();
   obstJ->placeObstacle();   
   obstK->placeObstacle();
   obstL->placeObstacle();
   obstM->placeObstacle();
   obstN->placeObstacle();
}
   
   

ConcreteBoard::~ConcreteBoard() {
   for (int y = 0; y < tilesNorth(); y++)  {
      for (int x = 0; x < tilesEast(); x++)  {
	 delete tiles[y][x];
      }
   }
}



Tile ConcreteBoard::getTile(int x, int y, ostream& out) {
/// Because we already had a spot to output error messages and it needed to
/// change where it was outputting for the test cases, I changed this function
/// from throwing an exception to outputting the error message to draw 

   if (x < 0 || x >= tilesEast()){
      draw("You chose a tile that does not exist. Error occured", out);
      return (tiles[0][0]);
   }
   
   if (y < 0 || y >= tilesNorth()){
      draw("You chose a tile that does not exist. Error occured", out);
      return (tiles[0][0]);
   }

   return (tiles[y][x]);
}


void ConcreteBoard::move(char dir, RobotInterface* active,
			 RobotInterface* otherBot, ostream& output) {
   int x = active->getX();
   int y = active->getY();
   Tile activeLoc = getTile(x,y,output);

   /// Checks that they can still move
   if( (active->getMove() > 0) && (active->getFuel() > 0) ){

      /// Directional input
      switch (dir){
	 case 'w': case 'W':
	    y++;
	    break;
	 case 'a': case 'A':
	    x--;
	    break;
	 case 's': case 'S':
	    y--;
	    break;
	 case 'd': case 'D':
	    x++;
	    break;
      }

      /// Makes sure there isn't another robot or a wall in the way
      if( ( ((x >= 0) && (x < xBound)) && ((y >= 0) && (y < yBound)) )
	  && ( !(x == otherBot->getX() && y == otherBot->getY()) ) ) {
	 
	 if(activeLoc == robotA){
	    P1ChangeLoc(x,y,output);
	    player1->decMove();
	    player1->changeX(x);
	    player1->changeY(y);
	 }else if(activeLoc == robotB){
	    P2ChangeLoc(x,y,output);
	    player2->decMove();
	    player2->changeX(x);
	    player2->changeY(y);
	 }
	 /// output resulting move
	 draw(active->getName()+" moved.", output);

      } else{
	 draw("You can't go there.", output);
	 return;
      }
   } else{
      draw("You can't move any more, choose another option.", output);
      return;
   }
}
      
Tile ConcreteBoard::P1Location(){
   return robotA;
}
Tile ConcreteBoard::P2Location(){
   return robotB;
}

void ConcreteBoard::P1ChangeLoc(int x, int y, ostream& out){
   robotA->robotMoved();
   robotA = getTile(x,y,out);
   robotA->robotArrive();

}

void ConcreteBoard::P2ChangeLoc(int x, int y, ostream& out){
   robotB->robotMoved();
   robotB = getTile(x,y,out);
   robotB->robotArrive();

}

void ConcreteBoard::displayRange(RobotInterface* active, ostream& out){
/// makes variables responsible for indicating robot's range
   int range = active->getRange();
   int xRLimit = active->getX() + range;
   int xLLimit = active->getX() - range;
   int yTLimit = active->getY() + range;
   int yBLimit = active->getY() - range;

   for (int y = 0; y < tilesNorth(); y++) {
      for (int x = 0; x < tilesEast(); x++) {
	 /// Checks to make the tile is within the range
	 if ( ((x >= xLLimit) && (x <= xRLimit)) && (y == active->getY()) )
	    tiles[y][x]->rangeDisp(); /// sets the tile to be in range
	 if ( ((y >= yBLimit) && (y <= yTLimit)) && (x == active->getX()) )
	    tiles[y][x]->rangeDisp();
      }
   }
   /// Draws resulting board
   draw(active->getName() + "'s range displayed.", out);

   /// erases all of the in range highlighting
   for (int y = 0; y < tilesNorth(); y++) {
      for (int x = 0; x < tilesEast(); x++) {
	 if ( ((x >= xLLimit) && (x <= xRLimit)) && (y == active->getY()) )
	    tiles[y][x]->rangeErase();
	 if ( ((y >= yBLimit) && (y <= yTLimit)) && (x == active->getX()) )
	    tiles[y][x]->rangeErase();
      }
   }

}

Tile ConcreteBoard::getObst(char obstacle){
   switch(obstacle){
      /// Returns resulting obstacle tile variable stored in the board object
      case 'a':
	 return obstA;
	 break;
      case 'b':
	 return obstB;
	 break;
      case 'c':
	 return obstC;
	 break;
      case 'd':
	 return obstD;
	 break;
      case 'e':
	 return obstE;
	 break;
      case 'f':
	 return obstF;
	 break;
      case 'g':
	 return obstG;
	 break;
      case 'h':
	 return obstH;
	 break;
      case 'i':
	 return obstI;
	 break;
      case 'j':
	 return obstJ;
	 break;
      case 'k':
	 return obstK;
	 break;
      case 'l':
	 return obstL;
	 break;
      case 'm':
	 return obstM;
	 break;
      case 'n':
	 return obstN;
	 break;
      default:
	 return 0;
	 break;
	 
   }
   
}
