#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename T>
bool Confronta(T, T);

int Genera_Numero(int min, int max){
    return min + rand()%(max-min+1);
}

float Genera_Numero(float min, float max){
    return min + (rand() / (float)RAND_MAX) * (max - min);
}

template <typename T>
bool Confronta(T num_segr, T tent){
    if(num_segr == tent)
        return true;
    else 
        return false;
}

int main(){
    int scelta;
    char scelta_2;
    srand(time(nullptr));

    cout << endl << "BENVENUTO NEL GIOCO INDOVINA IL NUMERO" << endl << endl;

    do{
        cout << "Vuoi inserire numero reale (r) o intero (i)?";
        cin >> scelta_2;

        while(scelta_2 != 'r' && scelta_2 != 'i'){
            cout << "Inserire il giusto input: " << endl;
            cin >> scelta_2;
        }
        
        cout << endl << "Inserire minimo e massimo: " << endl;
        float min, max, tentativo, n_s;
        cin >> min >> max;

        cout << "Inserire il tuo tentativo: " << endl;
        cin >> tentativo;

        // Chiamata alla funzione Genera_Numero in base alla scelta dell'utente
        if (scelta_2 == 'i') {
            // Per numeri interi
            int n_s_int = Genera_Numero((int)min, (int)max);
            if (Confronta(n_s_int, (int)tentativo)) {
                cout << "HAI VINTO, era " << n_s_int << endl;
            } else {
                cout << "HAI PERSO, era " << n_s_int << endl;
            }
        } else if (scelta_2 == 'r') {
            // Per numeri reali
            n_s = Genera_Numero(min, max);
            n_s = (int)(n_s * 10.0f) / 10.0f;
            if (Confronta(n_s, tentativo)) {
                cout << "HAI VINTO, era " << n_s << endl;
            } else {
                cout << "HAI PERSO, era " << n_s << endl;
            }
        }

    cout << endl << "0) CONTINUARE" << endl << "1) TERMINARE IL GIOCO" << endl;
        cin >> scelta;

    while(scelta != 1 && scelta != 0){
        cout << "Inserire il giusto input: " << endl;
        cin >> scelta;
    }
        
    }while(scelta != 1);
}