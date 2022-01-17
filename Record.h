#ifndef RECORD_H
#define RECORD_H

//The record class' purpose is to represent a record about a specific region/subregion's
//number of farms/animals for the animal type of the record

//The member functions for this class are mostly just getters for all the data members,
//which are the region (as string), year (as int), animalName (as string), subregion (as string),
//and number of farms (as int)

//The default constructor takes in the year, the region, then subregion, animaltype, numfarms, then numAnimals

class Record{
  public:
    Record(int = 0, string = "unknown", string = "unknown", string = "unknown", int = 0, int = 0);
    ~Record();
    string getRegion();
    int getAnimalNumber();
    int getYear();
    string getAnimalName();
    string getSubRegion();
    int getNumFarms();

  private:
    string region;
    int numAnimals;
    int year;
    string subRegion;
    int numFarms;
    string animalType;
};

#endif
