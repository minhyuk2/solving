#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

bool isprime(int n){
    if(n==1)return 0;
    for(int i=2;i * i<=n;i++){
        if(n%i == 0) return 0;
    }
    return 1;
}
int N;
int answer;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>  N;

    for(int i=0;i<N;i++){
        int number;
        cin >> number;
        if(isprime(number)){
            answer ++;
        }

    }
    cout << answer << "\n";
    
}