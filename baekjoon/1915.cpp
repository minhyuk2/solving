#include <bits/stdc++.h>

using namespace std;

int N,M;

int dp[1005][1005];
// int arr[1001][1001];
string arr[1005];

void checkRect(){
    //어떻게 하면 가장 큰 정사각형을 만들 수 있을까
    //정사각형의 정의를 생각하면 가로 길이와 세로의 길이가 같다는 것을 이용하면 되는 것 같은데
    for(int i =0;i<N;i++){
        for(int t=0;t<M;t++){
            if(i==0 && t == 0){
                if(arr[i][t] == '1'){
                    dp[i][t] = 1; 
                }
            }else if(i == 0){
                if(arr[i][t] == '1'){
                    dp[i][t] = 1;
                } 
            }else if(t ==0){
                if(arr[i][t] == '1'){
                    dp[i][t] = 1;
                }              
            }else{
                if(arr[i][t] == '1'){
                    dp[i][t] = min(dp[i][t-1],dp[i-1][t-1]);
                    dp[i][t] = min(dp[i][t],dp[i-1][t]);
                    dp[i][t] += 1;
                } 
            }
        }
    }
    
    int answer = 0;
    for(int i =0;i<N;i++){
        for(int t=0;t<M;t++){
            // cout << dp[i][t] << " ";
            answer = max(answer,dp[i][t]);
        }
        // cout << "\n";
    }
    long long int realAnswer = answer*answer;
    cout <<  realAnswer << "\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i =0;i<N;i++){
        cin >> arr[i];
    }
    checkRect();

}