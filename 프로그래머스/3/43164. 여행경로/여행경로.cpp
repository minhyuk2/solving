#include<bits/stdc++.h>

using namespace std;
bool visited[10005];
bool isAnswer;
vector<string> answer;
void DFS(vector<vector<string>> &tickets,int num,string start){
   answer.push_back(start);
    cout << start << "\n";
    if(num == tickets.size()){
       isAnswer = true;
   } 
    for(int i=0;i<tickets.size();i++){
        if(visited[i]) continue;
        
        if(tickets[i][0] == start){
            visited[i] = true;
            
            DFS(tickets,num+1,tickets[i][1]);
            if(!isAnswer){
                  visited[i] = false;
                  answer.pop_back();  
            }
        }
    }
}



vector<string> solution(vector<vector<string>> tickets) {
    //일단 정렬부터 시켜줌
    sort(tickets.begin(),tickets.end());
    DFS(tickets,0,"ICN");
    return answer;
}