/// \file
#include "../../include/RandNorm.h"
#include "../../include/user.h"
#include "../../include/utility.h"
#include "../../include/ConcreteBoard.h"
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cmath>

std::string User::play(RobotInterface* player1, RobotInterface* player2, BoardInterface* board1) {
   
   randstub* prod = new randnorm();
   
   char decision;
   int temp;
   std::string outputString = "";  
   
   std:: cout<<"Please display an action: ";
   decision = getMove(cout, cin);

   ///the switch case controlling what action is commenced
   switch(decision){
      case 'r':/// show range
	 board1->displayRange(player1, std::cout);
	 break;
	 
      case 'j': ///attacking case
	 ///check if the deffending robat is withing attacking robots range
	 if ( (player1->getX() == player2->getX() && abs(player1->getY()-player2->getY()) <= player1->getRange()) || (player1->getY() == player2->getY() && abs(player1->getX()-player2->getX()) <= player1->getRange()) )
	 {
	    ///is there is a sufficient charge
	    if (player1->getCharge() > 0)
	    {
	       temp = player1->attack(player2, prod);
	       /// did the attack miss?
	       ///if so display a specific message
	       if (temp == 0)
	       {
		  board1->draw("Your attack missed", std::cout);
		  delete prod;
		  return "end turn.";
		     }
	       else
	       {
		  ///display the amount of damage 
		  outputString += "attacked for ";
		  char mnumster[21];
		  sprintf(mnumster, "%d", temp);
		  outputString.append(mnumster);
		  outputString += " damage";

		  ///displays the death of an opponant
		  if (player2->getHP() <= 0){
		     outputString += ", killing your opponent. ";
		     outputString += player1->getName();
		     outputString += " has won the match!";
		  }
		  
		  board1->draw(outputString, std::cout);
		  delete prod;
		  return "end turn.";
	       }
	    }
	    else
	    {
	       board1->draw("Insufficient charge.", std::cout);
	       break;
	    }
	 }
	 else
	 {
	    /// display a comment if the user's robot is out of range
	    board1->draw("You are out of range. enter r to display blocks available to hit", std::cout);
	 }
	 break;
	 
      case 'k': ///defending case
	 /// display that defence is raised or already maxed 
	 if (player1->getDefUse() == player1->getDefCap())
	 {
	    board1->draw("Defence is already maxed.", std::cout);
	    break;
	       }
	 else
	 {
	    player1->defend();
	    board1->draw("Defence increased.", std::cout);
	    delete prod;
	    return "end turn.";
	 }
	 break;
	 
      case 'l': ///charging case
	 player1->charge();
	 board1->draw("Battery Charge increased.", std::cout);
	 delete prod;
	 return "end turn.";
	 break;

      default: ///movement
	 board1->move(decision, player1, player2,std::cout);

	 ///check if the active player is player 1
	 if(board1->getTile(player1->getX(), player1->getY(), std::cout) == board1->P1Location())
	 {
	    ///checks if the player moves onto an obstacle
	    ///if so take damage and display a message
	    if(
	       (board1->P1Location() == board1->getObst('a')) ||
	       (board1->P1Location() == board1->getObst('b')) ||
	       (board1->P1Location() == board1->getObst('c')) ||
	       (board1->P1Location() == board1->getObst('d')) ||
	       (board1->P1Location() == board1->getObst('e')) ||
	       (board1->P1Location() == board1->getObst('f')) ||
	       (board1->P1Location() == board1->getObst('g')) ||
	       (board1->P1Location() == board1->getObst('h')) ||
	       (board1->P1Location() == board1->getObst('i')) ||
	       (board1->P1Location() == board1->getObst('j')) ||
	       (board1->P1Location() == board1->getObst('k')) ||
	       (board1->P1Location() == board1->getObst('l')) ||
	       (board1->P1Location() == board1->getObst('m')) ||
	       (board1->P1Location() == board1->getObst('n'))
	       ){
	       player1->takeDamage(20);
	       board1->draw("20 Spike damage applyed.", std::cout);
	    }
	 }
	 else{
	    if(
	       (board1->P2Location() == board1->getObst('a')) ||
	       (board1->P2Location() == board1->getObst('b')) ||
	       (board1->P2Location() == board1->getObst('c')) ||
	       (board1->P2Location() == board1->getObst('d')) ||
	       (board1->P2Location() == board1->getObst('e')) ||
	       (board1->P2Location() == board1->getObst('f')) ||
	       (board1->P2Location() == board1->getObst('g')) ||
	       (board1->P2Location() == board1->getObst('h')) ||
	       (board1->P2Location() == board1->getObst('i')) ||
	       (board1->P2Location() == board1->getObst('j')) ||
	       (board1->P2Location() == board1->getObst('k')) ||
	       (board1->P2Location() == board1->getObst('l')) ||
	       (board1->P2Location() == board1->getObst('m')) ||
	       (board1->P2Location() == board1->getObst('n'))
	       ){
	       player1->takeDamage(20);
	       board1->draw("20 Spike damage applyed.", std::cout);
	    }
	 }
	 
	 break;
	    
   }

   delete prod;
   return "continue your turn.";
}
