#include <bits/stdc++.h>

using namespace std;

int N;
int answer;


//1000까지만 고려하면 되는 문제인건데 흠.
void checkNums(){
    if(N < 100){
        answer = N;
        return;
    }
    answer = 99;
    //3자릿수에 대한 처리만 해주면 되는 것이다.
    for(int i=100;i<=N;i++){
        int first = i%10;
        int second = (i/10)%10;
        int third = i/100;
  
        if(third-second == second - first){
            answer ++;
        }
    }

}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    checkNums();

    cout << answer << "\n";



}