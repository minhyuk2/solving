#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> vec;
vector<int> uses;
int dp[105];
int answer ;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //겹치지 않으려면 대세가 유지되는 동안에 대세를 꺾게끔 만들어지면 안됨 그리고 유지되고 있는 애보다 더 앞에 있으면 안됨
    //일단 정렬? 
    //어떤 것을 없앨지 고려를 잘해야겠다. 어떤 것을 지워야할까?
    //일단은 어떠한 기준으로 없앨지를 고려하는게 제일 먼저네
    //이게 어떻게 DP로 풀릴 수 있을까?
    //DP? 계속해서 공부를 해야겠다 이제..제대로 안하면 안될 듯 너무 알고리즘 근육이 또 빠졌네
    //가장 긴 증가하는 부분 수열로 이 문제를 판단하는게 중요하네

    int N;
    cin >> N;
    int temp1, temp2;

    for(int i =0 ; i<N;i++){
        cin >> temp1 >> temp2;
        vec.push_back({temp1,temp2});
    }

    sort(vec.begin(),vec.end());

    for(int i =0 ; i<N;i++){
        uses.push_back(vec[i].second);
    }

    //이제 여기서 제일 큰 증가하는 부분수열 구하기
    //증가하는 부분 수열이니까 계속 큰 게 나와야하는데


    for(int i =0 ; i< N; i++){
        dp[i] = 1;
        for(int p = 0;p<i;p++){
            if(uses[p] < uses[i]){
                dp[i] = max(dp[i],dp[p]+1);
            }
        }
    }

    answer = *max_element(begin(dp),end(dp));

    cout << N-answer << "\n";
    //근데 이제 관계없는 애들에 대한 처리를 따로 해줘야한다.

}