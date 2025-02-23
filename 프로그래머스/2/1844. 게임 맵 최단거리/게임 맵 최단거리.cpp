#include <bits/stdc++.h>


using namespace std;

int visited[110][110];
int forX[4] = {-1,0,1,0};
int forY[4] = {0,1,0,-1};




int solution(vector<vector<int> > maps)
{
    int answer = 0;
    //n-1 과 m-1의 위치를 구해야 하는 것이다.
    queue<pair<int,int>> que;
    que.push({0,0});
    for(int i =0; i<110;i++){
        fill(visited[i],end(visited[i]),-1);
    }
    visited[0][0] = 1;
    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        for(int i =0;i<4;i++){
            int newX = forX[i] + newPair.first;
            int newY = forY[i] + newPair.second;
            
            if(newX < 0 || newY <0 || newX >=maps.size() || newY >=maps[0].size()) continue;
            if(visited[newX][newY] > -1 || maps[newX][newY] == 0) continue;
            visited[newX][newY] = visited[newPair.first][newPair.second] + 1;
            que.push({newX,newY});
        }
    }
    answer = visited[maps.size()-1][maps[0].size()-1];
    
    
    return answer;
}