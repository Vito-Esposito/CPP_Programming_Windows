#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Int_Cnt {
private:
    int cnt;
public:
    Int_Cnt(int cnt=0);

    void Incr();
    void Decr();
    int Val();
    ~Int_Cnt();
};

Int_Cnt::Int_Cnt(int x){
    cnt= x;
}

void Int_Cnt::Incr(){
    cnt++;
}  

void Int_Cnt::Decr(){
    cnt--;
} 

int Int_Cnt::Val(){
    return cnt;
}

Int_Cnt::~Int_Cnt(){
}

class Cnt_Str {
private:
    string cnt;
public:
    Cnt_Str(string cnt="");
    
    void Set();
    void Incr();
    int Val();
    ~Cnt_Str();
};
    
Cnt_Str::Cnt_Str(string x){
    cnt= x;
}

void Cnt_Str::Set(){
    getline(cin, cnt);
}
    
void Cnt_Str::Incr(){
    cnt= cnt+"1";
}  
    
int Cnt_Str::Val(){
    return cnt.size();
}
    
Cnt_Str::~Cnt_Str(){
}

template <typename T>
void stampa_cnt(T x){
    int r;
    
    r=x.Val();
    cout << endl << "Valore del contatore: " << r << endl;
}

int main() {
    Cnt_Str myStr;
    
    cout << "Inserisci stringa: " << endl;
    myStr.Set();

    cout << "Valore iniziale: " << myStr.Val() << endl;  // Dovrebbe stampare 5 (lunghezza di "Hello")
    
    myStr.Incr();
    cout << "Dopo Incr: " << myStr.Val() << endl;  // Dovrebbe stampare 6 (lunghezza di "Hello1")
    
    myStr.Incr();
    cout << "Dopo altro Incr: " << myStr.Val() << endl;  // Dovrebbe stampare 7 (lunghezza di "Hello11")
    
    stampa_cnt(myStr);

    return 0;
}