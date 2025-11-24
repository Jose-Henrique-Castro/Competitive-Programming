#include <bits/stdc++.h>
using namespace std;

int main() 
{

int x; cin >> x;
int q = x;
int inv=0;

while(q){

    inv = inv*10+q%10;
    q/=10;
}

if(x==inv) cout << "palindromo";
else cout << "fora";

    return 0;
}