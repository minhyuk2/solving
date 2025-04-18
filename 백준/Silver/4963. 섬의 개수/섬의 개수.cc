#include <bits/stdc++.h>

using namespace std;

bool visited[60][60];
int forX[8] = {0,-1,-1,-1,0,1,1,1};
int forY[8] = {-1,-1,0,1,1,1,0,-1};
int W,H;
void getBFS(vector<vector<int>> vec,pair<int,int> start){
    queue<pair<int,int>> que;
    que.push(start);
    visited[start.first][start.second] = 1;

    while(!que.empty()){
        pair newPair = que.front();
        que.pop();
        for(int i =0;i<8;i++){
            int newX = forX[i] + newPair.first;
            int newY = forY[i] + newPair.second;

            if(newX < 0 || newY < 0 || newX >= H|| newY >= W) continue;
            if(visited[newX][newY] == 1 || vec[newX][newY] == 0) continue;
            visited[newX][newY] = 1;
            que.push({newX,newY});
        }
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    while(1){
        cin >> W >> H;
        if(W==0&&H==0){
            break;
        }
        for(int i=0;i<60;i++){
            fill(begin(visited[i]),end(visited[i]),0);
        }
        vector<vector<int>> vecs;
        for(int i =0;i<H;i++){
            vector<int> newV;
            for(int t= 0;t<W;t++){
                int num;
                cin >> num;
                newV.push_back(num);
            }
            vecs.push_back(newV);
        }
        int answer = 0;
        for(int i =0;i<H;i++){
            for(int t= 0;t<W;t++){
                if(visited[i][t] == 0 && vecs[i][t] == 1){
                    answer ++;
                    getBFS(vecs,{i,t});
                }
            }
        }
        cout << answer << "\n";
        
    }


}