/// \file
#include <cppunit/ui/text/TestRunner.h>
#include "TestTile.h"
#include "TestBoard.h"
#include "robotTest.h"
#include "revAiTest.h"

int main() {
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TestTile::suite());
	runner.addTest(TestBoard::suite());
	runner.addTest(robotTest::suite());
	runner.addTest(revAiTest::suite());
	runner.run();
	return 0;
}
