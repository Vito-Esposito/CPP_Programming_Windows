#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
        fstream fin;
        string data;
        char scelta;
        int count = 0;

        ios_base::openmode mode;

        cout << "*** Input (lettura) da file ***" << endl;
        cout << "Mode: (i)n, (a)te." << endl;
        cin >> scelta;

        switch (scelta){
                case 'i':
                        mode = ios_base::in;
                        cout << "in" << endl;
                        break;
                default:
                case 'a':
                        mode = ios_base::ate;
                        cout << "ate" << endl;
                        break;
        }

        fin.open("data.txt", mode);

        if(!fin){
                cout << endl << "Impossibile aprire il file!" << endl;
                return 1;
        }

        cout << "Lettura dei dati: " << endl << endl;

        while (fin >> data){
                cout << "data: " << data << endl;
                count++;
        }
        

        cout << "Operazione conclusa. ";
        cout << "Lette " << count << " righe" << endl;
        fin.close();
}

