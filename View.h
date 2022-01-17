#ifndef VIEW_H
#define VIEW_H

//the view class serves as the view class in the paradigm. This class
//essentially displays the menu to the user using the showMenu member function
//this member function takes in an int reference and represents the user's choice

class View{
  public:
    void showMenu();
    void readInt(int&);
};

#endif
