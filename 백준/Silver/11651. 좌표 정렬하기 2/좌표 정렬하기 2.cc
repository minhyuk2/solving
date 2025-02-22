#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> vec;

bool comp(pair<int,int> A, pair<int,int> B){
    if(A.second < B.second){
        return true;
    }else if(A.second == B.second){
        if(A.first < B.first){
            return true;
        }else if(A.first==B.first){
            return false;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
int N;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i =0; i<N;i++){
        pair<int,int> newPair;
        cin >> newPair.first >> newPair.second;
        vec.push_back(newPair);
    } 
    sort(vec.begin(),vec.end(),comp);
    for(auto it : vec){
        cout << it.first << " " << it.second <<"\n";
    }
}