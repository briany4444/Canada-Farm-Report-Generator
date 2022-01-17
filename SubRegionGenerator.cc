#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
#include <sstream>

#include "SubRegionGenerator.h"

SubRegionGenerator::SubRegionGenerator(){
  CompareBehaviour<int> *descBehaviour = new DescBehaviour<int>();
  if(descBehaviour == nullptr){
    return;
  }
  reportData = new ReportData<int>(descBehaviour);
  if(reportData == nullptr){
    return;
  }
}

SubRegionGenerator::~SubRegionGenerator(){
  delete reportData;
}

void SubRegionGenerator::printReport() const{
  stringstream ss;
  ss << endl;
  ss << setfill(' ') << setw(7) << "" << "SUB-REGION WITH MOST HORSES/PONIES BY REGION in 2016" << endl;
  ss << setfill(' ') << setw(7) << "" << "----------------------------------------------------" << endl;
  ss << *reportData << endl;

  cout << ss.str();

  ofstream outfile("SubRegion.txt", ios::out);
  if (!outfile) {
    cout << "file not found" << endl;
  }
  outfile << ss.str();
}

void SubRegionGenerator::formatData(string region, string subRegion, int animalNum) const{
  stringstream ss;
  ss << setfill(' ') << setw(7) << "" << region;
  ss << setfill(' ') << setw(7) << "" << subRegion;
  ss << setfill(' ') << setw(42-subRegion.length()) << animalNum << endl;
  reportData->add(animalNum, ss.str());
}

void SubRegionGenerator::compute(){
  try{
    vector <string> regions = regionMap.get();
    vector<Record*> horseRecords = animalMap["Horses-Ponies"];
    for(int i =0; i < regionMap.getSize(); i++){
      if(regions[i] == "CAN"){
        continue;
      }
      int highestFreq;
      string largestSubRegion;
      findMostHorses(horseRecords, regions[i], highestFreq, largestSubRegion);
      formatData(regions[i], largestSubRegion, highestFreq);
    }
    printReport();
    reportData->cleanUp();
  }
  catch(char const* error){
    cout << error << endl;
    return;
  }
}

void SubRegionGenerator::findMostHorses(vector<Record*>& horses, string region, int& mostFreq, string& subRegion) const{
  mostFreq = 0;
  subRegion = "";
  for(int i = 0; i < horses.size(); i++){
    if(horses[i]->getSubRegion() == "All"){
      continue;
    }
    int year = horses[i]->getYear();
    string currRegion = horses[i]->getRegion();
    int numHorses = horses[i]->getAnimalNumber();
    if((currRegion == region) && (numHorses > mostFreq) &&  (year == 2016)){
      subRegion = horses[i]->getSubRegion();
      mostFreq = horses[i]->getAnimalNumber();
    }
  }
}
