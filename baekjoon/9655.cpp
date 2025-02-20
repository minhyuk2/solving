#include <bits/stdc++.h>

using namespace std;


int N;

int dp[1001];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    //1인 경우 SK, 2인 경우 CY
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    //지난 것에 대해서 바라볼 수 있기에 dp처럼 생각해볼 수 있다.
    //바로 답지를 보는 습관을 버리자... 왜 이상한 습관이 들었지,,, 쉽게 구하려고 하지말고 노력해서 끙끙 앓는 습관을 기르자,, 이게 이번에 들통났으니까 혼자서
    //천천히 푸는게 안되니까 빠르게 답을 못구하면 멘붕 이렇게 공부하진 말자

    if(N%2==0){
        cout << "CY\n";
    }else{
        cout << "SK\n";
    }

}