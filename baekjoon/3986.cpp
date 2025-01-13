#include <bits/stdc++.h>

using namespace std;

int N;
long long int answer;


void checkWord(string lines){
    stack<char> sta;
    stack<char> sta2; 
    for(auto c : lines){
        if(c == 'A'){
            if(sta.empty()){
                sta.push('A');
            }else{
                if(sta.top()=='B'){
                    sta.push('A');
                }else{
                    sta.pop();
                }
            }
        }else if(c == 'B'){
            if(sta.empty()){
                sta.push('B');
            }else{
                if(sta.top()=='A'){
                    sta.push('B');
                }else{
                    sta.pop();
                }
            }
        }
    }

    if(sta.empty()){
        answer ++;
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    string lines;
    for(int i =0; i<N; i++){
        cin >> lines;
        checkWord(lines);
    }
    cout << answer << "\n";
}