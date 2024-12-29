#include <bits/stdc++.h>

using namespace std;

int board[100001]; //int 배열의 최대 크기 25만

int answer[100001]; //정답배열

int findMax(int count){
    //지금 이 문제는 무조건 o(n)으로 풀어야하는 것이고 dp라면 answer배열을 적극활용했어야한다. 그리고 그 위치가 중요한게 아니니까
    //어디서 발생하던지 간에.. 걍 위치를 찾아내면 되는 것이다.
    int nowMax = 0;
    //항상 초기값 설정 점화식 기억하기
    answer[0] =  board[0];
    nowMax = answer[0];
    for(int i = 1 ; i < count; i ++){
        //어디에서 최대인지가 중요한게 아니기에 다음 연속까지의 최대는 현재 거를 더하느냐 아니면 더하지 않느냐로 결정되는 것,
        //이전까지에 현재 것 더한게 더 작으면 새롭게 지금부터 시작인거 왜냐 이전에 큰거면 쭉 이어져 온 것일테니까
        answer[i] = max((answer[i-1]+board[i]),board[i]);
        nowMax = max(nowMax,answer[i]);
    }
    return nowMax;
}



int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int count = 0;
    cin >> count;

    bool minusOk = false;
    for(int i  = 0 ; i < count ; i++){
        cin >> board[i];
        if(board[i] < 0 ) minusOk = true;
    }  
    int ans = 0 ;

    cout << findMax(count) << "\n";

}