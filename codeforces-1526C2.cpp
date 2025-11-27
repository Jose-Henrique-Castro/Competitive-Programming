#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

int numeros; cin >> numeros;
priority_queue<ll,vector<ll>,greater<ll>> poçoes; // menor pro maior

ll vida =0;

for(int i=0;i<numeros;i++){
    ll x; cin >> x;

    vida += x;
    poçoes.push(x);

    while(vida<0){
        ll pior_poçao = poçoes.top();
        poçoes.pop();

        vida -= pior_poçao;
    }

}

cout << poçoes.size() << endl;

    return 0;
}