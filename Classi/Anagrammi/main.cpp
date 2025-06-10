#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void verifica_anagramma(string, string, int[]);

int main(){
    string s1, s2;
    int conteggio[256]={0};

    cout<<"Inserisci le due stringe:"<<endl;
    cin>>s1>>s2;

    verifica_anagramma(s1, s2, conteggio);
}
    

void verifica_anagramma(string s1, string s2, int conteggio[]){
    cout<<"Una e' l'anagramma dell'altra?"<<endl;

    if(s1.size() == s2.size()){
        for (int i = 0; i < (int)s1.size(); i++){
            conteggio[(unsigned char)s1.at(i)]++;
            conteggio[(unsigned char)s2.at(i)]--;
        }

        for (int i = 0; i < 256; i++){
           if (conteggio[i] != 0){
            cout<<endl<<"Una non e' l'anagramma dell'altra.";
            return;
           }
        }    
    }else{
        cout<<"Parole di lunghezza diversa, impossibile che una sia l'anagramma di un'altra.";
    }

    cout<<endl<<"Una e' l'anagramma dell'altra.";
}
