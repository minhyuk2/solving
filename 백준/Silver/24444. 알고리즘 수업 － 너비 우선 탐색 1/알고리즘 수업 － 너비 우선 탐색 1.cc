#include <bits/stdc++.h>

using namespace std;

int N, M,St;

set<int> sets[100005];
bool visited[100005];
int arr[100005];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> St;


    int temp1, temp2;
    for(int i=0;i<M;i++){
        cin >> temp1 >> temp2;
        sets[temp1].insert(temp2);
        sets[temp2].insert(temp1);
    }

    
    queue<int> que;
    int count =1;
    que.push(St);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        if(visited[now] == 0){
            visited[now] = 1;
            arr[now] = count;
            count ++;
            for(auto it : sets[now]){
                que.push(it);
            }
        }
    }

    for(int i = 1;i<=N;i++){
        cout << arr[i] << "\n";
    }

}