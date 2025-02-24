#include <bits/stdc++.h>


using namespace std;

// int forX[4] = {-1,0,1,0};
int forY[2] = {1,-1};

int visited[220][220];

void getNet(queue<pair<int,int>> &que,int N, int M,vector<vector<int>> &computers){
    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        for(int i= 0; i<M;i++ ){
            int newX = newPair.second;
            int newY = i;
            
            if(newX <0 || newY < 0 || newX >=N || newY >=M ) continue;
            if(visited[newX][newY] == 1 || computers[newX][newY] == 0) continue;
            visited[newX][newY] = 1;
            visited[newY][newX] = 1;
            que.push({newX,newY});
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<pair<int,int>> que;

    //연결되어 있으면 하나의 네트워크 한 번이라도 연결이 끊기면 다른 네트워크 쉬운 BFS 문제
    for(int i = 0;i<computers.size();i++){
        for(int t=0; t<computers[i].size();t++){
            if(visited[i][t] == 0 && computers[i][t] == 1){
                    que.push({i,t});
                    visited[i][t] = 1;
                    getNet(que,computers.size(),computers[i].size(),computers);
                    answer++;
            }
        }
    }
    
    return answer;
}