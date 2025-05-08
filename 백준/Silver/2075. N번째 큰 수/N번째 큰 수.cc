#include<bits/stdc++.h>

using namespace std;

int arr[2250000];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;

    cin >> N;

    // vector<vector<int>> vec;
    int num; 
    // vector<int> vec2;
    for(int i=0;i<N*N;i++){
        cin >> num;
        arr[i] = num;
    }
    sort(begin(arr),arr+N*N);

    cout << arr[N*N-N] <<"\n";

    // cout << vec2[N*N-N] << "\n";
    // for(int i=0;i<N;i++){
    //     vector<int> temp;
    //     for(int t=0;t<N;t++){
    //         cin >> num;
    //         temp.push_back(num);
    //     } 
    //     vec.push_back(temp);
    // }

    // for(int i=0;i<N;i++){
    //     sort(vec[i].begin(),vec[i].end());
    // }
    //이렇게 해결되는게 아니긴 하네
    //메모리 초과가 발생하면 흠

}