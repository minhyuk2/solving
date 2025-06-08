#include <bits/stdc++.h>

using namespace std;

int arr[1010][3];
int dp[1010][3];
int N;
vector<vector<pair<int,int>>> vec;
int answer = 10000000;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i =1; i<=N;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        // vector<pair<int,int>> temp;
        // temp.push_back({0,0});
        // temp.push_back({0,0});
        // temp.push_back({0,0});
        // vec.push_back(temp);
    }

    // vector<pair<int,int>> temp;
    // temp.push_back({0,0});
    // temp.push_back({0,0});
    // temp.push_back({0,0});
    // vec.push_back(temp);

    

    //이게 냅색이던가?
    //무슨 색을 골랐는지 알고 있어야 하나?
    // vec[1][0].first = arr[1][0];
    // vec[1][0].second = 0;
    // vec[1][1].first = arr[1][1];
    // vec[1][1].second = 1;
    // vec[1][2].first = arr[1][2];
    // vec[1][2].second = 2;

    // dp[1][0] = arr[1][0];
    // dp[1][1] = arr[1][1];
    // dp[1][2] = arr[1][2];

    //빨간 집 선택
    dp[1][0] = arr[1][0];
    dp[1][1] = 10000000;
    dp[1][2] = 10000000;

    for(int i =2; i<=N;i++){
        //이렇게 해서 DP가 제일 작은 거 선택하면 되는데 이제 첫번째와 마지막이 달라야 한다는 규칙이 어렵네
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + arr[i][2];
    }

    answer = min(dp[N][1],dp[N][2]);

    //초록집 선택
    dp[1][1] = arr[1][1];
    dp[1][0] = 10000000;
    dp[1][2] = 10000000;

    for(int i =2; i<=N;i++){
        //이렇게 해서 DP가 제일 작은 거 선택하면 되는데 이제 첫번째와 마지막이 달라야 한다는 규칙이 어렵네
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + arr[i][2];
    }

    answer = min(answer,dp[N][2]);
    answer = min(answer,dp[N][0]);
   

    //파란 집 선택
    dp[1][2] = arr[1][2];
    dp[1][0] = 10000000;
    dp[1][1] = 10000000;

    for(int i =2; i<=N;i++){
        //이렇게 해서 DP가 제일 작은 거 선택하면 되는데 이제 첫번째와 마지막이 달라야 한다는 규칙이 어렵네
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + arr[i][2];
    }

    answer = min(answer,dp[N][1]);
    answer = min(answer,dp[N][0]);


    
    cout << answer << "\n";


}