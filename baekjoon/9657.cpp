#include <bits/stdc++.h>

using namespace std;

int N;

int dp[1050];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;


    //이 패턴으로 반복된다.
    //그러면
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    dp[4] = 1;
    
    dp[5] = 1; 
    //3 1 1 -> 얘는 이렇게 둘거임
    //4 1
    //1 4

    //1 1 4
    //3 3 -> 지가 지는데 할 일이 없음

    //4 1 1 -> 이렇게 했을거임 -> 상근이
    dp[6] = 1;
    //4 3
    
    dp[7] = 2;
    //1 4 1 1 -> 얘가 이렇게 햇을거임 -> CY가 이김


    //4 4
    //4 3 1
    //3 4 1
    //1 4 3
    //1 4 3
    //4 4
    //1 1 1 4 1

    int numbers = 0;
    for(int i =8 ; i<=N;i++){
        numbers = max(dp[i-1],dp[i-3]);
        numbers = max(numbers,dp[i-4]);
        if(numbers == 2){
            dp[i] = 1;
        }else{
            dp[i] = 2;
        }
    }
    
    
    if(dp[N] == 1){
        cout << "SK\n";
    }else{
        cout << "CY\n";
    }

    //5일때 3일 때 
    
    //1이면 SK 2면 CY
    //6개의a 패턴이 가능
    // if(N%6 == 1 || N%6 == 3 || N%6 == 4){
    //     cout << "SK\n";
    // }else{
    //     cout << "CY\n";
    // }
}