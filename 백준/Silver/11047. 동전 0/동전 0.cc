#include <bits/stdc++.h>

using namespace std;
int N;
long long int K;
vector<long long int> vec;
vector<pair<int,long long int>> dp;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //흔한 냅색 문제다.
    cin >> N;
    int number;
    cin >> K;
    for(int i=0;i<N;i++){
        cin >> number;
        vec.push_back(number);
        // dp.push_back({number,1});
    }

    reverse(vec.begin(),vec.end());

    int answer = 0;
    for(int i=0;i<N;i++){
        // cout << vec[i] << "\n";
        if(K%vec[i] ==0){
            answer += K/vec[i];
            break;
        }else{
            if(K < vec[i])
                continue;
            answer += K/vec[i];
            K = K- vec[i]*(K/vec[i]);
        }
    }


    cout << answer << "\n";

}