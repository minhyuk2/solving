#include <bits/stdc++.h>

using namespace std;

int N,M;
int arrNumber[10];
int answerArr[10];
int arrOkay[10];

void makeCase(int X){
    
    if(X == M){
        for(int i = 0 ; i < M; i++){
            cout << answerArr[i] << " ";
        }
        cout << "\n";
        
    }
    
    for(int i = 0 ; i<N;i++){
        if(arrOkay[i] == 1){
            continue;
        }
        arrOkay[i] = 1;
        answerArr[X] = arrNumber[i];
        makeCase(X+1);
        arrOkay[i] = 0;
    }
}

//중복이 안나오게끔 하는 방식 ㅇㅋ
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i< N; i++){
        cin >> arrNumber[i];
    }
    sort(arrNumber,arrNumber+N);
    makeCase(0);
}