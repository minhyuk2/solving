#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
long long int N,K;


vector<long long int> vec;

bool solve(ll target){
    ll cur = 0;
    for(int i=0;i<K;i++){
        cur += vec[i] / target;
    }
    return cur >= N;
}




int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> N;

    for(int i =0 ;i<K;i++){
        ll number;
        cin >> number;
        vec.push_back(number);
    }
    // sort(vec.begin(),vec.end());
    ll st = 1;
    ll en = INT_MAX;
    while(st < en){
        ll mid = (st+en+1)/2;
        if(solve(mid)) st = mid; //걍 배열의 값이랑 비교하는게 아니라 이렇게 solve함수 같은거 만들어서 비교하면 그게 매개변수 탐색
        else
            en = mid -1;
    }
    cout << st << "\n";
    
}