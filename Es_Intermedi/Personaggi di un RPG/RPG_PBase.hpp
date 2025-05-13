#ifndef RPG_HPP
#define RPG_HPP

class RPG_PBase{
    public:
    int forza;
    int velocita;
    int salute;

    RPG_PBase();
    RPG_PBase(int, int, int);

    void setForza(int);
    void setVelocita(int);
    void setSalute(int);
    int getForza();
    int getVelocita();
    int getSalute(); 

    void show();
};

#endif