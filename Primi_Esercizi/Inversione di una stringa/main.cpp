/*
Senza utilizzare la libreria <string.h>, scrivere un programma che inserita
una stringa nello stdin la inverte modificandola.
*/

#include <iostream>
#include <iomanip>

using std:: cin;
using std:: cout;
using std:: endl;

int main(){
    char s[20], temp;
    int n= 0, i= 0;

    cout<<"Inserisci stringa da invertire:"<<endl;
    cin>>s;

    while(s[i] != '\0'){
        n++;
        i++;
    }
    cout<<"La sua lunghezza e' "<<n<<".";
    
    for(i=0; i<(n/2); i++){
        temp= s[i]; 
        s[i]= s[n-i-1];
        s[n-1-i]= temp;
    }

    cout<<endl<<"Stringa invertita: "<<s;
}