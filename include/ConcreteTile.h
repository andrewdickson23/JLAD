/// \file
#ifndef __CONCRETETILE_H
#define __CONCRETETILE_H

#include "Tile.h"
#include <string>

/// Class implementing the Tile interface
class ConcreteTile : public TileInterface {
private:
   bool robot;    ///< contains a robot or doesn't
   bool obst;     ///< contains an obstacle or doesn't
   bool inRange;  ///< is in range of a robot or isn't
   
  public:

   /// Name: getState()
   /// \param none
   /// \return returns a string variable, "." for empty tile, "X" for an obstacle, "R" for a robot, and is highlighted green if the tile is in range 
   virtual std::string getState();

   /// Name: robotMoved()
   /// \param none
   /// Purpose: Moves the robot from the current tile
   /// \return none
   virtual void robotMoved();
   
   /// Name: robotArrive()
   /// \param none
   /// Purpose: Places a robot on the tile
   /// \return none
   virtual void robotArrive();

   /// Name: placeObstacle()
   /// \param none
   /// Purpose: Places an obstacle on the tile
   /// \return none
   virtual void placeObstacle();

   /// Name: rangeDisp()
   /// \param none
   /// Purpose: Switches the character output to a green highlight because it is in range
   /// \return none 
   virtual void rangeDisp();

   /// Name: rangeErase()
   /// \param none
   /// Purpose: Switches the character output to be normal because it is not in range
   /// \return none 
   virtual void rangeErase();
   
   /// Destructor
   virtual ~ConcreteTile() {};
   
   /// Name: Constructor for concrete tile
   /// \param none
   /// Purpose: to construct a blank tile
   ConcreteTile();

};


#endif
