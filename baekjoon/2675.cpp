#include <bits/stdc++.h>

using namespace std;
int P;

void getArr(int number,string arr){
    for(auto it : arr){
        for(int i =0;i<number;i++)
            cout << it;
    }
    cout << "\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> P;
    int number;
    string arr;
    for(int i =0; i<P;i++){
        cin >> number;
        cin >> arr;
        getArr(number,arr);
    }
}