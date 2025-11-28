#include  <bits/stdc++.h>
using namespace std;
// cont++ quando unir
// guardar a dupla em um vector<pair<int,int>>
int cont = 0;
vector<pair<int,int>> p;

vector<int> parent,siz;

int findUP(int u){
    if(u == parent[u]) return u; // ele nao é ultp dele mesmo
    return parent[u] = findUP(parent[u]); // ache o ult de u
}

void unionbysize (int x,int y){
    int ult_x = findUP(x);
    int ult_y = findUP(y);

    if(ult_x == ult_y) return;
    if(siz[ult_y]>siz[ult_x]){
        parent[ult_x] = ult_y; // 2 conecta no 1
        siz[ult_y] += siz[ult_x];
    }
    else{
        parent[ult_y] = ult_x;
        siz[ult_x] += siz[ult_y];
    }
}

int main(){

    int cities , conecçoes; cin >> cities >> conecçoes;
    parent.resize(cities+1);
    siz.resize(cities+1,1);

    for(int i=1;i<=cities;i++){
        parent[i] = i;
    }

    for(int i=0;i<conecçoes;i++){
        int x ,y;cin >> x >> y;
        unionbysize(x,y);
    }

   vector<int> lideres;

   for(int i=1;i<=cities;i++){
    if(parent[i]==i)lideres.push_back(i);
   }

   cout << lideres.size()-1 << endl;
   for(int i=0;i<lideres.size()-1;i++){
    cout << lideres[i] << " " << lideres[i+1] << endl;
   }
    return 0;
}