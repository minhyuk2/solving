#include <bits/stdc++.h>

using namespace std;

int N;


//2차원 배열을 생각해서 풀이를 해봤어야 한다.
//오르막의 수라는 규칙을 발견했어얗 한다.

//끝이 2인 애도 가능하고, 끝이 1이었던 애도 가능하다는 것을 생각해야한다.

long long int dp[1010][10];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    fill(dp[1],end(dp[1]),1);


    for(int i=2;i<=N;i++){
        for(int t = 0;t<10;t++){
            if(t==0){
                dp[i][t] = 1;
            }
            else{
                dp[i][t] = (dp[i][t-1]%10007 + dp[i-1][t]%10007)%10007 ; 
            }
        }
    }
    long long int answer = 0;
    for(int i=0;i<10;i++){
        answer = (answer%10007+dp[N][i]%10007)%10007;
    }
    cout << answer << "\n";
}