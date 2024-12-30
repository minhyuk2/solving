#include <bits/stdc++.h>

using namespace std;

int bugs[51][51];
int visitss[51][51];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void queCal(queue<pair<int,int>> que,int M, int N);

int getBugs(int M, int N){
    int answer = 0;
    queue<pair<int,int>> que;
    for(int i = 0 ; i< N ;  i++){
        for(int t = 0 ; t < M ; t++){
            if(bugs[i][t]==1){
                //이것에 대해서 이제 판단해 나가야 하는 것인데
                if(visitss[i][t] == -1){
                    //visit하지 않은 경우
                    visitss[i][t] = 1;
                    answer ++;
                    que.push({i,t});
                    //여기서 이제 반복문 돌면서 해당 과정을 반복하게끔 진행하면 될 듯? 이러면 처음에만 answer가 생기고 나머지 애들은 처리가 되어지니까 ㅇㅋ
                    queCal(que,M,N);
                }else{
                    //만약에 이미 visit이 되어있던 것이면 그냥 건너뛴다.
                    continue;
                }
            }
        }
    }
    return answer;
}


void queCal(queue<pair<int,int>> que,int M, int N){
    //이걸로 큐를 돌면서 확인하는 것이다.
    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        
        for(int i =0 ; i < 4 ; i ++){
            //pair이기에 first와 second로 설정하는 것이 좋다.
            int nx = newPair.second + dx[i];
            int ny = newPair.first + dy[i];
            if( nx < 0 || nx >= M || ny < 0 || ny >= N ) continue;
            if(visitss[ny][nx] != -1 || bugs[ny][nx] != 1 ) continue;
            que.push({ny,nx});
            visitss[ny][nx] = 1;
        }
    }
}


int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // queue<int> que;

    int cases;
    cin >> cases;
    int M, N, K;
    int X,Y;


//bfs랑 dfs로 주변 다 확인하고 진행하는 식으로 만들어져야 할듯
    for(int i  = 0 ; i < cases; i++){
        //처음에 cases를 입력받고 입력받은 case만큼 횟수 진행
        cin >> M >> N >> K;
        for(int p = 0 ; p < 50 ; p++){
            //2차원 행렬 0으로 다시 한 번 초기화
            fill(bugs[p],bugs[p]+51,0);
            fill(visitss[p],visitss[p]+51,-1);
        }
        //인접행렬에 값을 집어넣기
        for(int  p = 0 ; p < K; p++){
            cin >> X >> Y;
            bugs[Y][X] = 1;
        } 
        //이 인접행렬을 이용한 bfs 수행
        cout << getBugs(M,N) << "\n";
    }
}