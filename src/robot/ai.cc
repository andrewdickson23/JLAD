/// \file
#include "../../include/RandNorm.h"
#include "../../include/ai.h"

std::string Ai::play(RobotInterface* player1, RobotInterface* player2, randstub*aiTest) {

   randstub* prod = new randnorm();
   /// outputString is the returned output which will be given to the draw func
   /// allowing for the description of what has happened to be displayed
    std::string outputString = "";

    /// charge the robot if its charge is 0 and its defence is capped
    if (player1->getCharge() == 0 && player1->getDefence() == player1->getDefCap()){
       //charging
       player1->charge();
       outputString += player1->getName();
       outputString += " charged.";
    }

    /// attack the opponant if its charge is a relatively large value,
    /// and defence is capped
    else if (player1->getCharge() >= 5 && player1->getDefence() == player1->getDefCap())
    {
       //attacking
       player1->attack(player2, prod);
	  /// displays a different message if a player has killed the other
	  if (player2->getHP() <= 0){
	     outputString += player1->getName();
	     outputString += " killed ";
	     outputString += player2->getName();
	     outputString += ".  ";
	     outputString += player1->getName();
	     outputString += " has won the match!";
	  }
	  /// basic attack comment
	  else{
	     outputString += player1->getName();
	     outputString += " attacked ";
	     outputString += player2->getName();
	  }

    }

    else if (player1->getCharge() >= 5){
       if (aiTest->randvar() == false)
	  srand(time(NULL));
       else
	  srand(1); //rand() generates the value 1804289383 if srand(1)
       
       //attacking
       if (rand()%5 <= 3){
	  player1->attack(player2, prod);
	  /// displays a different message if a player has killed the other
	  if (player2->getHP() <= 0){
	     outputString += player1->getName();
	     outputString += " killed ";
	     outputString += player2->getName();
	     outputString += ".  ";
	     outputString += player1->getName();
	     outputString += " has won the match!";
	  }
	  /// basic attack comment
	  else{
	     outputString += player1->getName();
	     outputString += " attacked ";
	     outputString += player2->getName();
	  }
       }
       
       //defending
       else{
	  player1->defend();
	  outputString += player1->getName();
	  outputString += " raised their defence by one.";
       }
    }
    
    /// defence is capped:
    /// 80% chance to attack the opponant
    /// 20% chance to charge
    else if (player1->getDefence() == player1->getDefCap()){
       
       if (aiTest->randvar() == false)
	  srand(time(NULL));
       else
	  srand(1); //rand() generates the value 1804289383 if srand(1)
       
       //attacking
       if (rand()%5 <= 3){
	  player1->attack(player2, prod);
	  /// displays a different message if a player has killed the other
	  if (player2->getHP() <= 0){
	     outputString += player1->getName();
	     outputString += " killed ";
	     outputString += player2->getName();
	     outputString += ".  ";
	     outputString += player1->getName();
	     outputString += " has won the match!";
	  }
	  /// basic attack comment
	  else{
	     outputString += player1->getName();
	     outputString += " attacked ";
	     outputString += player2->getName();
	  }
       }
       
       //charging
       else{
	  player1->charge();
	  outputString += player1->getName();
	  outputString +=" charged.";
       }
    }
    
    /// if charge is 0:
    /// 80% chance to charge
    /// 20% chance to defend
    else if (player1->getCharge() == 0){
       
       if (aiTest->randvar() == false)
	  srand(time(NULL));
       else
	  srand(1); //rand() generates the value 1804289383 if srand(1)
       
       // charging
       if (rand()%5 <= 3){
	  player1->charge();
	  outputString += player1->getName();
	  outputString +=" charged.";
       }
       // defending
       else{
	  player1->defend();
	  outputString += player1->getName();
	  outputString += " raised their defence by one.";
       }
    }
    
    /// basic ai:
    /// 50% chance to attack
    /// 25% chance to defend
    /// 25% chance to charge
    else{
       
       if (aiTest->randvar() == false)
	  srand(time(NULL));
       else
	  srand(1); //rand() generates the value 1804289383 if srand(1)
       
       int temp = rand()%5;

       //attacking
       if (temp<=1){
	  player1->attack(player2, prod);
	  /// again, tests if player1 killed player2
	  if (player2->getHP() <= 0){
	     outputString += player1->getName();
	     outputString += " killed ";
	     outputString += player2->getName();
	     outputString += ".  ";
	     outputString += player1->getName();
	     outputString += " has won the match!";
	  }
	  /// basic attack comment
	  else{
	     outputString += player1->getName();
	     outputString += " attacked ";
	     outputString += player2->getName();
	  }
       }
       //defending
       else if (temp == 2){
	  player1->defend();
	  outputString += player1->getName();
	  outputString += " raised their defence by one.";
       }
       //charging
       else{
	  player1->charge();
	  outputString += player1->getName();
	  outputString +=" charged.";
       }
    }

    delete prod;
    /// returns the appropriate display message based on what move was taken
    return outputString;
}
