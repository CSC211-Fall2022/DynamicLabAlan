#ifndef header_h
#define header_h

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


struct dynamicArray{
    string menuItem;
    double menuPrice;
    int count;
    int positionInList;
};

dynamicArray* getData(dynamicArray*);
void showMenu(dynamicArray*);
void printCheck(dynamicArray*);



#endif
