#include <bits/stdc++.h>
using namespace std;

int main(){

size_t vet_tam; cin >> vet_tam;
vector<int> qtd_A(vet_tam+1,0);
vector<int>A(vet_tam),B(vet_tam),C(vet_tam);

for (int i=0;i<vet_tam;i++){
    cin >> A[i];
    qtd_A[A[i]]++; // contar qtds que x aparece em A
}

for (int i=0;i<vet_tam;i++) cin >>B[i];

for (int i=0;i<vet_tam;i++) cin >>C[i];

long long sum=0;

for(int i=0;i<vet_tam;i++){

int pos = C[i]-1;
int alvo = B[pos];

sum+= qtd_A[alvo];

}

cout << sum << endl;


    return 0;
}