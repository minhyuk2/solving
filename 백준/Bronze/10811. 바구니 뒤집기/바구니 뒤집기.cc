#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N , M;
    cin >> N >> M;

    vector<int> vec;

    for(int i =0;i<N;i++){
        vec.push_back(i+1);
    }
    int temp1, temp2;
    for(int i =0;i<M;i++){
        cin >> temp1 >> temp2;
        reverse(vec.begin()+temp1-1,vec.begin()+temp2);
    }

    for(auto it : vec){
        cout << it << " ";
    }
    cout << "\n";

}