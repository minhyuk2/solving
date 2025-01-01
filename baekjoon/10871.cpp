#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,X;
    cin >> N >> X;
    int number;
    for(int i =0 ; i< N ; i ++){
        cin >> number;
        if(number < X)
            cout << number << " " ;
    }
}