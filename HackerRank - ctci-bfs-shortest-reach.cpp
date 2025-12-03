#include <bits/stdc++.h>
using namespace std;

void add_aresta(int edges,vector<vector<int>>& adj){
    for(int i=0;i<edges;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

vector<int> BFS(int start,int end,vector<vector<int>>& adj){ // 1 2 3 4


vector <pair<int,int>> node_distance(end+1);
queue <int> q;
vector <int> dist(end+1,-1);

dist[start] = 0;
q.push(start); 

while(!q.empty()){

int node = q.front();
q.pop();

for (auto vizinho : adj[node]){
    if(dist[vizinho]==-1){
        dist[vizinho] = dist[node] + 6;
        q.push(vizinho);
    }
    
}
   
}
return dist;
}

int main(){

int queries; cin >> queries;

while(queries--){

    int nodes,edges; cin >> nodes >> edges;

    vector<vector<int>> adj(nodes+1);
    add_aresta(edges,adj);
    int start; cin >> start;

    vector <int> resultado = BFS(start,nodes,adj);

    for(int i=1;i<=nodes;i++){
        if(i==start) continue;
        else if(i<nodes) cout << resultado[i] << " ";
        else cout << resultado[i];
    }
    cout << endl;

}
    return 0;
}