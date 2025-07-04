#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N , K;
vector<ll> vec;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    ll temp;
    for(int i =0 ; i<N; i++){
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(),vec.end());

    cout << vec[K-1]  << "\n";



}