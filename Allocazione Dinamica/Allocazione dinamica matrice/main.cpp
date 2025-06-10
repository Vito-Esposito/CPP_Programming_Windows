/*
Leggere da tastiera una matrice di interi costituita da m x n elementi, allocandola
dinamicamente senza l'uso di funzioni.
Stampare gli elementi della matrice M.

Strutturare il seguente programma scrivendo per ciascun punto un opportuno
sottoprogramma.
Le matrici (e i vettori) devono essere allocati dinamicamente.
a) Leggere da tastiera una matrice di interi costituita da m x n elementi.
b) Stampare gli elementi della matrice M.
*/

#include <iomanip>
#include <iostream>

using std:: cin;
using std:: cout;
using std:: endl;

int ** allocazione_matrice(int*, int*);
void deallocazione_matrice(int**, int);
void riempi_m(int, int, int**);
void stampa_m(int, int, int**);

int main(){
    int n= 0, m= 0, **mat, **mat_2, n_2= 0, m_2= 0;

    cout<<"Inserisci dimensione nxm matrice: "<<endl;
    cin>>n;
    cin>>m;

    mat= new int*[n];
    for (int i = 0; i < n; i++)
        mat[i]= new int[m];

    cout<<"Inserire elementi della matrice:"<<endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin>>mat[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout<<endl<<"Matrice["<<i<<"]["<<j<<"]"<<"= "<<mat[i][j];
    
    deallocazione_matrice(mat, n);

    mat_2= allocazione_matrice(&n_2, &m_2);
    riempi_m(n_2, m_2, mat_2);
    stampa_m(n_2, m_2, mat_2);
    deallocazione_matrice(mat_2, n_2);
}

int ** allocazione_matrice(int *n, int *m){
    cout<<endl<<endl<<"Inserisci dimensione nxm matrice: "<<endl;
    cin>>(*n);
    cin>>(*m);

    int **mat= new int*[(*n)];

    for (int i = 0; i < (*n); i++)
        mat[i]= new int[(*m)];
    
    return mat;
}

void riempi_m(int n, int m, int **mat){
    cout<<endl<<"Inserire elementi della matrice:"<<endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin>>mat[i][j];
}

void stampa_m(int n, int m, int **mat){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout<<endl<<"Matrice["<<i<<"]["<<j<<"]"<<"= "<<mat[i][j];
}

void deallocazione_matrice(int **matrice, int n) {
    if (matrice != nullptr) {
        for (int i = 0; i < n; ++i) {
            delete[] matrice[i];  // Dealloca ogni riga
        }
        delete[] matrice;  // Dealloca l'array di righe
    }
}