#include <iomanip>
#include <iostream>

using std:: cin;
using std:: cout;
using std:: endl;

int main(){
    int matrice[3][3], n_magico=0, temp=0;
    bool isMagic= true;

    cout<<"Riempire una matrice di dimensioni 3x3 con i numeri da 1 a 9:"<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>matrice[i][j];
        }
    }

    cout<<endl<<"MATRICE"<<endl<<matrice[0][0]<<" "<<matrice[0][1]<<" "<<matrice[0][2]<<endl;
    cout<<matrice[1][0]<<" "<<matrice[1][1]<<" "<<matrice[1][2]<<endl;
    cout<<matrice[2][0]<<" "<<matrice[2][1]<<" "<<matrice[2][2]<<endl<<endl;

    cout<<endl<<"Quadrato magico?";

    for(int j=0; j<3; j++)
        n_magico += matrice[0][j];
    
    // righe    
    for(int i=1; i<3 && isMagic==true; i++){
        temp= 0;
        for(int j=0; j<3; j++){
            temp += matrice[i][j];
        }
        if(n_magico != temp){
            isMagic=false;
            break;
        }
    }

    // colonne
    for(int j=0; j<3 && isMagic==true; j++){
        temp= 0;
        for(int i=0; i<3; i++){
            temp += matrice[i][j];
        }
        if(n_magico != temp){
            isMagic=false;
            break;
        }
    }

    // Controllo della diagonale principale
    temp = matrice[0][0] + matrice[1][1] + matrice[2][2];
    if (temp != n_magico) {
        isMagic = false;
    }

    // Controllo della diagonale secondaria
    temp = matrice[0][2] + matrice[1][1] + matrice[2][0];
    if (temp != n_magico) {
        isMagic = false;
    }

    if (isMagic) {
        cout << endl << endl << "E' magico." << endl;
    } else {
        cout << endl << endl << "Non e' un quadrato magico." << endl;
    }


}