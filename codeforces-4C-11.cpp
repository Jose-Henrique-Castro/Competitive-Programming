#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
int num; cin >> num;
map <string,int> palavras;
for(int i=0;i<num;i++){
string s; cin >> s;  
 
if(palavras.find(s) != palavras.end()) { 
    cout << s << palavras[s] << endl; 
    palavras[s]++; 
    
}
 
else{
    cout << "OK" << endl;  
    palavras[s] = 1; }
 
}
 
 
    return 0;
}