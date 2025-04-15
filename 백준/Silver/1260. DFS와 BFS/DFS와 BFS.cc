#include<bits/stdc++.h>

using namespace std;

int N,M,V;

vector<pair<int,int>> vec;
bool visited[1010];
bool visited2[1010];

void getBFS(){

    queue<int> que;
    que.push(V);
    visited[V] = 1;
    while(!que.empty()){
        int temp = que.front();
        cout << temp << " ";
        que.pop();

        for(int i=0;i<vec.size();i++){
            if(vec[i].first==temp){
                if(!visited[vec[i].second]){
                    visited[vec[i].second] = 1;
                    que.push(vec[i].second);
                   
                }
            }
        }
    }
    cout << "\n";
}


void getDFS(stack<int> sta){
    
    int temp = sta.top();
    visited2[temp]=1;
    cout << temp << " ";
    sta.pop();

    for(int i=0;i<vec.size();i++){
        if(vec[i].first==temp){
            if(!visited2[vec[i].second]){
                sta.push(vec[i].second);
                getDFS(sta);
            }
        }
    }
}


int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    for(int i=0;i<M;i++){
        pair<int,int> newPair;
        pair<int,int> newPair2;
        cin >> newPair.first >> newPair.second;
        newPair2.first = newPair.second;
        newPair2.second = newPair.first;
        vec.push_back(newPair);
        vec.push_back(newPair2);
    }
    sort(vec.begin(),vec.end());
    stack<int> sta;
    sta.push(V);
    visited2[V]=1;
    getDFS(sta);
    cout << "\n";
    getBFS();




}