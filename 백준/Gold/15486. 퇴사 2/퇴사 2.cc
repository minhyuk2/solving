#include <bits/stdc++.h>

using namespace std;


    int N;
    int dp[1500006];
int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<pair<int,int>> vec;

    for(int i =0; i<N;i++){
        pair<int,int> newPair;
        cin >> newPair.first >> newPair.second;
        vec.push_back(newPair);
    }
    dp[0] = 0;
    int maxss = 0;
    for(int i =0;i<N;i++){
        maxss = max(dp[i],maxss);
        pair<int,int> newPair= vec[i];
        if(i+newPair.first <= N) dp[newPair.first+i] = max(dp[newPair.first+i],maxss + newPair.second);
        //쭉 가다가 그냥 비어있는 것뿐만 아니라 그 전의 것이 더 좋으면 10인 걸 포기하고 max를 더해야지

    }


    cout << *max_element(dp,dp+(N+1)) << "\n";

}