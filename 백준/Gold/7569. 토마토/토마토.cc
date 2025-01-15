#include <bits/stdc++.h>

using namespace std;

int N,M,H;

int tomato[101][101][101];
int visited[101][101][101];
int forX[6] = {-1,0,1,0,0,0};
int forY[6] = {0,1,0,-1,0,0};
int forZ[6] = {0,0,0,0,1,-1};
long long int answer;
queue<pair<pair<int,int>,pair<int,int>>> que2;

void ripeToma(){
    queue<pair<pair<int,int>,pair<int,int>>> que;

    // while(!que2.empty()){
    //     que.push(que2.front());
    //     que2.pop();
        while(!que2.empty()){
            pair<pair<int,int>,pair<int,int>> newPair;
            newPair = que2.front();
            que2.pop();
            for(int i = 0; i < 6 ; i++){
                int newX = newPair.second.first  + forX[i];
                int newY = newPair.second.second + forY[i];
                int newZ = newPair.first.second + forZ[i];

                if(newX < 0 || newY < 0 || newZ < 0 || newX >= N || newY >= M || newZ >= H) continue;
                if( (visited[newZ][newX][newY] == 1) || tomato[newZ][newX][newY] == -1 ) continue;
                //근데 여기서 새롭게 들어올
                visited[newZ][newX][newY] = 1;
                if(answer < newPair.first.first+1){
                    answer = newPair.first.first+1;
                }
                que2.push({{newPair.first.first+1,newZ},{newX,newY}});
            }
        }
    // }
    bool allOk = 1;
    int minuscount = 0;
    for(int i = 0; i < H ; i++){
        for(int t = 0 ; t < N; t++){
            for(int p = 0 ; p < M; p++){
                // cout << visited[i][t][p];
                if(tomato[i][t][p]!= -1){
                    if(visited[i][t][p]==0){
                        allOk = 0;
                        continue;
                    }
                }else{
                    minuscount++;
                }

            }
            // cout << "\n";
        }
        // cout << "\n";
    }
    

    if(minuscount == H*N*M){
        cout << -1 << "\n";
        return;
    }

    if(allOk == 0){
        cout << -1 << "\n";
    }else{
        if(answer == 0 ){
            cout << 0 << "\n";
        }else{
            cout << answer << "\n";
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M>> N>> H;

    for(int i = 0; i < H ; i++){
        for(int t = 0 ; t < N; t++){
            for(int p = 0 ; p < M; p++){
                cin >> tomato[i][t][p];
                if(tomato[i][t][p]==1){
                    visited[i][t][p] = 1;
                    que2.push({{0,i},{t,p}});
                }

            }
        }
    }

    ripeToma();


    
}