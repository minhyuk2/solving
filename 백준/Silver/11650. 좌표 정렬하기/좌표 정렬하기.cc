#include <bits/stdc++.h>

using namespace std;

int N;

bool comp(pair<int,int> A,pair<int,int> B){
    if(A.first < B.first){
        return true;
    }else if(A.first == B.first){
        if(A.second < B.second){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<pair<int,int>> vec;
    for(int i=0;i<N;i++){
        pair<int,int> newInt;
        cin >> newInt.first >> newInt.second;
        vec.push_back(newInt);
    }
    sort(vec.begin(),vec.end(),comp);

    for(auto it : vec){
        cout << it.first << " " << it.second << "\n";
    }

}