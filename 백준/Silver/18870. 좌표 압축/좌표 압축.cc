#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;
vector<int> vec;
set<int> sets;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i=0;i<N;i++){
        int number;
        cin >> number;
        arr.push_back(number);
        sets.insert(number);
    }


    for(auto it :sets){
        vec.push_back(it);
        // cout << it << "\n";
    }
    
    for(int i=0;i<N;i++){
        cout << lower_bound(vec.begin(),vec.end(),arr[i]) - vec.begin() << " ";
    }
    cout << "\n";

}