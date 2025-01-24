#include <bits/stdc++.h>

using namespace std;

int K;
int H,W;
int visited[31][201][201];
int arr[201][201];



int forX[4] = {1,0,-1,0};
int forY[4] = {0,1,0,-1};

int forHorseX[8] = {-2,-1,1,2,2,1,-1,-2};
int forHorseY[8] = {1,2,2,1,-1,-2,-2,-1};



void monkey(){
    queue<tuple<int,int,int>> que;
    que.push({0,0,0});
    
    visited[0][0][0] = 1;
    while(!que.empty()){
        tuple<int,int,int> newPair = que.front();
        que.pop();

       
        for(int i =0; i<4;i++){
            int newX = forX[i] + get<1>(newPair);
            int newY = forY[i] + get<2>(newPair);

            if(newX < 0 || newX >=H || newY < 0 || newY >=W)continue;
            if(arr[newX][newY] == 1 || visited[get<0>(newPair)][newX][newY] >= 1) continue;
            visited[get<0>(newPair)][newX][newY] = visited[get<0>(newPair)][get<1>(newPair)][get<2>(newPair)]+1;
            que.push({get<0>(newPair),newX,newY});
        }
        if(get<0>(newPair) < K){
            for(int i=0;i<8;i++){
                int newX = forHorseX[i] + get<1>(newPair);
                int newY = forHorseY[i] + get<2>(newPair);

                if(newX < 0 || newX >=H || newY < 0 || newY >=W)continue;
                if(arr[newX][newY] == 1 || visited[get<0>(newPair)+1][newX][newY] >= 1) continue;
                
                visited[get<0>(newPair)+1][newX][newY] = visited[get<0>(newPair)][get<1>(newPair)][get<2>(newPair)] + 1;
                que.push({get<0>(newPair)+1,newX,newY});
            }
    }
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;
    cin >> W >> H;
    for(int i=0;i<H;i++){
        for(int t=0;t<W;t++){
            cin >> arr[i][t];
        }
    }
    monkey();
    // for(int p =0;p<=K;p++){
    //     for(int i=0;i<H;i++){
    //         for(int t=0;t<W;t++){
    //             cout<<  visited[p][i][t] << " ";
    //         }
    //         cout << "\n";
    //     }   
    //     cout << "\n";
    // }
    int answer = 10000000;
    for(int i=0;i<=K;i++){
        if(visited[i][H-1][W-1] < answer && visited[i][H-1][W-1] != 0 ){
            answer = visited[i][H-1][W-1]-1;
        }
    }
    if( answer == 10000000){
        cout << -1 << "\n";
    }else{
        cout << answer << "\n";
    }
}