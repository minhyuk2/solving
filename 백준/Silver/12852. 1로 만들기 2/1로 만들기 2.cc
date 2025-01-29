#include <bits/stdc++.h>

using namespace std;

long long int N;

int dp[1000006];
int pre[1000006]; //경로 복원용 테이블을 의미한다.

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vec;
    cin >> N;
    dp[0] = 0;
    dp[1] = 0;
    pre[0] = 1;
    pre[1] = 1;
    for(int i =2;i <= N;i++){
        //제일 작은 것에 대한 비교를 진행하고 그 값을 넣어주어야 한다.
        if(i%3 == 0 && dp[i-1] > dp[i/3]){
            if(i%2 == 0 && dp[i/3] > dp[i/2]){
                dp[i] = dp[i/2] + 1;
                pre[i] = i/2;
            }else{
                dp[i] = dp[i/3] + 1;
                pre[i] = i/3;
            }
        }else if(i%2 == 0 && dp[i-1] > dp[i/2]){
                dp[i] = dp[i/2] +1;
                pre[i] = i/2;
        }else{
            dp[i] = dp[i-1] +1;
            pre[i] = i-1;
        }
    }
    cout << dp[N] << "\n";
    int t = N;
    cout << N << " ";
    while(t != 1){
        cout << pre[t] << " ";
        t = pre[t];
        if(t ==1)
            break;
    }
    cout << "\n";
}