#include <bits/stdc++.h>

using namespace std;


int N,M;
int arr[9];
int answer[9];

void makeCase(int X){
    
    if(X == M){
        //원하는 숫자 나오면 출력하기
        int checking =0;
        for(int i =0; i< M-1; i++){
            if(answer[i] > answer[i+1])
                checking =1;
        }
        if(checking == 0){
            for(int i =0; i< M; i++){
                cout << answer[i] << " ";
            }
            cout << "\n";
        }
        return;
    }

    for(int i =0; i < N ;i++){
        answer[X] = arr[i];
        makeCase(X+1);
        answer[X] = 0;
    }
}

// int compare()

void sameDelete(){
    int saming = 0;
    int count = N;
    int newArr[N];
    for(int i= 0; i< count-1; i++){
        saming = arr[i];
        if(saming != 0 && arr[i+1] == saming){
            //다 댕겨야지 아으
            //같은게 여러개 있을 때 삭제해야지
            for(int t = i; t < N; t++){
                if(t == N -1){
                    arr[t] = 0;
                    continue;
                }
                arr[t] = arr[t+1];
            }
            N --;
            i--;
        }
    }
}

//순서대로 만들고 중복을 제거해야함.
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i= 0; i< N; i++){
        cin >> arr[i];
    }
    //정렬해줌
    sort(arr,arr+N);

    sameDelete();

    makeCase(0);

}