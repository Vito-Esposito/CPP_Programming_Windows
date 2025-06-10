/*
Utilizzando la libreria <string>, si scriva un programma che data una matrice di caratteri
quadrata, controlla se la parola leggibile sulla diagonale principale è anche leggibile in una
delle righe o colonne della matrice, restituendo 1 in caso affermativo e zero altrimenti.
*/

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

bool matrice_quadrata(string[], int);
int leggile(string[], int);

int main(){
    int n;
    cout << "Inserisci la dimensione della matrice quadrata (n x n): ";
    cin >> n;
    string matrice[n];

    // Crea una matrice di caratteri
    cout << "Inserisci la matrice (una riga per volta, parole di uguale lunghezza):\n";
    for (int i = 0; i < n; i++) 
        cin >> matrice[i];

    // Verifica se la matrice è quadrata
    if (!matrice_quadrata(matrice, n)) {
        cout << "La matrice non e' quadrata! Le righe devono avere la stessa lunghezza della dimensione n.\n";
        return 1;
    }

    if(leggile(matrice, n) == 1)
        cout<<"Parola leggibile sulla diagonale principale e' anche leggibile in una delle righe o colonne della matrice";
    else if(leggile(matrice, n) == 0)
        cout<<"Parola leggibile sulla diagonale principale non e' anche leggibile in una delle righe o colonne della matrice";
}

bool matrice_quadrata(string mat[], int n){
    for (int i = 0; i < n; i++)
        if((int)mat[i].size() != n)
            return false;
    return true;
}

int leggile(string mat[], int n){
    string diagonale="";
    string colonna="";

    // Crea diagonale
    for (int i = 0; i < n; i++)
        diagonale += mat[i][i];

    for (int i = 0; i < n; i++)
    {
        // Controllo righe
        if(mat[i] == diagonale)
            return 1;
        
        //Controllo colonne
        for (int j = 0; j < n; j++)
            colonna += mat[j][i];

        if(colonna == diagonale)
            return 1;
    }

    return 0;
}