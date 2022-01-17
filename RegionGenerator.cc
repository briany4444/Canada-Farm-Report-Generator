#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#include "RegionGenerator.h"

RegionGenerator::RegionGenerator(){
  CompareBehaviour<float>* descBehaviour = new DescBehaviour<float>();
  if(descBehaviour == nullptr){
    return;
  }
  reportData = new ReportData<float>(descBehaviour);
  if(reportData == nullptr){
    return;
  }
}

RegionGenerator::~RegionGenerator() {
  delete reportData;
}

void RegionGenerator::formatData(string regionName, float total, float percents[], int arrSize) const{
  stringstream ss;
  ss << regionName;
  for(int i =0; i < arrSize; i++){
    ss << setfill(' ') << setw(10) << fixed << setprecision(1) << percents[i];
  }
  ss << setfill(' ') << setw(10) << fixed << setprecision(1) << total << endl;
  reportData->add(total, ss.str());
}

void RegionGenerator::printReport() const{
  stringstream ss;
  ss << endl;
  ss << setfill(' ') << setw(70) << "PERCENTAGE OF FARMS BY REGION IN 2016" << endl;
  ss << setfill(' ') << setw(33) << "";
  ss << setfill('-') << setw(37) << "" << endl << endl;
  ss << "       Horses/    Goats   Llamas    Rabbits    Bison/     Elk/     Domestic   Wild      Mink     Totals" << endl;
  ss << "       Ponies             Alpacas              Buffalo    Wapiti     Deer     Boars" << endl << endl;
  ss << *reportData << endl;

  cout << ss.str();

  ofstream outfile("Region.txt", ios::out);
  if (!outfile) {
    cout << "file not found " << endl;
    return;
  }
  outfile << ss.str();
}


void RegionGenerator::compute(){
  try{
    vector<string> animals = animalMap.get();
    vector<string> regions = regionMap.get();

    int animalSize = animalMap.getSize();
    int regSize = regionMap.getSize();

    int allFarms = 0;
    for(int i =0; i < animalSize; i++){
      vector<Record*> animalRecords = animalMap[animals[i]];
      addUpFarms(animalRecords, allFarms);
    }

    int totalForAnimal[animalSize];
    for(int i =0; i < animalSize; i++){
      vector<Record*> animalRecords = animalMap[animals[i]];
      int totalFarms = 0;
      addUpFarms(animalRecords, totalFarms);
      totalForAnimal[i] = totalFarms;
    }

    for(int i = 0; i < regSize; i++){
      if(regions[i] == "CAN"){
        continue;
      }
      float percents[animalSize];
      int provinceFarms = 0;
      float provincePercent;
      for(int j =0; j < animalSize; j++){
        vector<Record*> animalRecords = animalMap[animals[j]];
        int farmNumber;
        float percent;
        findFarmNumber(animalRecords, regions[i], farmNumber);
        percentCalc((float)farmNumber, (float)totalForAnimal[j], percent);
        provinceFarms += farmNumber;
        percents[j] = percent;
      }
      percentCalc((float) provinceFarms, (float)allFarms, provincePercent);
      formatData(regions[i], provincePercent, percents, animalSize);
    }
    printReport();
    reportData->cleanUp();
  }
  catch(char const* error){
    cout << error << endl;
    return;
  }
}

void RegionGenerator::addUpFarms(vector<Record*>& animalRecords, int& total) const{
  for(int k =0; k < animalRecords.size(); k++){
    Record *record = animalRecords[k];
    if(record == nullptr){
      return;
    }
    if((record->getYear() == 2016) && (record->getSubRegion() == "All") && (record->getRegion() != "CAN")){
      total += animalRecords[k]->getNumFarms();
    }
  }
}

void RegionGenerator::findFarmNumber(vector<Record*>& animalRecords, string region, int& farmNumber) const{
  farmNumber = 0;
  for(int k =0; k < animalRecords.size(); k++){
    Record *record = animalRecords[k];
    if(record == nullptr){
      return;
    }
    if((record->getRegion() == region) && (record->getYear() == 2016) && (record->getSubRegion() == "All")){
      farmNumber = record->getNumFarms();
    }
  }
}

void RegionGenerator::percentCalc(float numerator, float denom, float &percent) const{
  if(denom == 0){
    percent = 0;
    return;
  }
  percent = (numerator/denom) * 100;
}
