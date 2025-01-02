#include <bits/stdc++.h>

using namespace std;

long long int moveZ(long long int N, long long int rowz, long long int colz){
    if(N==0) return 0; //종료할 조건
    if(N==1){
        if(rowz == 0 && colz == 0){
            return 0;
        }else if(rowz ==1 && colz == 0){
            return 2;
        }else if(rowz == 0 && colz ==1){
            return 1;
        }else if(rowz == 1 && colz == 1){
            return 3;
        }
    }
    
    if((rowz < (1<<N)/2) && (colz < (1<<N)/2)){
        //1사분면에 위치
        return moveZ(N-1,rowz,colz);
    }else if((rowz < (1<<N)/2) && (colz >= (1<<N)/2)){
        //2사분면에 위치
        return moveZ(N-1,rowz,colz%(1<<(N-1))) + (1<<(N-1))*(1<<(N-1));
    }else if((rowz >= (1<<N)/2) && (colz < (1<<N)/2)){
        //3사분면에 위치
        return moveZ(N-1,rowz%(1<<(N-1)),colz) + (1<<(N-1))*(1<<(N-1)) * 2;
    }else if ((rowz >= (1<<N)/2) && (colz >= (1<<N)/2)){
        //4사분면에 위치
        return moveZ(N-1,rowz%(1<<(N-1)),colz%(1<<(N-1))) + (1<<(N-1))*(1<<(N-1)) * 3;
    }
    else{
        return 0;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int  N, rows,cols;
    cin >> N >> rows >> cols;

    cout << moveZ(N,rows,cols) << "\n";
}