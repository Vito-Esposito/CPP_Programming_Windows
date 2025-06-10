/*
Data una sequenza di n numeri interi.
Eseguire e stampare la sommatoria dei numeri di posto pari e la sommatoria
dei numeri di posto dispari utilizzando gli array nella versione con puntatori.
*/

#include <iostream>
#include <iomanip>

using std:: cout;
using std:: cin;
using std:: endl;

int main(){
    int n;

    cout<<"Inserisci lunghezza array:"<<endl;
    cin>>n;

    int array[n];
    cout<<"Inserisci gli n elementi: ";
    for(int i=0; i<n; i++){
        cin>>*(array+i);
    }

    cout<<endl<<endl<<"Array stampato: ";
    for(int i=0; i<n; i++){
        cout<<*(array+i)<<" ";
    }

    int somma_pari = 0, somma_dispari = 0;

    for(int i=0; i<n; i++){
        if(i%2==0)
            somma_pari += *(array+i);
        else
            somma_dispari += *(array+i);
    }

    // Stampa dei risultati
    cout<<endl<<"Somma degli elementi in posizione pari: "<< somma_pari<<endl;
    cout<<endl<< "Somma degli elementi in posizione dispari: "<<somma_dispari<<endl;
}