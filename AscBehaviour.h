#ifndef ASCBEHAVIOUR_H
#define ASCBEHAVIOUR_H

#include "CompareBehaviour.h"

//the ascBehaviour template class's purpose is to be used as a comparison class
//to check whether the first paramter is smaller or larger than the second parameter
//if the first parameter is smaller, than true is returned

//notice that the destructor and compare member function are virtual because it is
//inheriting from the abstract compareBehaviour class with public inheritance

template <class T>
class AscBehaviour: public CompareBehaviour<T>{
  public:
    AscBehaviour();
    virtual ~AscBehaviour();
    virtual bool compare(T, T);
};

template <class T>
AscBehaviour<T>::AscBehaviour() { }

template <class T>
AscBehaviour<T>::~AscBehaviour() { }

template <class T>
bool AscBehaviour<T>::compare(T t1, T t2){
  return t1 < t2;
}

#endif
