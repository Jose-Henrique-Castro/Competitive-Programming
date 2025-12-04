#include <bits/stdc++.h>
using namespace std;
vector <bool> vis;
vector <int> caminhoDFS;
vector <int> caminhoBFS;


vector <int> DFS(int end,int start,vector<vector<int>>& adj){

if(vis[start]) return caminhoDFS;

vis[start] = true;
caminhoDFS.push_back(start);

for(auto x : adj[start]){

    if(!vis[x]){
        DFS(end,x,adj);
    }
}
return caminhoDFS;
}

vector <int> BFS(int end,int start,vector<vector<int>>& adj){

vis[start] = true;
queue <int> q;
q.push(start);
caminhoBFS.push_back(start);

while(!q.empty()){

int atual = q.front();
q.pop();

for(auto vizinho : adj[atual]){

    if(!vis[vizinho]){
        vis[vizinho] = true;
        caminhoBFS.push_back(vizinho);
        q.push(vizinho);
    }

}

}
return caminhoBFS;
}


int main(){

int nodes,edges,start; cin >> nodes >> edges >> start;

vector <vector<int>> adj(nodes+1);

for(int i=0;i<edges;i++){
    int u,v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

for(int i=1;i<=nodes;i++){
    sort(adj[i].begin(),adj[i].end());
}

vis.assign(nodes+1,false);
vector <int> DFS_ = DFS(nodes,start,adj);
fill(vis.begin(),vis.end(),false);
vector <int> BFS_ = BFS(nodes,start,adj);

for(int i=0;i<DFS_.size();i++){
    cout << caminhoDFS[i] << (i == caminhoDFS.size() - 1 ? "" : " ");
}
cout << endl;

for(int i=0;i<BFS_.size();i++){
    cout << caminhoBFS[i] << (i == caminhoBFS.size() - 1 ? "" : " ");
}
cout << endl;

    return 0;
}