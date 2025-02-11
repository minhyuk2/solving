#include <bits/stdc++.h>

using namespace std;

long long int dp[10010];

int arr[105];
int N,K;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;


    for(int i =0; i<N;i++){
        cin >> arr[i] ;
    }
    
    dp[0] = 0;
    for(int i=0;i<N;i++){
        if(arr[i]>10000){
            continue;
        }
        dp[arr[i]] = dp[arr[i]] + 1;
        for(int t=arr[i]+1;t<=K;t++){
            dp[t] = dp[t-arr[i]] + dp[t];
        }
    }

    cout << dp[K] << "\n";

}