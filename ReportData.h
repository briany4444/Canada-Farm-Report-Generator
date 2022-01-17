#ifndef REPORTDATA_H
#define REPORTDATA_H

#include <iostream>
#include <string>
#include <vector>
#include "AscBehaviour.h"
#include "DescBehaviour.h"
using namespace std;

//this template class reportData's purpose is to hold all the data as strings
//and organize the rows by ascending order based on the their key (type T)

//the default constructor takes in a compareBehaviour pointer that is used to
//check whether ascending or descending behvauour is used
//the destructor simply deletes this compare behaviour

//this class also has a vector of reportrows, which are just the rows of data
//displayed to the user as strings. The ReportRow is nested inside
//the reportData class so only it has access to it. It's contructor takes in
//a key of any type and a formatted string, which is the row

//the ReportData can add to its vector of rows using the void add(T, string)
//member function that takes in a key and formatted string to create an instance
//of a ReportRow

//we have the cleanUp() member function that clears the rows after a
//computation has occured

//finally we have the global friend osteram operator that collects the stream of bytes
//so that the enture object can have all it's rows printed out to the user

template <class T>
class ReportData{
  template <class V>
  friend ostream& operator<<(ostream&, const ReportData<V>&);
  public:
    ReportData(CompareBehaviour<T>* = NULL);
    ~ReportData();
    void add(T , string);
    void cleanUp();

  private:
    class ReportRow{
      public:
        ReportRow(T k, string r){
          key = k;
          row = r;
        }
        string row;
        T key;
    };
    vector <ReportRow> rows;
    CompareBehaviour<T>* compareBehaviour;
};

template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* c){
  if(c == nullptr){
    return;
  }
  compareBehaviour = c;
}

template <class T>
ReportData<T>::~ReportData(){
  delete compareBehaviour;
}

template <class T>
void ReportData<T>::cleanUp(){
  rows.clear();
}

template <class T>
void ReportData<T>::add(T key, string row){
  typename vector< ReportRow >::iterator it;
  ReportRow newRow(key, row);
  for(it = rows.begin(); it != rows.end(); ++it){
    if(compareBehaviour->compare(key, it->key)){
      rows.insert(it, newRow);
      return;
    }
  }
  rows.insert(it, newRow);
}

template <class T>
ostream& operator<<(ostream& out, const ReportData<T>& reportData){
  for(int i =0; i < reportData.rows.size(); i++){
    out << reportData.rows[i].row;
  }
  return out;
}

#endif
