#include <bits/stdc++.h>

using namespace std;

int N,M;
int indexing;
int answerArr[10];


void func(int K){
    if(K == M){
        int hak=0;
        for(int i = 0; i < K-1 ; i++){
            if(answerArr[i] > answerArr[i+1]){
                hak = 1;
            }
        }
        if(hak == 0){
            for(int i = 0; i < K; i++){
                cout << answerArr[i] << " ";
            }
            cout << "\n";
        }
        return;
    }

    for(int i=1 ; i<= N;i++){
        answerArr[K] = i;
        func(K+1);
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    func(0);
}