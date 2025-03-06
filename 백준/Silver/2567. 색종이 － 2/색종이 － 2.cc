#include <bits/stdc++.h>

using namespace std;

int N;

int arr[205][205];
int visited[205][205];
int forX[4] = {1,0,-1,0};
int forY[4] = {0,1,0,-1};
int answer;
//얘도 한 번 했을 때 틀리면 두배 늘려서 접근하면 될 것 같긴하다.
//BFS 여러 번 돌리면 되겠네 ㅇㅋ
void getAnswer(int stx,int sty){
    stack<pair<int,int>> que;
    que.push({stx,sty});
    visited[stx][sty] = 0;
    int number =-1;
    while(!que.empty()){
        pair<int,int> newPair = que.top();
        que.pop();
        for(int i=0;i<4;i++){
            int newX = forX[i] + newPair.first;
            int newY = forY[i] + newPair.second;

            if(newX < 0|| newY <0 || newX >100 || newY > 100) continue;
            if(visited[newX][newY] !=-1 || arr[newX][newY] != 1) continue;
            
            visited[newX][newY] = visited[newPair.first][newPair.second] + 1;
            if(visited[newX][newY] > number){
                number = visited[newX][newY];
            }
            que.push({newX,newY});
        }
    }

    answer += number;
    
}


void colorArr(int stX,int stY){
    for(int i=0;i<=10;i++){
        for(int t=0;t<=10;t++){
            if(i==0 || i == 10){
                if(arr[stX+i][stY+t] == 0)
                    arr[stX+i][stY+t] = 1;
                else if(t ==0|| t==10){

                    // arr[stX+i][stY+t] = 1;
                }
                else
                    arr[stX+i][stY+t] = 2;
            }else if(t ==0||t==10){
                if(arr[stX+i][stY+t]==0)
                    arr[stX+i][stY+t] = 1;
                else if(arr[stX+i][stY+t] == 1){

                }
                else
                    arr[stX+i][stY+t] = 2;
            }else{
                arr[stX+i][stY+t] = 2;
            }
        }
    }
}

//일단 이해했다. 둘레를 구할때는 접하는 면이 몇 개인지를 구하면 되는 것이다.

void colorARr(int stY,int stX){

    for(int i=0;i<10;i++){
        for(int t=0;t<10;t++){
            arr[stY+i][stX+t] = 1;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    //위와 아래의 끝 점이 값으로 주어지게 되는 것이다.
    //이렇게 하면 좀 더 빠르게 하기 때문에 발생하는 문제를 해결 가능?

    for(int i=0; i<N;i++){
        int stX;
        int stY;
        cin >> stX >> stY;
        colorARr(stY,stX);
    }
    // int answer = 0;
    // for(int i =0; i<100;i++){
    //     fill(visited[i],end(visited[i]),-1);
    // }

    for(int i=1;i<102;i++){
        for(int t=1;t<102;t++){
            if(arr[i][t]==1){
                answer += 4-(arr[i-1][t] + arr[i][t-1] + arr[i+1][t] + arr[i][t+1]);
            }
        }
        // cout << "\n";
    }


    cout << answer << "\n";
}