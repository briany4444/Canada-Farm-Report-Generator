#include <iostream>
using namespace std;

#include "Control.h"

Control::Control(){
  ReportGenerator *subRegionGenerator = new SubRegionGenerator();
  if(subRegionGenerator == nullptr){
    return;
  }
  ReportGenerator *regionGenerator = new RegionGenerator();
  if(regionGenerator == nullptr){
    return;
  }
  ReportGenerator *percentChangeGenerator = new PercentChangeGenerator();
  if(percentChangeGenerator == nullptr){
    return;
  }
  generators.push_back(regionGenerator);
  generators.push_back(percentChangeGenerator);
  generators.push_back(subRegionGenerator);
}

Control::~Control(){
  for(int i =0; i < generators.size(); i++){
    delete generators[i];
  }
}

void Control::launch(){
  ReportGenerator::loadRecords();
  ReportGenerator::populateMaps();
  int choice;
  while(true){
    view.showMenu();
    view.readInt(choice);
    if(choice == 1){
      generators[REGION]->compute();
    }
    else if(choice == 2){
      generators[PERCENT]->compute();
    }
    else if(choice == 3){
      generators[SUBREGION]->compute();
    }
    else if(choice == 0){
      break;
    }
    else{
      cout << "invalid input" << endl;
    }
  }
  ReportGenerator::cleanUp();
}
