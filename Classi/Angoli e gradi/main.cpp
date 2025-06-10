#include <iomanip>
#include <iostream>

using namespace std;

class tellAngle{
private:
        int gradi;
        int primi;
        int secondi;
public:
    tellAngle();
    tellAngle(int, int, int);
    
    void show();
};

tellAngle::tellAngle(){
    gradi= 0;
    primi= 0;
    secondi= 0;
}

tellAngle::tellAngle(int g, int p, int s)
{
    cout<<endl<<"Stampa dei gradi, primi e secondi:"<<endl;
    gradi= g % 360;
    primi= p % 60;
    secondi= s % 60;

}

void tellAngle::show(){
    cout << setw(3) << setfill('0') << gradi << ":";
    cout << setw(2) << setfill('0') << primi << ":";
    cout << setw(2) << setfill('0') << secondi << endl;
}

int main(){
    cout<<endl<<"Inserisci gradi, primi e secondi:"<<endl;
    int g, p, s;
    cin>>g>>p>>s;

    tellAngle Esempio(g, p, s);

    Esempio.show();
}