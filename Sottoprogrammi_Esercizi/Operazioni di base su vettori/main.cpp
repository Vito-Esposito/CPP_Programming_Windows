/*
Utilizzando i sottoprogrammi, implementare un programma che esegua le seguenti
operazioni su un vettore, costituito dai seguenti sottoprogrammi.
a) Leggere da tastiera un vettore di interi V e il suo riempimento r.
b) Stampare gli elementi del vettore V.
c) Stampare gli elementi del vettore V in ordine inverso.
d) Richiedere il valore di un numero intero x e verificare se esiste nel vettore V. Nel caso in cui
l'elemento esista restituire la sua posizione.
e) Calcolare la sommatoria degli elementi di posto pari e la sommatoria degli elementi di
posto dispari e memorizzare in un vettore VP gli elementi con valore pari e in un vettore VD
gli elementi con valore dispari.
f) Calcolare il valore minimo, massimo e la media degli elementi di V.
g) Verificare se esistono elementi nulli nel vettore V. In caso positivo contarli e stamparli.
h) Dopo aver fatto la copia del vettore V, richiedere la posizione di un elemento da eliminare
nel vettore copia e eliminarlo dal vettore copia (V_copia).
i) Richiedere il valore di un elemento da eliminare nel vettore V e eliminarlo da V.
l) Richiedere il valore di un numero intero x e la posizione in cui deve essere inserito, e
successivamente inserire tale valore nel vettore V.
*/

#include <iomanip>
#include <iostream>
using std:: endl;
using std:: cin;
using std:: cout;

void lettura(int, int[]);
void stampa(int, int[]);
int ricerca(int, int, int[]);
int sommatoria_pari(int, int[]);
int sommatoria_dispari(int, int[]);
void vettore_el_pari(int*, int, int[], int[]);
void vettore_el_dispari(int*, int, int[], int[]);
int minimo(int, int[]);
int massimo(int, int[]);
float media(int, int[]);
void elem_nulli(int, int[]);
void copia_vettore(int, int[], int[]);
void elim_da_pos(int*, int[]);
void elim_da_pos_2(int, int*, int[]);
void elim_da_val(int*, int[]);
void inserimento(int*, int[]);

int main(){
    int n, pos_el, x, VP[50], n_p=0, n_d=0, VD[50], n_c=0;

    cout<<"Quanti elementi conterra' l'array?"<<endl;
    cin>>n;
    int array[n];

    lettura(n, array);
    stampa(n, array);

    cout<<endl<<endl<<"Inserire elemento da cercare nell'array:"<<endl;
    cin>>x;
    pos_el= ricerca(x, n, array);

    if(pos_el != -1)
        cout<<endl<<"Elemento trovato nell'indice' "<<pos_el<<".";
    else
        cout<<endl<<"Elemento non trovato.";

    cout<<endl<<endl<<"La sommatoria degli elementi di posto pari e': "<<sommatoria_pari(n, array);
    cout<<endl<<"La sommatoria degli elementi di posto dispari e': "<<sommatoria_dispari(n, array);

    vettore_el_pari(&n_p, n, array, VP);
    cout<<endl<<endl<<"Array con soli elementi pari: ";
    stampa(n_p, VP);

    vettore_el_dispari(&n_d, n, array, VD);
    cout<<endl<<endl<<"Array con soli elementi dispari: ";
    stampa(n_d, VD);

    cout<<endl<<endl<<"Il massimo, il minimo e la media dell'array sono: "<<massimo(n, array)<<" e "<<minimo(n, array)<<" e "<<media(n, array);

    elem_nulli(n, array);

    cout<<endl<<endl<<"Copia del vettore: ";
    int copia[n];
    n_c= n;
    copia_vettore(n, array, copia);
    stampa(n, copia);
    elim_da_pos(&n_c, copia);
    stampa(n_c, copia);

    elim_da_val(&n, array);
    stampa(n, array);

    inserimento(&n, array);
    stampa(n, array);
}

void lettura(int n, int array[]){
    cout<<"Inserisci "<<n<<" elementi dell'array:"<<endl;
    for(int i= 0; i<n; i++)
        cin>>array[i];
}

void stampa(int n, int array[]){
    for(int i= 0; i<n; i++){
    cout<<endl<<"Elemento array["<<i<<"]= "<<array[i];
    }
}

int ricerca(int x, int n, int array[]){

    for(int i=0; i<n; i++)
        if(x==array[i])
            return i;
    return -1;
}

int sommatoria_pari(int n, int array[]){
    int somma=0;
    for (int i = 0; i < n; i=i+2)
        somma += array[i];
    return somma;
}

int sommatoria_dispari(int n, int array[]){
    int somma=0;
    for (int i = 1; i < n; i=i+2)
        somma += array[i];
    return somma;
}

void vettore_el_pari(int *n_p, int n, int a[], int VP[]){
    for (int i = 0; i < n; i++)
    {
        if(a[i]%2 == 0){
            VP[*n_p]= a[i];
            (*n_p)++;
        }
    }
}

void vettore_el_dispari(int *n_d, int n, int a[], int VD[]){
    for (int i = 0; i < n; i++)
    {
        if(a[i]%2 != 0){
            VD[*n_d]= a[i];
            (*n_d)++;
        }
    }
}

int minimo(int n, int a[]){
    int min= a[0];

    for (int i = 1; i < n; i++)
        if(a[i] < min)
            min= a[i];
    return min;
}

int massimo(int n, int a[]){
    int max= a[0];

    for (int i = 1; i < n; i++)
        if(a[i] > max)
            max= a[i];
    return max;
}

float media(int n, int a[]){
    float media= 0;

    for (int i = 0; i < n; i++)
        media += a[i];
    return media/n;
}

void elem_nulli(int n, int a[]){
    int temp= 0;

    for (int i = 0; i < n; i++)
        if(a[i] == 0)
            temp++;
    
    if(temp == 0)
        cout<<endl<<"Non ci sono elementi nulli nell'array.";
    else
        cout<<endl<<"CI sono "<<temp<<" elementi nulli nell'array.";
}

void copia_vettore(int n, int a[], int copia[]){

    for (int i = 0; i < n; i++)
        copia[i]= a[i];
}

void elim_da_pos(int *n, int a[]){
    int pos=0;

    cout<<endl<<endl<<"Inserire indice posizione dell'elemento da eliminare?"<<endl;
    cin>>pos;
    *n= (*n)-1;

    for (int i = pos; i < *n; i++)
        a[i]= a[i+1];

}

void elim_da_pos_2(int pos, int *n, int a[]){
    *n= (*n)-1;

    for (int i = pos; i < *n; i++)
        a[i]= a[i+1];
}

void elim_da_val(int *n, int a[]){
    int el=0, pos= 0;

    cout<<endl<<endl<<"Inserire valore dell'elemento da eliminare?"<<endl;
    cin>>el;

    for (int i = 0; i < *n; i++)
        if(el == a[i])
            pos= i;
    
    elim_da_pos_2(pos, n, a);
}

void inserimento(int *n, int array[]){
    int el, pos, i;

    cout<<endl<<"Inserisci elemento e posizione (indice) da inserire: "<<endl;
    cin>>el;
    cin>>pos;

    for (i = *n; i > pos; i--)
        array[i]= array[i-1];
    
    array[i]= el;
    (*n)++;
}