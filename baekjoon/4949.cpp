#include <bits/stdc++.h>

using namespace std;

stack<char> sta;

void checkString(string lines){
    for(int i =0; i< lines.size();i++){
        //끝날 조건
        if(lines[i] == '.'){
            if(sta.empty()){
                //다 비어있는 경우
                cout << "yes\n";
            }else{
                cout << "no\n";
            }
        }

        if(lines[i] == '['){
            sta.push('[');
        }else if(lines[i] == ']'){
            if(sta.empty()){
                cout << "no\n";
                return;
            }else{
                if(sta.top() == '['){
                    sta.pop();
                }else{
                    cout << "no\n";
                    return;
                }
            }
        }else if(lines[i] == '('){
            sta.push('(');
        }else if(lines[i] == ')'){
            if(sta.empty()){
                cout << "no\n";
                return;
            }else{
                if(sta.top() == '('){
                    sta.pop();
                }else{
                    cout << "no\n";
                    return;
                }
            }

        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string lines;
    while(getline(cin,lines)){
        if(lines == "."){
            break;
        }
        while(!sta.empty())
            sta.pop();
        checkString(lines);
    }

}