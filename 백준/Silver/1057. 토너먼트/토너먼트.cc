#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int answer = -1;



    int N, X, Y;
    cin >> N >> X >> Y;
    int temp;
    if(N % 2==0){
        temp = ceil(log2(N));
    }else{
        temp = ceil(log2(N))+ 1;
    }



    for(int i=1;i<=temp;i++){
        if(X%2==0 && Y%2 == 1 && (X-Y == 1)){
            answer = i;
            break;
        }else if(Y%2==0 && X%2 == 1 && (Y-X==1)){
            answer = i;
            break;
        }

        if(X%2==0){
            X /= 2;
        }else{
            X = X/2 + 1;
        }
        if(Y%2==0){
            Y /= 2;
        }else{
            Y = Y/2 + 1;
        }

    }

    cout << answer << "\n";


}