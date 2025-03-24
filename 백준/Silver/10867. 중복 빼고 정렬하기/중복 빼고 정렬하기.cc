#include <bits/stdc++.h>

using namespace std;

int N;
set<int> sets;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int number;
    for(int i=0;i<N;i++){
        cin >> number;
        sets.insert(number);
    }
    for(auto it : sets){
        cout << it << " ";
    }
    cout << "\n";
}