#include <iomanip>
#include <iostream>

using namespace std;

class Dado{
private:
        int facce;
public:
        Dado(int nf= 6);
        void agita(int);
        int lancio();

        ~Dado();
};

Dado::Dado(int nf){
    if(nf < 2)
        facce= 2;
    else
        facce= nf;
}

void Dado::agita(int seed){
    srand(seed);
}

int Dado::lancio(){
    return (rand() % facce) + 1;
}

Dado::~Dado()
{
    cout << "Distruzione oggetto dado." << endl;
}

//----------------------------------------------------------------

class Bussolotto{
private:
        Dado *dadi;
        int numdadi;
public:
        Bussolotto(int num=2, int nf= 6);
        void agita(int);
        int lancio(int num=0);

        ~Bussolotto();
};

Bussolotto::Bussolotto(int num, int nf){
    dadi= new Dado[num];

    for (int i = 0; i < num; i++){
        dadi[i]= Dado(nf);
    }
    numdadi= num;
}

void Bussolotto::agita(int seed){
    srand(seed);
}

int Bussolotto::lancio(int num) {
    if (num < 1 || num > numdadi) {
        num = numdadi;  // Se num non è valido, lancia tutti i dadi
    }

    int somma = 0;
    for (int i = 0; i < num; i++) {
        somma += dadi[i].lancio();  // Somma il risultato di ogni dado
    }

    return somma;
}

Bussolotto::~Bussolotto(){
    delete []dadi;
}

//-----------------------------------------------------------------

int main(){
        Bussolotto b1(2,3);
        int seed;
        cout << "Inserisci un seed: ";
        cin >> seed;
        
        b1.agita(seed);
        cout << "Lancio i dadi, punteggio=" << b1.lancio() <<endl;
}