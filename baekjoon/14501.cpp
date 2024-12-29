#include <bits/stdc++.h>

using namespace std;

int day[16];
int pay[16];
int maxPay[16];

void collectMaxPay(int dayIn){
    for(int i= dayIn-1;i>=0;i--){
        //하루 실행하고 정하기
        //만약에 가능한지 판단하고 정하기
        //이러면 걍 안되면 넘기니까 이러지말고 마지막에 대해서만 이렇게 판단해야한다.
        //자동으로 걍 마지막으로온 애만 되겠구나 ㅇㅋ
        if(day[i] + i > dayIn){
            maxPay[i] = 0;
            continue;
        }        
        maxPay[i] += pay[i];
        int dayC = 0;
        dayC = day[i] + i;
        maxPay[i]+=*max_element(maxPay+dayC,maxPay+dayIn);
    }
}

int main(void){

    int dayIn =0;
    cin >> dayIn;

    for(int i = 0 ; i < dayIn ; i ++){
        cin >> day[i] >> pay[i];
    }
    collectMaxPay(dayIn);
    cout << *max_element(maxPay,maxPay+dayIn) << "\n";

    return 0;
}