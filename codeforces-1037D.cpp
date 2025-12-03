#include <bits/stdc++.h>
using namespace std;
vector <int> ordem_posiçao;

bool compararposiçao(int a,int b){
    return ordem_posiçao[a] < ordem_posiçao[b];
}

vector <int> BFS(int start,int end,vector <vector<int>>& adj){

    vector<bool> vis(end+1,0);
    queue <int> q;
    vector <int> caminho;

    vis[start] = true;
    q.push(start);
    caminho.push_back(start);
    int node;

    while(!q.empty()){
        node = q.front(); 
        q.pop();

        for(auto vizinho : adj[node]){

            if(!vis[vizinho]){
                vis[vizinho] = true;
                caminho.push_back(vizinho);
                q.push(vizinho);
            }

        }

    }

    return caminho;

}

int main(){

    int nodes; cin >> nodes;
    vector<vector<int>> adj(nodes+1);
    vector<int> teste(nodes);
    ordem_posiçao.resize(nodes+1);

    for(int i=0;i<nodes-1;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<nodes;i++){
        cin >> teste[i];
        ordem_posiçao[teste[i]] = i;
    }

    for(int i=1;i<=nodes;i++){
        sort(adj[i].begin(),adj[i].end(),compararposiçao);
    }

 vector<int> resultado = BFS(1,nodes,adj);
 
 if(teste==resultado) cout << "Yes\n" << endl;
 else cout << "No\n" << endl;
    return 0;
}