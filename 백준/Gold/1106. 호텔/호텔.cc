#include<bits/stdc++.h>

using namespace std;

int C,N;
vector<pair<int,int>> vec;
int answer = 100000000;
int dp[6005];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> C >> N;

    //그냥 DP 문제인가?

    for(int i =0; i< N;i++){
        pair<int,int> newPair;
        cin >>  newPair.first >> newPair.second;
        vec.push_back(newPair);
    }

    for(int i=0;i<6000;i++){
        dp[i] = 100000000;
    }

    //인원채우는 것을 기준으로 돌리면서 이에 대한 비용을 구하면 될 듯?
    //냅색으로 딱 나눠떨어지게 할 수가 없는 문제네,, 왜냐면 초과하는데 더 작을 수도 있기 때문이지
    //그럼 한 번씩 더 더해질 기회를 줘서 
    dp[0] = 0;
    for(int t=0; t<N; t++){
        for(int i =0; i<=6000; i++){
            if(i-vec[t].second >=0){
                dp[i] = min(dp[i], vec[t].first + dp[i-vec[t].second]);
                
            }
        }
    }
    // for(int i=0;i<=C*2;i++){
    //     cout << dp[i] << "\n";
    // }
    for(int i=C; i<=6000; i++){
        if(dp[i]!=0){
            // cout << answer << "\n";
            answer = min(answer,dp[i]);
        }
    }


    cout << answer << "\n";

}