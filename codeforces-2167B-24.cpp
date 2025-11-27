#include <bits/stdc++.h>
using namespace std;
int main(){
 
int testes;
cin >> testes;
 
for (int i=0;i<testes;i++){
    int tam_nome;
    cin >> tam_nome;
    vector <char> nome1;
    vector <char> nome2;
 
   for ( int j=0 ; j<tam_nome;j++){
    char c;
    cin >> c;
    nome1.push_back(c);
   }
 
   for ( int j=0 ; j<tam_nome;j++){
    char c;
    cin >> c;
    nome2.push_back(c);
   }
 
 
 
   sort(nome1.begin(),nome1.end());
   sort(nome2.begin(),nome2.end());
 
    if (nome1==nome2) cout << "YES\n";
    else cout << "NO\n";
 
    }
 
 
return 0;
}