#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <vector>
#include "Record.h"
#include "Map.h"

//the ReportGenerator class is a base class for the other generator classes
//that generate reports for the user. Its purpose is to be abstract and
//store all the static member functions and collections that it's derived classes need

//Some of these collections are the primary collectiom that has all the record pointers,
//the regionMap that has regions as keys (string), animalMap has animals as keys (string), and yearMap
//that has years as keys (int)

//The member functions are all void and take no parameters and essentially load
//and populate all the maps with the loadRecords() and populate() member function, which are public

//the void cleanup() function deletes all the records in the primary collection

//the pure virtual compute() gets inherited by all the derived classes and makes this class abstract

class ReportGenerator{
  public:
    ReportGenerator();
    virtual ~ReportGenerator();
    static void loadRecords();
    static void populateMaps();
    static void cleanUp();
    virtual void compute() = 0;

  private:
    static vector <Record*> records;

  protected:
    static Map<string> regionMap;
    static Map<string> animalMap;
    static Map<int> yearMap;
};

#endif
