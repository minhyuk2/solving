#include <bits/stdc++.h>

using namespace std;

int dp[110][110][110] ;

int solve(int a, int b, int c){

    if(a <=0 || b<=0 || c<=0){
        return 1;
    }

    if(a > 20  ||  b > 20 || c>20){
        return solve(20,20,20);
    }


    if(dp[a][b][c]){
        return dp[a][b][c];
    }

    if(a< b && b< c){
        dp[a][b][c] = (solve(a,b,c-1) + solve(a,b-1,c-1) - solve(a,b-1,c));
        return dp[a][b][c];
    }else {
        dp[a][b][c] = (solve(a-1,b,c) + solve(a-1,b-1,c) + solve(a-1,b,c-1) - solve(a-1,b-1,c-1));
        return dp[a][b][c];
    }


}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c;

    // for(int i =0;i<3;i++){
    //     if(i == 0){
    //         for (int t=  0; t<110;t++){
    //             for(int p=0;p<110;p++){
    //                 dp[0][t][p] = 1;
    //             }
    //         }  
    //     }else  if(i == 1){
    //         for (int t=  0; t<110;t++){
    //             for(int p=0;p<110;p++){
    //                 dp[t][0][p] = 1;
    //             }
    //         }  
    //     }else{
    //         for (int t=  0; t<110;t++){
    //             for(int p=0;p<110;p++){
    //                 dp[t][p][0] = 1;
    //             }
    //         }  
    //     }
    // }
    
    while(1){
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1){
            break;
        }


        cout << "w(" << a << ", " << b << ", " << c  << ") = " << solve(a,b,c) << "\n";
    }
}

//100으로 가버리면 걔네는 더 하게끔 해야해서 이상해지네 식이 ㅠㅠ
//아 재귀함수를 구해서 계속 반복하게끔 하는거구나