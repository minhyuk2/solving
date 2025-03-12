#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
ll N, K;
int dp[1050][1050];
ll answer ;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;

    //어떻게 DP로 풀 수 있는걸까?
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=0;i<1004;i++){
        dp[i][0] = 1;
    }

    for(int i =2;i<=N;i++){
        for(int t =1;t<=i;t++){
            dp[i][t] = (dp[i-1][t]%10007 + dp[i-1][t-1]%10007)%10007;
        }
    }


    // cout << dp[N] << "\n";
    // cout << dp[K] <<"\n";
    // cout << dp[N-K] << "\n";
    // answer = ((dp[N]%10007 / dp[K]%10007) / dp[N-K]%10007)%10007;

    cout << dp[N][K] << "\n";
}