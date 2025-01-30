#include <bits/stdc++.h>

using namespace std;
int N;

long long int dp[103][10];


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //정답을 10억으로 나눈 것을 출력
    cin >> N;

    //1자리인 경우는 9
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    dp[1][5] = 1;
    dp[1][6] = 1;
    dp[1][7] = 1;
    dp[1][8] = 1;
    dp[1][9] = 1;
    //2자리인 경우는 17
    

    //0과 9 , 1과 2에 대한 개수를 세서 계산하는 식으로 식을 작성해야 한다.
    for(int i=2;i<=N;i++){
        dp[i][0] = dp[i-1][1]%1000000000;
        dp[i][1] = (dp[i-1][0]%1000000000 + dp[i-1][2]%1000000000)%1000000000;
        dp[i][2] = (dp[i-1][1]%1000000000 + dp[i-1][3]%1000000000)%1000000000;
        dp[i][3] = (dp[i-1][2]%1000000000 + dp[i-1][4]%10000000000)%1000000000;
        dp[i][4] = (dp[i-1][3]%1000000000 + dp[i-1][5]%1000000000)%1000000000;
        dp[i][5] = (dp[i-1][4]%1000000000 + dp[i-1][6]%1000000000)%1000000000;
        dp[i][6] = (dp[i-1][5]%1000000000 + dp[i-1][7]%1000000000)%1000000000;
        dp[i][7] = (dp[i-1][6]%1000000000 + dp[i-1][8]%1000000000)%1000000000;
        dp[i][8] =(dp[i-1][7]%1000000000 + dp[i-1][9]%1000000000)%1000000000;
        dp[i][9] = dp[i-1][8]%1000000000;
    }

    //이렇게 늘어나는 것의 개수를 셀 수는 없다. 그렇다면, 대처를 다르게 해야하는 ㄱ것이다.
    long long int total = 0;
    for(int i=0;i<10;i++){
        total = (total%1000000000+dp[N][i]%1000000000)%1000000000;
    }
    cout << total << "\n";
}