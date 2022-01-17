#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

#include "ReportGenerator.h"

Map<string> ReportGenerator::regionMap;
Map<string> ReportGenerator::animalMap;
Map<int> ReportGenerator::yearMap;
vector <Record*> ReportGenerator::records;

ReportGenerator::ReportGenerator() { }

ReportGenerator::~ReportGenerator() { }

void ReportGenerator::loadRecords(){
  ifstream infile("farms.dat", ios::in);
  if (!infile) {
    cout << "file not found" << endl;
    return;
  }
  int year, numFarms, animalNum;
  string region, subRegion, animal;
  while(infile >> year >> region >> subRegion >> animal >> numFarms >> animalNum){
    Record *record = new Record(year, region, subRegion, animal, numFarms, animalNum);
    if(record == nullptr){
      return;
    }
    records.push_back(record);
  }
}

void ReportGenerator::populateMaps() {
  for(int i =0; i < records.size(); i++){
    animalMap.add(records[i]->getAnimalName(), records[i]);
    regionMap.add(records[i]->getRegion(), records[i]);
    yearMap.add(records[i]->getYear(), records[i]);
  }
}

void ReportGenerator::cleanUp(){
  for(int i =0; i < records.size(); i++){
    delete records[i];
  }
}
