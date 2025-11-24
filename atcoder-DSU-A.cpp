#include <bits/stdc++.h>
using namespace std;
class Disjointset {
vector<int> parent , size;
public:
Disjointset(int n){
    parent.resize(n+1,0);
    size.resize(n+1,1);
    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
}

int find_ult_parent(int node){
    if(node == parent[node]) return node;
    return parent[node] = find_ult_parent(parent[node]);
}

void unionbysize(int u,int v){
    int ult_u = find_ult_parent(u);
    int ult_v = find_ult_parent(v);

    if(ult_u == ult_v) return;
    if(size[ult_u]<size[ult_v]) {
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
        int add; cin >> add;
        int p1,p2; cin >> p1 >> p2;
        if(add) {
            if(dsu.find_ult_parent(p1)==dsu.find_ult_parent(p2)) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(!add){
            dsu.unionbysize(p1,p2);
        }

    }



    return 0;
}