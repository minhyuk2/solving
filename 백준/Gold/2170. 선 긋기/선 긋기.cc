#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
ll N;
vector<pair<ll,ll>> vec;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    //먼저 정렬해놓고 풀 수 있는 문제인 것이다.
    for(ll i=0;i<N;i++){
        pair<ll,ll> newPair;
        cin >> newPair.first >> newPair.second;
        vec.push_back(newPair);
    }

    sort(vec.begin(),vec.end());
    //정렬하게 되면 이미 시작 지점이 더 큰 애들 순서로 정렬되기에 길이를 구하는게 쉬워짐
    //그리디는 보통 정렬을 잘 쓰는게 범위를 줄여서 좋은 듯 그리디 연습 필요
    ll len = 0;
    ll st = vec[0].first;
    ll en = vec[0].second;
    for(ll i =1;i<N;i++){
        if(vec[i].first > en){
            len += (en-st);
            // cout << len << "\n";
            st = vec[i].first;
            en = vec[i].second;
        }else{
            if(en < vec[i].second){
                en = vec[i].second;
            }
        }
    }
    
    len += (en-st);

    cout << len << "\n";
}