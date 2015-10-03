/// \file
#ifndef __CONCRETEBOARD_H
#define __CONCRETEBOARD_H

#include <vector>
#include <string>
#include "Board.h"
#include "robot.h"
using namespace std;

/// class implementing the Board interface
class ConcreteBoard : public BoardInterface {
  public:
   int xBound, yBound; ///< private members for the board size
   RobotInterface* player1; ///< stores a pointer to player 1
   RobotInterface* player2; ///< stores a pointer to player 2
   Tile robotA; ///< stores a pointer to the location of player 1
   Tile robotB; ///< stores a pointer to the location of player 2
   Tile obstA; ///< stores a pointer to an obstacle tile
   Tile obstB; ///< stores a pointer to an obstacle tile
   Tile obstC; ///< stores a pointer to an obstacle tile
   Tile obstD; ///< stores a pointer to an obstacle tile
   Tile obstE; ///< stores a pointer to an obstacle tile
   Tile obstF; ///< stores a pointer to an obstacle tile
   Tile obstG; ///< stores a pointer to an obstacle tile
   Tile obstH; ///< stores a pointer to an obstacle tile
   Tile obstI; ///< stores a pointer to an obstacle tile
   Tile obstJ; ///< stores a pointer to an obstacle tile
   Tile obstK; ///< stores a pointer to an obstacle tile
   Tile obstL; ///< stores a pointer to an obstacle tile
   Tile obstM; ///< stores a pointer to an obstacle tile
   Tile obstN; ///< stores a pointer to an obstacle tile
   
   /// A 2D vector of tile pointers which represents the game board
   std::vector <std::vector <Tile> > tiles;
   
/// Name: tilesNorth()
/// \param[in] none
/// \return returns an integer containing the number of tiles high the board is
   int tilesNorth();

/// Name: tilesEast()
/// \param[in] none
/// \return returns an integer containing the number of tiles wide the board is
   int tilesEast();
   
/// Name: draw()
/// \param[in] takes two parameters, a string called statMess and an ostream reference called out
/// \post outputs the layout of the current board state and all status messages to the designated output stream 
/// \return none
   virtual void draw(string statMass, ostream& out);
   
   /// Constructor
   /// \param [in] userX is the number of tiles wide this board is
   /// \param [in] userY is the number of tiles high this board is
   /// \param [in] a is a pointer to a robot interface for player 1
   /// \param [in] b is a poitner to a robot interface for player 2 
   ConcreteBoard(int userX, int userY, RobotInterface* a, RobotInterface* b);
   
   /// virtual destructor for the ConcreteBoard. 
   virtual ~ConcreteBoard();
   
/// Name: getTile()
/// \param [in] takes two integers, x and y, which are the coordinates of the tile to be returned
/// \return returns a pointer to a tile which is designated by the coordinates provided
/// Note: The exception will never be thrown in this iteration, but it will be
/// used in the more advanced iteration
   virtual Tile getTile(int x, int y, ostream& out);

/// Name: move()
/// \param[in] takes four parameters, a char called dir that takes in the desired direction, a RobotInterface pointer called active which holds the active robot and another that holds the obstacle robot and an ostream reference called output
/// \post changes the locations of the active player passed to the function and draws the board with the updated locations of the players 
/// \return none
   virtual void move(char dir, RobotInterface* active,
		     RobotInterface* otherBot, ostream& output);

/// Name: P1Location()
/// \param[in] none
/// \return returns a tile pointer to the location of Player 1
   virtual Tile P1Location();

/// Name: P2Location()
/// \param[in] none
/// \return returns a tile pointer to the location of Player 2
   virtual Tile P2Location();

/// Name: P1ChangeLocation()
/// \param[in] takes in two ints, x and y, which are the coordinates of the tile you wish to change the location of Player 1 to. 
/// \return none
   virtual void P1ChangeLoc(int, int, ostream&);

/// Name: P2ChangeLocation()
/// \param[in] takes in two ints, x and y, which are the coordinates of the tile you wish to change the location of Player 2 to. 
/// \return none
   virtual void P2ChangeLoc(int, int, ostream&);

/// Name: displayRange()
/// \param[in] takes in a robot interface pointer pointing to the robot whos range you wish to display and an ostream reference which is where you want the range to be displayed 
/// \return none
   virtual void displayRange(RobotInterface*, ostream&);

/// Name: getObst()
/// \param[in] takes in a character that tells which obstacle to return
/// for example getObst(a) return the Tile position of obstA
/// This function allows the user class to know if the active player is on
/// a Tile that is an obstacle and from there can hurt the robot
/// \return none
   virtual Tile getObst(char obstacle);
};

#endif
