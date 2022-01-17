#include <iostream>
using namespace std;

#include "Control.h"

//author: Brian Yang 101140298

//the purpose of this program is to take data from statistics Canada about the
//number of farms and animals in a particular region and display the percent changes
//over 5 years and calculate the propotions of these animals for province and canada to the user
//the program must also find the largest subregion per province

//the main essentially just creates a control object and calls its public launch function
//to initialize the records from the file provided and creates a record for
//each line in the file. The records are then added to every map to be used
//in the derived gernerator files to produce the 3 different reports

int main(){
  Control control;
  control.launch();
  return 1;
}
