#include <bits/stdc++.h>

using namespace std;

int N;
char arr[101][101];
int forX[4] = {-1,0,1,0}; //X축
int forY[4] = {0,1,0,-1}; // y축
int visited[101][101];
int visited2[101][101];



void goBFS2(int X, int Y, char color){
    queue<pair<int,int>> que;
    que.push({X,Y});
    visited2[X][Y] = 1;

    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        for(int i =0 ; i<4;i++){
            int newX = newPair.first + forX[i];
            int newY = newPair.second + forY[i];
            
            //항상 범위를 벗어나는지부터 먼저 확인하는 식으로 코드를 작성해야 한다.
            if(newX < 0 || newY < 0 || newX >= N||newY >=N) continue;
            if(visited2[newX][newY] == 1 )continue;
            if(color == 'R' && arr[newX][newY] == 'B')continue;
            if(color == 'G' && arr[newX][newY] == 'B')continue;
            if(color == 'B' && arr[newX][newY] == 'R')continue;
            if(color == 'B' && arr[newX][newY] == 'G')continue;

            visited2[newX][newY] = 1;
            que.push({newX,newY});
        }
    }

}


void goBFS(int X, int Y, char color){
    queue<pair<int,int>> que;
    que.push({X,Y});
    visited[X][Y] = 1;

    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        for(int i =0 ; i<4;i++){
            int newX = newPair.first + forX[i];
            int newY = newPair.second + forY[i];
            
            //항상 범위를 벗어나는지부터 먼저 확인하는 식으로 코드를 작성해야 한다.
            if(newX < 0 || newY < 0 || newX >= N||newY >=N) continue;
            if(visited[newX][newY] == 1 || arr[newX][newY] != color)continue;
            visited[newX][newY] = 1;
            que.push({newX,newY});
        }
    }

}



int normalOr(int ans){
    //일반의 경우
    char color;
    int answer =0;
    for(int i = 0; i < N; i ++){
        for(int t = 0 ; t < N; t++){
            
            if(visited[i][t] ==0 && ans ==0 ){
                goBFS(i,t,arr[i][t]);
                answer ++;
            }

            if(visited2[i][t] ==0 && ans ==1 ){
                goBFS2(i,t,arr[i][t]);
                answer ++;
            }
            
        }
    }
    return answer;
}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i =0; i <N;i++){
        for(int t = 0; t < N; t++){
            cin >> arr[i][t];
        }
    }

    //visited초기화하는 코드를 작성해야 한다.


    cout << normalOr(0) << " "<< normalOr(1) << "\n";


}