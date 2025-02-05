#include <bits/stdc++.h>

using namespace std;

int N;
int dp[2][100005];
int arr[2][100005];
int T;

void getDp(){
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];

    dp[0][1] = dp[1][0] + arr[0][1];
    dp[1][1] = dp[0][0] + arr[1][1];

    for(int i =2;i<T;i++){
        for(int p=0;p<2;p++){
            if(p ==0 ){
                dp[p][i] = max(dp[1][i-2],dp[1][i-1]) + arr[p][i];
            }else{
                dp[p][i] = max(dp[0][i-2],dp[0][i-1]) + arr[p][i];
            }
        }
    }
    // for(int i =0;i<T;i++){
    //     for(int p=0;p<2;p++){
    //         cout << dp[p][i] << " ";
    //     }
    //     cout <<"\n";
    // }



    cout << max(dp[0][T-1],dp[1][T-1]) << "\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> T;
        for(int t=0;t<2;t++){
            fill(dp[t],end(dp[t]),0);
            fill(arr[t],end(arr[t]),0);
        }
        for(int t=0;t<2;t++){
            for(int p=0;p<T;p++){
                cin >> arr[t][p];
            }
        }
        getDp();

    }
    
    
}