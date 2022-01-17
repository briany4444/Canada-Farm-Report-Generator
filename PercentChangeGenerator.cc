#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#include "PercentChangeGenerator.h"

PercentChangeGenerator::PercentChangeGenerator(){
  CompareBehaviour<float> *ascBehaviour = new AscBehaviour<float>();
  if(ascBehaviour == nullptr){
    return;
  }
  reportData = new ReportData<float>(ascBehaviour);
  if(reportData == nullptr){
    return;
  }
}

PercentChangeGenerator::~PercentChangeGenerator(){
  delete reportData;
}

void PercentChangeGenerator::formatData(string animalName, float change, float eleven, float sixteen) const{
  stringstream ss;
  ss << setfill(' ') << setw(20) << animalName;
  ss << setfill(' ') << setw(6) << fixed << setprecision(1) << eleven;
  ss << setfill(' ') << setw(9) << fixed << setprecision(1) << sixteen;
  ss << setfill(' ') << setw(6) << "";
  if(change > 0){
    ss << "+";
  }
  ss << setfill(' ') << setw(3) << fixed << setprecision(1) << change << endl;
  reportData->add(change, ss.str());
}

void PercentChangeGenerator::printReport() const{
  stringstream ss;
  ss << endl;
  ss << setfill(' ') << setw(6) << "";
  ss << "PERCENTAGE CHANGE OF ANIMALS (2011-2016)" << endl;
  ss << setfill(' ') << setw(6) << "";
  ss << setfill('-') << setw(40) << "" << endl;
  ss << setfill(' ') << setw(46) << "2011     2016     Change" << endl << endl;
  ss << *reportData << endl;

  cout << ss.str();

  ofstream outfile("PercentChange.txt", ios::out);
  if (!outfile) {
    cout << "file not found" << endl;
    return;
  }
  outfile << ss.str();
}

void PercentChangeGenerator::compute(){
  try{
    vector <string> animals = animalMap.get();
    vector<Record*> twentyElevenRecords = yearMap[2011];
    vector<Record*> twentySixteenRecords = yearMap[2016];

    int animalsEleven = 0;
    int animalsSixteen = 0;

    addUpAllAnimals(twentyElevenRecords, animalsEleven);
    addUpAllAnimals(twentySixteenRecords, animalsSixteen);

    for(int i =0; i < animalMap.getSize(); i++){
      float percentTwentyEleven = 0.0f;
      float percentTwentySixteen = 0.0f;
      vector<Record*> animalRecords = animalMap[animals[i]];
      for(int j =0; j < animalRecords.size(); j++){
        if(animalRecords[j]->getRegion() != "CAN"){
          continue;
        }
        int year = animalRecords[j]->getYear();
        int animalNum = animalRecords[j]->getAnimalNumber();
        if(year == 2011){
          percentCalc((float)animalNum, (float) animalsEleven, percentTwentyEleven);
        }
        else if(year == 2016){
          percentCalc((float)animalNum, (float) animalsSixteen, percentTwentySixteen);
        }
      }
      float change = percentTwentySixteen - percentTwentyEleven;
      formatData(animals[i], change, percentTwentyEleven, percentTwentySixteen);
    }
    printReport();
    reportData->cleanUp();
  }
  catch(char const* error){
    cout << error << endl;
    return;
  }
}

void PercentChangeGenerator::percentCalc(float numerator, float denom, float& percent) const{
  if(denom == 0){
    percent = 0.0;
    return;
  }
  percent = (numerator / denom) * 100.0;
}

void PercentChangeGenerator::addUpAllAnimals(vector<Record*>& recordsThatYear, int& total) const{
  for(int i =0; i < recordsThatYear.size(); i++){
    if(recordsThatYear[i]->getRegion() == "CAN"){
      total += recordsThatYear[i]->getAnimalNumber();
    }
  }
}
