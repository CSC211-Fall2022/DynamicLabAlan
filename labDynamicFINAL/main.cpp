#include "header.h"
extern int dynSize;



extern double tax;
int main() {
    
    dynamicArray* list;

    cout << fixed << setprecision(2);
    cin >> dynSize;
    list = new dynamicArray[dynSize];
    cout << "Welcome to Johnny Restaurant" << endl;
    
    getData(list);
    showMenu(list);
    printCheck(list);
    
   

   return 0;
}
