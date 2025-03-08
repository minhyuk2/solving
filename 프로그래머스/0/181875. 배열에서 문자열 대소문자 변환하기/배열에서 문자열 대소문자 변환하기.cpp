#include<bits/stdc++.h>

using namespace std;

vector<string> changeWord(vector<string> strr){
    vector<string> answer;
    for(int i = 0;i<strr.size();i++){
        string temp = "";
        if(i%2==0){
            //짝수의 경우
            for(auto it : strr[i] ){
                temp += tolower(it);
            }
        }else{
            for(auto it : strr[i] ){
                temp += toupper(it);
            }
        }
        answer.push_back(temp);
    }
    return answer;
}


vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    answer = changeWord(strArr);
    return answer;
}