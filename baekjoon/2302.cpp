#include <bits/stdc++.h>

using namespace std;


int N,M;
int arr[45];
int dp[1010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N >> M;
    

    int number;
    for(int i=1;i<=M;i++){
        cin >> number;
        arr[i] = number;
    }

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    for(int i =5;i<=40;i++){
        dp[i] = dp[i] + dp[i-1] + dp[i-2];
    }
    
    long long int answer = 1;
    if(M ==0){
        cout << dp[N] << "\n";
        return 0;
    }
    int counter = 0;
    for(int i=1;i<=M;i++){
        counter = arr[i] - counter - 1;
        // cout << counter << "\n";
        //이러면 dp[1]개짜리 더하고
        // cout << "dp" << dp[counter] << "\n";
        answer *= dp[counter];
        counter = arr[i];
    }
    if(arr[M]!=N){
        // cout << counter << "\n";
        counter = N-counter;
        answer *= dp[counter];
    }

    cout << answer << "\n";
}