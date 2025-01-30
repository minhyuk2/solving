#include <bits/stdc++.h>

using namespace std;


int N;

int dp[1001];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    //1인 경우 SK, 2인 경우 CY
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    for(int i=4;i<=N;i++){
        dp[i] = min(dp[i-1],dp[i-3]);
    }

    if(N%2==0){
        cout << "CY\n";
    }else{
        cout << "SK\n";
    }

}