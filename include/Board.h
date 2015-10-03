/// \file
#ifndef __BOARD_H
#define __BOARD_H

#include "robot.h"
#include "Tile.h"

using namespace std;

/// Abstract class defining the Board interface
class BoardInterface {
public:

/// Name: tilesNorth()
/// \param[in] none
/// \return returns an integer containing the number of tiles high the board is
   virtual int tilesNorth() = 0;
   
/// Name: tilesEast()
/// \param[in] none
/// \return returns an integer containing the number of tiles wide the board is
   virtual int tilesEast() = 0;

/// Name: draw()
/// \param[in] takes two parameters, a string called statMess and an ostream reference called out
/// \post outputs the layout of the current board state and all status messages to the designated output stream 
/// \return none
   virtual void draw(string statMess, ostream& out) = 0;

/// virtual destructor for the Board interface.    
   virtual ~BoardInterface() {};

/// Name: getTile()
/// \param takes two integers, x and y, which are the coordinates of the tile to be returned
/// \return returns a pointer to a tile which is designated by the coordinates provided
/// Note: The exception will never be thrown in this iteration, but it will be
/// used in the more advanced iteration
   virtual Tile getTile(int x, int y, ostream& out) = 0;

/// Name: move()
/// \param[in] takes four parameters, a char called dir that takes in the desired direction, a RobotInterface pointer called active which holds the active robot and another that holds the obstacle robot and an ostream reference called output
/// \post changes the locations of the active player passed to the function and draws the board with the updated locations of the players 
/// \return none
   virtual void move(char dir, RobotInterface* active,
		     RobotInterface* otherBot, ostream& output) = 0;

/// Name: P1Location()
/// \param[in] none
/// \return returns a tile pointer to the location of Player 1
   virtual Tile P1Location() = 0;

/// Name: P2Location()
/// \param[in] none
/// \return returns a tile pointer to the location of Player 2
   virtual Tile P2Location() = 0;

/// Name: P1ChangeLocation()
/// \param[in] takes in two ints, x and y, which are the coordinates of the tile you wish to change the location of Player 1 to. 
/// \return none
   virtual void P1ChangeLoc(int, int, ostream&) = 0;

/// Name: P2ChangeLocation()
/// \param[in] takes in two ints, x and y, which are the coordinates of the tile you wish to change the location of Player 2 to. 
/// \return none
   virtual void P2ChangeLoc(int, int, ostream&) = 0;

/// Name: displayRange()
/// \param[in] takes in a robot interface pointer pointing to the robot whos range you wish to display and an ostream reference which is where you want the range to be displayed 
/// \return none
   virtual void displayRange(RobotInterface*, ostream&) = 0;

/// Name: getObst()
/// \param[in] takes in a character that tells which obstacle to return
/// for example getObst(a) return the Tile position of obstA
/// This function allows the user class to know if the active player is on
/// a Tile that is an obstacle and from there can hurt the robot
/// \return none
   virtual Tile getObst(char obstacle) = 0;
   
};

typedef BoardInterface* Board;

#endif
