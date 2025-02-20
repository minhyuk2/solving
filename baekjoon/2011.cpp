#include <bits/stdc++.h>

using namespace std;


int arr[5005];
long long int dp[5010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string inputs;
    char buffers;
    cin >> inputs;
    for(int i=0;i<inputs.size();i++){
        buffers = inputs[i];
        arr[i] = buffers - '0';
    }

    if(arr[0] == 0){
        dp[0] = 0;
    }else{
        dp[0] = 1;
    }

    if(inputs.size()>=2){
        int numbering = arr[0] *10 + arr[1] ;
        if(arr[1] == 0){
            if(numbering <= 26&&numbering >=10){
                 dp[1] = dp[0];
            }else{
                cout << 0 << "\n";
                return 0;
             }

        }else{
            if(numbering <= 26&&numbering >=10){
                dp[1] = dp[0] +1;
            }else{
                dp[1] = dp[0];
            }
        }
    }
    

    for(int i=2;i<inputs.size();i++){
        if(arr[i] == 0){
            if(arr[i-1] == 0){
                cout << 0 << "\n";
                return 0;
            }
            int numbering = arr[i-1] *10 + arr[i] ;
            if(numbering <= 26 &&numbering >=10){
                dp[i] = dp[i-2];
            }else{
                cout << 0 << "\n";
                return 0;
            }
        }else{
            int numbering = arr[i-1] *10 + arr[i] ;
            if(numbering <= 26 &&numbering >=10){
                dp[i] = (dp[i-2]%1000000 + dp[i-1]%1000000)%1000000;
            }else{
                dp[i] = dp[i-1];
            }
        }
    }

    cout << dp[inputs.size()-1] << "\n";

}