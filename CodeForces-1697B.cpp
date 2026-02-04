 #include <bits/stdc++.h> 
 using namespace std;
 #define ll long long


 int main(){

    ll items , queries; cin >> items >> queries;
    vector<ll> prices(items);

    for(int i=0;i<items;i++){
        cin >> prices[i];
    }

    sort(prices.begin(),prices.end());

    vector<ll> pref(items+1,0);

    for(int i=1;i<=items;i++) pref[i] = pref[i-1] + prices[i-1];

    while(queries--){

        ll compras , mais_baratos; cin >> compras >> mais_baratos;

        ll indice_f = items - compras + mais_baratos;
        ll indice_i = items - compras;

        cout << pref[indice_f] - pref[indice_i] << endl;


    }

    return 0;
 }