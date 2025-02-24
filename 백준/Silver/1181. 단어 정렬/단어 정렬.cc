#include <bits/stdc++.h>

using namespace std;

int N;
set<string> sets;
vector<string> vec;

bool comp(string &A,string &B){
    if(A.size() < B.size()){
        return true;
    }else if (A.size() == B.size()){
        if(A < B){
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
    for(int i=0;i<N;i++){
        string temp;
        cin >> temp;
        sets.insert(temp);
    }
    for(auto it : sets){
       vec.push_back(it);
    }

    //중복을 제거하고 넣어주면 된다.
    sort(vec.begin(),vec.end(),comp);

    for(auto it : vec){
        cout << it << "\n";
    }
}