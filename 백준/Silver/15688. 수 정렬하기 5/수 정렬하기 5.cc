#include <bits/stdc++.h>

using namespace std;

long long int N;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>N;
    vector<long long int> vec;

    for(int i=0;i<N;i++){
        long long int number;
        cin >> number;
        vec.push_back(number);

    }

    sort(begin(vec),end(vec));

    for(int i=0;i<N;i++){
        cout << vec[i] << "\n";
    }

}