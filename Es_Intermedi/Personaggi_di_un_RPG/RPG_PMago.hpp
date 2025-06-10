#ifndef RPGMago_HPP
#define RPGMago_HPP

#include "RPG_PBase.hpp"

class RPG_PMago: public RPG_PBase{
    public:
    int magia;
    int incantesimi;

    RPG_PMago();
    RPG_PMago(int, int, int, int, int);

    int getMagia();
    int getIncantesimi();

    void setMagia(int);
    void setIncantesimi(int);
    void show();
};

#endif
