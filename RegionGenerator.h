#ifndef REGIONGENERATOR_H
#define REGIONGENERATOR_H

#include "ReportGenerator.h"
#include "ReportData.h"
#include "DescBehaviour.h"

//the region generator class is a derived class from the reportGenerator base class that does the functionality for 2.1
//the purpose of this class is to generator a report of the percentage of a specfic animal per region in 2016
//and displays that information to the client in the terminal as well as a textfile generated

//the constructor dynamically allocates a new descendingBehvaiour object that is used to initialize the dynamically
//allocated reportData data member (using type float as a key) and sort each row in descending order when printed

//the compute member function computes all the particular animal percentages for each region and calls formatData
//to format the string for each row. The formatData, which takes a regionName, total percent (as the key) and a vector
//of all the region's percentages and adds it to reportData data member in descending order
//the printReport creates a new text file and prints all the information to that textfile and also prints it on it the console
//Note that the compute() member function and all the static maps are inherited from the base class

//findFarmNumber takes in a vector of records that correpond to an animal and searches until
//it finds a record that matches the region passed in (as a string). After that, the number of farms for that record
//is returned as an int reference as an output parameter

//percentCalc takes in a numerator, denominator and calculates the percentage and returns it through the output parameter
//as a float reference

//addUpFarms takes a vector of record pointers (for an animal) and adds up all the farms with the subregion "all" except for Canada
//this total is returned through an output parameter as an int reference

class RegionGenerator: public ReportGenerator{
  public:
    RegionGenerator();
    virtual ~RegionGenerator();
    virtual void compute();

  private:
    ReportData<float>* reportData;
    void formatData(string, float, float[], int) const;
    void printReport() const;
    void percentCalc(float, float , float&) const;
    void findFarmNumber(vector<Record*>&, string, int&) const;
    void addUpFarms(vector<Record*>&, int&) const;
};

#endif
