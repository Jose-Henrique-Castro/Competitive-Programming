#include <bits/stdc++.h>
using namespace std;

int main() 
{

    float x,y;
    cin >> x >> y;
    float L1 = x*3;
    float L2 = x/3;

    while(x!=0 && y!=0){
        if(x>0){
            if(y<=L1 && y>=L2) cout << "dentro";
            else cout << "fora";
        }
        else { // x<0
            if(y>=L1 && y<=L2) cout << "dentro";
            else cout << "fora";
        }
        cin >> x >> y;
    }

    return 0;
}