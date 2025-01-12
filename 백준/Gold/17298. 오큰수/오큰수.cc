#include <bits/stdc++.h>

using namespace std;

int N;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    stack<int> sta;
    int number;
    for(int i =0 ;i < N; i++){
        cin >> number;
        sta.push(number);
    }

    stack<int> sta2;
    sta2.push(10000001);
    stack<int> answer;
    for(int i = N; i>=1; i--){
        number = sta.top();
        sta.pop();

        while(sta2.top() <= number){
            sta2.pop();
        }
        if(sta2.top() == 10000001){
            answer.push(-1);
        }else{
            answer.push(sta2.top());
        }
        sta2.push(number);
    }

    while(!answer.empty()){
        cout << answer.top() << " ";
        answer.pop();
    }
    cout << "\n";
}