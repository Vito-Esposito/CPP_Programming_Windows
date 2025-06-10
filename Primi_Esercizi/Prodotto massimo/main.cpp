#include <iostream>
#include <iomanip>

using std:: cin;
using std:: cout;
using std:: endl;

int main(){
    int n=0, max1, max2;
    
    cout<<"Inserire numero di elementi da analizzare (almeno 2): ";
    do{
        cin>>n;
    }while(n<2);
    
    int a[n];

    cout<<endl<<"Inserire gli elementi (numeri): "<<endl;
    for(int i=0; i<n; i++)
        cin>>a[i];

    if (a[0] > a[1]) {
        max1 = a[0];
        max2 = a[1];
    } else {
        max1 = a[1];
        max2 = a[0];
    }

    for(int i=2; i<n; i++){
        if(a[i] > max1){
            max2= max1;
            max1= a[i];
        }
        else if(a[i] > max2){
            max2= a[i];
        }
    }

    cout<<"I due massimi sono "<<max1<<" e "<<max2;
    int temp= max1*max2;
    cout<<", per cui il prodotto massimo e' "<<temp<<".";
}