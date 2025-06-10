/* Si scriva un programma che:
Chieda all’utente di immettere:
• L’anno corrente (oggi)
• L’anno di nascita di Cappuccetto Rosso (nata_cr)
• Il numero di focaccine che C.R. porta nel cestino (focaccine)
• Il numero di focaccine che il Lupo sottrae a cappuccetto rosso (focacciout) */

#include <iostream>
#include <iomanip>

using std:: cin;
using std:: cout;
using std:: endl;

int main(){
    int anno, nata_cr, focaccine, focacciout;

    cout << "Inserisci anno corrente: ";
    cin >> anno;
    cout << "Inserisci anno di nascita di Cappuccetto Rosso: ";
    cin >> nata_cr;
    cout << "Inserisci numero di focaccine che ha C.R.: ";
    cin >> focaccine;
    cout << "Inserisci numero di focaccine che il lupo rubera': ";
    cin >> focacciout;

    cout <<"Nel "<<anno<<", Cappuccetto rosso era nata nel "<<nata_cr<<", e portava con se' "<<focaccine<<" focaccine, ma il lupo glie ne rubo' "
    <<focacciout<<"."<<endl; 

    return 0;
}