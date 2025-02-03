#include <bits/stdc++.h>

using namespace std;

int N, M;
int S,E;
int arr[2005];
int dp[2005][2005];

void fillPel(){
    //같은 거 두 개는 그냥 채워주기
    for(int i=1;i<=N;i++){
        for(int t=1;t<=N;t++){
            if(i==t)
                dp[i][t] = 1;
        }
    }

    for(int i=1;i<=N-1;i++){
        if(arr[i] == arr[i+1]){
            dp[i][i+1]=1;
        }
    }

    for(int t=2;t<=N-1;t++){
        for(int i=1;i<=N-t;i++){
            if(arr[i] == arr[i+t]){
                if(dp[i+1][i+t-1]==1)
                    dp[i][i+t]=1;
            }
        }
    }

    // for(int i=1;i<=N;i++){
    //     for(int t=1;t<=N;t++){
    //         cout << dp[i][t] << " ";
    //     }
    //     cout << "\n";
    // }


}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    cin >> M;
    fillPel();
    for(int i=0;i<M;i++){
        cin >> S >> E;
        cout << dp[S][E] << "\n";
    }


}