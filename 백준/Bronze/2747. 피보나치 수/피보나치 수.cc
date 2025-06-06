#include <bits/stdc++.h>

using namespace std;

int N;
long long int dp[10001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3;i<=N;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout << dp[N] << "\n";

}