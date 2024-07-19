#include <iostream>
#include <deque>

using namespace std;
int dp[12];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int caseTime;
    cin  >> caseTime;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 7;
    for(int i = 0;i<caseTime;i++){
        //들어온 테스트케이스 개수만큼 반복문을 수행시켜준다.
        //구성하는 숫자들의 순서도 고려해야 한다.
        int input;
        cin >> input;
        for(int j = 5;j<=input;j++){
            dp[j] = dp[j-1] + dp[j-2] +dp[j-3]; 
        }
        cout << dp[input]<<"\n";
    }


}