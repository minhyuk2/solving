#include <bits/stdc++.h>

using namespace std;

int N,M;

int arrOkay[8];
int arrOkay2[8];
int indexing;
int answerArr[8];

//next_permutaion 함수를 사용할 수도 있지만 그냥 풀어보기도 하자
//자기 자신이 중복되어 나오는 것도 필요하다
void makeCase(int X){   

    if(indexing == M){
        for(int i = 0;i < indexing;i++){
            // if(answerArr[i]==0){
            //     return;
            // }
            cout << answerArr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++){
            answerArr[indexing++] = i;
            makeCase(i+1);
            answerArr[indexing--] = 0;
    }
}


int main(void){
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cin >> N >> M;

    makeCase(0);
}