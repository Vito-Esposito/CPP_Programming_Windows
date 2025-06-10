#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void input (string, T &);

template <typename T>
void show (string, T &);

template <typename S, typename T>
void scaXvett(S, T &);

template <typename t1, typename t2>
t1 PSVett(t1, t2);
//----------------------------------------------

template <typename T>
void input (string messaggio, vector<T> &vet){
    cout << messaggio << "di size " << vet.size() << endl;

    for (int i = 0; i < (int)vet.size(); i++)
    
        cin >> vet[i];
}

template <typename T>
void show (string messaggio, vector<T> &vet){
    cout << messaggio << "di size " << vet.size() << endl;

    for (int i = 0; i < (int)vet.size(); i++)
        cout << vet[i] << endl;
}

template <typename S, typename T>
void scaXvett(S scalare, vector<T> &vet){
    for (int i = 0; i < (int)vet.size(); i++)
        vet[i]= vet[i]*scalare;
}

template <typename t1, typename t2>
t1 PSVett(vector<t1> v1, vector<t2> v2){
    t1 prod= 0;

    cout << "Prodotto scalare di questi due vettori: ";

    for (int i = 0; i < (int)v1.size(); i++)
        prod = prod + v1[i]*v2[i];
    
    cout << prod << endl;
    return prod;
}

int main(){
    vector<int> vet;
    int size, size1, size2;

    cout << "Inserire size del vettore:" << endl;
    cin >> size;
    vet.resize(size);

    input("Vettore 1: ", vet);
    show("Stampa vettore 1: ", vet);
    scaXvett(3, vet);
    show("Stampa vettore x scalare: ", vet);

    cout << "Inserire size di altri due vettori:" << endl;
    cin >> size1 >> size2;

    vector<float> vett1(size1);
    vector<int> vett2(size2);

    input("Nuovo vettore 1: ", vett1);
    input("Nuovo vettore 2: ", vett2);

    PSVett(vett1, vett2);
}