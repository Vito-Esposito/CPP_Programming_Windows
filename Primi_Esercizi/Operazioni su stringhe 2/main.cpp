/*
Scrivere un programma che confronta due stringhe inserite in input
dall'utente e restituisce:
• 1, se sono uguali o ottenibili l'una dall'altra con UN SOLO scambio di due
caratteri CONSECUTIVI
• 0, altrimenti.

Esempio:
fiore, foire, firoe, fioer
*/


#include <iostream>
#include <iomanip>

using std:: cin;
using std:: cout;
using std:: endl;

int main(){
    char s1[20], s2[20];
    int ris= 1;

    cout<<"Inserisci due stringhe:"<<endl;
    cin>>s1;
    cin>>s2;

    cout<<endl<<"Restituisce 1, se sono uguali o ottenibili l'una dall'altra con UN SOLO scambio di due caratteri CONSECUTIVI."<<endl<<"0, altrimenti."<<endl;

    int i= 0;
    while(s1[i] != '\0'){
        if(s1[i] != s2[i]){
            if(s1[i] != s2[i+1] && s1[i] != s2[i-1]){
                ris= 0;
                break;
            }
        }
        i++;
    }

    cout<<endl<<"Risultato: "<<ris;   
}