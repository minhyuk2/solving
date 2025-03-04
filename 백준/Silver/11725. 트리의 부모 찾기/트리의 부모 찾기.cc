#include <bits/stdc++.h>

using namespace std;


int N;
int vis[100010];
int parent[100010];

vector<int> adj[100010];

void getParent(){
    queue<int> que;
    que.push(1);

    while(!que.empty()){
        int num = que.front();
        que.pop();
        for(auto it : adj[num]){
            if(vis[it] !=0) continue;
            // cout << it << "\n";
            vis[it] = 1;
            parent[it] = num;
            que.push(it);
        }
    }
}

void printParent(){
    for(int i=2;i<=N;i++){
        cout << parent[i] << "\n";
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int A,B;
    // queue<int> que;
    // que.push(1);
    for(int i =0;i<N-1;i++){
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    getParent();
    printParent();


}