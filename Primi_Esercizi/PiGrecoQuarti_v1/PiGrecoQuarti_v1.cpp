#include <iostream>
#include <iomanip>

using std:: cout;
using std:: cin;
using std:: endl;

int main(){
    int i, n;
    double pi_greco= 0, num= 1;
    cout << "Calcolo di Pi Greco:" << endl;
    cout << "Inserisci numero di iterazioni: ";
    cin >> n;

    for(i=0; i<=n; i++){
        if(i%2==0)
            num= 1;
        else
            num= -1;

        pi_greco += num/(2*i+1);
    }
    
    pi_greco *= 4.0;
    cout << "Pi= " << pi_greco; 

    return 0;
}