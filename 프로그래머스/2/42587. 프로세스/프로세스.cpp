#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> que; //앞이 인덱스 뒤가 값
    for(int i=0;i<priorities.size();i++){
        que.push({priorities[i],i});
    }
    bool answerCheck = false;
    sort(priorities.begin(),priorities.end(),greater<>());
    for(auto it : priorities){
        while(!que.empty()){
            pair<int,int> temp = que.front();
            que.pop();
            if(temp.first ==it){
                 if(temp.second == location){
                     answerCheck = true;
                 }
                answer ++;
                break;
            }else{
                que.push(temp);
            }
        }
        if(answerCheck){
            break;
        }
    }
    
    return answer;
}