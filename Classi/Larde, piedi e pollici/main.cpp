#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

/*
Sulla falsariga dell’esercizio precedente, si implementi la classe
lunghezza, nella quale; le misure sono espresse nel sistema
anglosassone costituito da: yarde, piedi e pollici ma i valori possono
essere assegnati e letti anche nel sistema metrico decimale.
1. Oltre al costruttore di default lunghezza(), si forniscano anche i
costruttori lunghezza(double y, double f, double i) per
le yarde, e lunghezza (double m) per i metri.
2. Si forniscano i metodi set(double m) e set (double y,
double f, double i) per impostare i valori nei due sistemi di
misura;
3. Si forniscano i metodi get/set degli attributi yard, feet e inches
(tutti double)
*/

class Lunghezza {
private:
    double yard, piedi, pollici;
public:
    Lunghezza();
    Lunghezza(double, double, double);
    Lunghezza(double);

    void ConvertiDaMetri(double);
    double ConvertiInMetri();
    void set(double, double, double);
    void set(double);
    void setYard(double);
    void setFeet(double);
    void setInches(double);
    double getYard();
    double getFeet();
    double getInches();
    void print();

    ~Lunghezza();
};

Lunghezza::Lunghezza(){
    yard= 0;
    piedi= 0;
    pollici= 0;
}

Lunghezza::Lunghezza(double y, double f, double i){
    yard= y;
    piedi= f;
    pollici= i;
}

Lunghezza::Lunghezza(double m){
    ConvertiDaMetri(m);
}

void Lunghezza::ConvertiDaMetri(double m){
    yard= m*1.09361;
    piedi= m*3.28084;
    pollici= m*39.3701;
}

double Lunghezza::ConvertiInMetri(){
    double my = yard * 0.9144;
    double mp = piedi * 0.3048;
    double mpo = pollici * 0.0254;
    
    if(my != 0)
        return (int)ceil(my);
    else if(mp != 0)
        return (int)ceil(mp);
    else if(mpo != 0)
        return (int)ceil(mpo);
    else 
        return 0;
}

void Lunghezza::set(double a, double b, double c){
    yard= a;
    piedi= b;
    pollici= c;
}

void Lunghezza::set(double m){
    ConvertiDaMetri(m);
}

void Lunghezza::setYard(double y){
    yard= y;
}

double Lunghezza::getYard(){
    return yard;
}

void Lunghezza::setFeet(double f){
    piedi= f;
}

double Lunghezza::getFeet(){
    return piedi;
}

void Lunghezza::setInches(double i){
    pollici= i;
}

double Lunghezza::getInches(){
    return pollici;
}

void Lunghezza::print(){
    cout<<endl<<"Yard: "<<yard<<endl<<"Piedi: "<<piedi<<endl<<"Pollici: "<<pollici<<endl<<"Metri: "<<ConvertiInMetri()<<endl;;
}

Lunghezza::~Lunghezza(){
}


int main(){
    double m, pollici;

    cout<<"Inserisci metri: ";
    cin>>m;

    Lunghezza Misura(m);

    cout<<"Conversione e stampa:";
    Misura.print();

    cout<<"Inserisci pollici: ";
    cin>>pollici;

    Misura.setInches(pollici);
    cout<<"Pollici:"<<Misura.getInches();
}