#include <bits/stdc++.h>

using namespace std;
using ll = long long int;


ll N, M;
vector<int> vec;
int answer;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >>  N >> M;


    int temp;
    for(int i=0;i<N;i++){
        cin >> temp;
        vec.push_back(temp);
    }


    int st =0,en = 0;
    ll sums = 0;
    for(st = 0;st<N;st++){
        if(st != 0){
            sums -= vec[st-1];
        }

        while( en < N && sums < M){
            sums += vec[en];
            en ++;
        }
        
        if(sums == M){
            answer ++;
        }
    }

    cout << answer << "\n";


}