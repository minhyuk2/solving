#include <bits/stdc++.h>

using namespace std;


int N;
int forX[4] = {-1,0,1,0};
int forY[4] = {0,1,0,-1};

int arr[30][30];
int visited[30][30];
string temp[30];

int building;
vector<int> answer;

void getBFS(queue<pair<int,int>> &que){
    int numbers = 1;
    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        visited[newPair.first][newPair.second] = 1;
        for(int i=0;i<4;i++){
            int newX = newPair.first + forX[i];
            int newY = newPair.second + forY[i];

            if(newX<0||newY<0||newX>=N||newY>=N) continue;
            if(arr[newX][newY]!=1||visited[newX][newY] !=0) continue;

            visited[newX][newY] =1 ;
            que.push({newX,newY});
            numbers++;
        }
    }

    answer.push_back(numbers);
}

void getBuilding(){
    

    for(int i=0;i<N;i++){
        for(int t=0;t<N;t++){
            if(arr[i][t] == 1 && visited[i][t] == 0){
                building++;
                queue<pair<int,int>> que;
                que.push({i,t});
                getBFS(que);
            }
        }
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> temp[i];
    }


    for(int i=0;i<N;i++){
        for(int t=0;t<N;t++){
            arr[i][t] =  temp[i][t] - '0';
        }
    }
    getBuilding();
    cout << building << "\n";
    sort(answer.begin(),answer.end());
    for(auto it : answer)
        cout << it << "\n";

}