#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> mape;
vector<vector<bool>> vis;
int L,C;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool eh_valido(int r,int c){
    return r>=0 && r < L && c>=0 && c < C;
}

void DFS(int i,int j,int& cont){

    if(!eh_valido(i,j)) return;
    if(vis[i][j]) return;
    if(mape[i][j]=='#') return;

    if(mape[i][j]=='G') cont++;
    vis[i][j] = true;
    bool perigo = false;

    for(int k=0;k<4;k++){
        int RC = dx[k] + i;
        int LC = dy[k] + j;
        if(eh_valido(RC,LC) && mape[RC][LC]=='T'){
            perigo = true;
            break;
        }
    }

    if(perigo) return;

    for(int k=0;k<4;k++){
        DFS(dx[k]+i,dy[k]+j,cont);
    }
    
}

int main(){

    while(cin >> C >> L)
{
    mape.assign(L,vector<char>(C));
    vis.assign(L,vector<bool>(C,0));
    pair<int,int> inicio;

    for(int i=0;i<L;i++){
        for(int j=0;j<C;j++){
            cin >> mape[i][j];
            if(mape[i][j]=='P'){
                inicio.first = i;
                inicio.second = j;
            }
        }
    }
    int cont = 0;
    DFS(inicio.first,inicio.second,cont);
    
    cout << cont <<  endl;
}

    return 0;
}