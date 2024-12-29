#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int dist1[1002][1002];
int dist2[1002][1002];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

//모든 값들을 넣을 것들
string board[1002];

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int r , c;
    cin >> r >> c;
    
    //모든 값들 입력받기
    for(int i = 0 ; i < r ; i ++){
        cin >> board[i];
    }


    for(int  i = 0 ; i < r ; i++){
        for(int p = 0; p < c; p++){
            dist1[i][p] = -1;
            dist2[i][p] = -1;
        }
    }

    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;


    //불인 경우와 재훈이의 위치를 미리 표시
     for(int  i = 0 ; i < r ; i++){
        for(int p = 0; p < c; p++){
            if(board[i][p] == 'F'){
                Q1.push({i,p});
                dist1[i][p] = 0;
            }
            if(board[i][p] == 'J'){
                Q2.push({i,p});
                dist2[i][p] = 0;
            }
        }
    }
    //앞으로 이런 문제를 풀 때는 어떤게 먼저 움직이고 동시에 움직일지 두 개의 bfs는 어떻게 처리할지 등을 생각해봐야한다.

    //불이 먼저 이동하고 불에 대한 거리  == 시간이니까 같은 시간에 대해서 재훈이가 움직이지 않게 처리하면 된다.
    while(!Q1.empty()){
        pair<int,int> P2 = Q1.front();
        Q1.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            int nx = P2.first + dx[i];
            int ny = P2.second + dy[i];
            if(nx < 0  || nx >=r || ny < 0 || ny >= c) continue;
            //이미 지나갔거나 해당 위치가 벽인 경우에 대한 예외처리를 진행한다.
            if(dist1[nx][ny] >= 0 || board[nx][ny] == '#')continue;

            dist1[nx][ny] = dist1[P2.first][P2.second] + 1;
            Q1.push({nx,ny});
        }
    }

    //불에 대한 처리를 전부하였으니 이제 재훈이에 대한 처리를 해주면 된다.
    while(!Q2.empty()){
        pair<int,int> P2 = Q2.front();
        Q2.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            int nx = P2.first + dx[i];
            int ny = P2.second + dy[i];

            if(nx < 0  || nx >= r || ny < 0 || ny >= c){
                cout << dist2[P2.first][P2.second] + 1 << "\n";
                return 0;
            }
            //이미 지나갔거나 해당 위치가 벽인 경우에 대한 예외처리를 진행한다.
            if(dist2[nx][ny] >= 0 || board[nx][ny] == '#')continue;
            //불과 관련된 조건을 추가한다.
            if(dist1[nx][ny] != -1 &&dist1[nx][ny] <= dist2[P2.first][P2.second]+1){
                continue;
            }

            dist2[nx][ny] = dist2[P2.first][P2.second] + 1;
            Q2.push({nx,ny});
        }
    }

    cout << "IMPOSSIBLE\n";

}