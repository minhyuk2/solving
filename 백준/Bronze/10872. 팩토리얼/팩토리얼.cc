#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;
    long long int answer = 1;
    // vector<int> vec;
    // for(int i=1;i<=N;i++){
    //     vec.push_back(i);
    // }

    // do{
    //     answer ++;
    // }while(next_permutation(vec.begin(),vec.end()));
    for(int i=1;i<=N;i++){
        answer *= i;
    }
    cout << answer << "\n";
}