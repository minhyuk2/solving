#include<bits/stdc++.h>

using namespace std;

int arr[105][105];
int forX[4] = {-1,0,1,0};
int forY[4] = {0,1,0,-1};

int number = 1000000;
int visited[105][105];

int getAnswer(int characterX, int characterY, int itemX, int itemY){
    for(int i=0;i<=100;i++){
        fill(visited[i],end(visited[i]),-1);
    }
    queue<pair<int,int>> que;
    que.push({characterY*2,characterX*2});
    visited[characterY*2][characterX*2] = 0;
    
    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int newX = newPair.first + forX[i];
            int newY = newPair.second + forY[i];
            
            if( newX < 0 || newY < 0) continue;
            if(visited[newX][newY] != -1 || arr[newX][newY] != 1) continue;
            if(newX == itemY*2 && newY == itemX*2){
                if(number > visited[newPair.first][newPair.second] + 1){
                    number = visited[newPair.first][newPair.second] + 1;
                }
            }
            visited[newX][newY] = visited[newPair.first][newPair.second] + 1;
            que.push({newX,newY});
        }
        
    }
    return number;
}

void colorArr(vector<vector<int>> &rectangle){
    for(int i =0;i<rectangle.size();i++){
        int stX = rectangle[i][0] * 2;
        int stY = rectangle[i][1] * 2;
        int endX = rectangle[i][2] * 2;
        int endY = rectangle[i][3] * 2;
        
        for(int t=stY; t<=endY; t++){
            for(int p = stX; p<=endX;p++){
                if(t==stY || t ==endY){
                    if(arr[t][p]==0){
                        arr[t][p] = 1;
                    }
                }else if(p==stX || p == endX ){
                    if(arr[t][p] ==0){
                        arr[t][p] = 1;
                    }
                }else{
                    arr[t][p] = 2;
                }
            }
        }
    }    

}




int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    colorArr(rectangle);
    
    // for(int i=1;i<=10;i++){
    //     for(int t = 1;t<=10;t++){
    //         cout << arr[i][t] << " ";
    //     }
    //     cout << "\n";
    // }
    
    answer = getAnswer(characterX,characterY,itemX,itemY)/2;
    
    return answer;
}