/*
Implementare un programma che esegua le seguenti operazioni su una matrice, costituito
dai seguenti sottoprogrammi.
X) Leggere da tastiera una matrice di interi costituita da m x n elementi.
X) Stampare gli elementi della matrice M.
x) Richiedere l’inserimento di un numero intero x e verificare se esiste nella matrice M.
Nel caso in cui l’elemento esista restituire gli indici della sua posizione.
x) Calcolare la sommatoria di tutti gli elementi della matrice M.
x) Calcolare il valore minimo, massimo e la media degli elementi di M.
x) Verificare se esistono elementi nulli nella matrice e contemporaneamente
memorizzare gli elementi non nulli in un vettore V. Al termine stampare il numero
degli elementi nulli e il vettore V.
x) Dopo aver fatto la copia della matrice M, richiedere la posizione di una riga
(colonna) da eliminare dalla matrice copia (M_copia).
h) Calcolare la matrice trasposta
i) Verificare se la matrice è simmetrica
j) Copiare nei vettori VP e VS rispettivamente gli elementi della diagonale principale
e secondaria.
k) Memorizzare nei vettori MR e MC rispettivamente i minimi di ciascuna riga e di
ciascuna colonna.
*/

#include <iomanip>
#include <iostream>
using std:: endl;
using std:: cin;
using std:: cout;

void lettura(int, int, int*);
void stampa(int, int, int*);
void stampa_a(int, int[]);
int ricerca(int*, int*, int, int, int, int*);
int sommatoria(int, int, int*);
int minimo(int, int, int*);
int massimo(int, int, int*);
float media(int, int, int*);
void elem_nulli(int, int, int*);
void arr_el_non_nulli(int, int, int*, int*);
void copia_matrice(int, int, int*, int*);
void elim_rc(int*, int*, int*);

int main(){
    int n, m, x;;

    cout<<"Quanti elementi conterra' la matrice (righe e colonne)?"<<endl;
    cin>>n;
    cin>>m;
    int matrice[n][m];

    lettura(n, m, (int*)matrice);
    stampa(n, m, (int*)matrice);
    
    cout<<endl<<endl<<"Inserire elemento da cercare nella matrice:"<<endl;
    cin>>x;
    int i_r=-1, j_r=-1;
    ricerca(&i_r, &j_r, x, n, m, (int*)matrice);

    if(i_r!=-1 && j_r!=-1)
        cout<<endl<<"Elemento trovato negli indici "<<i_r<<" e "<<j_r<<".";
    else
        cout<<endl<<"Elemento non trovato.";
    
    cout<<endl<<"La sommatoria degli elementi e': "<<sommatoria(n, m, (int*)matrice);

    cout<<endl<<endl<<"Il massimo, il minimo e la media dell'array sono: "<<massimo(n, m, (int*)matrice)<<" e "<<minimo(n, m, (int*)matrice)<<" e "<<media(n, m, (int*)matrice);
   
    elem_nulli(n, m, (int*)matrice);
    
    cout<<endl<<endl<<"Copia della matrice: ";
    int matrice_c[n][m];
    copia_matrice(n, m, (int*)matrice, (int*)matrice_c);
    stampa(n, m, (int*)matrice_c);
    int n_c= n;
    int m_c= m;

    elim_rc(&n_c, &m_c, (int*)matrice_c);
    for (int i = 0; i < n_c; i++)
    {
        for (int j = 0; j < m_c; j++)
        {
            cout<<endl<<"Elemento matrice["<<i<<"]"<<"["<<j<<"]"<<"="<<matrice_c[i][j];
        }  
    }
}

void lettura(int n, int m, int *mat){
    cout<<"Inserisci "<<n<<"*"<<m<<" elementi dell'array:"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>*(mat+i*m+j);
        }  
    } 
}

void stampa(int n, int m, int *mat){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<endl<<"Elemento matrice["<<i<<"]"<<"["<<j<<"]"<<"="<<*(mat+i*m+j);
        }  
    } 
}

int ricerca(int *i_r, int*j_r, int x, int n, int m, int *mat){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(x==*(mat+i*m+j)){
                *i_r= i;
                *j_r= j;
                return 0;
            }
        }  
    } 
    return 0;
}

int sommatoria(int n, int m, int *mat){
    int somma=0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            somma += *(mat+i*m+j);
        }  
    } 
    return somma;
}

int minimo(int n, int m, int *mat){
    int min= *(mat+0*m+0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(*(mat+i*m+j) < min)
            min= *(mat+i*m+j);
        }  
    } 
    return min;
}

int massimo(int n, int m, int *mat){
    int max= *(mat+0*m+0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(*(mat+i*m+j) > max)
            max= *(mat+i*m+j);
        }  
    } 
    return max;
}

float media(int n, int m, int *mat){
    float media= 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            media += *(mat+i*m+j);
        }  
    } 
    return media/(n*m);
}

void elem_nulli(int n, int m, int *mat){
    int temp= 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(*(mat+i*m+j) == 0)
                temp++;
        }  
    } 
    
    if(temp == 0)
        cout<<endl<<"Non ci sono elementi nulli nell'array.";
    else
        cout<<endl<<"CI sono "<<temp<<" elementi nulli nell'array.";

    int n_a= ((n*m)-temp);
    int a[n_a];
    arr_el_non_nulli(n, m, (int*)mat, a);
    stampa_a(n_a, a);
}

void arr_el_non_nulli(int n, int m, int *mat, int *array){
    int k= 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(*(mat+i*m+j) != 0){
            *(array+k)= *(mat+i*m+j);
            k++;}
        }  
    } 
}

void stampa_a(int n, int array[]){
    for(int i= 0; i<n; i++){
    cout<<endl<<"Elemento array["<<i<<"]= "<<array[i];
    }
}

void copia_matrice(int n, int m, int *mat, int *mat_c){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(mat_c+i*m+j)=*(mat+i*m+j);
        }  
    } 
}

void elim_rc(int *n_c, int *m_c, int *mat_c){
    int i_r, n= *n_c, m= *m_c;

    cout<<endl<<endl<<"Inserisci indice riga: "<<endl;
        cin>>i_r;

        for(int i=i_r; i<n-1; i++){
            for(int j=0; j<m; j++){
                *(mat_c+i*m+j)= *(mat_c+(i+1)*m+j);
            }
        }
        *n_c= n-1;

    int i_c;

    cout<<endl<<"Inserisci indice colonna: "<<endl;
        cin>>i_c;

        for(int i=0; i<n; i++){
            for(int j=i_c; j<m-1; j++){
                *(mat_c+i*m+j)= *(mat_c+i*m+j+1);
            }
        }
        *m_c= m-1; 
}



