/*
Senza usare le funzioni di libreria string.h, scrivere un programma che
esegua le seguenti operazioni sulle stringhe.
• Legga dallo stdin due stringhe s1 e s2 e le visualizzi.
• Calcoli la lunghezza delle due stringhe.
• Confronti s1 e s2 assegnando alla variabile risultato_confronto il valore <0
se s1<s2, 0 se s1==s2, >0 se s1>s2.
• Copi la stringa s1 nella stringa s3 e la stringa s2 nella stringa s4.
• Concateni le stringhe s3 e s4.
NB: Si consideri una stringa come un array di caratteri che ha il carattere
terminale \0
*/

#include <iostream>
#include <iomanip>

using std:: cin;
using std:: cout;
using std:: endl;

int main(){
    char s1[20], s2[20];
    char frase[20];

    cout<<"Inserisci tre stringhe, di cui la terza con spazi:"<<endl;
    cin>>s1;
    cin>>s2;
    cin.ignore(); //svuota il buffer
    cin.getline(frase, 20);

    cout<<endl<<"Stringhe stampate:";
    cout<<endl<<s1;
    cout<<endl<<s2;
    cout<<endl<<frase;

    cout<<endl<<endl<<"Lunghezza prima stringa:";
    int n1=0, i=0;

    while(s1[i] != '\0'){
        n1++;
        i++;
    }
    cout<<endl<<n1;

    cout<<endl<<endl<<"Lunghezza seconda stringa:";
    int n2=0;
    i=0;

    while(s2[i] != '\0'){
        n2++;
        i++;
    }
    cout<<endl<<n2;

    // <0 se s1<s2, 0 se s1==s2, >0 se s1>s2
    int risultato_confronto=0;
    i= 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) {
            risultato_confronto = -1; 
            break;
        } else if (s1[i] > s2[i]) {
            risultato_confronto = 1;  
            break;
        }
        i++;
    }

    if (risultato_confronto == 0){
        if (s1[i] == '\0' && s2[i] != '\0'){
            risultato_confronto = -1;  
        } else if (s1[i] != '\0' && s2[i] == '\0'){
            risultato_confronto = 1; 
        }
    }
    cout<<endl<<endl<<"Risultato (<0 se s1<s2, 0 se s1==s2, >0 se s1>s2)= "<<risultato_confronto<<".";

    // Copi la stringa s1 nella stringa s3 e la stringa s2 nella stringa s4.
    char s3[n1], s4[n2];
    i= 0;

    while(s1[i] != '\0'){
        s3[i]= s1[i];
        i++;
    }
    s3[i] = '\0';  // Aggiungi il terminatore di stringa a s3

    i= 0;

    while(s2[i] != '\0'){
        s4[i]= s2[i];
        i++;
    }
    s4[i] = '\0';  // Aggiungi il terminatore di stringa a s3

    cout<<endl<<endl<<"Stringhe copiate: ";
    cout<<s3<<" - "<<s4;

    cout<<endl<<"Stringhe 3 e 4 concatenate:";
    int n3= n1+n2+1;
    i=0;
    char s5[n3];

    while(s3[i] != '\0'){
        s5[i]= s3[i];
        i++;
    }
    int j= 0;
    while(s4[j] != '\0'){
        s5[i]= s4[j];
        i++;
        j++;
    }
    s5[i]= '\0';

    cout<<endl<<"Stringa concatenata: "<<s5;
}