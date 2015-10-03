/// \file
#include "../../include/ConcreteTile.h"
#include <string>

std::string ConcreteTile::getState() {

   std::string output = "";
   
   if(inRange){  /// If its in range, highlight it green
      output += "\033[42m";
      if (robot)
	 output += "R";
      else if(obst)
	 output += 'X';
      else
	 output += '.';

      output += "\033[0m";
      return output;
   } else{

      if (robot)
	 output += "R";
      else if(obst)
	 output += 'X';
      else
	 output += '.';
      return output;
   }
}

ConcreteTile::ConcreteTile()  {
   robot = false;
   obst = false;
   inRange = false;
}


void ConcreteTile::robotMoved()  {
   robot = false;
}


void ConcreteTile::robotArrive()  {
   robot = true;
}

void ConcreteTile::placeObstacle() {
   obst = true;
}

void ConcreteTile::rangeDisp() {
   inRange = true;
}

void ConcreteTile::rangeErase() {
   inRange = false;
}
