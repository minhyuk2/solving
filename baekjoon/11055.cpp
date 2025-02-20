#include <bits/stdc++.h>

using namespace std;

int N;

long long int arr[1010];
long long int dp[1010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }
    
    for(int i=0;i<N;i++){
        for(int j =0;j<i;j++){
            if(arr[i] > arr[j]) dp[i] = max(arr[i] + dp[j] , dp[i]);
        }
    }

    cout << *max_element(dp,dp+N) << "\n";
}