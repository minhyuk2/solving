#include<bits/stdc++.h>
//일단 bfs로 1번 부터 퍼져 나갔을 때의 거리가 제일 먼거
//일단 인접행렬로 구해놓고 거기서 visited를 따로 두고 판단하는게 맞는 것 같다.

using namespace std;

vector<int> arr[20005];
int visited[20005];
int maxs = 0;


void getAnswer(vector<vector<int>> &edge){
    queue<pair<int,int>> que;
    que.push({1,0});
    int distance = 0;
    visited[1] = 1;
    while(!que.empty()){
        pair<int,int> temp = que.front();
        que.pop();
        // distance ++;
        for(auto it : arr[temp.first]){
            if(visited[it] !=0) continue;
            visited[it] = temp.second+1;
            que.push({it,temp.second+1});
            if(temp.second+1 > maxs){
                maxs = temp.second+1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i =0; i<edge.size();i++){
        arr[edge[i][0]].push_back(edge[i][1]);
        arr[edge[i][1]].push_back(edge[i][0]);
    }
    
    getAnswer(edge);
    
    for(int i = 1;i<=n;i++){
        if(visited[i] == maxs){
            answer ++;
        }
    }
    
    
    return answer;
}