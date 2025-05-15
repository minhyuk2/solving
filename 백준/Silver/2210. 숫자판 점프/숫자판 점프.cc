#include <bits/stdc++.h>

using namespace std;

int forY[4] = {0,1,0,-1};
int forX[4] = {1,0,-1,0};
set<string> sets;
char arr[5][5];

void gogo(int stX,int stY){
    bool visited[5][5] = {0,};

    queue<pair<pair<int,int>,string>> que;
    string temper = "";
    temper.push_back( arr[stX][stY]);
    que.push({{stX,stY},temper});
    visited[stX][stY] = 1;

    while(!que.empty()){
        string news = que.front().second;
        pair<int,int> newPair = que.front().first;
        que.pop();

        for(int i=0;i<4;i++){
            int newX = newPair.first + forX[i];
            int newY = newPair.second + forY[i];

            if(newX >=5 ||  newY >=5 || newX <0 || newY <0) continue;
            // if(visited[newX][newY]) continue;

            // visited[newX][newY] = 1;
            string newTemp = news;
            newTemp.push_back(arr[newX][newY]);
            if(newTemp.size() == 6){
                sets.insert(newTemp);
                // cout << newTemp << "\n";
                continue;
            } 
            que.push({{newX,newY},newTemp});
        }
    }
    

}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char temp;
    for(int i=0;i<5;i++){
        for(int t= 0;t<5;t++){
            cin >> temp;
            arr[i][t] = temp + '0';
        }   
    }

    for(int i=0;i<5;i++){
        for(int t= 0;t<5;t++){
           gogo(i,t);
        }   
    }
    cout << sets.size() << "\n";

}