/// \file
#ifndef __USER_H
#define __USER_H

#include <string>
#include <ctime>
#include <cstdlib>
#include "robot.h"
#include "ConcreteBoard.h"

class User{
  public:
   /// name: play
   /// \param[in] player1 (robot commiting the action)
   /// \param[in] player2 (robot being attacked)
   std::string play(RobotInterface* player1, RobotInterface* player2, BoardInterface* board1);
};

#endif
