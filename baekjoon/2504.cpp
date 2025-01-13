#include <bits/stdc++.h>

using namespace std;
stack<pair<char,int>> sta;
//내부원소에 접근하기 쉬워야하기 떄문에 스택보다는 벡터로 만드는게 나을듯 ㅇㅇ
vector<int> vec;

long long int answer;

void checkLine(string lines){
    bool count2 =0 ;
    bool count3= 0;
    int count = 0;
    for(auto c : lines){
        if(c == '('){
            count2 = 1;
            sta.push({'(',count});
            
        }else if( c == ')'){
            if(sta.empty()){
                cout << 0 << "\n";
                return;
            }

            if(sta.top().first != '('){
                cout << 0 << "\n";
                return;
            }
            if(count2 == 1){
                //바로 닫아서 2점짜리가 된 경우
                count2 = 0;
                vec.push_back(2);
                sta.pop();
                count++;
                continue;
            }
            count2 = 0;
            //곱하기 2를 해야한다.
            for(int i = sta.top().second; i < vec.size();i++){
                vec[i] *= 2;
            }
            sta.pop();
        }else if( c == '['){
            count2 = 1;
            sta.push({'[',count});
        }else if( c == ']'){
            if(sta.empty()){
                cout << 0 << "\n";
                return;
            }
            if(sta.top().first != '['){
                cout << 0 << "\n";
                return;
            }
            if(count2 == 1){
                //바로 닫아서 2점짜리가 된 경우
                count2 = 0;
                vec.push_back(3);
                sta.pop();
                count++;
                continue;
            }
            count2 = 0;
            //곱하기 2를 해야한다.
            for(int i = sta.top().second; i < vec.size();i++){
                vec[i] *= 3;
            }
            sta.pop();
        }
        if(sta.empty()){
            for(int i = 0; i < vec.size();i++){
                answer += vec[i];
            }
            vec.clear();
            count = 0;
        }
    }
    if(sta.empty()){
        for(int i = 0; i < vec.size();i++){
            answer += vec[i];
        }
        vec.clear();
        count = 0;
    }
    cout << answer << "\n";
}


int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    string st; 
    cin >> st;



    checkLine(st);


}