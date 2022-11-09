#include <stdio.h>
#include"header.h"


int totalOrders = 0, dynSize;

string line;

double tax = 0.0886;

void showMenu(dynamicArray*list){
    
    for(int i = 0; i < dynSize; i++){
        cout << list[i].menuItem << "   $" << list[i].menuPrice << endl;
    }
    
}

void printCheck(dynamicArray*list){
    int numberOfOrders, item, count;
    double total = 0;
    cin >> numberOfOrders;
    for(int i = 0; i < numberOfOrders;i++){
    cin >> item >> count;
        list[item-1].count += count;
        
    }
    
    for(int i = 0;i < dynSize; i++){//sets count proper
        list[i].menuPrice *= list[i].count;
    }
    
        cout << "\n\n";
        cout << "Your check: " << endl;
        
    for(int i = 0; i < dynSize; i++){//sets them in order correct
            if((list[i].positionInList == (i+1)) && (list[i].count != 0)){
                cout << list[i].menuItem << "   " << list[i].count << "   $" << list[i].menuPrice << endl;
                
                totalOrders += list[i].count;
                total += list[i].menuPrice;
            }
    }
    

        
    cout << left << setw(19) << "Total items ordered: " << totalOrders << endl;
   cout << left << setw(19) << "Amount Total" << "$" << total << endl;
   cout << left << setw(19) << "Tax" << "$" << (total * tax) << endl;
   cout << left << setw(19) << "Amount Due" << "$" << total + (total * tax);



    delete[]list;
    list = nullptr;

}


dynamicArray* getData(dynamicArray*list){
    
    string line, name = "", price = "", menu;
    bool name_done = false;
    ifstream fin;
    cin >> menu;
    fin.open (menu);
    
        
        for(int i = 0; i < dynSize; i++){
            getline(fin,line);
            
        
            for(int j = 0; j < line.size(); j++){
                if(line[j+1] == '$'){
                    name_done = true;
                }
                else if(name_done == false){
                    name += line[j];
                    
                }
                else if(line[j] != '$' && name_done == true){
                    price += line[j];
                }
                
            }
            
            list[i].menuItem = name;
            list[i].menuPrice = stod(price);
            name_done = false;
            name = "";
            price = "";
            list[i].positionInList = i+1;
            list[i].count = 0;
            
        }
                fin.close();
    
                return list;
    }
            
    
            
        

