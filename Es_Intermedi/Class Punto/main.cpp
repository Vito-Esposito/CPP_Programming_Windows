
#include <iomanip>
#include <iostream>
#include "punto3D.hpp"

using namespace std;

int main() {
    Punto3D punti3[9];
    int pos=0;
    int seed;

    cout << "Seed: ";
    srand(seed);

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            punti3[pos++].setX(i).setY(j).setZ(rand()%3);

    for(int i=0;i<9;i++){
        punti3[i].show();
        cout<<":"<<punti3[i].distanza_origine()<<endl;
    }
}