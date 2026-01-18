#include <bits/stdc++.h>
using namespace std;
vector<int> resultado_dfs;
vector<int> resultado_bfs;

void DFS (int u,vector <bool>& vis1,vector<vector<int>>&adj){

    vis1[u] = true;
    resultado_dfs.push_back(u);

    for(auto x : adj[u]){

        if(!vis1[x]){
            DFS(x,vis1,adj);
        }

    }


}

int main(){

int v , c,start; cin >> v >> c >> start;

vector<vector<int>> adj(v+1);
vector<bool> vis1(v+1,false);
vector<bool> vis2(v+1,false);

for(int i=0;i<c;i++){
int r,n; cin >> r >> n;
adj[r].push_back(n);
adj[n].push_back(r);
}

for(int i=1;i<=v;i++){
    sort(adj[i].begin(),adj[i].end());
}

DFS(start,vis1,adj);

queue <int> fila;
fila.push(start);
vis2[start] = true;

while(!fila.empty()){

    int u = fila.front();
    fila.pop();

    resultado_bfs.push_back(u);

    for(int x: adj[u]){

        if(!vis2[x]){
            vis2[x] = true;
            fila.push(x);
        }
    }

}

for(int i=0;i<resultado_dfs.size();i++){

cout << resultado_dfs[i];
i < resultado_dfs.size()-1 ? cout << " " : cout << "";

}
cout << endl;

for(int i = 0; i < resultado_bfs.size(); i++){
        cout << resultado_bfs[i];
        (i < resultado_bfs.size() - 1) ? cout << " " : cout << "";
    }
    cout << endl;

    
    return 0;
}