#include <iomanip>
#include <iostream>
#include "punto.hpp"

using namespace std;

int main(){
    Punto punti[9];
    int pos=0;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            punti[pos].setX(i).setY(j);
            pos++;
    }

    for(int i=0;i<9;i++){
        punti[i].show();
        cout<<":"<<punti[i].distanza_origine()<<endl;
    }

}