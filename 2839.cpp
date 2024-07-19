#include <iostream>


//얘도 다시 풀어볼 것
using namespace std;
int dp[5001]; //전역변수로 초기화하기 때문에 0으로 전부 초기화된다.

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int input;
    int count= 0;
    cin >> input;
    dp[3] = dp[5] = 1;
    //전역변수에 넣으면 다 0이니까 0일때는 -1이 출력되게끔 마지막에 설정해주면 되는 것이고
    //그 전까지의 값은 다 알기때문에 6부터 도는 것이다.
    for(int i =6;i<=input;i++){
        if(dp[i-3]){
            //0이 아니고 값이 존재한다면
            //얘부터 판단하는 이유는 3으로 초기화하고 뒤에서 5로 초기화를 해줄 수도 있기 때문이다.
            dp[i] = dp[i-3]+1;
        }
        if(dp[i-5])
            dp[i] = dp[i-5]+1;

    }
    if(dp[input]==0){
        cout << -1 << "\n";
    }else{
        cout << dp[input] << "\n";
    }
}