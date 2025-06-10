/*
f) Verificare se esistono elementi nulli nella matrice e contemporaneamente
memorizzare gli elementi non nulli in un vettore V. Al termine stampare il numero
degli elementi nulli e il vettore V.
g) Dopo aver fatto la copia della matrice M, richiedere la posizione di una riga
(colonna) da eliminare dalla matrice copia (M_copia).
h) Calcolare la matrice trasposta
i) Verificare se la matrice è simmetrica
j) Copiare nei vettori VP e VS rispettivamente gli elementi della diagonale principale
e secondaria.
k) Memorizzare nei vettori MR e MC rispettivamente i minimi di ciascuna riga e di
ciascuna colonna.
*/

#include <iostream>
#include <iomanip>

using std:: cout;
using std:: cin;
using std:: endl;

int main(){
    int n, m;

    cout<<"Inserire n righe e m colonne di una matrice: "<<endl;
    cin>>n;
    cin>>m;
    int matrice[n][m];

    cout<<endl<<"Riempi matrice: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<"matrice["<<i<<"]"<<"["<<j<<"]= ";
            cin>>matrice[i][j];  
        }
    }

    cout<<endl<<"Stampa:"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<"matrice["<<i<<"]"<<"["<<j<<"]= "<<matrice[i][j]<<endl;
        }
    }

    cout<<endl<<"Ci sono elementi nulli?";
    int trovato= 0, cnt=0, vettore[20], k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrice[i][j] == 0){
                trovato= 1;
                cnt++;
            }
            else{
                vettore[k]= matrice[i][j];
                k++;
            }
        }
    }
    if(trovato == 1){
        cout<<endl<<"Elementi nulli trovati e ne sono "<<cnt<<".";
        cout<<endl<<"Vettore con gli elementi non nulli della matrice: "<<endl;
        for(int i=0; i<k; i++)
            cout<<"vettore["<<i<<"]= "<<vettore[i]<<endl;
    }
    else
        cout<<endl<<"Elementi nulli non trovati";

    int n_c=n, m_c=m;
    int matrice_copia[n_c][m_c];
    char risposta;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrice_copia[i][j]= matrice[i][j];
        }
    }
    cout<<endl<<"Eliminare riga (r) o colonna (c) della matrice copia? ";
    int r_c;
    cin>>risposta;
    while(risposta!='c' && risposta!='r'){
        cout<<"Riprova"<<endl;
        cin>>risposta;
    }
    if(risposta == 'r'){
        cout<<"Inserisci indice riga: "<<endl;
        cin>>r_c;

        for(int i=r_c; i<n_c; i++){
            for(int j=0; j<m_c; j++){
                matrice_copia[i][j]= matrice_copia[i+1][j];
            }
        }
        n_c= n-1;
        cout<<endl<<"Stampa:"<<endl;
        for(int i=0; i<n_c; i++){
            for(int j=0; j<m_c; j++){
                cout<<"matrice_copia["<<i<<"]"<<"["<<j<<"]= "<<matrice_copia[i][j]<<endl;
            }
        }
    }
    else if(risposta == 'c'){
        cout<<endl<<"Inserisci indice colonna: "<<endl;
        cin>>r_c;

        for(int i=0; i<n_c; i++){
            for(int j=r_c; j<m_c; j++){
                matrice_copia[i][j]= matrice_copia[i][j+1];
            }
        }
        m_c= m-1;
        cout<<endl<<"Stampa:"<<endl;
        for(int i=0; i<n_c; i++){
            for(int j=0; j<m_c; j++){
                cout<<"matrice_copia["<<i<<"]"<<"["<<j<<"]= "<<matrice_copia[i][j]<<endl;
            }
        }
    }

    cout<<endl<<"Matrice trasposta:";
    int matrice_trasp[m][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrice_trasp[j][i]= matrice[i][j];
        }
    }
    cout<<endl<<"Stampa:"<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"matrice_trasp["<<i<<"]"<<"["<<j<<"]= "<<matrice_trasp[i][j]<<endl;
        }
    }
    
    cout<<endl<<"Matrice simmetrica?";
    int simm=1;
    if(n==m){
        for(int i=0; i<n && simm==1; i++){
            for(int j=0; j<m; j++){
                if(matrice[i][j]==matrice[j][i])
                    simm=1;
                else{
                    simm=0;
                    break;
                }
            }
        }
    }else
        cout<<endl<<"Non e' una matrice quadrata.";
    if(simm == 1)
        cout<<endl<<"Matrice simmetrica.";
    else
        cout<<endl<<"Matrice non simmetrica";

    cout<<endl<<endl<<"Elementi della diagonale principale:";
    int VD[n];
    if(n==m){
        for(int i=0; i<n; i++){
            VD[i]= matrice[i][i];
        }

        for(int i=0; i<n; i++)
        cout<<endl<<VD[i]<<" ";
    }else
        cout<<endl<<"Non e' una matrice quadrata.";

    cout<<endl<<endl<<"Elementi della diagonale secondaria:";
    int VS[n];
    if(n==m){
        for(int i=0; i<n; i++){
            VS[i]= matrice[i][n-1-i];
        }

        for(int i=0; i<n; i++)
        cout<<endl<<VS[i]<<" ";
    }else
        cout<<endl<<"Non e' una matrice quadrata.";

    cout<<endl<<endl<<"Minimi di ogni riga:";
    int MR[n];
    MR[0]= matrice[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrice[i][j] < MR[i])
                MR[i]= matrice[i][j];
        }
    }
    cout<<endl<<"Minimi delle righe:";
    for (int i = 0; i < n; i++) {
        cout << " " << MR[i];
    }

    cout<<endl<<endl<<"Minimi di ogni colonna:";
    int MC[n];
    MC[0]= matrice[0][0];
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            if(matrice[i][j] < MC[j])
                MC[j]= matrice[i][j];
        }
    }
    cout<<endl<<"Minimi delle colonne:";
    for (int i = 0; i < n; i++) {
        cout << " " << MC[i];
    }
}