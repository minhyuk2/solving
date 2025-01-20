#include <bits/stdc++.h>

using namespace std;

int N,M;
int arr[301][301];
int visited[301][301];
bool visit2[301][301];
int forX[4] = {1,0,-1,0};
int forY[4] = {0,1,0,-1};

void glacier(queue<pair<int,int>> &que){
    int answer = 0;
    while(1){
        //원래 큐에다가 새로 나온 애를 집어넣어주면 된다.
        answer++;
        queue<pair<int,int>> newQue  = que;
        for(int i= 0; i <N;i++){
            fill(visited[i],visited[i]+301,0);
            fill(visit2[i],visit2[i]+301,0);
        }
        while(!newQue.empty()){
            pair<int,int> newPair = newQue.front();
            newQue.pop();
            
            for(int i =0; i<4;i++){
                int newX = forX[i] + newPair.first;
                int newY = forY[i] + newPair.second;

                if(newX < 0|| newY < 0||newX>=N|| newY >= M) continue;
                if(arr[newX][newY] == 0)continue;

                //숫자인 경우에 대해서
                visited[newX][newY] = 1;
                arr[newX][newY] = arr[newX][newY] -1;
                if(arr[newX][newY] == 0){
                    que.push({newX,newY});
                }
            }
        }
        int count = 0;
        queue<pair<int,int>> newQue2;
        for(int i =0;i<N;i++){
            for(int t= 0; t<M;t++){
                if(arr[i][t] != 0 && visit2[i][t] == 0){
                    newQue2.push({i,t});
                    visit2[i][t] = 1;
                    count ++;
                    while(!newQue2.empty()){
                        pair<int,int> newPair = newQue2.front();
                        newQue2.pop();
                        
                        for(int i =0; i<4;i++){
                            int newX = forX[i] + newPair.first;
                            int newY = forY[i] + newPair.second;

                            if(newX < 0|| newY < 0||newX>=N|| newY >= M) continue;
                            if(visit2[newX][newY] == 1||arr[newX][newY] == 0)continue;

                            //숫자인 경우에 대해서
                            visit2[newX][newY] = 1;
                            newQue2.push({newX,newY});
                        }
                    }
                }
            }
        }
        if(count > 1){
            cout << answer << "\n";
            return;
        }else if(count == 0){
            cout << 0 << "\n";
            return;
        }

    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    queue<pair<int,int>> que;
    for(int i =0; i<N;i++){
        for(int t=0; t<M;t++){
            cin >> arr[i][t];
            if(arr[i][t] == 0){
                que.push({i,t});
                visited[i][t] = 1;
            }

        }
    }
    glacier(que);

}