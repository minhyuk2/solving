#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> vec;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int num;
    for(int i =0; i<N;i++){
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(),vec.end());

    for(auto it:vec){
        cout << it << "\n";
    }
    
}