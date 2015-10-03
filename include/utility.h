/// \file

#ifndef UTILITY_H
#define UTILITY_H

#include <cstdlib>
#include <string>
#include <limits>
#include <iostream>
#include <iomanip>
using namespace std;

// ASCI codes make writing much easier.
//const static string RED = "\033[0;31m";
//const static string GREEN_BACKGROUND = "\033[42m";

/// function to grab explicitly w,s,a, or d (and return it as a character)
//
///    \param out -- ostream object where the output will be printed (if the user enters invalid input). Typically cout.
///    \param in -- the istream object where the input will be captured from. Typically cin.
///
///     \return char w,s,a, or d based on user input
char getMove(ostream& out, istream& in);



/// function to grab explicitly an integer, and return it as an integer.
//
///    \param out -- ostream object where the output will be printed (if the user enters invalid input). Typically cout.
///    \param in -- the istream object where the input will be captured from. Typically cin.
///
///     \return an integer that the user has entered.
int getInt(ostream& out, istream& in);

/// function to explicity get a boolean value, and return it as such
//
///     \param out -- ostream object where the output will be printed (if the user enters invalid input). Typically cout.
///     \param in -- the istream object where the input will be captured from. Typically cin.
///
///     \return the users' decision
bool getBool(ostream& out, istream& in);

/// function to provide extra style. Will "deliberately" print a string, printing each character \i time apart.
/// \param in -- the string that you want to be printed.
/// \param time -- the time to separate each character printing.
///
/// \post the string is printed one character at a time, delayed by \i time, to standard output.
void deliberatePrintStyle(const string &in, const unsigned &time);

/// alias to dPS that uses unsigned ints for the time.
void dPS(const string &in, const unsigned &time);

/// alias to deliberatePrintStyle. Uses int to make things easier while working. Includes a default value.
void dPS(const string &in, int time=80000);

void pc(const string &in, int time=20000, bool bold=false);

#endif
