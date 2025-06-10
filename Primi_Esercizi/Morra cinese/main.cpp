#include <iostream>
#include <iomanip>
#include <cstdlib>  // Per rand() e srand()
#include <ctime>    // Per time()

using std:: cout;
using std:: cin;
using std:: endl;

int main(){
    bool matrice[3][3]={{false, false, true},{true, false, false},{false, true, false}};
    int mossa=0;
    // Inizializza il generatore di numeri casuali con il tempo corrente
    srand(time(0)); 

    cout<<"Inserisci la mossa da fare (inserire qualsiasi altro numero per terminare il gioco della morra cinese)"<<endl;
    cout<<"| SASSO 0 | CARTA 1 | FORBICI 2 |"<<endl;
    while(mossa == 0 || mossa == 1 || mossa == 2){
        cin>>mossa;

        cout<<"Hai giocato: ";
        if(mossa == 0)
            cout<<"sasso"<<endl;
        else if(mossa == 1)
            cout<<"carta"<<endl;
        else
            cout<<"forbici"<<endl;

        // Genera un numero casuale tra 0, 1 e 2
        int CPU = rand() % 3;

        cout<<"La CPU ha giocato: ";
        if(CPU == 0)
            cout<<"sasso"<<endl;
        else if(CPU == 1)
            cout<<"carta"<<endl;
        else
            cout<<"forbici"<<endl;

        cout<<endl<<"ESITO: ";
        if(mossa==CPU)
            cout<<"parita'."<<endl;
        else if(matrice[mossa][CPU]==true)
            cout<<"hai vinto."<<endl;
        else if(matrice[mossa][CPU]==false)
            cout<<"hai perso."<<endl;
    }
}