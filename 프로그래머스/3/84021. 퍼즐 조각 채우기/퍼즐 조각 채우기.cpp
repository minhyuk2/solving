#include<bits/stdc++.h>


using namespace std;

//일단 90도 돌리는 것도 구현해야 하고,
//각각의 game_board의 bfs를 통해서 2차원 배열을 구할 거임
//일단 3차원 배열에 내게 주어진 모형을 얻어야함.
vector<vector<pair<int,int>>> blocks;
vector<vector<pair<int,int>>> vaccum;
int forX[4] = {0,1,0,-1};
int forY[4] = {1,0,-1,0};
bool isUsed[1000];
int visited[1000][1000];
int visited2[1000][1000];
int answer = 0;

//블럭을 따로 뺴두고 돌려가면서 구하면 안되는건가?


vector<pair<int,int>> goBFS(vector<vector<int>>table,int stX, int stY){
    vector<pair<int,int>> block;
    queue<pair<int,int>> que;
    que.push({stX,stY});
    block.push_back({0,0});
    visited[stX][stY] = 1;
    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int newX = forX[i] + newPair.first;
            int newY = forY[i] + newPair.second;
            
            if(newX < 0 || newY < 0  || newX >=table.size() || newY >=table.size()) continue;
            if(visited[newX][newY] !=0 || table[newX][newY]!=1) continue;
            visited[newX][newY] =1;
            que.push({newX,newY});
            block.push_back({newX-stX,newY-stY});
        }
    }
    return block;
}


void getBFS(vector<vector<int>> &table){
    
    for(int i=0;i<table.size();i++){
        for(int t=0;t<table.size();t++){
            if(table[i][t] == 1 && visited[i][t]==0){
               blocks.push_back( goBFS(table,i,t));
            }
        }
    }
}



vector<pair<int,int>> goAnswer(vector<vector<int>> game_board,int stX,int stY){
    vector<pair<int,int>> block;
    queue<pair<int,int>> que;
    que.push({stX,stY});
    visited2[stX][stY] = 1;
    block.push_back({0,0});
    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int newX = forX[i] + newPair.first;
            int newY = forY[i] + newPair.second;
            
            if(newX < 0 || newY < 0  || newX>=game_board.size() || newY >=game_board.size() ) continue;
            if(visited2[newX][newY]!=0 || game_board[newX][newY]!=0) continue;
            visited2[newX][newY] =1;
            que.push({newX,newY});
            block.push_back({newX-stX,newY-stY});
        }
    }
    return block;
    
}

// vector<pair<int,int>> rollBlock(vector<pair<int,int>> block){
//     vector<pair<int,int>> ans;
//     for(int i=0;i<block.size();i++){
//         ans.push_back({block[i].second,-block[i].first});
//     }
//     return ans;
// }

// vector<pair<int,int>> rollBlock(vector<pair<int,int>> block) {
//     vector<pair<int,int>> ans;
    
//     // 90도 회전: (x, y) → (y, -x)
//     for(auto &p : block) {
//         ans.push_back({p.second, -p.first});
//     }

//     // 🔹 좌표 정규화 (정렬)
//     int minX = INT_MAX, minY = INT_MAX;
//     for(auto &p : ans) {
//         minX = min(minX, p.first);
//         minY = min(minY, p.second);
//     }
    
//     // 🔹 (0,0) 기준으로 이동
//     for(auto &p : ans) {
//         p.first -= minX;
//         p.second -= minY;
//     }

//     return ans;
// }
// vector<pair<int,int>> rollBlock(vector<pair<int,int>> block) {
//     vector<pair<int,int>> ans;
    
//     // 90도 회전: (x, y) → (y, -x)
//     for (auto &p : block) {
//         ans.push_back({p.second, -p.first});
//     }

//     // 🔹 가장 첫 번째 등장하는 좌표를 (0,0)으로 맞추기
//     pair<int, int> first = *min_element(ans.begin(), ans.end());
//     //이게 그냥 평행이동 시켜주는 것이지 ㅇㅇ
//     for (auto &p : ans) {
//         p.first -= first.first;
//         p.second -= first.second;
//     }

//     return ans;
// }
vector<pair<int,int>> rollBlock(vector<pair<int,int>> block) {
    vector<pair<int,int>> ans;

    // 90도 회전: (x, y) → (y, -x)
    for (auto &p : block) {
        ans.push_back({p.second, -p.first});
    }

    // 🔹 x 오름차순 → x가 같으면 y 오름차순 정렬
    sort(ans.begin(), ans.end());

    // 🔹 (0,0) 기준으로 이동
    int minX = ans[0].first;
    int minY = ans[0].second;
    for (auto &p : ans) {
        p.first -= minX;
        p.second -= minY;
    }

    return ans;
}



bool checkBlock(vector<pair<int,int>> A, vector<pair<int,int>> B){
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    return A == B;
}


void realAnswer(){
    
    for(int i=0;i<vaccum.size();i++){
        bool finds = 0;
        for(int t=0;t<blocks.size();t++){
            if (vaccum[i].size() == blocks[t].size() && !isUsed[t]) {
             vector<pair<int, int>> rotatedBlock = blocks[t]; // 원본 유지

                for (int p = 0; p < 4; p++) {
                    rotatedBlock = rollBlock(rotatedBlock); // 회전 후 비교
                    if (checkBlock(vaccum[i], rotatedBlock)) {
                        answer += blocks[t].size();
                        finds = true;
                        isUsed[t] = true;
                        break;
                    }
                }
            
        if(finds){
            break;
        }
        }
        }
    }
}




int solution(vector<vector<int>> game_board, vector<vector<int>> table) {

    getBFS(table);
    for(int i=0;i<game_board.size();i++){
        for(int t=0;t<game_board.size();t++){
            if(game_board[i][t] == 0 && visited2[i][t] == 0){
                //4방향에 대해서 이걸 진행시켜줘야하는데,,흠,,
                vaccum.push_back(goAnswer(game_board,i,t));
            }
        }
    }
    
    realAnswer();

    
    return answer;
}