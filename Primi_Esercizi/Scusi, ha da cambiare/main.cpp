/*
Si scriva un programma C++ che chieda all’utente di inserire un importo di denaro
in una variabile intera e restituisca il numero di banconote e monete necessarie per
comporlo, scegliendo tra i seguenti tagli:
500, 200, 100, 50, 20, 10, 5, 2, 1

Esempio: l’importo 5609 è composto da 11 pezzi da 500, 1 pezzo da 100, 1 pezzo da
5, 2 pezzi da 2.

Suggerimento: E’ opportuno che il programma dichiari un array
di 9 interi contenente i tagli e che confronti l’importo inserito
dall’utente con ciascun taglio dal maggiore al minore. Un
ulteriore array conterrà il numero di pezzi utilizzato per ciascun
taglio.
*/

#include <iostream>
#include <iomanip>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: setw;
using std:: right;
using std:: left;

int main(){
    int denaro;
    int tagli[9]={500, 200, 100, 50, 20, 10, 5, 2, 1};
    int numero_tagli[9]= {0, 0, 0, 0, 0, 0, 0, 0, 0};;

    cout << endl << "Inserisci un importo di denaro: ";
    cin >> denaro;

    for(int i=0; i < 9; i++){
        if(denaro >= tagli[i]){
            numero_tagli[i]= denaro/tagli[i]; 
            denaro= denaro%tagli[i];
        }
    }

    cout << endl << "Tagli necessari per l'importo di " << denaro << endl;

    cout << endl << "+-------+----+";
        cout << endl << "|" << setw(7) << left << "TAGLI" << "|" << setw(5) << right << "N|";

    for(int i=0; i < 9; i++){
        cout << endl << "+-------+----+";
        cout << endl << "|" << setw(7) << left << tagli[i] << "|" << setw(4) << right << numero_tagli[i] << "|";

    }
}