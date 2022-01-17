#ifndef PERCENTCHANGEGENERATOR_H
#define PERCENTCHANGEGENERATOR_H

#include "ReportGenerator.h"
#include "ReportData.h"
#include "AscBehaviour.h"

//the percentChangeGenerator class is a derived class from the reportGenerator base class that does the functionality for 2.2
//the purpose of this class is to generator a report that checks the changes in animal number percentage from 2011 to 2016
//and displays that information to the client

//the constructor dynamically allocates a new AscendingBehvaiour object that is used to initialize the dynamically
//allocated reportData data member using type float (percentage) as a key to sort the rows in ascending order
//note that all the maps are inherited and this class makes use of the year and animal maps

//the compute member function (inherited) calculates the change in animal percent from 2011 to 2016 for every province. To calculate the percentages
//the function calls the percentCalc member function. Once a region's change is found, compute calls
//formatData (that takes in an animalName as a string, the percent animals in 2011, 2016 and the percent change) and
//adds the formatted row to reportData to be sorted in ascending behaviour

//percentCalc takes in a numerator, denominator and calculates the percentage and returns it through the output parameter
//as a float reference

//addUpAllAnimals finds the total animals in canada per year
//it takes in a vector of record pointers that correpond to a particular year and adds the number of animals to that year
//as long as the region is "CAN". The total number is then returned as an int reference

//note that all these member functions are const

class PercentChangeGenerator: public ReportGenerator{
  public:
    PercentChangeGenerator();
    virtual ~PercentChangeGenerator();
    virtual void compute();

  private:
    ReportData<float>* reportData;
    void formatData(string, float, float, float) const;
    void printReport() const;
    void percentCalc(float, float, float&) const;
    void addUpAllAnimals(vector<Record*>&, int &) const;
};

#endif
