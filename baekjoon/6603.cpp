#include <bits/stdc++.h>

using namespace std;

int arr[50];
int arrOkay[50];
int answerArr[50];



void cleanCase(){
    for(int i = 0; i<50;i++){
        arr[i] = 0;
        arrOkay[i] = 0;
    }
}
//이게 조합을 고르는 문제네
//근데 6개의 숫자를 선택하는 문제였지 ;
//그리고 오름차순으로 진행해야 한다는 것이다.
// 6개를 뽑고 오름 차순 정리
// 오름차순된 것 만 출력되게끔 해야한다.
void popCase(int X,int N,int indexing){

    if(indexing == 6){
        int overLap = 0;
        for(int i =0; i< 6; i++){
            if(answerArr[i+1] != 0 &&answerArr[i] > answerArr[i+1]){
                overLap ++;
            }
        }
        if(overLap == 0){
            for(int i =0; i< 6; i++){
                cout << answerArr[i] << " ";
            }
            cout << "\n";
        }

    }
    if(X == N){
        return ;
    }
    //한 번만 나오게끔 이러면 모든 조합이기 때문에 우리는 순열로서 가능한 것만 나오게끔 만들어야 한다.

    //이렇게 모든 숫자는 가는게 맞음
    for(int i = X; i < N; i++){
        if(arrOkay[i] == 1){
            continue;
        }
        //얘도 답안 array를 넘겨주는 식으로 작동해야할듯
        //계속 답안 array를 가지고 있고 그걸 유지하는 식으로 작성해야겠네
        answerArr[indexing++] = arr[i];
        arrOkay[i] = 1;
        popCase(X+1,N,indexing);
        arrOkay[i] = 0;
        answerArr[indexing--] = 0;
    }

}


int makeCase(){
    int N;
    cin >> N;
    if(N == 0){
        return 1;
    }
    cleanCase();
    for(int i = 0 ; i< N; i++){
        cin >> arr[i];
    }
    
    popCase(0,N,0);
    cout << "\n";
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(makeCase() == 0);
    
}