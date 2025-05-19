#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int  X,N;

    cin >> X >> N;

    long long int temp1, temp2;
    long long int answ = 0;
    for(int i=0;i<N;i++){
        cin >> temp1 >> temp2;

        answ += (temp1 * temp2);
    }

    if(answ == X){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }

}