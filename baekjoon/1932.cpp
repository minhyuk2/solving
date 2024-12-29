#include <bits/stdc++.h>

using namespace std;

int board[501][501];
int sumBor[501][501];

void selectSum(int tri){
    sumBor[0][0] = board[0][0];
    for(int i = 1; i <tri;i++){
        for(int p = tri ; p >= tri-i; p --){ 
            if((tri-p) > 0){
                sumBor[i][tri-p] = max(sumBor[i-1][tri-p-1],sumBor[i-1][tri-p]) + board[i][tri-p];
            }else{
                sumBor[i][tri-p] = sumBor[i-1][tri-p]+ board[i][tri-p];
            }
        }
    }
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int tri = 0;
    cin >> tri;
    //어차피 나머지는 0으로 채워진 상태고
    for(int i = 0; i <tri;i++){
        for(int p = tri ; p >= tri-i; p --){ 
            cin >> board[i][tri-p] ;
        }
    }
    selectSum(tri);
    cout << *max_element(sumBor[tri-1],sumBor[tri-1]+tri) <<"\n";

}