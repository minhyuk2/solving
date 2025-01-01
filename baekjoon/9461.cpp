#include <bits/stdc++.h>

using namespace std;

long long dp[101];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //dp문제이기에 규칙을 제대로 찾는 것이 중요하다.
    //점화식을 찾아서 넣어가는 것을 구하는 것이다.
    int testCase = 0;
    cin >> testCase;
    //4개 전 것을 빼서 구하는건가?
    //숫자가 커질 것 같으면 그냥 long long으로 해야한다.
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    int caseNum;
    for(int t = 6 ; t <= 100; t++){
            dp[t] = dp[t-5] + dp[t-1];
    }
    for(int i = 0 ; i < testCase; i++){
        cin >> caseNum;
        cout << dp[caseNum] << "\n";
    }

}