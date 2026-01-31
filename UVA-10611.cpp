#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

// lower_bound e upper_bound


ll chimpamzes; cin >> chimpamzes;
vector<ll> altura_femeas;

for(int i=0;i<chimpamzes;i++){
    ll altura; cin >> altura;
    altura_femeas.push_back(altura);
}

sort(altura_femeas.begin(),altura_femeas.end());

ll alturas_macho; cin >> alturas_macho;
vector<ll> alturas_luchu(alturas_macho);

for(int i=0;i<alturas_macho;i++){ cin >> alturas_luchu[i];}

for(int i=0;i<alturas_macho;i++){
ll altura_luchu = alturas_luchu[i];

auto lower = lower_bound(altura_femeas.begin(),altura_femeas.end(),altura_luchu);

ll baixo = lower == altura_femeas.begin() ? -1 : *(lower-1);

auto upper = upper_bound(altura_femeas.begin(),altura_femeas.end(),altura_luchu);

ll alto = upper == altura_femeas.end() ? -1 : *upper;

if(baixo == -1) {
    cout << "X ";
}
else {
    cout << baixo << " ";
}

if(alto == -1){
    cout << "X" << endl;
}
else{
    cout << alto << endl;
}


}

    return 0;
}