/// \file

/// JLAD Tile interface file

#ifndef __TILE_H
#define __TILE_H

#include <string>

/// Abstract class defining the Tile interface
class TileInterface {
  public:
   
   /// Name: getState()
   /// \param none
   /// \return returns a string variable, "." for empty tile, "X" for an obstacle, "R" for a robot, and is highlighted green if the tile is in range 
   virtual std::string getState() = 0;
   
   /// Name: robotMoved()
   /// \param none
   /// Purpose: Moves the robot from the current tile
   /// \return none
   virtual void robotMoved() = 0;
   
   /// Name: robotArrive()
   /// \param none
   /// Purpose: Places a robot on the tile
   /// \return none
   virtual void robotArrive() = 0;

   /// Name: placeObstacle()
   /// \param none
   /// Purpose: Places an obstacle on the tile
   /// \return none
   virtual void placeObstacle() = 0;

   /// Name: rangeDisp()
   /// \param none
   /// Purpose: Switches the character output to a green highlight because it is in range
   /// \return none 
   virtual void rangeDisp() = 0;

   /// Name: rangeErase()
   /// \param none
   /// Purpose: Switches the character output to be normal because it is not in range
   /// \return none    
   virtual void rangeErase() = 0;
   
   /// Destructor
   virtual ~TileInterface() {};
   
};

/// typedef for easier code writing
typedef TileInterface* Tile;

#endif
