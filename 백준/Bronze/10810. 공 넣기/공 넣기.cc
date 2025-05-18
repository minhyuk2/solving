#include <bits/stdc++.h>

using namespace std;

int arr[110];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    int temp1,temp2,temp3;
    for(int i=0;i<M;i++){
        cin >> temp1 >> temp2 >> temp3;

        for(int t= temp1; t<=temp2; t++){
            arr[t] = temp3;
        }
    }

    for(int i=1;i<=N;i++){
        cout << arr[i] << " " ;
    }

    cout << "\n";
}
