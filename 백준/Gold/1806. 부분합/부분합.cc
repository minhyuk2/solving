#include<bits/stdc++.h>

using namespace std;

int arr[100005];
int N, S;

int answer = 1000009;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N >> S;

    int temp;
    for(int i =0; i< N;i++){
        cin >> arr[i];
    }
    

    int st = 0 , en = 0 ;

    int nowS = 0;

    for(st = 0; st<N; st++){
        if(st > 0){
            nowS -= arr[st-1];
        }else{
            nowS = arr[st];
        }
        //하나로 바로 만족하는 것에 대한 예외가 제대로 되어있는지는 확인하자
        while(en < N && nowS < S){
            en++;
            nowS += arr[en];
        }
        if(en == N) break;
        answer = min(en-st+1, answer);
    }



    if(answer == 1000009){
        cout << 0 << "\n";
    }else{
        cout << answer << "\n";
    }

}