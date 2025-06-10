#include <iomanip>
#include <iostream>

using namespace std;

template <class T> // definisco una classe template
class Couple{
    public:
        T data[2];

        Couple();
        Couple(T x, T y);
        void set(T x, T y);
        void get(T &a, T &b);

        // Ridefinizioni degli operatori
        Couple<T>& operator>>(T &i);
};

template <class T>
Couple<T>& operator>>(T i, Couple<T> &c){
    c.data[0]= i;

    return c;
}

template <class T>
Couple<T>::Couple(T x, T y){  // devo scrivere <T> perchè ho una classe template
    set(x, y);
}

template <class T>
Couple<T>::Couple(){
    data[0]= 0;
    data[1]= 0;
}

template <class T>
void Couple<T>::set(T a, T b){
    data[0]= a;
    data[1]= b;
}

template <class T>
void Couple<T>::get(T &a, T &b){
    a= data[0];
    b= data[1];
}

template <class T>
Couple<T>& Couple<T>::operator>>(T &i){
    i= this->data[1];
    return *this;
}

int main(){
    Couple<float> x;
    
    cout<<"Valori iniziali: "<<endl<<x.data[0]<<" e "<<x.data[1]<<endl;
    cout<<"Inserisci una coppia di valori float: "<<endl;
    float v1, v2;
    cin>>v1>>v2;

    x.set(v1, v2);
    cout<<"Valori attuali: "<<endl<<x.data[0]<<" e "<<x.data[1]<<endl;

    cout<<"Variabile i ora contiene grazie all'operatore >>: "<<endl;
    float i=0;

    x>>i;
    cout<<i<<endl;

    cout<<"Inserisci nuovo i:"<<endl;
    cin>>i;

    i>>x;
    cout<<"Ora il secondo elemento della coppia contiene i: "<<x.data[0]<<endl;
}

