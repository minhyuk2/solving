#include <bits/stdc++.h>

using namespace std;

int N;
int W,H;
char building[1001][1001];
int fire[1001][1001];
int sangV[1001][1001];
int forX[4] = {-1,0,1,0};
int forY[4] = {0,1,0,-1};
pair<int,int> sang;

void buildingFire(queue<pair<int,int>> &que){

    //모든 불이 붙은 시간에 대한 표현을 함
    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        for(int i =0; i< 4; i++){
            int newX = forX[i] + newPair.first;
            int newY = forY[i] + newPair.second;

            if(newX >= H || newX < 0 || newY >= W || newY < 0) continue;
            if(building[newX][newY] == '#' || building[newX][newY] == '@') continue;
            if(fire[newX][newY] > -1)continue;

            fire[newX][newY] = fire[newPair.first][newPair.second] + 1;
            que.push({newX,newY});
        }
    }

    int counting = 0;
    queue<pair<int,int>> sangQ;
    sangQ.push(sang);  
    sangV[sang.first][sang.second] = 0;
    while(!sangQ.empty()){
        pair<int,int> newPair = sangQ.front();
        sangQ.pop();

        for(int i =0 ; i<4 ; i++){
            int newX = forX[i] + newPair.first;
            int newY = forY[i] + newPair.second;
            if(newX >= H || newX < 0 || newY >= W || newY < 0) continue;
            if(building[newX][newY] == '#' || building[newX][newY] == '*') continue;
            if(sangV[newPair.first][newPair.second] + 1 >= fire[newX][newY]&&fire[newX][newY] != -1) continue;
            if(sangV[newX][newY] > -1) continue;
            sangV[newX][newY] =  sangV[newPair.first][newPair.second] + 1;
            sangQ.push({newX,newY});
        }
    }
    
    long long int answer = 1000000000;
    //끝에 둘레만 돌면된다.
    for(int i= 0; i<H;i++){
        for(int t= 0; t<W;t++){
            if(i == 0||i == H-1){
                if(sangV[i][t] < answer && sangV[i][t] != -1){
                     answer = sangV[i][t];
                 }
            }else{
                if(t==0||t==W-1){
                    if(sangV[i][t] < answer && sangV[i][t] != -1){
                     answer = sangV[i][t];
                    }
                }
            }

        }
    }

    if(answer == 1000000000 ){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << answer + 1 << "\n";
    }

}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for(int i = 0 ; i < N; i++){
        cin >> W >> H;
        for(int t = 0; t<1001; t++){
            //다 쓰고 나서는 초기화를 진행
            fill(building[t],building[t]+1001,'0');
            fill(fire[t],fire[t]+1001,-1);
            fill(sangV[t],sangV[t]+1001,-1);
        }
        queue<pair<int,int>> que;
        for(int t = 0; t<H;t++){
            for(int p =0; p < W; p++){
                cin >> building[t][p];
                if(building[t][p] == '*'){
                    que.push({t,p});
                    fire[t][p] = 0;
                }else if(building[t][p] == '@'){
                    sang = {t,p};
                }
            }
        }
        buildingFire(que);
    }


}