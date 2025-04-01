#include <bits/stdc++.h>

using namespace std;

bool isPrime[270000];

void getPrime(){
    // if(n == 1){
    //     return 1;
    // }
    // int counter = 0;
    for(int i=2;i<=(123456*2) ;i++){
        if(isPrime[i]) continue;
        for(int t= 2*i;t<=(123456*2); t+=i){
            isPrime[t] = 1;
        } 
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //일단 에라토스 테네스의 체로 구현
    getPrime();
    int number;
    while(1){
        cin >> number;
        if(number == 0){
            break;
        }
        int counter = 0;
        if(number == 1){
            cout << 1 << "\n";
            continue;
        }
        for(int i=number+1; i<=(number*2);i++){
            if(isPrime[i] == false){
                counter ++;
            }
        }
        cout << counter << "\n";
    }
}