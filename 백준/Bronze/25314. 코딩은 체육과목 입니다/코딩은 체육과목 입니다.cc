#include <bits/stdc++.h>

using namespace std;

int N;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;


    int temp = N/4;

    for(int i= 0 ; i<temp;i++){
        cout << "long ";
    }
    cout << "int\n";
}