#include <bits/stdc++.h>

using namespace std;

long long int N;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vec;
    cin >> N;
    for(int i =0;i<N;i++){
        int num;
        cin >> num;
        vec.push_back(num);
    }

    sort(begin(vec),end(vec));

    for(int i = N-1;i>=0;i--){
        cout << vec[i] << "\n";
    }
}