/*
Implementare un programma che esegua le seguenti operazioni su una matrice
a) Leggere da tastiera una matrice di interi costituita da m x n elementi.
b) Stampare gli elementi della matrice M.
c) Richiedere l’inserimento di un numero intero x e verificare se esiste nella matrice M.
Nel caso in cui l’elemento esista restituire gli indici della sua posizione.
d) Calcolare la sommatoria di tutti gli elementi della matrice M.
e) Calcolare il valore minimo, massimo e la media degli elementi di M.
*/

#include <iostream>
#include <iomanip>

using std:: cout;
using std:: cin;
using std:: endl;

int main(){
    int n, m;

    cout<<"Inserire n righe e m colonne di una matrice: "<<endl;
    cin>>n;
    cin>>m;
    int matrice[n][m];

    cout<<endl<<"Riempi matrice: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<"matrice["<<i<<"]"<<"["<<j<<"]= ";
            cin>>matrice[i][j];  
        }
    }

    cout<<endl<<"Stampa:"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<"matrice["<<i<<"]"<<"["<<j<<"]= "<<matrice[i][j]<<endl;
        }
    }

    cout<<endl<<"Ricerca elemento, inseriscilo:"<<endl;
    int elem, posizione_i, posizione_j, trovato=0;
    cin>>elem;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(elem == matrice[i][j]){
                trovato= 1;
                posizione_i= i;
                posizione_j= j;
                break;
            }
        }
    }
    if(trovato == 1)
    cout<<"Elemento trovato in posizione: "<<posizione_i<<" "<<posizione_j<<endl;
    else 
    cout<<"Elemento non trovato"<<endl;

    cout<<endl<<"Sommatoria di tutti gli elementi: "<<endl;
    int somma=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            somma += matrice[i][j];
        }
    }
    cout<<"Sommatoria: "<<somma;

    cout<<endl<<"Media: "<<(float)somma/(n*m);

    cout<<endl<<"Minimo: ";
    int minimo= matrice[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrice[i][j] < minimo)
                minimo= matrice[i][j];
        }
    }
    cout<<minimo;

    cout<<endl<<"Massimo: ";
    int massimo= matrice[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrice[i][j] > massimo)
                massimo= matrice[i][j];
        }
    }
    cout<<massimo;







    
}