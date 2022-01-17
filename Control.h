#ifndef CONTROL_H
#define CONTROL_H

#include <vector>
#include "SubRegionGenerator.h"
#include "PercentChangeGenerator.h"
#include "RegionGenerator.h"
#include "View.h"

#define REGION 0
#define PERCENT 1
#define SUBREGION 2

//this class is the primary control object and it's purpose is to maintain the
//flow of the program at hand using the launch() member function called by main.
//the launch member function really just computes each generator's functionality
//depending on the generator (since the function is polymorphic)
//and displays the results to the user using its view data member

//For data members, the control class only has a vector of generator pointers
//there are 3, one PercentChangeGenerator, one SubRegionGenerator, one RegionGenerator
//and they are stored in the same order in the array as displayed as the menu

//the contructor dynamically allocates these generators and adds them to generators Vector
//while the detructor deletes the generators in the vector

class Control{
  public:
    Control();
    ~Control();
    void launch();

  private:
    vector<ReportGenerator*> generators;
    View view;
};

#endif
