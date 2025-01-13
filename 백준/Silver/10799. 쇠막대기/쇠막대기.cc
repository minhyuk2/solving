#include <bits/stdc++.h>

using namespace std;

stack<char> sta;
vector<int> vec;
long long int answer;

void getPipe(string lines){
    int counting = 0;
    bool openTrue = 0;
    for(auto it : lines){
        if(it == '('){
            openTrue = 1;
            sta.push('(');
            vec.push_back(1);
        }else if(it == ')'){
            if(openTrue == 1){
                //얘는 레이저의 위치
                for(int i =0; i<vec.size();i++){
                    vec[i] ++;
                }
                vec.pop_back();
                openTrue = 0;  
            }else{
                openTrue = 0;
                sta.pop();
                answer += vec[vec.size()-1];
                vec.pop_back();
            }
        }
        if(sta.empty()){
            counting = 0 ;
        }
    }
    cout << answer << "\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string lines;
    cin >> lines;

    getPipe(lines);

}