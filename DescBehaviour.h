#ifndef DESCBEHAVIOUR_H
#define DESCBEHAVIOUR_H

#include "CompareBehaviour.h"

//the DescBehaviour template class's purpose is to be used as a comparison class
//to check whether the first paramter is smaller or larger than the second parameter
//if the second parameter is smaller than true is returned

//notice that the destructor and compare member function are virtual because it is
//inheriting from the abstract compareBehaviour class with public inheritance

template <class T>
class DescBehaviour: public CompareBehaviour<T>{
  public:
    DescBehaviour();
    virtual ~DescBehaviour();
    virtual bool compare(T, T);
};

template <class T>
DescBehaviour<T>::DescBehaviour() { }

template <class T>
DescBehaviour<T>::~DescBehaviour() { }

template <class T>
bool DescBehaviour<T>::compare(T t1, T t2){
  return t1 > t2;
}

#endif
