#include <bits/stdc++.h>

using namespace std;

string temp;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> temp;

    int sizes = temp.size();
    for(int i =0; i<sizes;i++){
        if(temp[i] != temp[sizes-i-1]){
            cout << 0 << "\n";
            return 0 ;
        }
    }
    cout << 1 << "\n";

}