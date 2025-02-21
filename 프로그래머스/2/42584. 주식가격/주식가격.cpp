#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int>> sta;
    //근데 answer에 있는게 언제 나가는지에 대해서 계속 체크하면 되긴 하겠네 ㅇㅋ
    //count 
    for(int i=0;i<prices.size();i++){
        answer.push_back(0);
    }
    for(int i=0;i<prices.size();i++){
        while(!sta.empty()){
            if(sta.top().second > prices[i]){
                pair<int,int> newPair = sta.top();
                answer[newPair.first] = i - newPair.first;
                sta.pop();
            }else{
                break;
            }
        }
        sta.push({i,prices[i]});
    }
    
    while(!sta.empty()){
        pair<int,int> newPair = sta.top();
        answer[newPair.first] = prices.size() - newPair.first -1;
        sta.pop();
    }
    //스택으로 더 작은게 나오면 처리하는 함수
    return answer;
}