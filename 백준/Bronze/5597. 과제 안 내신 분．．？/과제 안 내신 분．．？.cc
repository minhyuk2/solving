#include<bits/stdc++.h>

using namespace std;

int arr[31];
bool arr2[31];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int N = 28;
    int temp;
    for(int i = 0; i < 28;i++){
        cin >> temp;
        arr2[temp]  = 1;
    }

    for(int i = 1; i <=30;i++){
        if(arr2[i] == false){
            cout << i << "\n";
        }
    }

    

}