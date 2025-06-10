/*
Senza utilizzare la libreria <string.h>, scrivere un programma che inserite
due stringhe nello stdin verifichi se una è l’anagramma dell’altra.

• Esempi di anagrammi:
Scoiattolo/ciottolosa
Ingolfare/fragoline
Tasso/ sosta
Ribes/ serbi
*/

#include <iostream>

using namespace std;

int main() {
    char s1[50], s2[50];
    int freq1[256] = {0}, freq2[256] = {0}; // Array per contare i caratteri (256 per tutti i caratteri ASCII)
    int len1 = 0, len2 = 0;
    
    // Input delle stringhe
    cout << "Inserisci la prima stringa: ";
    cin >> s1;
    cout << "Inserisci la seconda stringa: ";
    cin >> s2;

    // Conta la lunghezza della prima stringa e riempie il conteggio dei caratteri
    while (s1[len1] != '\0') {
        freq1[(unsigned char)s1[len1]]++; // Incrementa il conteggio per il carattere s1[len1]
        len1++; // Aumenta la lunghezza
    }

    // Conta la lunghezza della seconda stringa e riempie il conteggio dei caratteri
    while (s2[len2] != '\0') {
        freq2[(unsigned char)s2[len2]]++; // Incrementa il conteggio per il carattere s2[len2]
        len2++; // Aumenta la lunghezza
    }

    // Se le lunghezze sono diverse, non possono essere anagrammi
    if (len1 != len2) {
        cout << "Le stringhe NON sono anagrammi." << endl;
        return 0; // Esce dal programma
    }

    // Confronta i conteggi dei caratteri
    for (int i = 0; i < 256; i++) {
        if (freq1[i] != freq2[i]) { // Se un carattere ha conteggio diverso, non sono anagrammi
            cout << "Le stringhe NON sono anagrammi." << endl;
            return 0; // Esce dal programma
        }
    }

    // Se il ciclo non ha trovato differenze, le stringhe sono anagrammi
    cout << "Le stringhe sono anagrammi." << endl;

    return 0;
}
