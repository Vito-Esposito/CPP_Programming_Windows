#ifndef PUNTO_HPP
#define PUNTO_HPP

class Punto{
    public:
    double x;
    double y;

    Punto();
    Punto(double, double);

    double getX() const;  // aggiungendo const, posso usare questo metodo anche su oggetti const, e mi assicuro che nessun membro venga così modificato da questo metodo
    double getY() const;
    Punto &setX(double);
    Punto &setY(double);
    double distanza_origine() const;
    void show();
};

#endif