/*
C’era una AAAA di nome Cappuccetto Rosso che si recava dalla sua nonnina al di là del bosco per
portarle BBBB focaccine calde calde. Durante il tragitto, il Lupo Cattivo rubò a Cappuccetto Rosso
ben CCCC focaccine.
Giunta infine dalla nonna, cappuccetto le porse il cestino e la nonna disse:
a) «grazie nipotina mia per queste DDDD focaccine» se nel cesto ci sono ancora focaccine
b) «grazie nipotina mia per avermi fatto visita!» se nel cesto non c’è più alcuna focaccina.

• Al posto di AAAA il programma deve scrivere «bambina» se l’età di C.R. è inferiore ai 12 anni,
«ragazza» se è superiore ai 12 anni ma inferiore ai 20 e «donna» negli altri casi;
• Al posto di BBBB e CCCC vanno sostituiti corrispondenti valori ottenuti in input
• Al posto di DDDD deve essere visualizzato il numero di focaccine residue */

#include <iostream>
#include <iomanip>

using std:: cout;
using std:: cin;
using std:: endl;

int main(){
    int eta, focac, focac_rub, focac_res;

    cout << "Inserisci l'eta' di Cappuccetto Rosso: ";
    cin >> eta;
    cout << "Inserisci numero di focaccine che ha Cappuccetto Rosso: ";
    cin >> focac;
    cout << "Inserisci numero di focaccine che il lupo ha rubato: ";
    cin >> focac_rub;


    cout <<endl<< "C'era una ";
    if(eta < 12)
        cout << "bambina ";
    else if(eta > 12 && eta < 20)
        cout << "ragazza ";
    else if(eta >= 20)
        cout << "donna ";

    cout << "di nome Cappuccetto Rosso che si recava dalla sua nonnina al di la' del bosco per portarle " <<focac<<" focaccine calde calde."<<endl<<
    "Durante il tragitto, il Lupo Cattivo rubo' a Cappuccetto Rosso ben "<<focac_rub<<" focaccine."<<endl<<"Giunta infine dalla nonna, cappuccetto le porse il cestino e la nonna disse: "<<endl;
    
    focac_res= focac-focac_rub;

    if(focac_res > 0)
        cout << "grazie nipotina mia per queste "<<focac_res<<" focaccine!";
    else
        cout << "grazie nipotina mia per avermi fatto visita!";
    
    return 0;
}