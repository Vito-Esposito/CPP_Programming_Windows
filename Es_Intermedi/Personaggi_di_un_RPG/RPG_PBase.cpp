#include "RPG_PBase.hpp"
#include <iostream>

using namespace std;

RPG_PBase::RPG_PBase(){
    forza= 0;
    velocita= 0;
    salute= 0;
}

RPG_PBase::RPG_PBase(int f, int v, int s){
    forza= f;
    velocita= v;
    salute= s;
}

void RPG_PBase::setForza(int f){
    forza= f;
}

void RPG_PBase::setVelocita(int v){
    velocita= v;
}

void RPG_PBase::setSalute(int s){
    salute= s;
}

int RPG_PBase::getForza(){
    return forza;
}

int RPG_PBase::getVelocita(){
    return velocita;
}

int RPG_PBase::getSalute(){
    return salute;
}

void RPG_PBase::show(){
    cout << "[F:"<<forza<<", V:"<<velocita<<", S:"<< salute<<"]";
}