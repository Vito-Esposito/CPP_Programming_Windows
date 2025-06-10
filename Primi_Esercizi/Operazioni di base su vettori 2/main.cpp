/*
f) Calcolare il valore minimo, massimo e la media degli elementi di V.
g) Verificare se esistono elementi nulli nel vettore V. In caso positivo contarli e stamparli.
h) Dopo aver fatto la copia del vettore V, richiedere la posizione di un elemento da eliminare
nel vettore copia e eliminarlo dal vettore copia (V_copia).
i) Richiedere il valore di un elemento da eliminare nel vettore V e eliminarlo da V.
l) Richiedere il valore di un numero intero x e la posizione in cui deve essere inserito, e
successivamente inserire tale valore nel vettore V.
*/

#include <iostream>
#include <iomanip>

using std:: cin;
using std:: cout;
using std:: endl;

int main(){
    int n;

    cout << endl << "INSERISCI NUMERO ELEMENTI DEL VETTORE" << endl;
    cin >> n;
    int vettore[n];

    cout << endl << "INSERISCI ELEMENTI VETTORE" << endl;
    for(int i=0; i<n; i++)
        cin >> vettore[i];
    
    cout << endl << "VETTORE STAMPATO" << endl;
    for(int i=0; i<n; i++)
        cout << "Vettore[" << i << "]= " << vettore[i] << endl;  

    cout << endl << "MINIMO: ";
    int minimo= vettore[0];
    for(int i=1; i<n; i++)
        if( vettore[i] < minimo)
            minimo= vettore[i];
    cout << minimo;

    cout << endl << "MASSIMO: ";
    int massimo= vettore[0];
    for(int i=1; i<n; i++)
        if( vettore[i] > massimo)
            massimo= vettore[i];
    cout << massimo;

    cout << endl << "MEDIA: ";
    double media= 0;
    for(int i=0; i<n; i++)
        media += vettore[i];
    media= media/n;
    cout << media << endl;

    cout << endl << "CI SONO ELEMENTI NULLI?" << endl;
    int cnt= 0;
    for(int i=0; i<n; i++)
        if(vettore[i] == 0)
            cnt++;
    if( cnt != 0)
        cout << "SI, " << cnt << ".";
    else
        cout << "No.";

    cout << endl << "ELIMINARE ELEMENTO DA POSIZIONE DA VETTORE COPIA" << endl;
    int vettore_copia[n];
    int i_elem, n_c= n-1;
    for(int i=0; i<n; i++)
        vettore_copia[i]= vettore[i];
    
    cout << "Inserire indice posizione: ";
    cin >> i_elem;
    cout << endl << "VETTORE COPIA STAMPATO DOPO ELIMINAZIONE" << endl;
    for(int i= i_elem; i<n_c; i++){
        vettore_copia[i]= vettore_copia[i+1];
    }
    for(int i=0; i<n_c; i++)
        cout << "Vettore[" << i << "]= " << vettore_copia[i] << endl;  

    cout << endl << "ELIMINARE ELEMENTO DA POSIZIONE DA VETTORE" << endl;
    int elem, posizione= 0, n_nuovo= n-1;
    cout << "Inserire valore dell'elemento da eliminare: ";
    cin >> elem;
    cout << endl << "VETTORE STAMPATO DOPO ELIMINAZIONE" << endl;
    for(int i= 0; i<n; i++)
        if(elem == vettore[i]){
            posizione= i;
            break;
        }
    for(int i= posizione; i<n_nuovo; i++){
        vettore[i]= vettore[i+1];
    }
    for(int i=0; i<n_nuovo; i++)
        cout << "Vettore[" << i << "]= " << vettore[i] << endl;  

    cout << endl << "INSERIRE ELEMENTO" << endl;
    int el, ins_pos, n_n= n_nuovo+1;
    cout << "Inserire valore dell'elemento da inserire e indice posizione di dove inserirlo: ";
    cin >> el;
    cin >> ins_pos;
    cout << endl << "VETTORE STAMPATO DOPO INSERIMENTO" << endl;
    for(int i= n_n; i>ins_pos; i--){
        vettore[i]= vettore[i-1];
    }
    vettore[ins_pos]= el;
    for(int i=0; i<n_n; i++)
        cout << "Vettore[" << i << "]= " << vettore[i] << endl;  









}