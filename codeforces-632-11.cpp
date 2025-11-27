#include <bits/stdc++.h>
using namespace std;
 
bool maior(string a,string b){
  return a+b < b + a;
}
 
int main() 
{
    
    int testes; cin >> testes;
    
    vector <string> frase;
    
    for(int i=0;i<testes;i++){
      string s; cin >> s;
      frase.push_back(s);
    }
    
    sort(frase.begin(),frase.end(),maior);
    
    for (auto x : frase){
      cout << x;
    }
    cout << endl;
    
    return 0;
}