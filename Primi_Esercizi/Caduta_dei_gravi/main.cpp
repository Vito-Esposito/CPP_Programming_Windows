/*
Un peso viene lasciato cadere verticalmente da un’altezza h
e desideriamo sapere a che altezza si trova ogni d secondi
fino a che non tocca il suolo. 
Si scriva un programma in C++ che:
1) chieda in input due numeri h e d in doppia precisione;
2) calcoli e visualizzi l’altezza a cui si trova, ogni 𝑑 secondi. */

#include <iostream>
#include <iomanip>
#include <math.h>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: setw;
using std:: left;
using std:: right;

int main(){
    double h, t= 0, d, temp;
    const double g= 9.81;

    cout << "Inserisci altezza h: ";
    cin >> h;
    cout << "Inserisci d (intervallo secondi): ";
    cin >> d;

    temp= h;

    cout << endl << "Tempo" << setw(4) << " " << "Altezza" << endl;

    while(temp>0){
        temp= h-(g*pow(t,2))/2;
        cout << setw(10) << left << t;
        cout << setw(10) << left << temp << endl;

        t= t+d;
    }

    return 0;
}