#include <bits/stdc++.h>

using namespace std;

int N;
long long int arr[91][91];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;

    arr[1][0] = 0;
    arr[1][1] = 1;
    
    arr[2][0] = 1;
    arr[2][1] = 0;
    
    arr[3][0] = 1;
    arr[3][1] = 1;

    for(int i =4;i<=N;i++){
        arr[i][0] = arr[i-1][0] + arr[i-1][1];
        arr[i][1] = arr[i-1][0];
    }

    cout << arr[N][0] + arr[N][1] << "\n";

}