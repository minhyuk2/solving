#include <bits/stdc++.h>

using namespace std;


int N;
int M;
long long int dp[1050][1050];
int arr[1050][1050];

void arrCor(int x1,int y1, int x2, int y2){
    if(x1 == x2 && x1==1){
        cout << dp[x2][y2] - dp[x1][y1-1] <<"\n";
    }else if(y1 == y2 && y2== 1){ 
        cout << dp[x2][y2] - dp[x1-1][y1] << "\n";
    }else{
        if(x1==x2){
            cout << dp[x2][y2] - dp[x2-1][y2] - dp[x1][y1-1]  + dp[x2-1][y1-1] << "\n";
        }else if(y1 == y2){
            cout << dp[x2][y2] - dp[x2][y2-1] - dp[x1-1][y1] +  dp[x1-1][y2-1]  << "\n";
        }else{
            cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] <<"\n";
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N >> M;

    for(int i =1;i<=N;i++){
        for(int p =1; p<=N;p++){
            cin >> arr[i][p];
        }
    }

    for(int i =1;i<=N;i++){
        for(int p =1; p<=N;p++){
            if(i==1){
                //맨 첫번쨰 줄
                dp[i][p] = dp[i][p-1] + arr[i][p];
            }else if(p ==1){
                dp[i][p] = dp[i-1][p] + arr[i][p];
            }else{
                dp[i][p] = dp[i-1][p] + dp[i][p-1] - dp[i-1][p-1] + arr[i][p];
            }
        }
    }

    int x1,y1,x2,y2;
    for(int i=0;i<M;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        arrCor(x1,y1,x2,y2);
    }
}