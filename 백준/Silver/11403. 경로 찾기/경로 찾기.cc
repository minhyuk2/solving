#include <bits/stdc++.h>

using namespace std;

int N;
int arr[103][103];

void go(int stX,int stY){
    queue<pair<int,int>> que;
    que.push({stX,stY});
    while(!que.empty()){
        pair<int,int> newPair = que.front();
        que.pop();
        for(int i=0;i<N;i++){
            if(arr[newPair.second][i] == 1){
                if(arr[newPair.first][i]!=1){
                    arr[newPair.first][i] = 1;
                    que.push({newPair.second,i});
                }
            }
        }
    }

    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >>N;
    for(int i=0;i<N;i++){
        for(int t= 0;t<N;t++){
            cin >> arr[i][t];
        }
    }

    for(int i=0;i<N;i++){
        for(int t= 0;t<N;t++){
            if(arr[i][t] == 1){
                go(i,t);
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int t= 0;t<N;t++){
            if(arr[i][t] == 1){
                go(i,t);
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int t= 0;t<N;t++){
            cout << arr[i][t] << " ";
        }
        cout << "\n";
    }
}  