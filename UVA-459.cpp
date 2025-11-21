#include <bits/stdc++.h>
using namespace std;

vector <int> letras[26];
bool vis[26];

void DFS(int i){  // marca os que ja foram como visitados 
    vis[i] = true; // vis[0] = true

    for(auto x : letras[i]){
        if(!vis[x]){
            DFS(x); // marca todos conectados como visitados
        }
    }

}

int main() 
{

   int testes; cin >> testes;
   cin.ignore();
   cin.ignore();

   while(testes--){

    string tam_char;
    getline(cin,tam_char);
    int tam_num = tam_char[0] - 'A' + 1; // tamanho

    for(int i=0;i<26;i++){
        letras[i].clear();
        vis[i] = false;
    }

    string linha;

    while(getline(cin,linha) &&  !linha.empty()){

        int c1 = linha[0] - 'A'; // índice
        int c2 = linha[1] - 'A';

        letras[c1].push_back(c2); // letra[1] = 2
        letras[c2].push_back(c1); // letra[2] = 1

    }

    int cont = 0;

    for(int i=0;i<tam_num;i++){
        if(!vis[i]){
            cont++; // conta quando a letra nao for visitada , inclusive as que sobrarem;
            DFS(i); 
        }
    }

    cout << cont << endl;

    if(testes > 0) cout << endl;

   }

     return 0;
}