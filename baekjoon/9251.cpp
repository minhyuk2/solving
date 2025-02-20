#include <bits/stdc++.h>

using namespace std;

int arr[1002][1002];


//풀이를 봤기에 다시 풀어보는게 좋다.

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;


    for(int i = 1; i<= str1.size();i++){
        for(int t =1; t<=str2.size();t++){
            if(str1[i-1] == str2[t-1]){
                arr[i][t] = arr[i-1][t-1] +1;
            }else{
                arr[i][t] = max(arr[i-1][t],arr[i][t-1]);
            }
   
        }
    }
    cout << arr[str1.size()][str2.size()] << "\n";    
}