#include <bits/stdc++.h>

using namespace std;

int forX[4] = {-1,0,1,0};
int forY[4] = {0,1,0,-1};

int arr[55][55];
int N, M;
int X,Y,Z;
int answer;


void getAnswer(){
    queue<pair<int,int>> que;
    que.push({X,Y});
    arr[X][Y] = 2;
    answer ++;

    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();

        int backCount = 0;
        for(int i=0;i<4;i++){
            int temp = (Z+1) % 4; // 시계방향 회전
            temp =  4 - temp;
            if(temp == 4){
                temp = 2;
            }else if(temp == 2){
                temp = 0;
            }
            //반시계방향으로 이동해줌
            Z = temp; //방향 회전
            int newX = newPair.first + forX[temp];
            int newY = newPair.second + forY[temp];

            if(newX < 0 || newY < 0 || newX >=N || newY >=M) continue;
            if(arr[newX][newY] == 2 || arr[newX][newY] == 1) {
                backCount++;
                continue;
            }
          

            arr[newX][newY] = 2;
            answer++;
            que.push({newX,newY});
            
            break;
        }

        if(backCount == 4){
            int temp = (Z + 2) % 4;
            int newX = newPair.first + forX[temp];
            int newY = newPair.second + forY[temp];
            if(newX < 0 || newY < 0 || newX >=N || newY >=M) return;
            if(arr[newX][newY] == 1) return;
            que.push({newX,newY});
        }

    }

}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N >> M;


    cin >> X >> Y >> Z;
    //시작위치  + 바라보는 방향

    for(int i =0; i< N;i ++){
        for(int t=0;t<M;t++){
            cin >> arr[i][t];
        }
    }


    getAnswer();
    // for(int i =0; i< N;i ++){
    //     for(int t=0;t<M;t++){
    //         cout << arr[i][t] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << answer << "\n";

}