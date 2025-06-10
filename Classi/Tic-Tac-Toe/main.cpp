#include <iomanip>
#include <iostream>

using namespace std;

class tttPlayGround
{
private:
    int playground[3][3];
    int prossimoG;
public:
    tttPlayGround();
    void show();
    char prossimo();
    bool muovi(int, int);
    void reset();
};

void tttPlayGround::reset()
{
    for(int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            playground[i][j]= 0;
}

tttPlayGround::tttPlayGround()
{
    reset();

    prossimoG= 1;
}

void tttPlayGround::show()
{
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(playground[i][j] == 0)
                cout<<"|"<<" ";
            if(playground[i][j] == 1)
                cout<<"|"<<"O";
            if(playground[i][j] == 2)
                cout<<"|"<<"X";
        }
        cout<<"|"<<endl;
    }
}

char tttPlayGround::prossimo()
{
    if(prossimoG == 1) 
        return 'O';
    else if(prossimoG == 2)
        return 'X';
}

bool tttPlayGround::muovi(int riga, int col)
{
    if (riga < 0 || riga > 2 || col < 0 || col > 2)
        return false;
    if (playground[riga][col] != 0)
        return false;

    playground[riga][col]= prossimoG; 

    if(prossimoG == 1)
        prossimoG= 2;
    else if(prossimoG == 2)
        prossimoG= 1;
    
    return true;
}


int main(){
    int riga, colonna;
    tttPlayGround Partita;

    cout<<"INIZIO PARTITA"<<endl<<endl;

    Partita.show();



    cout<<endl<<"Turno del giocatore: "<<Partita.prossimo();

    cout<<endl<<"Inserisci riga e colonna di dove giocare:"<<endl;
    cin>>riga>>colonna;
    Partita.muovi(riga, colonna);
    Partita.show();

    cout<<endl<<"Turno del giocatore: "<<Partita.prossimo();

    cout<<endl<<"Inserisci riga e colonna di dove giocare:"<<endl;
    cin>>riga>>colonna;
    Partita.muovi(riga, colonna);
    Partita.show();


}