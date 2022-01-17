#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

//this is the abstract base class for the comparison object classes that only has a
//pure virtual function compare(T, T) that takes in 2 arguments and checks which is
//larger (this class does not have the implementation though since abstract) and returns bool

//note that this class, as well as the 2 derived classes, are template classes,
//so it accepts any argument type

//this class ensures that all the rows in the reportData is in order at all times
//depeding on the desire orderings

template <class T>
class CompareBehaviour{
  public:
    CompareBehaviour();
    virtual ~CompareBehaviour();
    virtual bool compare(T, T) = 0;
};

template <class T>
CompareBehaviour<T>::CompareBehaviour() { }

template <class T>
CompareBehaviour<T>::~CompareBehaviour() { }

#endif
