#include <bits/stdc++.h>
using namespace std;

int main() 
{

    int x,i; cin >> x;
    int raiz = sqrt(x);
    cout << "1" << x << endl;
    for( i=2;i<raiz;i++){
        if(x%i==0) cout << x;
    }
    if(i*i==raiz) cout << i;

    return 0;
}