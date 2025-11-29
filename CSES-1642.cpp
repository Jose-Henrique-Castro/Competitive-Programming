#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int>> arr;
vector <int> resposta;

int sum4(int alvo,int inicio,int array_tam){


for(int i=inicio;i<array_tam-3;i++){ // deixar 3 slots -> j , left , right

    for(int j=i+1;j<array_tam-2;j++){ // deixar 2 slots -> left , right

        int sum = arr[i].first + arr[j].first;
        int dif = alvo - sum;

        int left = j+1; // primeiro numero depois do j
        int right = array_tam-1; // ultimo num do array

    

    while(left<right){
    if(arr[left].first+arr[right].first == dif){
       cout << arr[i].second << " "
       << arr[j].second << " "
       << arr[left].second << " "
       << arr[right].second << endl;
        return 0;
    }
    else if(arr[left].first+arr[right].first<dif) {
        left++;
    }
    else right--;
}
    }
}
 return -1;
}

int main() 
{

    int qtd_num , soma; cin >> qtd_num >> soma;
    arr.resize(qtd_num);

    for(int i=0;i<qtd_num;i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    sort(arr.begin(),arr.end()); // 1 2 2 3 3 3 5 8

    int resultado = sum4(soma,0,qtd_num);

    if(resultado==-1) cout << "IMPOSSIBLE\n";

     return 0;
}