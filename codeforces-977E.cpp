#include  <bits/stdc++.h> // no minimo 3 arestas / 3 componentes 
using namespace std; // o ultimo no DFS tem que voltar pro primeiro 

vector <vector<int>> casa;
vector <bool> vis;
vector <int> componente_atual;
void DFS(int u){
  
vis[u] = true;
componente_atual.push_back(u);// pega todos que estão conectados
  
    for(auto x : casa[u]){ 
      if(!vis[x]){
        DFS(x);
      }
    }

}

int main(){

int nodes , coneccoes; cin >> nodes >>  coneccoes;
casa.resize(nodes+1);
vis.resize(nodes+1);

int cont_ciclos=0;

for (int i=0;i<coneccoes;i++){
  int x,y; cin >> x >> y;
  casa[x].push_back(y);
  casa[y].push_back(x);
}

for(int i=1;i<=nodes;i++){

  if(!vis[i]){
componente_atual.clear();
DFS(i);
bool ciclo=true;

for(auto x:componente_atual){// veja a conecção de todos conecatdos , tem que ter 2
  if(casa[x].size()!=2){
    ciclo=false;
    break;
  }
}

if(ciclo){
  cont_ciclos++;
}
  }
}
cout << cont_ciclos << endl;
  return 0;
}