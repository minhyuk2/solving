#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
vector<ll> vec;
ll N;


ll ucl(ll A, ll B){

    ll C = A  % B;

    if(C==0){
        return B;
    }else{
        return ucl(B,C);
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    ll temp;
    ll last;
    cin >> last;
    for(int i=1;i<N;i++){
        cin >> temp;
        vec.push_back(temp - last);
        last = temp;
    }
    //간격을 계산하는 것이다.
    temp = vec[0];
    for(int i=1;i<vec.size();i++){
        temp = ucl(temp,vec[i]);
    }

    ll answer = 0;
    ll temp2;
    bool t1 = 0;
    for(int i=0;i<vec.size();i++){
        answer += (vec[i]/temp -1);
    }

    cout << answer << "\n";
    

}