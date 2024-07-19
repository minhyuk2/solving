#include <iostream>
#include <algorithm>
using namespace std;

int dp[302];//계단의 dp를 사용하기 위함이다.
int result[302];

//이 문제는 한 번 더 풀어보면 확실히 좋을 것 같다.


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int input; 
    cin >> input;
    dp[0] = 0; //1부터하는 식으로 해도 될 것 같긴한데 직관적으로 일단 짜보자

    for(int i = 1; i <= input; i++){
        //어떤 식으로 짜는 코드가 좋은 형태인지 다른 사람 코드 보면서 조금 확인
        cin >> dp[i];
    }//계단 값들을 넣어준다.
    result[0]= 0 ;
    result[1] = dp[1] ;
    result[2] = dp[2] + dp[1] ;
    result[3] = max(dp[1],dp[2]) + dp[3] ;
    
    for(int i = 4; i <=input; i ++){
        result[i] = dp[i] + max(result[i-2],(result[i-3]+dp[i-1]));
    }

    cout << result[input] << "\n";
    
}