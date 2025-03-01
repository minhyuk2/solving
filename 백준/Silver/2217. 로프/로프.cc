#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int N;
vector<int> vec;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //모든 로프의 사용 필요가 없이 몇 개를 골라서 최대한 크기를 넓혀야하는데 하나를 고르면 줄 수 있는 하중의 크기도 줄어든다.
    //이를 전부 고려해서 구해야한다.
    cin >> N;

    int number;
    for(int i=0;i<N;i++){
        cin >> number;
        vec.push_back(number);
    }

    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());

    ll answer= 0;
    ll temp   =0;
    for(int i =0; i<vec.size();i++){
        if(answer < vec[i] * (i+1)){
            answer = vec[i]*(i+1);
        }
    }

    cout << answer << "\n";
}
