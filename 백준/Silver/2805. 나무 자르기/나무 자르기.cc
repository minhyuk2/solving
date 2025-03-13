#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
ll N,M;
vector<ll> vec;

bool solve(ll mid){
    if(mid == 0) return true;
    ll cnt=0;
    for(int i =0;i<vec.size();i++){
        if(vec[i] >= mid){
            cnt += (vec[i] -mid);
        }
    }
    return cnt >= M;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    ll number;
    for(int i=0;i<N;i++){
        cin >> number;
        vec.push_back(number);
    }

    ll st = 0;
    ll en = *max_element(vec.begin(),vec.end());

    while(st < en){
        ll mid = (st+en+1)/2;

        if(solve(mid)){
            st = mid;
        }else{
            en = mid-1;
        }
    }

    cout << st << "\n";

}