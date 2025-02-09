#include <bits/stdc++.h>

using namespace std;


int N,K;
int dp[100010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //냅색 문제를 어떻게 풀었었는지를 떠올리는게 좀 필요하겠네..
    //이렇게 동전의 단위로 배열을 돌리는 문제가 냅색 문제인 것이다.
    //동전을 최소로 쓸 수 있는 경우
    set<int> sets;
    cin >> N >> K;

    for(int i =0 ; i< N;i++){
        int number;
        cin >> number;
        sets.insert(number);
    }

    fill(begin(dp),end(dp),10000000);
    dp[0] = 0;
    // dp[1] = 0;
    for(int num : sets){
        if(num > K){
            continue;
        }
        dp[num] = 1;
        for(int i=num+1 ; i<=K;i++){
            dp[i] = min(dp[i-num]+1,dp[i]);
        }
    }

    if(dp[K] == 10000000){
        cout << -1 <<"\n";
    }else{
        cout << dp[K] << "\n";
    }
}