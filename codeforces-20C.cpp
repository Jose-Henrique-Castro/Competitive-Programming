#include <bits/stdc++.h>
using namespace std;
int nodes,edges;

vector <int> Dijkstra(int start,int nodes,vector<vector<pair<int,int>>>&adj){

    vector<long long> dist(nodes+1,1e18);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    vector <int> caminho;
    vector <int> parent(nodes+1,0);
dist[start] = 0;
pq.push({0,start}); // peso , node 

while(!pq.empty()){

    long long dist_atual = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(dist_atual > dist[node]) continue;

    for(auto vizinho : adj[node]){

        int V = vizinho.first;
        int peso = vizinho.second;

        if(dist[node] + peso < dist[V]){
            dist[V] = dist[node] + peso;
            pq.push({dist[V],V});
            parent[V] = node;
        }

    }
}

if(dist[nodes]==1e18) return {};

        int atual = nodes;
        while(atual!=0){
            caminho.push_back(atual);
            atual = parent[atual];
        }
    reverse(caminho.begin(),caminho.end());
    return caminho;
}

int main(){

cin >> nodes >> edges;

vector<vector<pair<int,int>>>adj(nodes+1);

for(int i=0;i<edges;i++){
    int u ,v , peso;
    cin >> u >> v >> peso;
    adj[u].push_back({v,peso});
    adj[v].push_back({u,peso});
}

vector <int> resultado = Dijkstra(1,nodes,adj);

if(resultado.empty()) cout << -1 << endl;
else {
    for(int i=0;i<resultado.size();i++){
        i == resultado.size()-1 ? cout << resultado[i] : cout << resultado[i] << " ";
    }
    cout << endl;
}

    return 0;
}