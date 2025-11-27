#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
 
    int qtd_nomes; cin >> qtd_nomes;
    vector <string> nomes;
    bool flag = false;
 
    for (int i=0;i<qtd_nomes;i++){
        string nome; cin >> nome;
 
        if(find(nomes.begin(),nomes.end(),nome) != nomes.end()) cout << "YES" << endl;
        else {
            nomes.push_back(nome);
            cout << "NO" << endl;
        }
        
    }
     
    return 0;
}