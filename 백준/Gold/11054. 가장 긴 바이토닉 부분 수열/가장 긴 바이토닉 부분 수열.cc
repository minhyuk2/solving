#include <bits/stdc++.h>

using namespace std;

int N;
//앞의 숫자는 작은 거의 숫자.
//뒤의  숫자는 큰 것의 숫자.
int dp[1050];
int dp2[1050];
int arr[1050];
bool checking[1050];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    dp[0] = 1;
    dp2[0] = 1;

    for(int i=1;i<N;i++){
        // int tempIndex =0;
        int temp =0;
        // int temp2 =0;
        // int maxTemp = 0;
        // int maxTemp2 = 0;
        for(int t=i-1;t>=0;t--){
            if(arr[t] < arr[i]){
                //증가하는 값에 대한 설정
                if( dp[t] > temp){
                    temp = dp[t];
                }   
            }
        }
        //4개의 값을 비교하는 if문??
        dp[i] = temp + 1;
    }

    for(int i=N-1;i>=0;i--){
        // int tempIndex =0;
        int temp =0;
        // int temp2 =0;
        // int maxTemp = 0;
        // int maxTemp2 = 0;
        for(int t=i+1;t<=N-1;t++){
            if(arr[t] < arr[i]){
                //증가하는 값에 대한 설정
                if( dp2[t] > temp){
                    temp = dp2[t];
                }   
            }
        }
        //4개의 값을 비교하는 if문??
        dp2[i] = temp + 1;
    }
    int answer =0;
    for(int i=0;i<N;i++){
        if(dp[i] + dp2[i] > answer){
            answer = dp[i] + dp2[i];
        }
    }

    // for(auto it : dp){
    //     cout << it << " ";
    // }
    // cout << "\n";

    // for(auto it : dp2){
    //     cout << it << " ";
    // }
    // cout << "\n";
    cout << answer - 1 << "\n";
}