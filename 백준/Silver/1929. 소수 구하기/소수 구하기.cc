#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

ll N,M;

vector<ll> vec;
vector<ll> primes;

void checkPrime(){
    for(int i=2;i<=M;i++){
        bool isPrime = 1;
        for(int it : primes){
            if(it * it > i) break;
            if(i% it == 0){
                isPrime = 0;
                break;
            }
        }
        if(isPrime){
            primes.push_back(i);
        }
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    checkPrime();

    for(int it : primes){
        if(it < N){
            continue;
        }else{
            cout << it << "\n";
        }
    }



}