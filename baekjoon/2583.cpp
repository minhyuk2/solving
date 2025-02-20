#include <bits/stdc++.h>

using namespace std;

int N,M,K;
int board[110][110];
int visited[110][110];
int forX[4] ={-1,0,1,0};
int forY[4] ={0,1,0,-1};

int counter;
vector<int> answer;
void getAll(queue<pair<int,int>> &que);

void colorBoard(pair<int,int> newPair,pair<int,int> newPair2){
    for(int i = newPair.second;i<newPair2.second;i++){
        for(int t=newPair.first;t<newPair2.first;t++){
            board[i][t] = 1;
        }
    }

    // for(int i =0;i<M;i++){
    //     for(int t=0;t<N;t++){
    //         cout << board[i][t] << " ";
    //     }
    //     cout << "\n";
    // }
}
void getSquare(){

    for(int i=0;i<M;i++){
        for(int t=0;t<N;t++){
            if(board[i][t] == 0){
                // cout << "here" << i << " " << t  <<"\n";
                queue<pair<int,int>> que;
                counter++;
                que.push({i,t});
                getAll(que);
            }
        }
    }
}

void getAll(queue<pair<int,int>> &que){
    int numbers = 1;
    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        board[newPair.first][newPair.second] = 1;
        for(int i=0;i<4;i++){
            int newX = newPair.first + forX[i];
            int newY = newPair.second + forY[i];
            
            if(newX <0 || newY <0 || newX>=M||newY >=N)continue;
            if(board[newX][newY] != 0)continue;

            board[newX][newY] = 1;
            que.push({newX,newY});
            numbers++;
        }
    }
    answer.push_back(numbers);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N >> K;
    //M이 가로길이 N이 세로 길이
    for(int i=0;i<K;i++){
        pair<int,int> newPair;
        pair<int,int> newPair2;

        cin >> newPair.first >> newPair.second >> newPair2.first >> newPair2.second;
        colorBoard(newPair,newPair2);
    }

    getSquare();

    sort(answer.begin(),answer.end());
    cout << counter << "\n";
    for(auto it : answer){
        cout << it << " ";
    }
    cout << "\n";
}