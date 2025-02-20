#include <bits/stdc++.h>

using namespace std;

int T;
int W;

int arr[1010];
int dp[1010][32][3];




int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T >> W;
    for(int i=1;i<=T;i++){
        cin >> arr[i];
    }

    for(int i =1 ;i <=T;i++){
        //한 번도 움직이는 않는 경우에 대해서
        dp[i][0][1] = dp[i-1][0][1] + (arr[i] == 1 ? 1: 0);

        for(int j = 1; j<=W;j++){
            if(j>i) break;
            if(arr[i] == 1){
                //안 움직여야지
                dp[i][j][1] = max(dp[i-1][j-1][2],dp[i-1][j][1]) +1;
                dp[i][j][2] = max(dp[i-1][j][2],dp[i-1][j-1][1]);
            }else{
                dp[i][j][1] = max(dp[i-1][j-1][2],dp[i-1][j][1]);
                dp[i][j][2] = max(dp[i-1][j][2],dp[i-1][j-1][1]) + 1;
            }
        }
    }
    int answer = 0;
    for(int i =0;i<=W;i++){
        if(answer < dp[T][i][1]){
            answer = dp[T][i][1];
        }
    }

    for(int i =0;i<=W;i++){
        if(answer < dp[T][i][2]){
            answer = dp[T][i][2];
        }
    }

    
    cout << answer << "\n";

}