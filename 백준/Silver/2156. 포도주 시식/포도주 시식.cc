#include <bits/stdc++.h>

using namespace std;

int N;
int arr[10005];
int dp[10005];


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;


    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
   
    
    if(N ==2){
        cout << arr[1] + arr[2] << "\n";
        return 0;
    }else if(N==1){
        cout << arr[1] << "\n";
        return 0;
    }


    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    //1부터 넣는 이유는 그래야지 첫번재 경우에 대한 예외처리를 안하고 쉽게 계산할 수 있기 때문이다.
    //이러면 4도 선택불가
    for(int i=3;i<=N;i++){
        dp[i] = max({dp[i-3]+arr[i-1]+arr[i],dp[i-1],dp[i-2]+arr[i]});
    }
    cout << *max_element(begin(dp),dp+N+1) << "\n";
}