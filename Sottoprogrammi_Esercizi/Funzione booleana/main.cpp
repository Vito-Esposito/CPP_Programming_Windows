/*
Si scriva un programma C++ che chieda all’utente fornire in
input i valori da applicare ai tre ingressi A,B e C del circuito
al lato (codificate con delle variabili booleane), quindi
calcoli e visualizzi il valore dell’uscita X.
1) Input e output devono essere effettuate utilizzando le
costanti testuali true e false
2) Il circuito deve essere implementato nella funzione
circuito(), mentre la funzione main() si dovrà
occupare solo di chiedere l’input, invocare la funzione
e visualizzarne il risultato.
*/

#include <iostream>
#include <iomanip>
#include <string>

using std:: cin;
using std:: cout;
using std:: endl;
using std:: string;

bool circuito(bool, bool, bool);

int main(){
    bool A, B, C;
    string input;

    // Chiediamo i valori di A, B e C con controllo dell'input
    while (true) {
        cout << "Inserisci valore per A (true/false): ";
        cin >> input;
        if (input == "true" || input == "false") {
            A = (input == "true");
            break;
        } else {
            cout << "Valore non valido! Devi inserire 'true' o 'false'." << endl;
        }
    }

    while (true) {
        cout << "Inserisci valore per B (true/false): ";
        cin >> input;
        if (input == "true" || input == "false") {
            B = (input == "true");
            break;
        } else {
            cout << "Valore non valido! Devi inserire 'true' o 'false'." << endl;
        }
    }

    while (true) {
        cout << "Inserisci valore per C (true/false): ";
        cin >> input;
        if (input == "true" || input == "false") {
            C = (input == "true");
            break;
        } else {
            cout << "Valore non valido! Devi inserire 'true' o 'false'." << endl;
        }
    }

    cout<<endl<<"Il risultato del circuito logico e' "<<circuito(A, B, C)<<".";
}

bool circuito(bool a, bool b, bool c){
    return (a&&b)||(b||c);
}