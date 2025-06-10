#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
        fstream fout;
        string data;
        char scelta;
        int count = 0;

        ios_base::openmode mode;

        cout << "*** Output su file ***" << endl;
        cout << "Mode: (o)ut, (a)pp." << endl;
        cin >> scelta;

        switch (scelta){
                case 'a':
                        mode = ios_base::app;
                        cout << "append"<<endl;
                        break;
                default:
                case 'o':
                        mode = ios_base::out;
                        cout << "out" << endl;
                        break;
        }

        fout.open("data.txt", mode);

        cout << "Inserisci i dati: (exit per terminare)" << endl << endl;

        do{
            cout << "data> ";
            cin >> data;

            if (data == "exit")
                break;

            fout << data << endl;
            count++;

        } while(1);

        cout << "Operazione conclusa. ";
        cout << "Salvate " << count << " righe" << endl;
        fout.close();
}

