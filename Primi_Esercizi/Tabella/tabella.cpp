/*
Dati due array: il primo contenente un elenco di nomi di valute e il secondo
contenente i rispettivi cambi contro Euro (in singola precisione), desideriamo
visualizzare in una tabella su ciascuna riga il nome della divisa e il suo
corrispondente importo in Euro. */

#include <iostream>
#include <iomanip>

using std:: cin;
using std:: cout;
using std:: endl;
using std:: setw;
using std:: right;
using std:: left;

int main(){
    int i;
    char *valuta[6]= {"Dollaro US","Dollaro Can","LST","Franco Svizzero","Yen","Corona Svedese"};
    const float cambio[6]={0.95, 0.69, 0.89, 1.01, 144.66, 11.32};

    cout << endl << "*** LISTINO CAMBI ***" << endl;

    for(i= 0; i<6; i++){
        cout << "Valuta: " << setw(15) << left << valuta[i];
        cout << " | " << "Cambio in Euro: " << setw(6) << right << cambio[i] << endl;
    }

    return 0;
}

