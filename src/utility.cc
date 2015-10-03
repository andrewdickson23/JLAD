//**************************************************************************
///\file
///\author James Palawaga
///\date November 26, 2012
//
// Implementation for the utility file. Provides extended functionality for
// classes.
//*************************************************************************

#include "utility.h"
//NOTE:: using standard namespace.
//NOTE:: All includes are inside of the header
using namespace std;

// ASCI codes to make writing color much easier.
//


int getInt(ostream& out, istream& in) {
   int ret; /// stores the variable for checking

   while (0 == 0) {
      if (in >> ret)
	 break;
      else { 
	 out << "Please supply a valid integer: ";
	 in.clear();
	 in.ignore(numeric_limits<streamsize>::max(), '\n');
      }
   }
   out << endl;
   return ret;
}

char getMove(ostream& out, istream& in) {
   string proc; /// stores the variable for checking

   while (1) {
      if ((in >> proc) && (proc.length() == 1) && ((tolower(proc[0]) == 'w') || (tolower(proc[0]) == 'd') || (tolower(proc[0]) == 'a') || (tolower(proc[0]) == 's') || (tolower(proc[0]) == 'r') || (tolower(proc[0]) == 'j') || (tolower(proc[0]) == 'k') || (tolower(proc[0]) == 'l')))
	 break;
      else {
	 cout << "Please supply a single valid move:";
	 in.clear();
	 in.ignore(numeric_limits<streamsize>::max(), '\n');
      }
   }
   
   out << endl;
   return tolower(proc[0]);
}
						
bool getBool(ostream& out, istream& in) {
   string ret; /// stores the variable for checking

   while (0 == 0) {
      if (in >> ret) {
	 if ((ret == "0") || (ret == "false") || (ret == "no") || (ret == "n"))
	    return false;
	 else if ((ret == "1") || (ret == "true") || (ret=="yes") || (ret=="y"))
	    return true;
	 else {
	    out << "Please supply a valid input: ";
	    in.clear();
	    in.ignore(numeric_limits<streamsize>::max(), '\n');
	 }
      }
      else { 
	 out << "Please supply a valid input: ";
	 in.clear();
	 in.ignore(numeric_limits<streamsize>::max(), '\n');
      }
   }
}

void deliberatePrintStyle(const string &in, const unsigned &time) {
   for (unsigned i = 0; i < in.length(); i++) {
      cout.flush();
      cout << in.at(i);
      cout.flush();
      usleep(time);
      cout.flush();
   }
}

void dPS(const string &in, const unsigned &time) {
   deliberatePrintStyle(in, time);
}

void dPS(const string &in, int time) {
   unsigned u = 0;
   if (time > 0)
      u = static_cast<unsigned>(time);
      
   deliberatePrintStyle(in, u);
}
 
 
void pc(const string &in, int time, bool bold) {
   int left = 40-(in.length()/2);

   string t = "";
   for (int i = 0; i < left; i++)
      t = t+" ";

   dPS(t, 2000);
   string gog = "";
   if (bold)
      gog = "\033[1m"+in+"\033[0m";
   else
      gog = in;
   deliberatePrintStyle(gog, time);

}
