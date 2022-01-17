#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Record.h"

Record::Record(int y, string reg, string subReg, string animal, int farms, int anNum){
  animalType = animal;
  year = y;
  region = reg;
  subRegion = subReg;
  numFarms = farms;
  numAnimals = anNum;
}

Record::~Record() { }

string Record::getRegion(){
  return region;
}

string Record::getSubRegion(){
  return subRegion;
}

int Record::getAnimalNumber(){
  return numAnimals;
}

int Record::getYear(){
  return year;
}

string Record::getAnimalName(){
  return animalType;
}

int Record::getNumFarms(){
  return numFarms;
}
