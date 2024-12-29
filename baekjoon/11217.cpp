#include <bits/stdc++.h>

using namespace std;

int dp[10001];

int main(void){

    int number;
    cin >> number;

    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;

    for(int i = 2;  i< number;i++){
        dp[i+1] = (dp[i] + 2*dp[i-1])%10007;
    }

    cout << dp[number] <<"\n";

}
