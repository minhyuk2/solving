#include <bits/stdc++.h>

using namespace std;

//이제 벽을 뚫는 것에 대한 경우를 한 번 추가해주면 됨.
//pair를 하나 더 써서 구현하면 됨
//일단 visited를 써두고 시작해야하는 걸 잊으면 안됨

//이미 한 번 벽을 뚫고 visited가 되어버리는 경우가 발생하기 때문에,,
//벽을 부순 애가 이동하는 것에 대해서는 어떠한 처리가 필요해보임
//벽을 뚫는 것에 대한 visited가 발생하여서 이를 통한 것이 쉽지 않아 진다.


int N, M;
// int arr[1001][1001];
char board[1001][1001];
int visited[1001][1001] = {-1,};
int visited2[1001][1001] = {-1,};
int forX[4] = {1,0,-1,0};
int forY[4] = {0,1,0,-1};

void breakWall(){

    for(int i =0; i< N; i++){
        fill(visited[i],visited[i]+1001,-1);
        fill(visited2[i],visited2[i]+1001,-1);
    }
    queue<pair<int,pair<int,int>>> que;
    que.push({1,{0,0}});
    visited[0][0] = 1;
    //시간 복잡도가 2초 2중 for문 돌아도 100만 이기에 200번 더 돌릴 수 있음. 4방향 이동 + 벽을 깨는 경우로 for문을 두 번 돌리기
    while(!que.empty()){
        pair<int,pair<int,int>> newPair = que.front();
        que.pop();
        // cout << "base : "<< newPair.second.first << " " << newPair.second.second << "\n";
        if(newPair.first == 1 ){
            for(int i= 0;i<4;i++){
                int newX = newPair.second.first + forX[i];
                int newY = newPair.second.second + forY[i];
                //얘는 다른 애의 영향을 받지 않고 이제 돌아야하는게 아닌가?
                if(newX >= N || newY >= M || newX < 0|| newY < 0)continue;
                if(visited[newX][newY] > -1 || board[newX][newY] != '0')continue;
                visited[newX][newY] = visited[newPair.second.first][newPair.second.second] + 1;
                que.push({newPair.first,{newX,newY}});
                // cout <<"0 case "<< newX  << " "<< newY << "\n";
            }
                for(int i= 0;i<4;i++){
                    int newX = newPair.second.first + forX[i];
                    int newY = newPair.second.second + forY[i];

                    if(newX >= N || newY >= M || newX < 0|| newY < 0)continue;
                    if(visited[newX][newY] > -1 || board[newX][newY] == '0')continue; //무조건 벽이 이쓴 경우에 대한 처리
                    visited2[newX][newY] = visited[newPair.second.first][newPair.second.second] + 1;
                    // board[newX][newY] = '0';
                    que.push({newPair.first-1,{newX,newY}});
                    // cout << "1case " << newX  << " "<< newY << "\n";
                }
        }else{
            for(int i= 0;i<4;i++){
                int newX = newPair.second.first + forX[i];
                int newY = newPair.second.second + forY[i];

                if(newX >= N || newY >= M || newX < 0|| newY < 0)continue;
                if(visited2[newX][newY] > -1 || board[newX][newY] != '0')continue; 
                visited2[newX][newY] = visited2[newPair.second.first][newPair.second.second] + 1;
                // board[newX][newY] = '0';
                que.push({newPair.first,{newX,newY}});
                // cout <<"2 case :"<< newX  << " "<< newY << "\n";
            }
        }
    }

    if(visited[N-1][M-1] == visited2[N-1][M-1]){
        cout << visited[N-1][M-1] << "\n";
    }else if(visited2[N-1][M-1] > visited[N-1][M-1] && visited[N-1][M-1] != -1){
        cout << visited[N-1][M-1] << "\n";
    }else if(visited[N-1][M-1] > visited2[N-1][M-1] && visited2[N-1][M-1] != -1){
        cout << visited2[N-1][M-1] << "\n";
    }else if(visited[N-1][M-1] > visited2[N-1][M-1] && visited2[N-1][M-1] == -1){
        cout << visited[N-1][M-1] << "\n";
    }else if(visited2[N-1][M-1] > visited[N-1][M-1] && visited[N-1][M-1] == -1){
        cout << visited2[N-1][M-1] << "\n";
    }

}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    //띄어쓰기 없이 들어갔네
    for(int i= 0 ; i < N;i++){
        for(int t=0; t < M; t++){
            cin >> board[i][t];
            // cout << board[i][t] << " ";
        }
        // cout << "\n";
    }
    breakWall();

}