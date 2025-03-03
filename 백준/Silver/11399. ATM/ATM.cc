#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

ll N;
vector<ll> vec;
vector<ll> ans;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    ll number;
    for(int i =0 ; i<N;i++){
        cin >> number;
        vec.push_back(number);
    }
    sort(vec.begin(),vec.end());
    ll answer = 0;
    for(int i =0;i<N;i++){
        answer += vec[i];
        ans.push_back(answer);
    }
    answer = 0;
    for(auto it: ans){
        answer += it;
    }

    cout << answer << "\n";
}