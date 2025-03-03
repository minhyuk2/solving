#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

ll T;
ll N;
ll answer;
vector<ll> vec;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //역으로 생각하는 것도 할 줄 알아야한다.
    //항상 관점을 반대로 생각할 수도 있어야 함
    cin >> T;
    int number;
    for(int i=0;i<T;i++){
        cin >> N;
        vec.clear();
        for(int t=0;t<N;t++){
            cin >> number;
            vec.push_back(number);
        }
        int max_val = vec[N-1];
        answer = 0;
        for(int t=N-2;t>=0;t--){
            if(max_val  < vec[t]) max_val = vec[t];
            answer += (max_val - vec[t]);
        }
        cout << answer << "\n";
    }

    
}