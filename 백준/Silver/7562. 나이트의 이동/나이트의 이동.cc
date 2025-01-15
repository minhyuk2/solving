#include <bits/stdc++.h>

using namespace std;

int N ,M;
int visited[301][301];

int forX[8] = {2,1,-1,-2,-2,-1,1,2};
int forY[8] = {1,2,2,1,-1,-2,-2,-1};


void goHorse(pair<int,int> start, pair<int,int> end){
    long long int answer = 10000000000;
    queue<pair<int,pair<int,int>>> que;
    que.push({0,start});
    visited[start.first][start.second] =1;
    if(start == end){
        cout << 0 << "\n";
        return;
    }
    while(!que.empty()){
        long long int count = que.front().first;
        pair<int,int> newPair = que.front().second;
        que.pop();
        if((newPair == end) && answer > count){
                answer = count;
                break;
        }
        for(int i =0 ; i < 8 ; i++){
            int newX = newPair.first + forX[i];
            int newY = newPair.second + forY[i];

            if(newX < 0||newY < 0|| newX >= M || newY >= M) continue;
            if(visited[newX][newY] == 1) continue; //중복되는 경우가 생길 수 있으니까 반드시 확인해야지
            que.push({count+1,{newX,newY}});
            visited[newX][newY] = 1;
        }
    }
    cout << answer << "\n";
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    pair<int,int> start;
    pair<int,int> end;
    for(int i =0; i< N; i++){
        cin >> M;
        for(int t= 0; t< M; t++){
            fill(visited[t],visited[t]+301,0);
        }
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;
        goHorse(start,end);
    }
}