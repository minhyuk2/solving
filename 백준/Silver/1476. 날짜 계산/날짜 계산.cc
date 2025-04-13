#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

ll maxN = 100000000;

int X,Y,Z;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> X >> Y >> Z;
    for(int i=1;i<=maxN;i++){
        int numX = i%15;
        if(numX == 0){
            numX = 15;
        }
        int numY = i%28;
        if(numY == 0){
            numY = 28;
        }
        int numZ = i%19;
        if(numZ == 0){
            numZ = 19;
        }
        if(numX == X && numY == Y && numZ == Z){
            cout << i << "\n";
            return 0 ;
        }
    }
}