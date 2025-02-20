#include <bits/stdc++.h>

using namespace std;
int N,M;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    vector<int> vec1;
    vector<int> vec2;
    vector<int> answer;
    int number;
    for(int i=0;i<N;i++){
        cin >> number;
        vec1.push_back(number);
    }
    for(int i=0;i<M;i++){
        cin >> number;
        vec2.push_back(number);
    }   

    int index1 =0, index2 =0 ;
    for(int i=0;i<M+N;i++){
        if(index1 == N) answer.push_back(vec2[index2++]);
        else if(index2 == M) answer.push_back(vec1[index1++]);
        else if(vec2[index2] < vec1[index1]) answer.push_back(vec2[index2++]);
        else answer.push_back(vec1[index1++]);
    }

    for(auto it : answer)
        cout << it << " ";
    cout << "\n";
}   