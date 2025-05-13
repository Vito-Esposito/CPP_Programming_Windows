#include <iostream>
#include "RPG_PMago.hpp"

using namespace std;

int main(){
    RPG_PBase pedone(5,1,5);
    RPG_PMago merlino(1,5,5,5,5);
    cout << "pedone: ";
    pedone.show();
    cout << endl;
    
    cout << "merlino: ";
    merlino.show();
    cout<< endl;
}