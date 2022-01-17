#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Record.h"

//the map class essentially functions as a map of sorts. It holds a key that points
//to a vector of records that correpond to that key. Note that the key can be any type

//the map's get method returns a reference to the keys as a vector
//the add method returns nothing and adds the key to the vector of keys if it doeesn't exist
//The record is then added to a new vector (containing record pointers)
//and is pushed back to the values vector

//if the key exists, the record is simply pushed back to the correponding vector

//the subscript operator returns a reference to a vector of pointers that correpond to
// a specific key by searching through the vector of keys
//if the key is not found, then an error is thrown
//this operator takes an argument of type in accordance to the type of the map

//getSize returns the size of the key array and is const
//the get() method returns the vector of keys as a reference, as the template type

template <class T>
class Map{
  public:
    Map();
    ~Map();
    vector <T>& get();
    void add(T, Record *);
    vector <Record*>& operator[](T);
    int getSize() const;

  private:
    vector <T> keys;
    vector < vector<Record*> > values;
};

template <class T>
Map<T>::Map() { }

template <class T>
Map<T>::~Map() { }

template <class T>
vector <T>& Map<T>::get(){
  return keys;
}

template <class T>
int Map<T>::getSize() const{
  return keys.size();
}

template <class T>
void Map<T>::add(T key, Record* rec){
  if(rec == nullptr){
    return;
  }
  for(int i = 0; i < getSize(); i++){
    if(keys[i] == key){
      values[i].push_back(rec);
      return;
    }
  }
  keys.push_back(key);
  vector <Record*> newVector;
  newVector.push_back(rec);
  values.push_back(newVector);
}

template <class T>
vector<Record*>& Map<T>::operator[](T key){
  for(int i = 0; i < getSize(); i++){
    if(keys[i] == key){
      return values[i];
    }
  }
  throw "The key is not found";
}

#endif
