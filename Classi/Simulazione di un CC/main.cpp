/*
    Modifichiamo la classe MiniCCB per aggiungere la gestione di
    un PIN, richiesto per autorizzare ogni operazione su C/C.
    Il PIN di una istanza della classe è impostato dal costruttore
    Deve essere inserito dall’utente prima di ogni operazione e
    passato al metodo che la implementa;
    La classe verifica il PIN e rifiuta l’operazione in caso sia sbagliato;
    Tre errori di fila bloccano il C/C;
*/

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class MiniCCB {
    public:
        double Avere;
        string PIN;
        int count_error;
        int bloccato= false;
        string PUK="12345678910";

    MiniCCB(string pininserito){
        Avere=0; 
        count_error=0;
        PIN= pininserito;
        bloccato= false;
    }

    void Sblocca(){
        int i= 0;
        string mioPUK="", newPIN="";

        while (i < 10)
        {
            do{
            cout<<"Inserire PUK di 10 cifre: "<<endl;
            cin>>mioPUK;
            }while(mioPUK.size() < 10);

            if(mioPUK == PUK){
                cout<<"Inserire nuovo pin:";
                cin>>newPIN;
                cambiaPIN(newPIN);
                count_error= 0;
                bloccato= false;
                break;
            }
            else
                i++;
        }  
    }

    void cambiaPIN(string newPIN){
        while(newPIN.size() < 5){
            cout<<"Inserire nuovo PIN di 5 numeri: "<<endl;
            cin>>newPIN;
        }
        PIN= newPIN; 
    }

    void Blocco(int errori){
        if(errori == 3)
            bloccato= true;
    }

    int VerificaPin(string pininserito){
        if(count_error < 3){
            if(pininserito == PIN)
                return 1;
            else{
                count_error++;
                return 0;
            }
        } 
        return 0;
    }

    double Saldo(){
        return Avere;
    }

    void Deposito(double importo){
        Avere+=importo;
    }

    void Prelievo(double importo){
        Avere -= importo;
    }
};

int main(){
    bool ancora=true;
    int scelta=0;
    MiniCCB Conto("1234");
    string pin="";
    string NewPIN="";
    string PUK="";
    double importo=0;

    cout<<"Simulazione di un C/C Bancario v.1"<<endl<<endl;
    cout<<endl<<"MENU"<<endl<<endl;

    do{
        Conto.Blocco(Conto.count_error);
        

        cout << "MENU"<<endl<<endl;
        cout << "1: Deposito" << endl;
        cout << "2: Prelievo" << endl;
        cout << "3: Saldo " << endl;
        cout << "4: Cambio PIN"<<endl;
        cout << "5: Sblocca"<<endl;
        cout << "0: Fine " << endl<<endl;
        cout << "Inserisci la scelta:";
        cin >> scelta;

        switch(scelta){
            case 0:
                ancora=false;
                break;
            case 1:

                while(Conto.count_error < 3 && Conto.bloccato != true){
                    cout<<"Inserire PIN del CC: "<<endl;
                    cin>>pin;

                    if(Conto.VerificaPin(pin) == 1){
                        cout << "Importo da versare: ";
                        cin >> importo;
                        Conto.Deposito(importo);
                        Conto.count_error = 0;
                        break;
                    }
                    else{
                        cout<<"Pin sbagliato.";
                        cout<<endl<<"Tentativi fatti: "<<Conto.count_error<<"/3"<<endl;
                    }
                }
                break;

            case 2:

                while(Conto.count_error < 3 && Conto.bloccato != true){
                    cout<<"Inserire PIN del CC: "<<endl;
                    cin>>pin;

                    if(Conto.VerificaPin(pin) == 1){
                        cout << "Importo da prelevare: ";
                        cin >> importo;
                        Conto.Prelievo(importo);
                        Conto.count_error = 0;
                        break;
                    }
                    else{
                        cout<<"Pin sbagliato.";
                        cout<<endl<<"Tentativi fatti: "<<Conto.count_error<<"/3"<<endl;
                    }
                }
                break;
                
            case 3:

                while(Conto.count_error < 3 && Conto.bloccato != true){
                    cout<<"Inserire PIN del CC: "<<endl;
                    cin>>pin;

                    if(Conto.VerificaPin(pin) == 1){
                        cout<< "Saldo del conto: ";
                        cout<< Conto.Saldo() << endl;
                        Conto.count_error = 0;
                        break;
                    }
                    else{
                        cout<<"Pin sbagliato.";
                        cout<<endl<<"Tentativi fatti: "<<Conto.count_error<<"/3"<<endl;
                    }
                }
                break;

            case 4:

                if (Conto.bloccato != true) {
                    cout << "Inserire nuovo PIN di 5 numeri: " << endl;
                    cin >> NewPIN;

                Conto.cambiaPIN(NewPIN);
                pin= Conto.PIN;
                }else{
                    cout << "Il conto e' bloccato. Sbloccalo prima di cambiare il PIN." << endl;
                }
                break;
            
            case 5:

                if(Conto.bloccato == true){
                    Conto.Sblocca();

                    if(Conto.bloccato == false){
                        pin= Conto.PIN;
                    }
                }


        }
    }while(ancora);
}
