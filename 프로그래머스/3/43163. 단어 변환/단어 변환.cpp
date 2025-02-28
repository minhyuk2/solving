#include<bits/stdc++.h>

using namespace std;


int checkWord(string temp, string finds){
    int changeCount =0;
    for(int i=0;i<temp.size();i++){
        if(temp[i] != finds[i]){
            changeCount++;
        }
    }     
    return changeCount;
}

int findWord(string target,queue<pair<int,string>> &que, vector<string> words,int *visited){
    int counts = 1 ;
    while(!que.empty()){
        pair<int,string> newPair = que.front();
        string temp = newPair.second;
        que.pop();
        for(int i=0;i<words.size();i++){
            if(visited[i] != 0) continue;
            if(checkWord(temp,words[i])!=1)continue;
            visited[i] = 1;
            que.push({newPair.first+1,words[i]});
            if(words[i] == target){
                return newPair.first+1;
            }
        }
    }
    if(counts == 1){
        return 1000000;
    }
}

int getAnswer(string begin, string target, vector<string> words){
    string temp;
    int answer = 1000000;
    for(int i=0;i<words.size();i++){
        temp = words[i];
        if(checkWord(begin,temp)==1){
            if(temp == target){
                return 1;
            }else{
                //아닌 경우 que에 넣고 이제 하나씩 돌려가면서 찾아야하나?
                int visited[words.size()];
                for(int t=0;t<words.size();t++)
                {
                    visited[t] = 0;
                }
                visited[i] = 1;
                queue<pair<int,string>> que; 
                que.push({1,temp});
                int number = findWord(target,que,words,visited);
                if( number < answer){
                    answer = number;
                }
            }
        }
    }
    return answer;
}




int solution(string begin, string target, vector<string> words) {
    int answer = 1000000;
    
    answer = getAnswer(begin,target,words);
    
    if(answer == 1000000){
        answer = 0;
    }
    return answer;
}