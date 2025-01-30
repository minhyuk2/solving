#include <bits/stdc++.h>

using namespace std;

int N;

int branch;
int money;
long long int dp[100000];

//겹치는 경우에 대한 것을 어떻게 제거할 수 있을까?
//순서에 대한 이해가 필요하다 내가 원래 짜던 대로 가면 경우의 수를 다 구하고 거기서 늘어나는데
//동전을 먼저 기준으로 해당동전으로 만들 수 있는 것들을 늘리고 그 다음 동전으로 만들 수 있는 것을 처리하는 형태로 해서 중복을 제거할 수 있게 되는 것이다.
//이미 10으로 만들 수 있는 걸 다 구해놓고 더 하는거랑 10으로 구하는걸 추가로 더 해주는거랑 그 차이네 ㅇㅋ

void dyna(vector<int> &vec){
    fill(begin(dp),end(dp),0);
    dp[0] = 1;
    for(int t = 0;t<branch;t++){
        for(int i = vec[t];i<=money;i++){
                dp[i] = dp[i] + (dp[i-vec[t]]);
        }
    }
    cout << dp[money] << "\n";
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> branch;
        vector<int> vec;
        for(int t= 0; t<branch;t++){
            int number;
            cin >> number;
            vec.push_back(number);
        }
        cin >> money;
        dyna(vec);
    }

}