#include <bits/stdc++.h>

using namespace std;

int N;
int money[10010];
long long int dp[10010];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //카드의 개수를 N개로 고정시키고 금액을 최대로 맞추는 문제
    //냅색 처럼 풀면 되나?를 고민해봤다.
    cin >> N;

    for(int i=1;i<=N;i++){
        cin >> money[i];
    }
    dp[0] = 0;
    dp[1] = money[1];
    
    for(int i=2;i<=N;i++){
        long long int maxEl = 0;
        for(int t = i;t>0;t--){
            maxEl = max(dp[i-t]+money[t],maxEl);
        }
        dp[i] = maxEl;
    }

    cout << dp[N] << "\n";
}