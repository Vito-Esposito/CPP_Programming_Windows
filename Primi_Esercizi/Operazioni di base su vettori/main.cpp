/*
Implementare un programma che esegua le seguenti operazioni su un vettore
a) Leggere da tastiera un vettore di interi V e il suo riempimento r.
b) Stampare gli elementi del vettore V.
c) Stampare gli elementi del vettore V in ordine inverso.
d) Richiedere il valore di un numero intero x e verificare se esiste nel vettore V. Nel caso in cui
l'elemento esista restituire la sua posizione.
e) Calcolare la sommatoria degli elementi di posto pari e la sommatoria degli elementi di
posto dispari e memorizzare in un vettore VP gli elementi con valore pari e in un vettore VD
gli elementi con valore dispari.
*/

#include <iostream>
#include <iomanip>

using std:: cin;
using std:: cout;
using std:: endl;

int main(){
    int n, elem, trovato= 0, posizione= 0;

    cout << endl << "INSERISCI NUMERO ELEMENTI DEL VETTORE" << endl;
    cin >> n;
    int vettore[n];

    cout << endl << "INSERISCI ELEMENTI VETTORE" << endl;
    for(int i=0; i<n; i++)
        cin >> vettore[i];
    
    cout << endl << "VETTORE STAMPATO" << endl;
    for(int i=0; i<n; i++)
        cout << "Vettore[" << i << "]= " << vettore[i] << endl;  

    cout << endl << "VETTORE STAMPATO INVERSAMENTE" << endl;
    for(int i=n-1; i>=0; i--)
        cout << "Vettore[" << i << "]= " << vettore[i] << endl;  

    cout << endl << "INSERIRE ELEMENTO DA RICERCARE" << endl;
    cin >> elem;
    
    for(int i=0; i<n; i++){
        if(elem == vettore[i]){
            trovato = 1;
            posizione = i;
            break;
        }
    }

    if(trovato == 1)
        cout << "Elemento trovato alla posizione di indice " << posizione << "." << endl;
    else
        cout << "Elemento non trovato." << endl;

    cout << endl << "SOMMA DEGLI ELEMENTI";
    int somma_p= 0, somma_d= 0;

    for(int i=0; i<n; i++){
        if(i%2 == 0)
            somma_p += vettore[i];
        else
            somma_d += vettore[i];
    }
    cout << endl << "Somma degli elementi di posto pari: " << somma_p << " e degli elementi di posto dispari: " << somma_d << "." << endl; 

    cout << endl << "VETTORE CON ELEMENTI PARI";
    int i_p=0;
    int vettore_p[50];
    for(int i=0; i<n; i++){
        if(vettore[i]%2 == 0){
            vettore_p[i_p]= vettore[i];
            i_p++;
        }
    }
    cout << endl << "STAMPA VETTORE CON ELEMENTI PARI";
    for(int i=0; i<i_p; i++){
        cout << endl << vettore_p[i];
    }

    cout << endl << endl << "VETTORE CON ELEMENTI DISPARI";
    int i_d=0;
    int vettore_d[50];
    for(int i=0; i<n; i++){
        if(vettore[i]%2 != 0){
            vettore_d[i_d]= vettore[i];
            i_d++;
        }
    }
    cout << endl << "STAMPA VETTORE CON ELEMENTI DIPARI";
    for(int i=0; i<i_d; i++){
        cout << endl << vettore_d[i];
    }

}