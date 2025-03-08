#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

vector<ll> dp;
int N;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(2);
    for(int i=3;i<=N;i++){
        ll number = (dp[i-2]%15746 + dp[i-1]%15746) %15746;
        dp.push_back(number);
    }

    cout << dp[N] << "\n";

}