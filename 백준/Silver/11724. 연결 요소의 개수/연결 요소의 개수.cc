#include <bits/stdc++.h>

using namespace std;

int N, M;



vector<pair<int,int>> vec;
bool visited[1010];

int answer;
void getBFS(int N){
    visited[N] = 1;
    queue<int> que;
    que.push(N);

    while(!que.empty()){
        int temp = que.front();
        que.pop();

        for(int i =0;i<M*2;i++){
            if(vec[i].first == temp){
                if(!visited[vec[i].second]){
                    visited[vec[i].second] = 1;
                    que.push(vec[i].second);
                }
            }
        }
    }
}

void getEdge (){
    //bfs로 찾아가던 dfs로 찾아가던 둘 중 하나만 하면 될 듯

    for(int i=1;i<=N;i++){
        if(!visited[i]){
            // cout << i << "\n";
            answer ++ ;
            getBFS(i);
        }
    }

}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=0;i<M;i++){
        pair<int,int> newPair;
        pair<int,int> newPairRev;
        cin >> newPair.first >> newPair.second;
        newPairRev.first = newPair.second;
        newPairRev.second = newPair.first;
        vec.push_back(newPair);
        vec.push_back(newPairRev);
    }
    getEdge();
    cout << answer << "\n";

}