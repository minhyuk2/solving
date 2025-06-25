#include <bits/stdc++.h>

using namespace std;

int ucl(int A, int B){

    int C = A % B;

    if(C == 0){
        return B;
    }else{
       return ucl(B,C);
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A1, A2, B1,B2;

    cin >> A1 >> B1 >> A2 >> B2;

    int up,down;
    down = B1 * B2;
    up = A1*B2 + A2*B1;

    int temp = ucl(down, up);

    cout << up/temp <<  " " << down/temp <<"\n";

}