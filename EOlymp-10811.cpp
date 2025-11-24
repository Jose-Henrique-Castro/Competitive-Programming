#include <bits/stdc++.h>
using namespace std;
class Disjointset {
vector<int> parent,size;
public:
Disjointset(int n){
    parent.resize(n+1);
    size.resize(n+1,1);
    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
}

int findUltParent(int u){
    if(u==parent[u]) return u;
    return parent[u] = findUltParent(parent[u]);
}

void unionbysize(int u,int v){
int ult_u = findUltParent(u);
int ult_v = findUltParent(v);

if(ult_u==ult_v) return;
if(size[ult_v]>size[ult_u]){
    parent[ult_u] = ult_v;
    size[ult_v] += size[ult_u];
}
else{
    parent[ult_v] = ult_u;
    size[ult_u] += size[ult_v];
}
}
};

int main() 
{

int nodes , testes; cin >> nodes >> testes;
Disjointset dsu(nodes);
while(testes--){

string s; cin >> s;
int  p1,p2; cin >> p1 >> p2;

if(s=="union"){
    dsu.unionbysize(p1,p2);
}
else if (s=="get"){
    if(dsu.findUltParent(p1)==dsu.findUltParent(p2)) cout << "YES\n";
    else cout << "NO\n";
}

}

    return 0;
}