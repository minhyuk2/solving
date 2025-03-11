#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

ll M, N;

vector<ll> vec1;



ll answer = 0;


bool solve(ll x){
    if(x==0){return true;}
    ll cnt =0;
    for(ll i = 0; i < M;i++){
        cnt += vec1[i]/x;
    }

    return cnt>=N;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    
    ll number;
    for(int i=0;i<M;i++){
        cin >> number;
        vec1.push_back(number);
    }

    //일단 이분탐색 문제니까 sort를 해놓고 생각을 하자
    sort(vec1.begin(),vec1.end());
    
    ll st = 0;
    ll en = *max_element(vec1.begin(),vec1.end());

    while(st<en){
        ll mid = (st+en+1)/2;

        if(solve(mid)){
            st = mid;
        }else{
            en = mid -1;
        }


    }

    cout << st << "\n";
}