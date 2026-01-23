#include <bits/stdc++.h> 
using namespace std;


map<int,int> BFS(int inicio,int dist_max,map<int,vector<int>>& adj){

    map<int,int> dist;
queue <int> pq;
pq.push(inicio);
dist[inicio] = 0;

while(!pq.empty()){

int atual = pq.front();
pq.pop();

if(dist[atual]>=dist_max) continue;

for(auto viz : adj[atual]){
    if(dist.find(viz)==dist.end()){
        dist[viz] = dist[atual]+1;
        pq.push(viz);
    }
}

}
    return dist;
}

int main(){

    int caso =1;
int nodes;

while(cin >> nodes && nodes!=0){

map <int,vector<int>> adj;
set <int> edges;

for(int i=0;i<nodes;i++){
    int u,v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edges.insert(u);
    edges.insert(v); 
}

int inicio , dist_max;
while(cin >> inicio >> dist_max && (inicio!=0 || dist_max!=0)){

map <int,int> visitados = BFS(inicio,dist_max,adj);

int nao_alcansados = 0;

for( auto x : edges){
    if(visitados.find(x) == visitados.end()) nao_alcansados++;
}
printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", 
                    caso++, nao_alcansados, inicio, dist_max);
        }


}

}

