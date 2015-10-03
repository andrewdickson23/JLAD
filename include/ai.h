/// \file
#ifndef __AI_H
#define __AI_H

#include <string>
#include <ctime>
#include <cstdlib>
#include "robot.h"
#include "RandNorm.h"

/// Class defining the psuedo random (weighted based on current stats) algorithm
/// chances are based off whether or not the robot has a charge or not
/// robots without charge physically cannot attack and have a higher % to charge
/// robots with their deffence at the defined cap will not defend as it would
/// render a useless result

class Ai{
  public:
   /// name: play
   /// \param[in] player1 (robot commiting the action)
   /// \param[in] player2 (robot being attacked)
   /// \param[in] aiTest (the stub to set the seed for the random function)
   /// Purpose: decides the "random" action that player1 will take
   /// between the choices of attacking player2, defending or charging battery
   /// \return returns a string to be inputed into the draw board function
   /// to state what action is played
   std::string play(RobotInterface* player1, RobotInterface* player2, randstub* aiTest);
};

#endif
