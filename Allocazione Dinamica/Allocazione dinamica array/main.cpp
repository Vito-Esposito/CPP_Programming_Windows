
/*
Leggere da tastiera un vettore di interi V e il suo riempimento r, allocandolo dinamicamente
senza l’uso di funzioni.
Stampare gli elementi del vettore V

Strutturare il seguente programma scrivendo per ciascun punto un opportuno
sottoprogramma.
Leggere da tastiera un vettore di interi V e il suo riempimento r, allocandolo dinamicamente.
Stampare gli elementi del vettore V.
*/

#include <iomanip>
#include <iostream>

using std:: cin;
using std:: cout;
using std:: endl;

int * allocazione_vettore(int*);
void riempi_v(int, int[]);
void stampa_v(int, int[]);

int main(){
    int n, *vet, *vet_2, n_2;

    cout<<"Inserisci dimensione n array: "<<endl;
    cin>>n;
    vet= new int[n];

    cout<<"Inserire elementi del vettore:"<<endl;
    for (int i = 0; i < n; i++)
        cin>>vet[i];

    for (int i = 0; i < n; i++)
        cout<<endl<<"Vettore["<<i<<"]= "<<vet[i];

    vet_2= allocazione_vettore(&n_2);
    riempi_v(n_2, vet_2);
    stampa_v(n_2, vet_2);

    delete []vet_2;
    delete []vet;


}

int * allocazione_vettore(int *n){
    cout<<endl<<endl<<"Inserisci dimensione n array: "<<endl;
    cin>>(*n);

    return new int[(*n)];;
}

void stampa_v(int n, int vet[]){
    for (int i = 0; i < n; i++)
        cout<<endl<<"Vettore["<<i<<"]= "<<vet[i];
}

void riempi_v(int n, int vet[]){
    cout<<"Inserire elementi del vettore:"<<endl;
    for (int i = 0; i < n; i++)
        cin>>vet[i];
}
