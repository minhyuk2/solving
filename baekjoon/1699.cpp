#include <bits/stdc++.h>

using namespace std;

int N;

int dp[100005];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 1;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 2;
    dp[9] = 1;

    //이걸 어떻게 줄여나가야 하는걸까?
    //한 개부터 채워가기 시작하는 것이다.

    //제곱근의 합쳐럼 구해지면 그거에 대해서는 다르게 처리를 해주어야 하는 것이다.
    int index = 2;
    for(int i = 5;i <=N;i++){
        for(int t=index+1;t>=1;t--){
            int vals = pow(t,2);
            if(i<vals){
                continue;
            }else{
                if(i-vals == 0){
                    index++;
                    if(dp[i] == 0){
                        dp[i] = 1;
                    }else{
                         dp[i] = min(dp[i],1);
                    }
                }else if(i%vals == 0){
                    if(dp[i] == 0){
                        dp[i] = i/vals;
                    }else{
                         dp[i] = min(dp[i],i/vals);
                    }
                }
                else{
                    //i가 그냥 vals보다 큰 경우
                    if(dp[i] == 0){
                        dp[i] = dp[i-vals] + 1;
                    }else{
                        dp[i] = min(dp[i],dp[i-vals] + 1);

                    }
                }
            }
        }
    }

    cout << dp[N] << "\n";

}