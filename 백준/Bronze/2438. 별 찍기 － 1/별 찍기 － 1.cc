#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i=1;i<=N;i++){
        for(int t=1;t<=i;t++){
            cout <<"*";
        }
        cout << "\n";
    }
}