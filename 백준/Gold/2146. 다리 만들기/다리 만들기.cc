#include <bits/stdc++.h>

using namespace std;

int N;
int arr[102][102];
// int visited[101][101];
int island[102][102];

int forX[4] = {1,0,-1,0};
int forY[4] = {0,1,0,-1};

void getIsland(queue<pair<int,int>> &que,int numbering){
    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        for(int i=0; i<4;i++){
            int newX = forX[i] + newPair.first;
            int newY = forY[i] + newPair.second;

            if(newX < 0||newY < 0||newX>=N||newY>=N) continue;
            if(arr[newX][newY] != 1 || island[newX][newY] > 0) continue;

            island[newX][newY] = numbering;
            que.push({newX,newY});
        }
    }
}


void findIsland(){
    int numbering = 0;
    queue<pair<int,int>> que;

    for(int i= 0; i<N;i++){
        for(int t= 0; t <N;t++){
            if(arr[i][t] == 1 && island[i][t] == 0){
                numbering ++;
                island[i][t] = numbering;
                que.push({i,t});
                getIsland(que,numbering);
            }
        }
    }
}

long long int findNewIsland(queue<pair<int,int>> &que){
    int visited[105][105] = {0,};
    visited[que.front().first][que.front().second] = 1;
    int myIsland = -1;
    int length = 0;
     while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        for(int i=0; i<4;i++){
            int newX = forX[i] + newPair.first;
            int newY = forY[i] + newPair.second;

            if(newX < 0||newY < 0||newX>=N||newY>=N) continue;
            if(island[newX][newY]!=0){
                // cout << newX <<" " <<newY << "\n";
                if(myIsland == -1)
                {
                    myIsland = island[newX][newY];
                    // cout << myIsland << "\n";
                }else if(myIsland != island[newX][newY]){
                    length = visited[newPair.first][newPair.second] ;
                    // cout <<"length :"<< length << "\n";

                    // for(int i= 0; i<N;i++){
                    //     for(int t= 0; t <N;t++){
                    //         cout << visited[i][t] << " ";
                    //     }
                    //     cout << "\n";
                    // }
                    
                    return length;
                }
            }
            //섬은 큐에 저장하진 않음
            if(arr[newX][newY] != 0 || visited[newX][newY] >= 1) continue;

            visited[newX][newY] = visited[newPair.first][newPair.second] + 1;
            que.push({newX,newY});
        }
    }
    return 100000000;
}



void getLength(){

    long long int answer = 100000000;
    int numbering = 0;
 
    // for(int i= 0; i<N;i++) fill(visited[i],visited[i]+101,-1);
    //bfs만이 거리에 대해서 구할 수 있다.
    for(int i= 0; i<N;i++){
        for(int t= 0; t <N;t++){
            if(arr[i][t] == 0){
                bool isOk = 0;
                for(int p=0; p<4;p++){
                    int newX = forX[p] + i;
                    int newY = forY[p] + t;

                    if(newX < 0||newY < 0||newX>=N||newY>=N) continue;
                    if(island[newX][newY] != 0){
                        isOk =1;
                        break;
                    }
                }
                if(isOk){
                    queue<pair<int,int>> que;
                    que.push({i,t});
                    numbering = findNewIsland(que);
                    if(numbering < answer){
                        answer = numbering;
                    }
                }
            }
        }
    }
    if(answer == 100000000){
        cout << 0 << "\n";
    }else{
        cout << answer << "\n";
    }
}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;

    for(int i= 0; i<N;i++){
        for(int t= 0; t <N;t++){
            cin >> arr[i][t];
        }
    }

    findIsland();
    getLength();
}