#include <bits/stdc++.h>

using namespace std;
using ll = long long int;


ll N,M;
vector<ll> vec;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    ll temp;
    for(int i =0; i<N;i++){
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(),vec.end());


    //이분탐색으로 풀 때는 lower_bound를 쓰면 되는 것이다.

    ll answer = 2000000005;
    ll temperV = 0;
    for(int i =0; i<N;i++){
        temp = vec[i] + M;
        if(lower_bound(vec.begin()+i,vec.end(),vec[i]+M)!=vec.end()){
            temperV = *lower_bound(vec.begin()+i,vec.end(),vec[i]+M) - vec[i];
            answer = min(answer,temperV);
        } 
    }
    cout << answer <<"\n";
}