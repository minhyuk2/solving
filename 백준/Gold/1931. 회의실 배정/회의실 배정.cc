#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int N;

bool comp(pair<ll,ll > A, pair<ll,ll> B){
    if(A.second < B.second){
        return true;
    }else if(A.second == B.second){
        if(A.second-A.first == 0){
            return false;
        }else if(B.second-B.first == 0){
            return true;
        }

        if((A.second - A.first) < (B.second-B.first)){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

vector<pair<ll,ll>> vec;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i =0;i<N;i++){
        pair<ll,ll> newPair;
        cin >> newPair.first >> newPair.second;
        vec.push_back(newPair);
    }

    sort(vec.begin(),vec.end(),comp);
    ll answer=0;
    ll end = -1;
    for(int i=0;i<N;i++){
        if(end <= vec[i].first){
            // cout << vec[i].first << " " << vec[i].second << "\n";
            end = vec[i].second;
            answer ++;
        }
    }


    cout << answer << "\n";
}