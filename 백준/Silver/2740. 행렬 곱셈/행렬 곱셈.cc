#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> vec;
    vector<vector<int>> vec2;
    vector<vector<int>> answer;

    int N, M;
    int K;

    cin >> N >> M;
    int number;
    
    for(int i=0;i<N;i++){
        vector<int> vecs;
        for(int t= 0; t<M;t++){
            cin >> number;
            vecs.push_back(number);
        }
        vec.push_back(vecs);
    }

    cin >> M >> K;    
    for(int i=0;i<M;i++){
        vector<int> vecs;
        for(int t= 0; t<K;t++){
            cin >> number;
            vecs.push_back(number);
        }
        vec2.push_back(vecs);
    }

    //이제 행렬 곱셈
    for(int i=0; i<N;i++){
        vector<int> realVec(K,0);
        for(int t = 0;t< M;t++){
            for(int p=0;p<K;p++){
                int nums = vec[i][t] * vec2[t][p];
                realVec[p] += nums;
            }
        }
        answer.push_back(realVec);
    }

    for(auto it : answer){
        for(auto tt : it){
            cout << tt << " " ;
        }
        cout << "\n";
    }
}