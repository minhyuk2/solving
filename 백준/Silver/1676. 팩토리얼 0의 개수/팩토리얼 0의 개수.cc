#include <bits/stdc++.h>

using namespace std;

int N;


int getFive(int num){
    int counter = 0;
    while(1){
        if(num % 5 != 0){
            break;
        }
        counter ++;
        num = (num/5);

    }
    return counter;
}

int getTwo(int num){
    int counter = 0;
    while(1){
        if(num % 2 != 0){
            break;
        }
        counter ++;
        num = (num/2);

    }
    return counter;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //리얼 걍 팩토리얼 값에서 0이 몇 개인지 뒤에서부터 세는 것이다. 그러면 끝자리만 보면됨.
    //즉 10의 배수를 구하라는 의미다.

    cin >> N;
    int countFive = 0;
    int countTwo = 0;
    for(int i=1;i<=N;i++){
        countTwo += getTwo(i);
        countFive += getFive(i);
    }   

    if(countTwo > countFive){
        cout << countFive << "\n";
    }else{
        cout << countTwo << "\n";
    }

}