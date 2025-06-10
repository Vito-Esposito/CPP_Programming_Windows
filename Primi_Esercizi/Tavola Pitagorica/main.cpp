/* 
Scrivere un programma in C++ che calcoli e visualizzi la tavola pitagorica (5x5)
formattata come in figura. */

#include <iostream>
#include <iomanip>

using std:: cout;
using std:: cin;
using std:: right;
using std:: left;
using std:: setw;
using std:: endl;

int main(){

    cout << endl << "TAVOLA PITAGORICA";

    for(int i= 1; i<6; i++){
        cout << endl << "+---+---+---+---+---+";
        cout << endl << "|";
        for(int j=1; j<6; j++)
            cout << setw(3) << right << i*j << "|";
    }

    cout << endl << "+---+---+---+---+---+";

}