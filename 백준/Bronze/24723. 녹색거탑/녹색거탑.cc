#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int dp[6];
    dp[1] = 2;
    dp[2] = 4;
    
    cout << pow(2,N) << "\n";
}