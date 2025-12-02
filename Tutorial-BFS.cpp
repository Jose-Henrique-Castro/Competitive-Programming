#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> casa;
vector <bool> vis;
vector <int> parent;


vector <int> BFS(int start,int end){

queue <int> q;
vector <int> caminho;
   
vis[start] = true;
q.push(start);

while(!q.empty()){
    int atual = q.front();
    q.pop();

    if(atual==end) break;

    for(auto vizinho : casa[atual]){
        if(!vis[vizinho]){
            vis[vizinho]=true;
            parent[vizinho] = atual;
            q.push(vizinho);
        }
    }

}

if(!vis[end]){
    return {};
}

int curr = end;

while(curr != -1 ){
    caminho.push_back(curr); // caminho de tras pra frente
    curr = parent[curr]; // olhe o parent dele como proximo 
} 

reverse(caminho.begin(),caminho.end());

return caminho;


}

int main(){

    int testes; cin >> testes;

    while(testes--){
        int nodes , edges; cin >> nodes >> edges;
    casa.assign(nodes+1,vector<int>());
    vis.assign(nodes+1,0);
    parent.assign(nodes+1,-1);
    


    for(int i=0;i<edges;i++){
        int u,v; cin >> u >> v;
        casa[u].push_back(v); 
        casa[v].push_back(u);
        // conectando nós / formando arestas
    }

    int start; cin >> start;
    vector <int> shortest_path = BFS(start,nodes);

    if(shortest_path.empty()) cout << "caminho não encontrado!!";
    else {
        for(auto node : shortest_path){
            cout << node << " ";
        }
        cout << endl;
    }

    }
    

    return 0;
}