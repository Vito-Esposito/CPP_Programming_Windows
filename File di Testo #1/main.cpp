#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ofstream fileo;

    cout<<endl<<"Scrittura..";

    fileo.open("prova.txt");
    fileo<<"Ciao questa e' una prova."<<endl;
    fileo<<"CHIUSURA FILE"<<endl;
    fileo.close();

    cout<<endl<<"Fine scrittura."<<endl;

    ifstream filei;
    filei.open("prova.txt");

    if(!filei){
        cout<<endl<<"Errore apertura file!"<<endl;
        return 1;
    }

    cout<<endl;

    string riga;
    while (getline(filei, riga)) {
        cout << riga << endl;
    }

    filei.close();
}