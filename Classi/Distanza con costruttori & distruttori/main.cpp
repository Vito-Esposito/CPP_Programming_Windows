#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

class Punto{

    friend float Distanza(Punto, Punto);

    private:
            float x;
            float y;
    
    public:
    
    Punto(float x_val=0, float y_val=0){
        x= x_val;
        y= y_val;

        cout << "Costruttore chiamato per Punto(" << x << ", " << y << ")" << endl;
    }

    ~Punto(){
        cout << "Distruttore chiamato per Punto(" << x << ", " << y << ")" << endl;
    }
};

float Distanza(Punto p1, Punto p2){
    return sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
}

int main(){
    float p1_x, p1_y, p2_x, p2_y;

    cout << "Inserisci i punti P1 e P2:" << endl;
    cout << "P1:" << endl;
    cin>>p1_x>>p1_y;

    cout << "P2:" << endl;
    cin>>p2_x>>p2_y;

    Punto p1(p1_x, p1_y);
    Punto p2(p2_x, p2_y);

    cout << endl << "La distanza calcolata tra questi due punti e': " << Distanza(p1, p2) << endl;
}