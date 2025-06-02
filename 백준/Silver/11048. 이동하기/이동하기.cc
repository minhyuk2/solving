#include <bits/stdc++.h>

using namespace std;

int N, M;

int arr[1002][1002];
int answer[1002][1002];


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=1;i<=N;i++){
        for(int t= 1 ;t <=M;t++){
            cin >> arr[i][t];
        }
    }


    for(int i=1;i<=N;i++){
        for(int t= 1 ;t <=M;t++){
            int temp = max(arr[i-1][t-1],arr[i][t-1]);
            temp = max(temp,arr[i-1][t]);
            arr[i][t] = temp + arr[i][t];
        }
    }


    cout << arr[N][M] << "\n";


}