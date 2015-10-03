/// \file

#ifndef __TESTTILE_H
#define __TESTTILE_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "ConcreteTile.h"

/// Test class for ConcreteTile implementation of the Tile interface.

class TestTile : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestTile);
	CPPUNIT_TEST(testGetState);
	CPPUNIT_TEST(testRobotMoved);
	CPPUNIT_TEST(testRobotArrived);
	CPPUNIT_TEST(testPlaceObstacle);
	CPPUNIT_TEST_SUITE_END();
        
private:
	/// Pointers to 2 tiles, one to hold a robot and one with nothing
	Tile tile, robTile;
				
public:

	/// Initialises the tile variables 
	void setUp() {
	   tile = new ConcreteTile();
	   robTile = new ConcreteTile(); 
	}
	
	/// frees memory for the tiles
	void tearDown() {
	   delete tile;
	   delete robTile;
	}
	
	/// test that tiles are empty initially
	void testGetState() {
	   CPPUNIT_ASSERT(tile->getState() == ".");
	   CPPUNIT_ASSERT(robTile->getState() == ".");
	}
	
	/// test that the robot arrive function caused the tile to represent
	/// a robot
	void testRobotArrived()  {
	   robTile->robotArrive();
	   CPPUNIT_ASSERT(robTile->getState() == "R");
	}
	
	/// test that the robot moved function caused the robot representation
	/// to be removed from the tile
	void testRobotMoved()  {
	   robTile->robotMoved();
	   CPPUNIT_ASSERT(robTile->getState() == ".");
	}


	/// test that the initially empty tile can represent an obstacle
	/// placed on it by the place obstacle function
	void testPlaceObstacle()  {
	   tile->placeObstacle();
	   CPPUNIT_ASSERT(tile->getState() == "X");
	}
		
};

#endif
