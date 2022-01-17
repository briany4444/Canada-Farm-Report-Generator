#ifndef SUBREGIONGENERATOR_H
#define SUBREGIONGENERATOR_H

#include "ReportGenerator.h"
#include "ReportData.h"
#include "DescBehaviour.h"

//the subregiongenerator class is a derived class from the reportGenerator base class that does the functionality for 2.3
//the purpose of this class is to generator a report that seeks the subregion with the most horses in 2016 for each region
//and displays that information to the client

//the constructor dynamically allocates a new AscendingBehvaiour object that is used to initialize the dynamically
//allocated reportData data member using type int as a key to sort the rows in ascending order

//the compute member function finds the subregion with most horses in a region for evert province and calls formatData
//to format the string for each region. The formatData, which takes a regionName (string), subregion (string) and number of horses
//and the formated string to the reportData data member in ascending order (key is a int)
//the printReport creates a new text file and prints all the information to that textfile and also prints to the console

//findMostHorses takes in a vector of record pointers that correpond to horses and finds the subregion with the most horses that
//correpond to the regionName passed in (as a string) by keeping track of the largest number. Once iterated, the largest amount of
//horses is returned as an int reference (mostFreq) and the name of the subregion is also returned (as a string reference)

//note that all these member functions are const

class SubRegionGenerator: public ReportGenerator{
  public:
    SubRegionGenerator();
    virtual ~SubRegionGenerator();
    virtual void compute();

  private:
    ReportData<int>* reportData;
    void printReport() const;
    void formatData(string, string, int) const;
    void findMostHorses(vector<Record*>&, string, int&, string&) const;
};

#endif
