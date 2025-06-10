#include <iomanip>
#include <iostream>

using namespace std;

class prova{
    private:
            int *p; //puntatore a un array dinamico
            int size; //dimensione dell'array

    public:
            prova(int n= 10){
                p= new int[n];
                size= n;
            }

            int len(){
                return size;
            }

            void set(int pos, int valore){
                if(pos >= 0 && pos < size)
                    p[pos]= valore;
            }

            int get(int pos){
                if(pos >= 0 && pos < size)
                    return p[pos];
                else
                    return -1;
            }

            ~prova(){
                delete[] p;
                cout << "Array distrutto." << endl;
            }

        };

void stampa(prova array){
    for (int i = 0; i < array.len(); i++)
    {
        cout << "Array stampato: ";
        cout << array.get(i) << endl;
    }
}       

int main(){
    int n, temp;

    cout << "Inserire size dell'array che si vuole creare:" << endl;
    cin >> n;

    prova array(n);

    cout << endl << "Il suo size e': " << array.len() << endl;

    cout << "Inserisci " << array.len() << " valori:" << endl;
    for (int i = 0; i < array.len(); ++i) {
        cin >> temp;
        array.set(i, temp);
    }

    stampa(array);
}