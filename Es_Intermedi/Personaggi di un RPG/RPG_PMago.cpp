#include "RPG_PMago.hpp"
#include <iostream>

using namespace std;

RPG_PMago::RPG_PMago(){
    forza= 0;
    velocita= 0;
    salute= 0;
    magia= 0;
    incantesimi= 0;
}

RPG_PMago::RPG_PMago(int f, int v, int s, int m, int i):  RPG_PBase(f, v, s){
    magia= m;
    incantesimi= i;
}

int RPG_PMago::getMagia(){
    return magia;
}

int RPG_PMago::getIncantesimi(){
    return incantesimi;
}

void RPG_PMago::setMagia(int m){
    magia= m;
}

void RPG_PMago::setIncantesimi(int i){
    incantesimi= i;
}

void RPG_PMago::show(){
    RPG_PBase::show();
    cout << " (Mag:"<<magia<<", Inc:"<<incantesimi<<")";
}